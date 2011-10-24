/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  28 Jan 2007 11:25:43 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_OGGSOUNDHOLDER_OGGSOUNDHOLDER_979F6855__
#define __JUCER_HEADER_OGGSOUNDHOLDER_OGGSOUNDHOLDER_979F6855__

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
class oggsoundholder  : Component
{
public:
    //==============================================================================
    oggsoundholder ();
    ~oggsoundholder();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* jack_capture_02_ogg;
    static const int jack_capture_02_oggSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    oggsoundholder (const oggsoundholder&);
    const oggsoundholder& operator= (const oggsoundholder&);
};


#endif   // __JUCER_HEADER_OGGSOUNDHOLDER_OGGSOUNDHOLDER_979F6855__
