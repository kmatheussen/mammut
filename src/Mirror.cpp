/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 5:07:54 pm

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
#include "Mirror.h"
#define Slider DasSlider
//[/Headers]

#include "Mirror.h"



//==============================================================================
Mirror::Mirror ()
    : Component (T("Mirror")),
      groupComponent (0),
      textButton (0),
      description (0),
      mirror_frequencyslider (0),
      label (0),
      resetbutton (0),
      textButton2 (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Mirror")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (textButton = new TextButton (T("new button")));
    textButton->setButtonText (T("Do it!"));
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0x25bbbbff));

    addAndMakeVisible (description = new Label (T("new label"),
                                                T("Reflects the whole spectrum around the frequency you specify. ")));
    description->setFont (Font (15.0000f, Font::plain));
    description->setJustificationType (Justification::centredLeft);
    description->setEditable (false, false, false);
    description->setColour (Label::backgroundColourId, Colour (0x0));
    description->setColour (Label::textColourId, Colours::black);
    description->setColour (Label::outlineColourId, Colour (0x0));
    description->setColour (TextEditor::textColourId, Colours::black);
    description->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mirror_frequencyslider = new Slider (T("new slider")));
    mirror_frequencyslider->setRange (0, 22050, 0);
    mirror_frequencyslider->setSliderStyle (Slider::LinearHorizontal);
    mirror_frequencyslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mirror_frequencyslider->setColour (Slider::backgroundColourId, Colour (0x956565));
    mirror_frequencyslider->setColour (Slider::thumbColourId, Colour (0x7bfffcfc));
    mirror_frequencyslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    mirror_frequencyslider->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Mirror frequency (Hz)")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0x0));
    label->setColour (Label::textColourId, Colours::black);
    label->setColour (Label::outlineColourId, Colour (0x0));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (resetbutton = new TextButton (T("new button")));
    resetbutton->setButtonText (T("Reset"));
    resetbutton->addListener (this);
    resetbutton->setColour (TextButton::buttonColourId, Colour (0x25bbbbff));

    addAndMakeVisible (textButton2 = new TextButton (T("new button")));
    textButton2->setButtonText (T("Redo it!"));
    textButton2->addListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colour (0x25bbbbff));

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
    buttonClicked(resetbutton);
#undef Slider
    //[/Constructor]
}

Mirror::~Mirror()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (textButton);
    deleteAndZero (description);
    deleteAndZero (mirror_frequencyslider);
    deleteAndZero (label);
    deleteAndZero (resetbutton);
    deleteAndZero (textButton2);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Mirror::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
  fillit();
    //[/UserPaint]
}

void Mirror::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    textButton->setBounds (24, 48, 104, 48);
    description->setBounds (400, 40, 455, 72);
    mirror_frequencyslider->setBounds (136, 16, 696, 24);
    label->setBounds (16, 16, 112, 24);
    resetbutton->setBounds (232, 48, 128, 48);
    textButton2->setBounds (136, 48, 80, 48);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Mirror::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(mirror_ok);
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == resetbutton)
    {
        //[UserButtonCode_resetbutton] -- add your button handler code here..
      resetval(mirror,mirror_frequency);
        //[/UserButtonCode_resetbutton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
      redoit(mirror_ok);
        //[/UserButtonCode_textButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void Mirror::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == mirror_frequencyslider)
    {
        //[UserSliderCode_mirror_frequencyslider] -- add your slider handling code here..
      setval(mirror,mirror_frequency);
        //[/UserSliderCode_mirror_frequencyslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//void Mirror::paint2 (Graphics& g){
//  return;
//}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Mirror" componentName="Mirror"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" id="6f88f15a42650a8b" memberName="groupComponent"
                  pos="0 0 840 112" outlinecol="b0000000" title="Mirror" textpos="33"/>
  <TEXTBUTTON name="new button" id="e8889fe7c5dfde93" memberName="textButton"
              pos="24 48 104 48" bgColOff="25bbbbff" buttonText="Do it!" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="b14eb78e812dabb0" memberName="description"
         pos="400 40 455 72" bkgCol="0" textCol="ff000000" outlineCol="0"
         edTextCol="ff000000" edBkgCol="0" labelText="Reflects the whole spectrum around the frequency you specify. "
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="17b2687f9fce45ec" memberName="mirror_frequencyslider"
          pos="136 16 696 24" bkgcol="956565" thumbcol="7bfffcfc" textboxbkgd="ffffff"
          min="0" max="22050" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" id="14b8f40ddc43014a" memberName="label" pos="16 16 112 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Mirror frequency (Hz)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="fe1f9bbd877bdeae" memberName="resetbutton"
              pos="232 48 128 48" bgColOff="25bbbbff" buttonText="Reset" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="new button" id="10562b9b17841d7c" memberName="textButton2"
              pos="136 48 80 48" bgColOff="25bbbbff" buttonText="Redo it!"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
