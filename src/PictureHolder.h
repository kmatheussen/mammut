/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  12 Feb 2007 2:53:55 am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_PICTUREHOLDER_PICTUREHOLDER_D2CC121__
#define __JUCER_HEADER_PICTUREHOLDER_PICTUREHOLDER_D2CC121__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PictureHolder  : public Component
{
public:
    //==============================================================================
    PictureHolder ();
    ~PictureHolder();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    static Image *getImage(int num){
      static Image *images[3]={ImageFileFormat::loadFrom(mammut_zerlegen2_jpg, mammut_zerlegen2_jpgSize),
			       ImageFileFormat::loadFrom(mammut_zerlegen3_jpg, mammut_zerlegen3_jpgSize),
			       ImageFileFormat::loadFrom(mammut_zerlegen4_jpg, mammut_zerlegen4_jpgSize)};

      return images[num];
    }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* mammut_zerlegen3_jpg;
    static const int mammut_zerlegen3_jpgSize;
    static const char* mammut_zerlegen2_jpg;
    static const int mammut_zerlegen2_jpgSize;
    static const char* mammut_zerlegen4_jpg;
    static const int mammut_zerlegen4_jpgSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    PictureHolder (const PictureHolder&);
    const PictureHolder& operator= (const PictureHolder&);
};


#endif   // __JUCER_HEADER_PICTUREHOLDER_PICTUREHOLDER_D2CC121__
