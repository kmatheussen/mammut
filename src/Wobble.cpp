/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 4:56:17 pm

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
#include "Wobble.h"
#define Slider DasSlider
//[/Headers]

#include "Wobble.h"



//==============================================================================
Wobble::Wobble ()
    : Component (T("Wobble")),
      groupComponent2 (0),
      textButton (0),
      label (0),
      frequencyslider (0),
      amplitudeslider (0),
      label2 (0),
      resetbutton (0),
      label3 (0),
      textButton2 (0)
{
    addAndMakeVisible (groupComponent2 = new GroupComponent (T("new group"),
                                                             T("Wobble")));
    groupComponent2->setTextLabelPosition (Justification::centredLeft);
    groupComponent2->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (textButton = new TextButton (T("new button")));
    textButton->setButtonText (T("Do it!"));
    textButton->addButtonListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0x2ebbbbff));

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Frequency (0-1000)")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0x0));
    label->setColour (Label::textColourId, Colours::black);
    label->setColour (Label::outlineColourId, Colour (0x0));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (frequencyslider = new Slider (T("new slider")));
    frequencyslider->setRange (0, 1000, 0);
    frequencyslider->setSliderStyle (Slider::LinearHorizontal);
    frequencyslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    frequencyslider->setColour (Slider::thumbColourId, Colour (0x82ffffff));
    frequencyslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    frequencyslider->addListener (this);

    addAndMakeVisible (amplitudeslider = new Slider (T("new slider")));
    amplitudeslider->setRange (0, 1, 0);
    amplitudeslider->setSliderStyle (Slider::LinearHorizontal);
    amplitudeslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    amplitudeslider->setColour (Slider::thumbColourId, Colour (0x86ffffff));
    amplitudeslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    amplitudeslider->addListener (this);

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Amplitude (0-1)")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0x0));
    label2->setColour (Label::textColourId, Colours::black);
    label2->setColour (Label::outlineColourId, Colour (0x0));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (resetbutton = new TextButton (T("resetbutton")));
    resetbutton->setButtonText (T("Reset"));
    resetbutton->addButtonListener (this);
    resetbutton->setColour (TextButton::buttonColourId, Colour (0x46bbbbff));

    addAndMakeVisible (label3 = new Label (T("new label"),
                                           T("\nAll frequencies will be raised to the power of the exponent you specify, and the frequency axis is then re-normalized. This is a non-linear stretching of the frequency axis. Values close to 1 (0.9-1.1) are recommended. This transform will produce dispersion effects, with frequency sweeps. \n\n\n")));
    label3->setFont (Font (11.2000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (Label::backgroundColourId, Colour (0x0));
    label3->setColour (Label::textColourId, Colours::black);
    label3->setColour (Label::outlineColourId, Colour (0x0));
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

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

Wobble::~Wobble()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent2);
    deleteAndZero (textButton);
    deleteAndZero (label);
    deleteAndZero (frequencyslider);
    deleteAndZero (amplitudeslider);
    deleteAndZero (label2);
    deleteAndZero (resetbutton);
    deleteAndZero (label3);
    deleteAndZero (textButton2);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Wobble::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
    fillit();
    //[/UserPaint]
}

void Wobble::resized()
{
    groupComponent2->setBounds (0, 0, 840, 112);
    textButton->setBounds (432, 16, 120, 24);
    label->setBounds (16, 16, 152, 40);
    frequencyslider->setBounds (160, 24, 272, 24);
    amplitudeslider->setBounds (160, 64, 272, 24);
    label2->setBounds (16, 64, 150, 24);
    resetbutton->setBounds (432, 72, 120, 24);
    label3->setBounds (560, 0, 272, 120);
    textButton2->setBounds (432, 43, 121, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Wobble::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(wobble_ok);
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == resetbutton)
    {
        //[UserButtonCode_resetbutton] -- add your button handler code here..
      resetval(wobble,frequency);
      resetval(wobble,amplitude);
        //[/UserButtonCode_resetbutton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
      redoit(wobble_ok);
        //[/UserButtonCode_textButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void Wobble::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == frequencyslider)
    {
        //[UserSliderCode_frequencyslider] -- add your slider handling code here..
      setval(wobble,frequency);

        //[/UserSliderCode_frequencyslider]
    }
    else if (sliderThatWasMoved == amplitudeslider)
    {
        //[UserSliderCode_amplitudeslider] -- add your slider handling code here..
      setval(wobble,amplitude);
        //[/UserSliderCode_amplitudeslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Wobble" componentName="Wobble"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" id="dba13000fbf2e0f5" memberName="groupComponent2"
                  pos="0 0 840 112" outlinecol="b0000000" title="Wobble" textpos="33"/>
  <TEXTBUTTON name="new button" id="b39ea3e28a629c65" memberName="textButton"
              pos="432 16 120 24" bgColOff="2ebbbbff" buttonText="Do it!" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="ceb386e6c991715c" memberName="label" pos="16 16 152 40"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Frequency (0-1000)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="66883832af628709" memberName="frequencyslider"
          pos="160 24 272 24" thumbcol="82ffffff" textboxbkgd="ffffff"
          min="0" max="1000" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <SLIDER name="new slider" id="86615975c7634108" memberName="amplitudeslider"
          pos="160 64 272 24" thumbcol="86ffffff" textboxbkgd="ffffff"
          min="0" max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" id="5657d1ea6f6d6fe2" memberName="label2" pos="16 64 150 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Amplitude (0-1)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="resetbutton" id="3edbeb65e70e7a8c" memberName="resetbutton"
              pos="432 72 120 24" bgColOff="46bbbbff" buttonText="Reset" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="3deaf40851d20cb1" memberName="label3" pos="560 0 272 120"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="&#10;All frequencies will be raised to the power of the exponent you specify, and the frequency axis is then re-normalized. This is a non-linear stretching of the frequency axis. Values close to 1 (0.9-1.1) are recommended. This transform will produce dispersion effects, with frequency sweeps. &#10;&#10;&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="11.2" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="10562b9b17841d7c" memberName="textButton2"
              pos="432 43 121 24" bgColOff="40bbbbff" buttonText="Redo it!"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
