/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 4:56:58 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.8

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_DERIVATIVEAMP_DERIVATIVEAMP_DD5E9C08__
#define __JUCER_HEADER_DERIVATIVEAMP_DERIVATIVEAMP_DD5E9C08__

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
class DerivativeAmp  : public Component,
                       public SliderListener,
                       public ButtonListener
{
public:
    //==============================================================================
    DerivativeAmp ();
    ~DerivativeAmp();

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
    Slider* amp_derivate_multiplierslider;
    Label* label;
    TextButton* textButton;
    TextButton* resetbutton;
    Label* label2;
    TextButton* textButton2;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    DerivativeAmp (const DerivativeAmp&);
    const DerivativeAmp& operator= (const DerivativeAmp&);
};


#endif   // __JUCER_HEADER_DERIVATIVEAMP_DERIVATIVEAMP_DD5E9C08__
