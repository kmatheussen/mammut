/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  20 Jan 2007 11:44:45 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_ZOOM_ZOOM_B2DE80F8__
#define __JUCER_HEADER_ZOOM_ZOOM_B2DE80F8__

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
class Zoom  : public Component,
              public ButtonListener
{
public:
    //==============================================================================
    Zoom ();
    ~Zoom();

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
    GroupComponent* groupComponent2;
    ToggleButton* zoomtoggle;
    TextButton* zoomleft;
    TextButton* zoomright;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    Zoom (const Zoom&);
    const Zoom& operator= (const Zoom&);
};


#endif   // __JUCER_HEADER_ZOOM_ZOOM_B2DE80F8__
