/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 5:07:06 pm

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
#include "juce.h"

#include "Stretch.h"
#define Slider DasSlider
//[/Headers]

#include "Stretch.h"



//==============================================================================
Stretch::Stretch ()
    : Component (T("Stretch")),
      groupComponent (0),
      exponentslider (0),
      label (0),
      textButton (0),
      resetbutton (0),
      label2 (0),
      textButton2 (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Stretch")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (exponentslider = new Slider (T("exponentslider")));
    exponentslider->setRange (0.5, 1.5, 0);
    exponentslider->setSliderStyle (Slider::LinearHorizontal);
    exponentslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 30);
    exponentslider->setColour (Slider::backgroundColourId, Colour (0x865656));
    exponentslider->setColour (Slider::thumbColourId, Colour (0x75fffcfc));
    exponentslider->setColour (Slider::trackColourId, Colour (0x7f000000));
    exponentslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xe6c76b));
    exponentslider->setColour (Slider::textBoxOutlineColourId, Colours::black);
    exponentslider->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Exponent")));
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
    textButton->setColour (TextButton::buttonColourId, Colour (0x957f7f9f));

    addAndMakeVisible (resetbutton = new TextButton (T("resetbutton")));
    resetbutton->setButtonText (T("reset"));
    resetbutton->addButtonListener (this);
    resetbutton->setColour (TextButton::buttonColourId, Colour (0x3b7d7dab));

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("\nAll frequencies will be raised to the power of the exponent you specify, and the frequency axis is then re-normalized. This is a non-linear stretching of the frequency axis. Values close to 1 (0.9-1.1) are recommended. This transform will produce dispersion effects, with frequency sweeps. \n\n")));
    label2->setFont (Font (11.2000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0x0));
    label2->setColour (Label::textColourId, Colours::black);
    label2->setColour (Label::outlineColourId, Colour (0xcd1717));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (textButton2 = new TextButton (T("new button")));
    textButton2->setButtonText (T("Redo it!"));
    textButton2->addButtonListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colour (0x5498908a));

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
    buttonClicked(resetbutton);
    #undef Slider
    //[/Constructor]
}

Stretch::~Stretch()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (exponentslider);
    deleteAndZero (label);
    deleteAndZero (textButton);
    deleteAndZero (resetbutton);
    deleteAndZero (label2);
    deleteAndZero (textButton2);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Stretch::paint (Graphics& g)
{
    GradientBrush gradient_1 (Colour (0x7bf00ff),
                              50.0f, 50.0f,
                              Colour (0x8000),
                              48.0f, 136.0f,
                              false);
    g.setBrush (&gradient_1);
    g.fillRect (-32, -72, 984, 216);

    //[UserPaint] Add your own custom paint stuff here..
  //fillit();
    //[/UserPaint]
}

void Stretch::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    exponentslider->setBounds (88, 11, 736, 40);
    label->setBounds (17, 21, 64, 24);
    textButton->setBounds (24, 64, 136, 32);
    resetbutton->setBounds (240, 56, 104, 40);
    label2->setBounds (352, 56, 480, 48);
    textButton2->setBounds (160, 64, 72, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Stretch::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == exponentslider)
    {
        //[UserSliderCode_exponentslider] -- add your slider handling code here..
      setval(stretch,exponent);
      //stretch_exponent=exponentslider->getValue();
        //[/UserSliderCode_exponentslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void Stretch::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(stretch_ok);
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == resetbutton)
    {
        //[UserButtonCode_resetbutton] -- add your button handler code here..
      resetval(stretch,exponent);
        //[/UserButtonCode_resetbutton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
      redoit(stretch_ok);
        //[/UserButtonCode_textButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//double Stretch::getValueFromText(const String & 	text 	 ){
//  printf("gakk: -%s-\n",text.toUTF8());
//}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Stretch" componentName="Stretch"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="dedfd2">
    <RECT pos="-32 -72 984 216" fill="linear: 50 50, 48 136, 0=7bf00ff, 1=8000"
          hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="861cd5ab6e386a21" memberName="groupComponent"
                  pos="0 0 840 112" outlinecol="b0000000" title="Stretch" textpos="33"/>
  <SLIDER name="exponentslider" id="70a9a4d0ceb85170" memberName="exponentslider"
          pos="88 11 736 40" bkgcol="865656" thumbcol="75fffcfc" trackcol="7f000000"
          textboxbkgd="e6c76b" textboxoutline="ff000000" min="0.5" max="1.5"
          int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="30"/>
  <LABEL name="new label" id="650f625606ef6e82" memberName="label" pos="17 21 64 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Exponent" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="a3b718126599323b" memberName="textButton"
              pos="24 64 136 32" bgColOff="957f7f9f" buttonText="Do it!" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="resetbutton" id="7aaa3e2d855e515a" memberName="resetbutton"
              pos="240 56 104 40" bgColOff="3b7d7dab" buttonText="reset" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="4452769f089c5015" memberName="label2" pos="352 56 480 48"
         bkgCol="0" textCol="ff000000" outlineCol="cd1717" edTextCol="ff000000"
         edBkgCol="0" labelText="&#10;All frequencies will be raised to the power of the exponent you specify, and the frequency axis is then re-normalized. This is a non-linear stretching of the frequency axis. Values close to 1 (0.9-1.1) are recommended. This transform will produce dispersion effects, with frequency sweeps. &#10;&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="11.2" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="10562b9b17841d7c" memberName="textButton2"
              pos="160 64 72 32" bgColOff="5498908a" buttonText="Redo it!"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
