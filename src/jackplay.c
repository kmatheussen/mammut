
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "mammut.h"


#ifdef HAVE_JACK

#include <jack/jack.h>

#include "jackplay.h"



#define DEFAULT_NUM_CHANNELS 2
#define JP_MAX(a,b) (((a)>(b))?(a):(b))
#define JP_MIN(a,b) (((a)<(b))?(a):(b))


/* JACK data */
static jack_port_t **ports;
typedef jack_default_audio_sample_t sample_t;
static int jack_buffer_size;
static float jack_samplerate;
static int connect_num=0;
static jack_client_t *client=NULL;
static int channels;
static bool is_initialized=false;



static int findnumports(char **ports){
  int ret=0;
  while(ports && ports[ret]!=NULL)
    ret++;
  return ret;
}


static bool setup_ports(void){
  int ch;
  char **portnames;


  // Find ports to connect to
  {
    portnames=(char **)jack_get_ports(client,NULL,NULL,JackPortIsPhysical|JackPortIsInput);
    //channels=JP_MAX(DEFAULT_NUM_CHANNELS,findnumports(portnames));
    channels=DEFAULT_NUM_CHANNELS;
  }


  // Create my own ports
  {
    ports=erroralloc(sizeof(jack_port_t *)*channels);
    for(ch=0;ch<channels;ch++){
      char temp[500];
      sprintf(temp,"out_%d",ch+1);
      ports[ch]=jack_port_register(
					client,
					strdup(temp),
					JACK_DEFAULT_AUDIO_TYPE,
					JackPortIsOutput,
					0
					);
      if(ports[ch]==NULL){
	printerror("Error. Could not register jack port.\n");
	return false;
      }
    }
  }


  // Connect
  {
    for(ch=0;portnames && portnames[ch]!=NULL && ch<channels;ch++){
      if (
	  jack_connect(
		       client,
		       jack_port_name(ports[ch]),
		       portnames[ch]
		       )
	  )
	{
	  printf ("Warning. Cannot connect to jack output port %d: \"%s\".\n",ch,portnames[ch]);
	}
    }
  }


  return true;
}



static jack_client_t *new_jack_client(char *name){
  jack_client_t *client=jack_client_new(name);

  if(client==NULL){
    for(connect_num=1;connect_num<100;connect_num++){
      char temp[500];
      sprintf(temp,"%s_%d",name,connect_num);
      client=jack_client_new(temp);
      if(client!=NULL)
	return client;
    }
    fprintf(stderr,"\njack server not running? (Unable to create jack client \"%s\")\n",name);
    return NULL;
  }

  return client;
}


static bool start_jack(void){
  client=new_jack_client("mammut");
  if(client==NULL)
    return false;

  jack_buffer_size=jack_get_buffer_size(client);
  jack_samplerate=jack_get_sample_rate(client);

  return true;
}


static void jack_shutdown(void *arg){
  printerror("JACK shut down.\n");
  return;
}


static int process (jack_nframes_t nframes, void *arg){
  void (*audioCallback)(float ** 	inputChannelData, 
			int 	totalNumInputChannels, 
			float ** 	outputChannelData, 
			int 	totalNumOutputChannels, 
			int 	numSamples
			)=arg;
  
  int ch;
  sample_t *out[channels];

  if(is_initialized==false)
    return 1;

  for(ch=0;ch<channels;ch++){
    out[ch]=(sample_t*)jack_port_get_buffer(ports[ch],nframes);
  }

  audioCallback(NULL,0,out,channels,nframes);

  return 0;
}


static void cleanup_exit(void){
  jack_client_close(client);
}

double init_jack(void (*audioCallback)(float ** 	inputChannelData, 
				       int 	totalNumInputChannels, 
				       float ** 	outputChannelData, 
				       int 	totalNumOutputChannels, 
				       int 	numSamples
				       )){
  if(start_jack()==false)
    return -1.0;

  jack_on_shutdown(client, jack_shutdown, NULL);
  jack_set_process_callback(client, process, audioCallback);

  if(jack_activate(client)){
    printerror("Error. Cannot activate jack client.\n");
    jack_client_close(client);
    return -1.0;
  }
 
  if(setup_ports()==false){
    jack_client_close(client);
    return -1.0;
  }

  is_initialized=true;

  atexit(cleanup_exit);

  return jack_samplerate;
}

#else
double init_jack(void (*audioCallback)(float ** 	inputChannelData, 
				       int 	totalNumInputChannels, 
				       float ** 	outputChannelData, 
				       int 	totalNumOutputChannels, 
				       int 	numSamples
				       )){
  return -1;
}

#endif
