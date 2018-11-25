
#include "mammut.h"
#include <stdlib.h>

int combsplit_block_size_default=99;
int combsplit_number_of_files_default=10;

int combsplit_block_size=99;
int combsplit_number_of_files=10;

extern struct LoadStruct loadstruct;

void combsplit_ok(void)
{
  int i,ch;
  int div,num=0;
  char filename[400]={0};
  char extension[20]={0};
  char *extp;

  int nch,nchN;

  GUI_aboveprogressbar(0,samps_per_frame*num);
    
  div=combsplit_block_size;
  num=combsplit_number_of_files;
  
  for (i=0; i<samps_per_frame*N; i++) lyd2[i]=lyd[i];  

  /* rett kanal : (i/div)%num==kanalnr */
  for (ch=0; ch<num; ch++) {
    printf("ch: %d\n",ch);
    for(nch=0;nch<samps_per_frame;nch++){
      nchN=nch*N;
      for (i=0; i<N/2; i++) {
	if ( ((i/div)%num)==ch) {
	  lyd[i+i+nchN]=lyd2[i+i+nchN]; lyd[i+i+1+nchN]=lyd2[i+i+1+nchN];
	} else { 
	  lyd[i+i+nchN]=0.; lyd[i+i+1+nchN]=0.;
	}  
      }
    }

    /*og så må vi lagre da*/
    extp=strrchr(playfile,'.');
    if(extp>strrchr(playfile,'/')) { 
      char tmpfn[300]={0};
      strcpy(extension,++extp);
      strncpy(tmpfn,playfile,(extp-playfile)-1);
      //      tmpfn[extp-playfile-1]=0;
      sprintf(filename,"%s-%d.%s",tmpfn,ch,extension);
    }else{ 
      sprintf(filename,"%s-%d",playfile,ch);
    }

    /*
    out_AFsetup=afNewFileSetup();
    afInitChannels(out_AFsetup, AF_DEFAULT_TRACK, samps_per_frame);
    afInitRate(out_AFsetup, AF_DEFAULT_TRACK, R);
    afInitCompression(out_AFsetup, AF_DEFAULT_TRACK, compression);
    afInitFileFormat(out_AFsetup, filefmt);
    afInitSampleFormat(out_AFsetup, AF_DEFAULT_TRACK, samp_type, bits_per_samp);
    outfile=afOpenFile(filename, "wb", out_AFsetup);
    */

    outfile=sf_open_write(filename,&loadstruct.sfinfo);

    if (outfile==NULL) {
      fprintf(stderr,"Could not open file. \"%s\".\n",filename);
      continue;
    }

    for(nch=0;nch<samps_per_frame;nch++){
      GUI_aboveprogressbar(ch*samps_per_frame + nch,samps_per_frame*num);
      nchN=nch*N;
      rfft(lyd+nchN,N/2,INVERSE);
    }

    writesound(SaveWaveConsumer,outfile);
    //    afCloseFile(outfile);
    sf_close(outfile);
  }
  
  for (i=0; i<samps_per_frame*N; i++) lyd[i]=lyd2[i];

}
