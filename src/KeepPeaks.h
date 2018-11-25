/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  12 Feb 2007 1:59:29 am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_KEEPPEAKS_KEEPPEAKS_CA9FE13C__
#define __JUCER_HEADER_KEEPPEAKS_KEEPPEAKS_CA9FE13C__

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
class KeepPeaks  : public Component,
                   public Button::Listener
{
public:
    //==============================================================================
    KeepPeaks ();
    ~KeepPeaks();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
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
    GroupComponent* groupComponent;
    TextButton* textButton;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    KeepPeaks (const KeepPeaks&);
    const KeepPeaks& operator= (const KeepPeaks&);
};


#endif   // __JUCER_HEADER_KEEPPEAKS_KEEPPEAKS_CA9FE13C__
