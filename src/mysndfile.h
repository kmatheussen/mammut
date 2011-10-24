

#include <sndfile.h>


#ifdef SNDFILE_0
#  define MSF_FRAMENAME samples
#  define MSF_IS16(a) ((a).pcmbitwidth==16)
#  define MSF_IS24(a) ((a).pcmbitwidth==24)
#  define MSF_IS32(a) ((a).pcmbitwidth==32)
#  define MSF_ISFLOATTYPE(a) (((a).format&0xff)==0x2)
#  define MSF_ISFLOAT(a) (MSF_ISFLOATTYPE(a) && (a).pcmbitwidth==32)
#else
#  define MSF_FRAMENAME frames
#  define sf_open_read(a,b) sf_open(a,SFM_READ,b)
#  define sf_open_write(a,b) sf_open(a,SFM_WRITE,b)
#  define MSF_IS16(a) ((((a).format)&SF_FORMAT_SUBMASK)==SF_FORMAT_PCM_16)
#  define MSF_IS24(a) ((((a).format)&SF_FORMAT_SUBMASK)==SF_FORMAT_PCM_24)
#  define MSF_IS32(a) ((((a).format)&SF_FORMAT_SUBMASK)==SF_FORMAT_PCM_32)
#  define MSF_ISFLOAT(a) ((((a).format)&SF_FORMAT_SUBMASK)==SF_FORMAT_FLOAT)
#  define MSF_ISFLOATTYPE(a) (MSF_ISFLOAT(a) || ((((a).format)&SF_FORMAT_SUBMASK)==SF_FORMAT_DOUBLE))
#endif


