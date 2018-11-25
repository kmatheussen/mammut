/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 5:00:15 pm

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
#include "AmplitudeToPhase.h"
#define Slider DasSlider
//[/Headers]

#include "AmplitudeToPhase.h"



//==============================================================================
AmplitudeToPhase::AmplitudeToPhase ()
    : Component (T("AmplitudeToPhase")),
      groupComponent (0),
      amplitude_multiplierslider (0),
      label (0),
      textButton (0),
      resetbutton (0),
      label2 (0),
      textButton2 (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Amplitude->Phase")));
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
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0x4bbbbbff));

    addAndMakeVisible (resetbutton = new TextButton (T("resetbutton")));
    resetbutton->setButtonText (T("reset"));
    resetbutton->addListener (this);
    resetbutton->setColour (TextButton::buttonColourId, Colour (0x40bbbbff));

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("The phases of the partials are set to their respective amplitudes, after a specified gain multiplication. Rather useless.")));
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
    textButton2->addListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colour (0x40bbbbff));

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
    buttonClicked(resetbutton);
#undef Slider
    //[/Constructor]
}

AmplitudeToPhase::~AmplitudeToPhase()
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
void AmplitudeToPhase::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
    fillit();
    //[/UserPaint]
}

void AmplitudeToPhase::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    amplitude_multiplierslider->setBounds (184, 24, 344, 24);
    label->setBounds (16, 24, 168, 24);
    textButton->setBounds (16, 56, 240, 40);
    resetbutton->setBounds (360, 64, 150, 24);
    label2->setBounds (552, 16, 296, 88);
    textButton2->setBounds (256, 72, 104, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AmplitudeToPhase::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == amplitude_multiplierslider)
    {
        //[UserSliderCode_amplitude_multiplierslider] -- add your slider handling code here..
      setval(amplitudephase,amplitude_multiplier);
        //[/UserSliderCode_amplitude_multiplierslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AmplitudeToPhase::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(amplitude_phase_ok);
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == resetbutton)
    {
        //[UserButtonCode_resetbutton] -- add your button handler code here..
      resetval(amplitudephase,amplitude_multiplier);
        //[/UserButtonCode_resetbutton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
      redoit(amplitude_phase_ok);
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

<JUCER_COMPONENT documentType="Component" className="AmplitudeToPhase" componentName="AmplitudeToPhase"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" id="b880ddf3fdd6b193" memberName="groupComponent"
                  pos="0 0 840 112" outlinecol="b0000000" title="Amplitude-&gt;Phase"
                  textpos="33"/>
  <SLIDER name="new slider" id="807ca89b74850460" memberName="amplitude_multiplierslider"
          pos="184 24 344 24" bkgcol="956565" thumbcol="79fffcfc" textboxbkgd="ffffff"
          min="0" max="100" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" id="ce6c95c064dc0e4b" memberName="label" pos="16 24 168 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Amplitude multiplier (0-100)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="8d115d52803e1427" memberName="textButton"
              pos="16 56 240 40" bgColOff="4bbbbbff" buttonText="Do it!" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="resetbutton" id="162d7d09158f8957" memberName="resetbutton"
              pos="360 64 150 24" bgColOff="40bbbbff" buttonText="reset" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="88f6dfdb6cb4fdd5" memberName="label2" pos="552 16 296 88"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="The phases of the partials are set to their respective amplitudes, after a specified gain multiplication. Rather useless."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="10562b9b17841d7c" memberName="textButton2"
              pos="256 72 104 24" bgColOff="40bbbbff" buttonText="Redo it!"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
