
#ifndef LANGSPEC
#  ifdef __cplusplus
#    define LANGSPEC "C"
#  else
#    define LANGSPEC
#  endif
#endif

extern LANGSPEC double init_jack(void (*audioCallback)(float ** 	inputChannelData, 
						       int 	totalNumInputChannels, 
						       float ** 	outputChannelData, 
						       int 	totalNumOutputChannels, 
						       int 	numSamples
						       ));



