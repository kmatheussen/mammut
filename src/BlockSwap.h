/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 4:58:55 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.8

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_BLOCKSWAP_BLOCKSWAP_36316AF9__
#define __JUCER_HEADER_BLOCKSWAP_BLOCKSWAP_36316AF9__

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
class BlockSwap  : public Component,
                   public Slider::Listener,
                   public Button::Listener
{
public:
    //==============================================================================
    BlockSwap ();
    ~BlockSwap();

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
    Slider* number_of_swapsslider;
    Label* label;
    TextButton* textButton;
    ToggleButton* toggleButton;
    Slider* block_sizeslider;
    Label* label2;
    TextButton* resetbutton;
    Label* label3;
    TextButton* textButton2;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    BlockSwap (const BlockSwap&);
    const BlockSwap& operator= (const BlockSwap&);
};


#endif   // __JUCER_HEADER_BLOCKSWAP_BLOCKSWAP_36316AF9__
