/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 4:58:23 pm

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
#include "SpectrumShift.h"
#define Slider DasSlider
//[/Headers]

#include "SpectrumShift.h"



//==============================================================================
SpectrumShift::SpectrumShift ()
    : Component (T("SpectrumShift")),
      groupComponent (0),
      shift_valueslider (0),
      label (0),
      textButton (0),
      resetbutton (0),
      label2 (0),
      textButton2 (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Spectrum Shift")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (shift_valueslider = new Slider (T("new slider")));
    shift_valueslider->setRange (-22050, 22050, 0);
    shift_valueslider->setSliderStyle (Slider::LinearHorizontal);
    shift_valueslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    shift_valueslider->setColour (Slider::backgroundColourId, Colour (0x956565));
    shift_valueslider->setColour (Slider::thumbColourId, Colour (0x7bfffcfc));
    shift_valueslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    shift_valueslider->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Shift value (Hz)")));
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
    textButton->setColour (TextButton::buttonColourId, Colour (0x44bbbbff));

    addAndMakeVisible (resetbutton = new TextButton (T("resetbutton")));
    resetbutton->setButtonText (T("reset"));
    resetbutton->addButtonListener (this);
    resetbutton->setColour (TextButton::buttonColourId, Colour (0x25bbbbff));

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Optimal spectrum shift, with no window artefacts. The frequency you specify (positive or negative) will be added to all frequency values, shifting the spectrum up or down.")));
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

SpectrumShift::~SpectrumShift()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (shift_valueslider);
    deleteAndZero (label);
    deleteAndZero (textButton);
    deleteAndZero (resetbutton);
    deleteAndZero (label2);
    deleteAndZero (textButton2);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SpectrumShift::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
    fillit();
    //[/UserPaint]
}

void SpectrumShift::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    shift_valueslider->setBounds (136, 24, 696, 24);
    label->setBounds (16, 24, 112, 24);
    textButton->setBounds (16, 56, 104, 48);
    resetbutton->setBounds (216, 72, 150, 24);
    label2->setBounds (392, 48, 488, 56);
    textButton2->setBounds (128, 56, 88, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SpectrumShift::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == shift_valueslider)
    {
        //[UserSliderCode_shift_valueslider] -- add your slider handling code here..
      setval(spectrumshift,shift_value);
        //[/UserSliderCode_shift_valueslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SpectrumShift::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(spectrum_shift_ok);
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == resetbutton)
    {
        //[UserButtonCode_resetbutton] -- add your button handler code here..
      resetval(spectrumshift,shift_value);
        //[/UserButtonCode_resetbutton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
      redoit(spectrum_shift_ok);
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

<JUCER_COMPONENT documentType="Component" className="SpectrumShift" componentName="SpectrumShift"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" id="b8d6bf38a4f0a6ef" memberName="groupComponent"
                  pos="0 0 840 112" outlinecol="b0000000" title="Spectrum Shift"
                  textpos="33"/>
  <SLIDER name="new slider" id="9c3a1e90d7e77316" memberName="shift_valueslider"
          pos="136 24 696 24" bkgcol="956565" thumbcol="7bfffcfc" textboxbkgd="ffffff"
          min="-22050" max="22050" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" id="7e0298a16797539" memberName="label" pos="16 24 112 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Shift value (Hz)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="23a043d721f58297" memberName="textButton"
              pos="16 56 104 48" bgColOff="44bbbbff" buttonText="Do it!" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="resetbutton" id="cbd1757ea94be56b" memberName="resetbutton"
              pos="216 72 150 24" bgColOff="25bbbbff" buttonText="reset" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="ea140181e6355bff" memberName="label2" pos="392 48 488 56"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Optimal spectrum shift, with no window artefacts. The frequency you specify (positive or negative) will be added to all frequency values, shifting the spectrum up or down."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="10562b9b17841d7c" memberName="textButton2"
              pos="128 56 88 32" bgColOff="40bbbbff" buttonText="Redo it!"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
