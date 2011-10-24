/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  11 Feb 2007 11:30:46 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_PREFS_PREFS_4F2799EC__
#define __JUCER_HEADER_PREFS_PREFS_4F2799EC__

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
class Prefs  : public Component,
               public ButtonListener
{
public:
    //==============================================================================
    Prefs ();
    ~Prefs();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    PropertiesFile *propertiesfile;
    bool firstRun_questionmark();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ToggleButton* soundonoffButton;
    ToggleButton* movingcameraButton;
    ToggleButton* animationButton;
    ToggleButton* pictureButton;
    ToggleButton* loopButton;
    TextButton* audioSettingsButton;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    Prefs (const Prefs&);
    const Prefs& operator= (const Prefs&);
};


#endif   // __JUCER_HEADER_PREFS_PREFS_4F2799EC__
