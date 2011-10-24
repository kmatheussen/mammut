/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 5:07:54 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.8

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MIRROR_MIRROR_72236A5B__
#define __JUCER_HEADER_MIRROR_MIRROR_72236A5B__

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
class Mirror  : public Component,
                public ButtonListener,
                public SliderListener
{
public:
    //==============================================================================
    Mirror ();
    ~Mirror();

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
    GroupComponent* groupComponent;
    TextButton* textButton;
    Label* description;
    Slider* mirror_frequencyslider;
    Label* label;
    TextButton* resetbutton;
    TextButton* textButton2;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    Mirror (const Mirror&);
    const Mirror& operator= (const Mirror&);
};


#endif   // __JUCER_HEADER_MIRROR_MIRROR_72236A5B__
