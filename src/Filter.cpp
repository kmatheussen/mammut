/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Mar 2007 4:57:42 pm

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
#include "Filter.h"
#define Slider DasSlider
//[/Headers]

#include "Filter.h"



//==============================================================================
Filter::Filter ()
    : Component (T("Filter")),
      groupComponent (0),
      textButton (0),
      label (0),
      lower_cutoffslider (0),
      upper_cutoffslider (0),
      label2 (0),
      sharpnessslider (0),
      label3 (0),
      resetbutton (0),
      label4 (0),
      textButton2 (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Filter")));
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (textButton = new TextButton (T("new button")));
    textButton->setButtonText (T("Do it!"));
    textButton->addButtonListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0x42bbbbff));

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Lower cutoff (Hz)")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0x0));
    label->setColour (Label::textColourId, Colours::black);
    label->setColour (Label::outlineColourId, Colour (0x0));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (lower_cutoffslider = new Slider (T("new slider")));
    lower_cutoffslider->setRange (0, 10000, 0);
    lower_cutoffslider->setSliderStyle (Slider::LinearHorizontal);
    lower_cutoffslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    lower_cutoffslider->setColour (Slider::thumbColourId, Colour (0x7bffffff));
    lower_cutoffslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    lower_cutoffslider->addListener (this);

    addAndMakeVisible (upper_cutoffslider = new Slider (T("new slider")));
    upper_cutoffslider->setRange (0, 22050, 0);
    upper_cutoffslider->setSliderStyle (Slider::LinearHorizontal);
    upper_cutoffslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    upper_cutoffslider->setColour (Slider::thumbColourId, Colour (0x7dffffff));
    upper_cutoffslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    upper_cutoffslider->addListener (this);

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Upper cutoff (Hz)")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0x0));
    label2->setColour (Label::textColourId, Colours::black);
    label2->setColour (Label::outlineColourId, Colour (0x0));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (sharpnessslider = new Slider (T("new slider")));
    sharpnessslider->setRange (0, 10, 0);
    sharpnessslider->setSliderStyle (Slider::LinearHorizontal);
    sharpnessslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    sharpnessslider->setColour (Slider::thumbColourId, Colour (0x77ffffff));
    sharpnessslider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    sharpnessslider->addListener (this);

    addAndMakeVisible (label3 = new Label (T("new label"),
                                           T("Sharpness (0-10)")));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (Label::backgroundColourId, Colour (0x0));
    label3->setColour (Label::textColourId, Colours::black);
    label3->setColour (Label::outlineColourId, Colour (0x0));
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (resetbutton = new TextButton (T("resetbutton")));
    resetbutton->setButtonText (T("reset"));
    resetbutton->addButtonListener (this);
    resetbutton->setColour (TextButton::buttonColourId, Colour (0x56bbbbff));

    addAndMakeVisible (label4 = new Label (T("new label"),
                                           T("Optimal bandstop filter. The ultimate in cut-off performance!")));
    label4->setFont (Font (12.4000f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (Label::backgroundColourId, Colour (0x0));
    label4->setColour (Label::textColourId, Colours::black);
    label4->setColour (Label::outlineColourId, Colour (0x0));
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

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

Filter::~Filter()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (textButton);
    deleteAndZero (label);
    deleteAndZero (lower_cutoffslider);
    deleteAndZero (upper_cutoffslider);
    deleteAndZero (label2);
    deleteAndZero (sharpnessslider);
    deleteAndZero (label3);
    deleteAndZero (resetbutton);
    deleteAndZero (label4);
    deleteAndZero (textButton2);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Filter::paint (Graphics& g)
{
    //[UserPaint] Add your own custom paint stuff here..
    fillit();
    //[/UserPaint]
}

void Filter::resized()
{
    groupComponent->setBounds (0, 0, 840, 112);
    textButton->setBounds (616, 16, 40, 88);
    label->setBounds (8, 8, 152, 40);
    lower_cutoffslider->setBounds (160, 16, 456, 24);
    upper_cutoffslider->setBounds (160, 48, 456, 24);
    label2->setBounds (8, 48, 150, 24);
    sharpnessslider->setBounds (160, 80, 456, 24);
    label3->setBounds (8, 80, 150, 24);
    resetbutton->setBounds (704, 16, 32, 88);
    label4->setBounds (744, 16, 80, 88);
    textButton2->setBounds (656, 16, 48, 88);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Filter::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      doit(filter_ok);
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == resetbutton)
    {
        //[UserButtonCode_resetbutton] -- add your button handler code here..
      resetval(filter,lower_cutoff);
      resetval(filter,upper_cutoff);
      resetval(filter,sharpness);
        //[/UserButtonCode_resetbutton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
      redoit(filter_ok);
        //[/UserButtonCode_textButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void Filter::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == lower_cutoffslider)
    {
        //[UserSliderCode_lower_cutoffslider] -- add your slider handling code here..
      setval(filter,lower_cutoff);
        //[/UserSliderCode_lower_cutoffslider]
    }
    else if (sliderThatWasMoved == upper_cutoffslider)
    {
        //[UserSliderCode_upper_cutoffslider] -- add your slider handling code here..
      setval(filter,upper_cutoff);
        //[/UserSliderCode_upper_cutoffslider]
    }
    else if (sliderThatWasMoved == sharpnessslider)
    {
        //[UserSliderCode_sharpnessslider] -- add your slider handling code here..
      setval(filter,sharpness);
        //[/UserSliderCode_sharpnessslider]
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

<JUCER_COMPONENT documentType="Component" className="Filter" componentName="Filter"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <GROUPCOMPONENT name="new group" id="18dab2997cfa100c" memberName="groupComponent"
                  pos="0 0 840 112" outlinecol="b0000000" title="Filter" textpos="33"/>
  <TEXTBUTTON name="new button" id="5f136d404edb3db6" memberName="textButton"
              pos="616 16 40 88" bgColOff="42bbbbff" buttonText="Do it!" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="6bb714d5bf6773b7" memberName="label" pos="8 8 152 40"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Lower cutoff (Hz)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="e5a32b976af5c6e3" memberName="lower_cutoffslider"
          pos="160 16 456 24" thumbcol="7bffffff" textboxbkgd="ffffff"
          min="0" max="10000" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <SLIDER name="new slider" id="1ded34e762cd159e" memberName="upper_cutoffslider"
          pos="160 48 456 24" thumbcol="7dffffff" textboxbkgd="ffffff"
          min="0" max="22050" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" id="c7619f1df5ed676" memberName="label2" pos="8 48 150 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Upper cutoff (Hz)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="ce58da39c79428b0" memberName="sharpnessslider"
          pos="160 80 456 24" thumbcol="77ffffff" textboxbkgd="ffffff"
          min="0" max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" id="1522a264de8b0764" memberName="label3" pos="8 80 150 24"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Sharpness (0-10)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="resetbutton" id="ce83e0b9810b5413" memberName="resetbutton"
              pos="704 16 32 88" bgColOff="56bbbbff" buttonText="reset" connectedEdges="0"
              needsCallback="1"/>
  <LABEL name="new label" id="ba6ace2c652dfbd9" memberName="label4" pos="744 16 80 88"
         bkgCol="0" textCol="ff000000" outlineCol="0" edTextCol="ff000000"
         edBkgCol="0" labelText="Optimal bandstop filter. The ultimate in cut-off performance!"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.4" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="10562b9b17841d7c" memberName="textButton2"
              pos="656 16 48 88" bgColOff="40bbbbff" buttonText="Redo it!"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
