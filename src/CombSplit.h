/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 5:00:57 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.8

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_COMBSPLIT_COMBSPLIT_22B5F0B9__
#define __JUCER_HEADER_COMBSPLIT_COMBSPLIT_22B5F0B9__

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
class CombSplit  : public Component,
                   public ButtonListener,
                   public SliderListener
{
public:
    //==============================================================================
    CombSplit ();
    ~CombSplit();

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
    Label* label;
    Slider* block_sizeslider;
    Slider* number_of_filesslider;
    Label* label2;
    TextButton* resetbutton;
    TextButton* textButton2;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    CombSplit (const CombSplit&);
    const CombSplit& operator= (const CombSplit&);
};


#endif   // __JUCER_HEADER_COMBSPLIT_COMBSPLIT_22B5F0B9__
