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

//[Headers] You can add your own extra header files here...
#include "transformheader.h"
#include "Gain.h"
#define Slider DasSlider
//[/Headers]

#include "Gain.h"



//==============================================================================
Gain::Gain ()
    : Component (T("Gain")),
      groupComponent (0),
      amplitude_multiplierslider (0),
      label (0),
      textButton (0),
      resetbutton (0),
      label2 (0),
      textButton2 (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Gain")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (amplitude_multiplierslider = new Slider (T("new slider")));
    amplitude_multiplierslider->setRange (0, 100, 0);
    amplitude_multiplierslider->setSliderStyle (Slider::LinearHorizontal);
    amplitude_multiplierslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    amplitude_multiplierslider->setColour (Slider::backgroundColourId, Colour (0x956565));
    amplitude_multiplierslider->setColour (Slider::thumbColourId, Colour (0x79fffcfc));
    amplitude_multiplierslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    amplitude_multiplierslider->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Amplitude multiplier (0-100)")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0x0));
    label->setColour (Label::textColourId, Colours::black);
    label->setColour (Label::outlineColourId, Colour (0x0));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (textButton = new TextButton (T("new button")));
    textButton->setButtonText (T("Do it!"));
    textButton->addButtonListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0x39bbbbff));

    addAndMakeVisible (resetbutton = new TextButton (T("resetbutton")));
    resetbutton->setButtonText (T("reset"));
    resetbutton->addButtonListener (this);
    resetbutton->setColour (TextButton::buttonColourId, Colour (0x40bbbbff));

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("A highly useful function, because many of the transforms will change the gain and the spectrum may have to be re-scaled manually. (An alternative is to use the \"normalize\" button)")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0x0));
    label2->setColour (Label::textColourId, Colours::black);
    label2->setColour (Label::outlineColourId, Colour (0x0));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (textButton2 = new TextButton (T("new button")));
    textButton2->setButtonText (T("Redo it!"));
    textButton2->addButtonListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colour (0x40bbbbff));

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
    buttonClicked(resetbutton);
#undef Slider
    //[/Constructor]
}

Gain::~Gain()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (amplitude_multiplierslider);
    deleteAndZero (label);
    deleteAndZero (textButton);
    deleteAndZero (resetbutton);
    deleteAndZero (label2);
    deleteAndZero (textButton2);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Gain::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
    fillit();
    //[/UserPaint]
}

void Gain::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    amplitude_multiplierslider->setBounds (192, 24, 400, 24);
    label->setBounds (16, 24, 168, 24);
    textButton->setBounds (8, 56, 150, 24);
    resetbutton->setBounds (272, 56, 296, 48);
    label2->setBounds (600, 24, 224, 72);
    textButton2->setBounds (185, 64, 63, 40);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Gain::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == amplitude_multiplierslider)
    {
        //[UserSliderCode_amplitude_multiplierslider] -- add your slider handling code here..
      setval(gain,amplitude_multiplier);
        //[/UserSliderCode_amplitude_multiplierslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void Gain::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(gain_ok);
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == resetbutton)
    {
        //[UserButtonCode_resetbutton] -- add your button handler code here..
      resetval(gain,amplitude_multiplier);
        //[/UserButtonCode_resetbutton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
      redoit(gain_ok);
        //[/UserButtonCode_textButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Gain" componentName="Gain"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" id="8a4305fe9202d789" memberName="groupComponent"
                  pos="0 0 840 112" outlinecol="b0000000" title="Gain" textpos="33"/>
  <SLIDER name="new slider" id="55a79003204e2b63" memberName="amplitude_multiplierslider"
          pos="192 24 400 24" bkgcol="956565" thumbcol="79fffcfc" textboxbkgd="ffffff"
          min="0" max="100" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" id="66594d2209fd12cf" memberName="label" pos="16 24 168 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Amplitude multiplier (0-100)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="37fd5a7f469171ba" memberName="textButton"
              pos="8 56 150 24" bgColOff="39bbbbff" buttonText="Do it!" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="resetbutton" id="af43ac9e697ae875" memberName="resetbutton"
              pos="272 56 296 48" bgColOff="40bbbbff" buttonText="reset" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="5d9800aa5230dbec" memberName="label2" pos="600 24 224 72"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="A highly useful function, because many of the transforms will change the gain and the spectrum may have to be re-scaled manually. (An alternative is to use the &quot;normalize&quot; button)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="10562b9b17841d7c" memberName="textButton2"
              pos="185 64 63 40" bgColOff="40bbbbff" buttonText="Redo it!"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
