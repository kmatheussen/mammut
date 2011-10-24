/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 4:58:55 pm

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
#include "BlockSwap.h"
#define Slider DasSlider
//[/Headers]

#include "BlockSwap.h"



//==============================================================================
BlockSwap::BlockSwap ()
    : Component (T("BlockSwap")),
      groupComponent (0),
      number_of_swapsslider (0),
      label (0),
      textButton (0),
      toggleButton (0),
      block_sizeslider (0),
      label2 (0),
      resetbutton (0),
      label3 (0),
      textButton2 (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Block Swap")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (number_of_swapsslider = new Slider (T("new slider")));
    number_of_swapsslider->setRange (0, 10000, 1);
    number_of_swapsslider->setSliderStyle (Slider::LinearHorizontal);
    number_of_swapsslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    number_of_swapsslider->setColour (Slider::backgroundColourId, Colour (0x956565));
    number_of_swapsslider->setColour (Slider::thumbColourId, Colour (0x82fffcfc));
    number_of_swapsslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    number_of_swapsslider->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Number of swaps")));
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

    addAndMakeVisible (toggleButton = new ToggleButton (T("new toggle button")));
    toggleButton->setButtonText (T("Old version with error"));
    toggleButton->addButtonListener (this);

    addAndMakeVisible (block_sizeslider = new Slider (T("new slider")));
    block_sizeslider->setRange (0, 100, 0);
    block_sizeslider->setSliderStyle (Slider::LinearHorizontal);
    block_sizeslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    block_sizeslider->setColour (Slider::backgroundColourId, Colour (0x956565));
    block_sizeslider->setColour (Slider::thumbColourId, Colour (0x28ffffff));
    block_sizeslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    block_sizeslider->addListener (this);

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Block size (0-100%)")));
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
    resetbutton->addButtonListener (this);
    resetbutton->setColour (TextButton::buttonColourId, Colour (0x4fbbbbff));

    addAndMakeVisible (label3 = new Label (T("new label"),
                                           T("Selects randomly positioned regions of the spectrum, and interchanges their halves. The Block size parameter sets the size of the blocks, given in percents of the whole frequency axis. This procedure is repeated a number of times, as specified, thus permutating the partials.")));
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

BlockSwap::~BlockSwap()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (number_of_swapsslider);
    deleteAndZero (label);
    deleteAndZero (textButton);
    deleteAndZero (toggleButton);
    deleteAndZero (block_sizeslider);
    deleteAndZero (label2);
    deleteAndZero (resetbutton);
    deleteAndZero (label3);
    deleteAndZero (textButton2);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void BlockSwap::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
    fillit();
    //[/UserPaint]
}

void BlockSwap::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    number_of_swapsslider->setBounds (160, 16, 344, 24);
    label->setBounds (16, 16, 152, 24);
    textButton->setBounds (184, 72, 176, 24);
    toggleButton->setBounds (16, 72, 208, 24);
    block_sizeslider->setBounds (160, 40, 344, 24);
    label2->setBounds (16, 40, 152, 24);
    resetbutton->setBounds (432, 72, 64, 24);
    label3->setBounds (520, 16, 296, 88);
    textButton2->setBounds (368, 72, 57, 22);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void BlockSwap::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == number_of_swapsslider)
    {
        //[UserSliderCode_number_of_swapsslider] -- add your slider handling code here..
      setval(blockswap,number_of_swaps);
        //[/UserSliderCode_number_of_swapsslider]
    }
    else if (sliderThatWasMoved == block_sizeslider)
    {
        //[UserSliderCode_block_sizeslider] -- add your slider handling code here..
      setval(blockswap,block_size);
        //[/UserSliderCode_block_sizeslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void BlockSwap::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(block_swap_ok);
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == toggleButton)
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
      blockswap_old_version_with_error=toggleButton->getToggleState();
        //[/UserButtonCode_toggleButton]
    }
    else if (buttonThatWasClicked == resetbutton)
    {
        //[UserButtonCode_resetbutton] -- add your button handler code here..
      resetval(blockswap,number_of_swaps);
      resetval(blockswap,block_size);
      toggleButton->setToggleState(blockswap_old_version_with_error,true);
        //[/UserButtonCode_resetbutton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
      redoit(block_swap_ok);
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

<JUCER_COMPONENT documentType="Component" className="BlockSwap" componentName="BlockSwap"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" id="eb1aec589fcc903" memberName="groupComponent"
                  pos="0 0 840 112" outlinecol="b0000000" title="Block Swap" textpos="33"/>
  <SLIDER name="new slider" id="e0fb83e1b09279aa" memberName="number_of_swapsslider"
          pos="160 16 344 24" bkgcol="956565" thumbcol="82fffcfc" textboxbkgd="ffffff"
          min="0" max="10000" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" id="c855b39e5875a879" memberName="label" pos="16 16 152 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Number of swaps" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="5f102c2d9581a667" memberName="textButton"
              pos="184 72 176 24" bgColOff="39bbbbff" buttonText="Do it!" connectedEdges="0"
              needsCallback="1"/>
  <TOGGLEBUTTON name="new toggle button" id="e547cfcd0d96c77c" memberName="toggleButton"
                pos="16 72 208 24" buttonText="Old version with error" connectedEdges="0"
                needsCallback="1" state="0"/>
  <SLIDER name="new slider" id="ce157ef27c1fc2c7" memberName="block_sizeslider"
          pos="160 40 344 24" bkgcol="956565" thumbcol="28ffffff" textboxbkgd="ffffff"
          min="0" max="100" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" id="9ab080a3e81b0c5" memberName="label2" pos="16 40 152 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Block size (0-100%)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="resetbutton" id="f3db135c91577023" memberName="resetbutton"
              pos="432 72 64 24" bgColOff="4fbbbbff" buttonText="reset" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="cf3b98cb38797efd" memberName="label3" pos="520 16 296 88"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Selects randomly positioned regions of the spectrum, and interchanges their halves. The Block size parameter sets the size of the blocks, given in percents of the whole frequency axis. This procedure is repeated a number of times, as specified, thus permutating the partials."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="11.2" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="10562b9b17841d7c" memberName="textButton2"
              pos="368 72 57 22" bgColOff="40bbbbff" buttonText="Redo it!"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
