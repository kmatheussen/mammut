
/*

This is a quick and not that nice (but good enough) example on how to make sound with juce,
including jack support. It is made in such a way, that changing an old juceplayer class
into supporting jack should be very simple.

The constructor first checks if the jack server is running. If not, it will use juce's
sound API instead. Erik de Castro Lopo's libsamplerate is used for resampling, in case
resampling is needed.

Instructions:
* The methods getSourceLength, getSourceData, getSourceRate, getSourceNumChannels, sourceInit,
  and sourceCleanup must be provided.
* First call juceplay_init()
* To make sound, call juceplay_start()
* To stop the sound, call juceplay_stop()

I'm sorry about all the non-C++ stuff. I'm not a big C++ fan.


-Kjetil S. Matheussen/2007
*/


#include <vorbis/codec.h>
#include <vorbis/vorbisfile.h>
#include <samplerate.h>


#include "juce.h"
#include "mammut.h"
#include "juceplay.h"

#include "oggsoundholder.h"


#ifdef HAVE_JACK
#  include "jackplay.h"
#endif


#define SRC_QUALITY SRC_SINC_BEST_QUALITY
#define JP_MIN(a,b) (((a)<(b))?(a):(b))
#define JP_MAX(a,b) (((a)>(b))?(a):(b))


extern LANGSPEC void audio_jack_callback (float ** 	inputChannelData, 
					  int 	totalNumInputChannels, 
					  float ** 	outputChannelData, 
					  int 	totalNumOutputChannels, 
					  int 	numSamples
					  );

long audio_getOggResampledData_callback(void *cb_data, float **data);


static int oggpos=0;

static size_t oggread_func  (void *ptr, size_t size, size_t nmemb, void *datasource){

  const char *source=oggsoundholder::jack_capture_02_ogg;
  int maxsize=oggsoundholder::jack_capture_02_oggSize;
  char *dst=(char*)ptr;

  //fprintf(stderr,"oggread\n");

  if(oggpos>=maxsize){
    return 0;
  }

  int i;
  for(i=0;i<(int)nmemb;i++){
    for(int b=0;b<(int)size;b++){
      dst[i*size+b]=source[oggpos++];
    }
    if(oggpos>=maxsize){
      break;
    }
  }
  return i;
}

static int  oggseek_func(void *datasource, ogg_int64_t offset, int whence){
  //fprintf(stderr,"oggseek\n");
  switch(whence){
  case SEEK_SET:
    oggpos=offset;
    break;
  case SEEK_CUR:
    oggpos+=offset;
    break;
  case SEEK_END:
    oggpos=oggsoundholder::jack_capture_02_oggSize - offset;
    break;
  }

  return 0;
}

static int oggclose_func (void *datasource){
  fprintf(stderr,"oggclose\n");
  return 0;
}

static long oggtell_func  (void *datasource){
  fprintf(stderr,"oggtell\n");
  return oggpos;
}


int jp_playpos;
bool jp_isplaying=false;
static float normalize_val;

static void source_init(void){
  //int progval=0;

  memcpy(lyd2,lyd,samps_per_frame*N*sizeof(float));
  
  for (int ch=0; ch<samps_per_frame; ch++) {
    GUI_aboveprogressbar(ch,samps_per_frame); 
    rfft(lyd+ch*N,  N/2,  INVERSE);
  }
  
  normalize_val=get_normalize_val();
  //fprintf(stderr,"source_init finished\n");
  //if(synthandsave_normalize_gain)
  //  normalize();
}

class JucePlayer : public AudioIODeviceCallback, public ChangeListener
{
  AudioDeviceManager audioDeviceManager;
  PropertiesFile *propertiesfile;

public:

  JucePlayer(PropertiesFile *propertiesfile)
  {
    this->propertiesfile=propertiesfile;

    jp_isplaying=false;
    isreadingdata=false;
    pleasestop=false;
    isinitialized=false;
    isusingjack=false;

    {
      num_src_states=0;
      src_states=NULL;
    }

    {
      ov_callbacks ov_cb={oggread_func,oggseek_func,oggclose_func,oggtell_func};
      lastreadoggpos=-1;
      nextreadoggpos=-1;      
      if(ov_open_callbacks(&oggvorbisfile,&oggvorbisfile,NULL,0,ov_cb)==0)
	isplaying_ogg=true;
      else
	isplaying_ogg=false;
      N=getSourceLength();
      g_samplerate=44100;
      oggsrc_state=src_callback_new(audio_getOggResampledData_callback,SRC_QUALITY,2,NULL,NULL);
    }


#ifdef HAVE_JACK
    samplerate=init_jack(audio_jack_callback);

    if(samplerate!=-1){
      isinitialized=true;
      isusingjack=true;
    }else
#endif
      initJuceAudio();


    audioDeviceManager.addChangeListener(this);
  }

  void changeListenerCallback(ChangeBroadcaster *source) override {
    printf("Some audio change thing.\n");
    if(audioDeviceManager.getCurrentAudioDevice()!=NULL){
      samplerate=audioDeviceManager.getCurrentAudioDevice()->getCurrentSampleRate();
      propertiesfile->setValue("audiodevicemanager",audioDeviceManager.createStateXml());
    }else{
      fprintf(stderr,"Gakkegakke\n");
    }
  }
  
  void initJuceAudio(void){
    XmlElement *settings=propertiesfile->getXmlValue("audiodevicemanager");
    const String error (audioDeviceManager.initialise (0, /* number of input channels */
						       8, /* number of output channels */
						       settings,
						       true  /* select default device on failure */));
    
    if (audioDeviceManager.getCurrentAudioDevice()==NULL || error.isNotEmpty())
      {
	AlertWindow::showMessageBox (AlertWindow::WarningIcon,
				     T("Mammut"),
				     T("Couldn't open an output device!\n\n") + error);
      }
    else
      {
	isinitialized=true;
	
	// start the IO device pulling its data from our callback..
	audioDeviceManager.addAudioCallback (this);
	
      }
  }

  int getSourceLength(){
    if(isplaying_ogg)
      return ov_pcm_total(&oggvorbisfile,-1);
    return N;
  }
  
  void getOggData(float **dst,int num_frames){
    float **sound;
    long read=ov_read_float(&oggvorbisfile,&sound,num_frames,&current_oggsection);
    if(read==0){
      ov_pcm_seek(&oggvorbisfile,0);
      read=ov_read_float(&oggvorbisfile,&sound,num_frames,&current_oggsection);
    }
    memcpy(dst[0],sound[0],read*sizeof(float));
    memcpy(dst[1],sound[1],read*sizeof(float));
    if(read<num_frames){
      float *newdst[2]={dst[0]+read,dst[1]+read};
      getOggData(newdst,num_frames-read);
    }
  }

  long getOggResampledData_callback(void *cb_data, float **data){
    static float ret[1024];
    static float ret3[1024];
    static float *ret2[2]={&ret[0],&ret[512]};
    getOggData(ret2,512);
    for(int i=0;i<512;i++){
      ret3[i*2]=ret2[0][i];
      ret3[i*2+1]=ret2[1][i];
    }
    *data=&ret3[0];
    return 512;
  }

  void getOggResampledData(float **dst,int num_frames){
    double ratio=samplerate/getSourceRate();
    long read;

#ifdef _MSC_VER
    // Quite ugly hack.
    static float *outsound = NULL;
    static int allocated_num_frames=0;
    if(num_frames>allocated_num_frames){
      outsound = new float(2*num_frames);
      allocated_num_frames=num_frames;
    }
#else
    float outsound[num_frames*2];
#endif

    read=src_callback_read(oggsrc_state,ratio,num_frames,outsound);
    //fprintf(stderr,"read: %d, num_frames: %d\n",read,num_frames);
    for(int i=0;i<read;i++){
      dst[0][i]=outsound[i*2];
      dst[1][i]=outsound[i*2+1];
    }
    if(read<num_frames){
      float *newdst[2]={dst[0]+read,dst[1]+read};
      getOggResampledData(newdst,num_frames-read);
    }
  }

  float *getSourceData(int channel,int position,int num_frames){
    return lyd+(position+(channel*N));
  }
  double getSourceRate(){
    return (double)g_samplerate;
  }
  int getSourceNumChannels(){
    return samps_per_frame;
  }
  void sourceCleanup(){
    memcpy(lyd,lyd2,getSourceNumChannels()*N*sizeof(float));
  }

  void insertDataResample(float **outdata,int frames,int num_channels){
    static float nulldata[512]={0.0f};
    int last_consumed=0;
    double ratio=samplerate/getSourceRate();
    for(int ch=0;ch<num_channels;ch++){
      SRC_DATA src_data={
	mustrunonemore==true?nulldata:getSourceData(ch,jp_playpos,1024), outdata[ch],
	mustrunonemore==true?512:JP_MIN((long)(64+1.2*frames/ratio),getSourceLength()-jp_playpos), frames,
	0,0,
	0,
	ratio
      };
      src_process(src_states[ch],&src_data);

      // This check is probably not necessarry.
      if(ch>0 && last_consumed!=src_data.input_frames_used)
	fprintf(stderr,"Serious error in playback.\n");
      last_consumed=src_data.input_frames_used;

      if(ch==num_channels-1){
	if(mustrunonemore==true){
	  if(last_consumed>0){
	    mustrunonemore=false;
	    if(prefs_loop==true){
	      jp_playpos=0;
	    }else{
	      isreadingdata=false;
	    }
	  }
	}else{
	  jp_playpos+=src_data.input_frames_used;
	  if(jp_playpos>=getSourceLength())
	    mustrunonemore=true;
	}
	//printf("running_more: %d, consumed: %d %f %d\n",mustrunonemore,last_consumed,rate,(int)(frames/rate));
      }
    }
  }

  void insertData(float **outdata,int frames,int num_channels){
    if(frames+jp_playpos <= getSourceLength()){
      for(int ch=0;ch<num_channels;ch++){
	memcpy(outdata[ch],getSourceData(ch,jp_playpos,frames),sizeof(float)*frames);
      }
    }else{
      int len = getSourceLength() - jp_playpos;
      for(int ch=0;ch<num_channels;ch++){
	memcpy(outdata[ch],getSourceData(ch,jp_playpos,len),sizeof(float)*len);
	zeromem(outdata[ch]+len,sizeof(float)*(frames-len));
      }
    }
    jp_playpos+=frames;
    if(jp_playpos>=getSourceLength()){
      if(prefs_loop==true){
	jp_playpos=0;
      }else{
	isreadingdata=false;
      }
    }
  }

  void audioDeviceIOCallback(const float ** 	inputChannelData, 
			     int 	totalNumInputChannels, 
			     float ** 	outputChannelData, 
			     int 	totalNumOutputChannels, 
			     int 	numSamples
			     )
    override
  {

    // First find the real number of totalNumOutputChannels.
    {
      int i;
      for(i=0;i<totalNumOutputChannels;i++)
	if(outputChannelData[i]==NULL)
	  break;
      totalNumOutputChannels=i;
    }

    if(totalNumOutputChannels<2)
      //???
      return;

    if(isplaying_ogg==true && prefs_soundonoff==true){
      if( (fabs(((double)g_samplerate) - samplerate)) > 0.1)
	getOggResampledData(outputChannelData,numSamples);
      else
	getOggData(outputChannelData,numSamples);
      return;
    }

    int num_channels=getSourceNumChannels();
    if(num_channels>totalNumOutputChannels)
      num_channels=totalNumOutputChannels;

    if(pleasestop==true)
      isreadingdata=false;

    if(isreadingdata==false){
      for(int ch=0;ch<totalNumOutputChannels;ch++){
	zeromem (outputChannelData[ch], sizeof (float) * numSamples);
      }
      return;
    }

    if( (fabs(((double)g_samplerate) - samplerate)) > 0.1){
      insertDataResample(outputChannelData,numSamples,num_channels);
    }else{
      insertData(outputChannelData,numSamples,num_channels);
    }

    if(synthandsave_normalize_gain)
      for(int ch=0;ch<num_channels;ch++)
	for(int i=0;i<numSamples;i++)
	  outputChannelData[ch][i]*=normalize_val;


    // Play mono files in both loudspeakers.
    if(isplaying_ogg==false && getSourceNumChannels()==1 && totalNumOutputChannels>1)
      memcpy(outputChannelData[1],outputChannelData[0],sizeof(float)*numSamples);

    for(int ch=JP_MAX(2,getSourceNumChannels());ch<totalNumOutputChannels;ch++){
      zeromem(outputChannelData[ch], sizeof (float) * numSamples);
    }

  }


  void play(){
    int num_channels=getSourceNumChannels();

    if(isinitialized==false || num_channels==0)
      return;

    if(isusingjack==false && audioDeviceManager.getCurrentAudioDevice()==NULL)
      return;

    stop();

    GUI_newprocess(source_init);
    //source_init();
    //fprintf(stderr,"GUI_newprocess finished\n");

#if 0      
    if(isusingjack==false){
      if(audioDeviceManager.getOutputChannels().countNumberOfSetBits()!=getSourceNumChannels()){
	if(num_channels==1)
	  num_channels=2;
	outchannels=new BitArray(0);
	for(int lokke=0;lokke<num_channels;lokke++)
	  outchannels->setBit(lokke);
	audioDeviceManager.setAudioDevice(
					  audioDeviceManager.getAvailableAudioDeviceNames()[0],
					  1024,
					  R,
					  new BitArray(0),
					  outchannels,
					false);
      }
    }
#endif  

    {
      int error;
      for(int i=0;i<num_src_states;i++)
	src_delete(src_states[i]);
      free(src_states);
      
      src_states=(SRC_STATE**)malloc(sizeof(SRC_STATE*)*num_channels);
      
      for(int ch=0;ch<num_channels;ch++)
	src_states[ch]=src_new(SRC_QUALITY,1,&error);
    }

    pleasestop=false;
    jp_playpos=0;
    mustrunonemore=false;
    jp_isplaying=true;
    isreadingdata=true;
  }

  void stop(){
    isplaying_ogg=false;

    if(isinitialized==false)
      return;
    if(jp_isplaying==false)
      return;
    if(isreadingdata==true){
      pleasestop=true;
      while(isreadingdata==true)
	Time::waitForMillisecondCounter(Time::getApproximateMillisecondCounter()+100);
    }

    sourceCleanup();

    jp_isplaying=false;
  }

  void prefs(){
      
    if(isusingjack==true){
      printerror("Can not change audio when using jack.");
      return;
    }

    AudioDeviceSelectorComponent audioSettingsComp (audioDeviceManager,
						    0, 0,
						    1, 2000,
						    false, false,
                                                    false, false
                                                    );
    
    // ...and show it in a DialogWindow...
    audioSettingsComp.setSize (400, 170);
    
    DialogWindow::showModalDialog (T("Audio Settings"),
				   &audioSettingsComp,
				   NULL,Colour((uint8)0xb90,(uint8)0x60,(uint8)0x60,(uint8)0xd0),true);
    if(audioDeviceManager.getCurrentAudioDevice()==NULL && isreadingdata==true){
      isreadingdata=false;
    }
  }
  
  void audioDeviceAboutToStart (AudioIODevice *device) override
  {
    double sampleRate = device->getCurrentSampleRate ();
    printf("Samplerate set to %f\n",(float)sampleRate);
    samplerate=sampleRate;
    return;
  }
  
  void audioDeviceStopped() override
  {
    return;
  }


private:
  double samplerate;
  bool pleasestop;
  bool isinitialized;
  bool isusingjack;
  bool mustrunonemore;
#if 0
  BigInteger *outchannels;
#endif
  
  bool isreadingdata;
  bool isplaying_ogg;
  SRC_STATE *oggsrc_state;
  int lastreadoggpos;
  int nextreadoggpos;
  int current_oggsection; //(?)
  OggVorbis_File oggvorbisfile;

  int num_src_states;
  SRC_STATE **src_states;
};


static JucePlayer *jp=NULL;

long audio_getOggResampledData_callback(void *cb_data, float **data){
  return jp->getOggResampledData_callback(cb_data,data);
}

void audio_jack_callback (float ** 	inputChannelData, 
			  int 	totalNumInputChannels, 
			  float ** 	outputChannelData, 
			  int 	totalNumOutputChannels, 
			  int 	numSamples
			  )
{
  //printf("Called %d/%d\n",totalNumInputChannels,totalNumOutputChannels);
  jp->audioDeviceIOCallback((const float**)inputChannelData,totalNumInputChannels,outputChannelData,totalNumOutputChannels,numSamples);
}


void juceplay_init(PropertiesFile *propertiesfile){
  jp=new JucePlayer(propertiesfile);
}

void juceplay_start(){
  jp->play();
}

void juceplay_stop(){
  jp->stop();
}

void juceplay_prefs(){
  jp->prefs();
}
