/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 5:00:38 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.8

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_GAIN_GAIN_2910006__
#define __JUCER_HEADER_GAIN_GAIN_2910006__

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
class Gain  : public Component,
              public SliderListener,
              public ButtonListener
{
public:
    //==============================================================================
    Gain ();
    ~Gain();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent;
    Slider* amplitude_multiplierslider;
    Label* label;
    TextButton* textButton;
    TextButton* resetbutton;
    Label* label2;
    TextButton* textButton2;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    Gain (const Gain&);
    const Gain& operator= (const Gain&);
};


#endif   // __JUCER_HEADER_GAIN_GAIN_2910006__
