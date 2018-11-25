/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  19 Jan 2007 11:26:58 pm

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

#include "SplitRealImag.h"



//==============================================================================
SplitRealImag::SplitRealImag ()
    : Component (T("SplitRealImag")),
      groupComponent (0),
      textButton (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Slit Real/Imag")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (textButton = new TextButton (T("new button")));
    textButton->setButtonText (T("Do it!"));
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0x37bbbbff));

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SplitRealImag::~SplitRealImag()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (textButton);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SplitRealImag::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
    fillit();
    //[/UserPaint]
}

void SplitRealImag::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    textButton->setBounds (64, 40, 736, 56);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SplitRealImag::buttonClicked (Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(split_real_imag_ok);
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

<JUCER_COMPONENT documentType="Component" className="SplitRealImag" componentName="SplitRealImag"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" memberName="groupComponent" pos="0 0 840 112"
                  outlinecol="b0000000" title="Slit Real/Imag" textpos="33"/>
  <TEXTBUTTON name="new button" memberName="textButton" pos="64 40 736 56"
              bgColOff="37bbbbff" buttonText="Do it!" connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
