/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 5:23:37 pm

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
#include "MultiplyPhase.h"
#define Slider DasSlider
//[/Headers]

#include "MultiplyPhase.h"



//==============================================================================
MultiplyPhase::MultiplyPhase ()
    : Component (("MultiplyPhase")),
      groupComponent (0),
      phase_multiplierslider (0),
      label (0),
      textButton (0),
      resetbutton (0),
      label2 (0),
      textButton2 (0),
      randomButton (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (("new group"),
                                                            ("Multiply Phase")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (phase_multiplierslider = new Slider (("new slider")));
    phase_multiplierslider->setRange (-5, 5, 0);
    phase_multiplierslider->setSliderStyle (Slider::LinearHorizontal);
    phase_multiplierslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    phase_multiplierslider->setColour (Slider::backgroundColourId, Colour (0x956565));
    phase_multiplierslider->setColour (Slider::thumbColourId, Colour (0x75ffffff));
    phase_multiplierslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    phase_multiplierslider->setColour (Slider::textBoxHighlightColourId, Colour (0x251111ee));
    phase_multiplierslider->addListener (this);

    addAndMakeVisible (label = new Label (("new label"),
                                          ("Phase multiplier (-5 5)")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0x0));
    label->setColour (Label::textColourId, Colours::black);
    label->setColour (Label::outlineColourId, Colour (0x0));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (textButton = new TextButton (("new button")));
    textButton->setButtonText (("Do it!"));
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0x18bbbbff));

    addAndMakeVisible (resetbutton = new TextButton (("resetbutton")));
    resetbutton->setButtonText (("reset"));
    resetbutton->addListener (this);
    resetbutton->setColour (TextButton::buttonColourId, Colour (0x25bbbbff));

    addAndMakeVisible (label2 = new Label (("new label"),
                                           ("Multiply all phases with the value you specify. A value of -1 will reverse the sound.\n")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0x0));
    label2->setColour (Label::textColourId, Colours::black);
    label2->setColour (Label::outlineColourId, Colour (0x0));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (textButton2 = new TextButton (("new button")));
    textButton2->setButtonText (("Redo it!"));
    textButton2->addListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colour (0x18bbbbff));

    addAndMakeVisible (randomButton = new ToggleButton (("new toggle button")));
    randomButton->setButtonText (("Random Phases"));
    randomButton->addListener (this);

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
#undef Slider
    buttonClicked(resetbutton);
    //[/Constructor]
}

MultiplyPhase::~MultiplyPhase()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (phase_multiplierslider);
    deleteAndZero (label);
    deleteAndZero (textButton);
    deleteAndZero (resetbutton);
    deleteAndZero (label2);
    deleteAndZero (textButton2);
    deleteAndZero (randomButton);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MultiplyPhase::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
    fillit();
    //[/UserPaint]
}

void MultiplyPhase::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    phase_multiplierslider->setBounds (192, 24, 632, 24);
    label->setBounds (32, 24, 152, 24);
    textButton->setBounds (200, 64, 136, 40);
    resetbutton->setBounds (432, 56, 80, 40);
    label2->setBounds (528, 48, 296, 64);
    textButton2->setBounds (336, 64, 88, 40);
    randomButton->setBounds (16, 64, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MultiplyPhase::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == phase_multiplierslider)
    {
        //[UserSliderCode_phase_multiplierslider] -- add your slider handling code here..
      setval(multiplyphase,phase_multiplier);
        //[/UserSliderCode_phase_multiplierslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MultiplyPhase::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(multiply_phase_ok);
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == resetbutton)
    {
        //[UserButtonCode_resetbutton] -- add your button handler code here..
      resetval(multiplyphase,phase_multiplier);
      randomButton->setToggleState(multiplyphase_phase_random_default,true);
        //[/UserButtonCode_resetbutton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
      redoit(multiply_phase_ok);
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == randomButton)
    {
        //[UserButtonCode_randomButton] -- add your button handler code here..
      multiplyphase_phase_random=randomButton->getToggleState();
      if(multiplyphase_phase_random==true){
	phase_multiplierslider->setEnabled(false);
      }else{
	phase_multiplierslider->setEnabled(true);
      }
        //[/UserButtonCode_randomButton]
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

<JUCER_COMPONENT documentType="Component" className="MultiplyPhase" componentName="MultiplyPhase"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" id="63982491923e616a" memberName="groupComponent"
                  pos="0 0 840 112" outlinecol="b0000000" title="Multiply Phase"
                  textpos="33"/>
  <SLIDER name="new slider" id="c78bbad1826a74b8" memberName="phase_multiplierslider"
          pos="192 24 632 24" bkgcol="956565" thumbcol="75ffffff" textboxbkgd="ffffff"
          textboxhighlight="251111ee" min="-5" max="5" int="0" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20"/>
  <LABEL name="new label" id="740a4249cc0cf9e7" memberName="label" pos="32 24 152 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Phase multiplier (-5 5)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="734d88f6daad4219" memberName="textButton"
              pos="200 64 136 40" bgColOff="18bbbbff" buttonText="Do it!" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="resetbutton" id="d27b0d5ba4bf5735" memberName="resetbutton"
              pos="432 56 80 40" bgColOff="25bbbbff" buttonText="reset" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="40dca1edd0d44f07" memberName="label2" pos="528 48 296 64"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Multiply all phases with the value you specify. A value of -1 will reverse the sound.&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="10562b9b17841d7c" memberName="textButton2"
              pos="336 64 88 40" bgColOff="18bbbbff" buttonText="Redo it!"
              connectedEdges="0" needsCallback="1"/>
  <TOGGLEBUTTON name="new toggle button" id="1d048fa86d10aed7" memberName="randomButton"
                pos="16 64 150 24" buttonText="Random Phases" connectedEdges="0"
                needsCallback="1" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
