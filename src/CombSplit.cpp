/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 5:00:57 pm

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
#include "CombSplit.h"
#define Slider DasSlider
//[/Headers]

#include "CombSplit.h"



//==============================================================================
CombSplit::CombSplit ()
    : Component (T("CombSplit")),
      groupComponent (0),
      textButton (0),
      label (0),
      block_sizeslider (0),
      number_of_filesslider (0),
      label2 (0),
      resetbutton (0),
      textButton2 (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Comb Split")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (textButton = new TextButton (T("new button")));
    textButton->setButtonText (T("Do it!"));
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0x2ebbbbff));

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Block size (# of bins)")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0x0));
    label->setColour (Label::textColourId, Colours::black);
    label->setColour (Label::outlineColourId, Colour (0x0));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (block_sizeslider = new Slider (T("new slider")));
    block_sizeslider->setRange (0, 99, 1);
    block_sizeslider->setSliderStyle (Slider::LinearHorizontal);
    block_sizeslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    block_sizeslider->setColour (Slider::thumbColourId, Colour (0x79ffffff));
    block_sizeslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    block_sizeslider->addListener (this);

    addAndMakeVisible (number_of_filesslider = new Slider (T("new slider")));
    number_of_filesslider->setRange (1, 10, 1);
    number_of_filesslider->setSliderStyle (Slider::LinearHorizontal);
    number_of_filesslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    number_of_filesslider->setColour (Slider::thumbColourId, Colour (0x6effffff));
    number_of_filesslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    number_of_filesslider->addListener (this);

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Number of files")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0x0));
    label2->setColour (Label::textColourId, Colours::black);
    label2->setColour (Label::outlineColourId, Colour (0x0));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (resetbutton = new TextButton (T("resetbutton")));
    resetbutton->setButtonText (T("reset"));
    resetbutton->addListener (this);
    resetbutton->setColour (TextButton::buttonColourId, Colour (0x35bbbbff));

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

CombSplit::~CombSplit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (textButton);
    deleteAndZero (label);
    deleteAndZero (block_sizeslider);
    deleteAndZero (number_of_filesslider);
    deleteAndZero (label2);
    deleteAndZero (resetbutton);
    deleteAndZero (textButton2);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void CombSplit::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
    fillit();
    //[/UserPaint]
}

void CombSplit::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    textButton->setBounds (496, 16, 264, 88);
    label->setBounds (16, 16, 152, 40);
    block_sizeslider->setBounds (168, 24, 320, 24);
    number_of_filesslider->setBounds (168, 64, 320, 24);
    label2->setBounds (16, 64, 150, 24);
    resetbutton->setBounds (792, 80, 38, 24);
    textButton2->setBounds (768, 16, 64, 56);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void CombSplit::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(combsplit_ok);
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == resetbutton)
    {
        //[UserButtonCode_resetbutton] -- add your button handler code here..
      resetval(combsplit,block_size);
      resetval(combsplit,number_of_files);
        //[/UserButtonCode_resetbutton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
      redoit(combsplit_ok);
      //[/UserButtonCode_textButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void CombSplit::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == block_sizeslider)
    {
        //[UserSliderCode_block_sizeslider] -- add your slider handling code here..
      setval(combsplit,block_size);
        //[/UserSliderCode_block_sizeslider]
    }
    else if (sliderThatWasMoved == number_of_filesslider)
    {
        //[UserSliderCode_number_of_filesslider] -- add your slider handling code here..
      setval(combsplit,number_of_files);
        //[/UserSliderCode_number_of_filesslider]
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

<JUCER_COMPONENT documentType="Component" className="CombSplit" componentName="CombSplit"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" id="813cf4cc6ef518ec" memberName="groupComponent"
                  pos="0 0 840 112" outlinecol="b0000000" title="Comb Split" textpos="33"/>
  <TEXTBUTTON name="new button" id="a296199c4ad44c76" memberName="textButton"
              pos="496 16 264 88" bgColOff="2ebbbbff" buttonText="Do it!" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="7fc4f4217eaac6c0" memberName="label" pos="16 16 152 40"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Block size (# of bins)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="ded377741f47ff6" memberName="block_sizeslider"
          pos="168 24 320 24" thumbcol="79ffffff" textboxbkgd="ffffff"
          min="0" max="99" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <SLIDER name="new slider" id="14d220fc7ed9e2c3" memberName="number_of_filesslider"
          pos="168 64 320 24" thumbcol="6effffff" textboxbkgd="ffffff"
          min="1" max="10" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" id="9cccb5561040c8ab" memberName="label2" pos="16 64 150 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Number of files" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="resetbutton" id="d7f90534ef7b8fe4" memberName="resetbutton"
              pos="792 80 38 24" bgColOff="35bbbbff" buttonText="reset" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="new button" id="10562b9b17841d7c" memberName="textButton2"
              pos="768 16 64 56" bgColOff="40bbbbff" buttonText="Redo it!"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
