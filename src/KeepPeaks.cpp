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

//[Headers] You can add your own extra header files here...
#include "transformheader.h"
//[/Headers]

#include "KeepPeaks.h"



//==============================================================================
KeepPeaks::KeepPeaks ()
    : Component (T("KeepPeaks")),
      groupComponent (0),
      textButton (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Keep Peaks")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (textButton = new TextButton (T("new button")));
    textButton->setButtonText (T("Do it!"));
    textButton->addButtonListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0x1fbbffd4));

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

KeepPeaks::~KeepPeaks()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (textButton);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KeepPeaks::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
    fillit();
    //[/UserPaint]
}

void KeepPeaks::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    textButton->setBounds (24, 24, 744, 80);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void KeepPeaks::buttonClicked (Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(keep_peaks_ok);
        //[/UserButtonCode_textButton]
    }
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KeepPeaks" componentName="KeepPeaks"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" memberName="groupComponent" pos="0 0 840 112"
                  outlinecol="b0000000" title="Keep Peaks" textpos="33"/>
  <TEXTBUTTON name="new button" memberName="textButton" pos="24 24 744 80"
              bgColOff="1fbbffd4" buttonText="Do it!" connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
