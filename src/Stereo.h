/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  12 Feb 2007 2:04:52 am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_STEREO_STEREO_CBB18BBE__
#define __JUCER_HEADER_STEREO_STEREO_CBB18BBE__

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
class Stereo  : public Component,
                public Button::Listener,
                public Slider::Listener
{
public:
    //==============================================================================
    Stereo ();
    ~Stereo();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent3;
    GroupComponent* groupComponent2;
    TextButton* swapphasesbutton;
    GroupComponent* groupComponent;
    TextButton* crossoverbutton;
    Label* label;
    Slider* switching_probabilityslider;
    Label* label2;
    TextButton* resetbutton;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    Stereo (const Stereo&);
    const Stereo& operator= (const Stereo&);
};


#endif   // __JUCER_HEADER_STEREO_STEREO_CBB18BBE__
