/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-6 by Raw Material Software ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the
   GNU General Public License, as published by the Free Software Foundation;
   either version 2 of the License, or (at your option) any later version.

   JUCE is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with JUCE; if not, visit www.gnu.org/licenses or write to the
   Free Software Foundation, Inc., 59 Temple Place, Suite 330,
   Boston, MA 02111-1307 USA

  ------------------------------------------------------------------------------

   If you'd like to release a closed-source product which uses JUCE, commercial
   licenses are also available: visit www.rawmaterialsoftware.com/juce for
   more information.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "DasButtons.h"


//==============================================================================
DasButtons::DasButtons ()
  :  textButton1 (0),
    textButton4 (0),
    textButton2 (0),
    textButton5 (0),
    textButton6 (0),
    textButton7 (0),
    toggleButton3 (0),
    slider (0)
{

    gc=new GroupComponent(T("ai"),T("")),
    gc->setSize (700, 100);
    gc->setBounds(0,0,700,100);
    addAndMakeVisible(gc);

    gc->addAndMakeVisible (textButton1 = new TextButton (T("Play")));
    textButton1->addButtonListener (this);
    textButton1->setColour (TextButton::buttonColourId, Colour (0xffbbbbff));
    textButton1->setColour (TextButton::buttonOnColourId, Colour (0xff4444ff));
    textButton1->setColour (TextButton::textColourId, Colours::black);

    gc->addAndMakeVisible (textButton4 = new TextButton (T("Play")));
    textButton4->setButtonText (T("<"));
    textButton4->addButtonListener (this);
    textButton4->setColour (TextButton::buttonColourId, Colour (0xffbbbbff));
    textButton4->setColour (TextButton::buttonOnColourId, Colour (0xff4444ff));
    textButton4->setColour (TextButton::textColourId, Colours::black);

    gc->addAndMakeVisible (textButton2 = new TextButton (T("Play")));
    textButton2->setButtonText (T("Stop"));
    textButton2->addButtonListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colour (0xffbbbbff));
    textButton2->setColour (TextButton::buttonOnColourId, Colour (0xff4444ff));
    textButton2->setColour (TextButton::textColourId, Colours::black);

    gc->addAndMakeVisible (textButton5 = new TextButton (T("Play")));
    textButton5->setButtonText (T(">"));
    textButton5->addButtonListener (this);
    textButton5->setColour (TextButton::buttonColourId, Colour (0xffbbbbff));
    textButton5->setColour (TextButton::buttonOnColourId, Colour (0xff4444ff));
    textButton5->setColour (TextButton::textColourId, Colours::black);

    gc->addAndMakeVisible (textButton6 = new TextButton (T("Play")));
    textButton6->setButtonText (T("Undo"));
    textButton6->addButtonListener (this);
    textButton6->setColour (TextButton::buttonColourId, Colour (0xffbbbbff));
    textButton6->setColour (TextButton::buttonOnColourId, Colour (0xff4444ff));
    textButton6->setColour (TextButton::textColourId, Colours::black);

    gc->addAndMakeVisible (textButton7 = new TextButton (T("Play")));
    textButton7->setButtonText (T("Redo"));
    textButton7->addButtonListener (this);
    textButton7->setColour (TextButton::buttonColourId, Colour (0xffbbbbff));
    textButton7->setColour (TextButton::buttonOnColourId, Colour (0xff4444ff));
    textButton7->setColour (TextButton::textColourId, Colours::black);

    gc->addAndMakeVisible (toggleButton3 = new ToggleButton (T("new toggle button")));
    toggleButton3->setButtonText (T("Zoom"));
    toggleButton3->addButtonListener (this);

    gc->addAndMakeVisible (slider = new Slider (T("new slider")));
    slider->setRange (0, 100, 0);
    slider->setSliderStyle (Slider::LinearBar);
    slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider->addListener (this);


    setSize(700,500);
    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DasButtons::~DasButtons()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (textButton1);
    deleteAndZero (textButton4);
    deleteAndZero (textButton2);
    deleteAndZero (textButton5);
    deleteAndZero (textButton6);
    deleteAndZero (textButton7);
    deleteAndZero (toggleButton3);
    deleteAndZero (slider);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DasButtons::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom paint stuff here..
    //[/UserPaint]
}

void DasButtons::resized()
{
    gc->setBounds(20,20,650,100);

    textButton1->setBounds (168, 24, 56, 24);
    textButton4->setBounds (360, 24, 56, 24);
    textButton2->setBounds (232, 24, 56, 24);
    textButton5->setBounds (424, 24, 56, 24);
    textButton6->setBounds (488, 24, 56, 24);
    textButton7->setBounds (552, 48 - 24, 56, 24);
    toggleButton3->setBounds (288, 24, 63, 24);
    slider->setBounds (8, 24, 152, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DasButtons::buttonClicked (Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == textButton1)
    {
        //[UserButtonCode_textButton1] -- add your button handler code here..
        //[/UserButtonCode_textButton1]
    }
    else if (buttonThatWasClicked == textButton4)
    {
        //[UserButtonCode_textButton4] -- add your button handler code here..
        //[/UserButtonCode_textButton4]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton5)
    {
        //[UserButtonCode_textButton5] -- add your button handler code here..
        //[/UserButtonCode_textButton5]
    }
    else if (buttonThatWasClicked == textButton6)
    {
        //[UserButtonCode_textButton6] -- add your button handler code here..
        //[/UserButtonCode_textButton6]
    }
    else if (buttonThatWasClicked == textButton7)
    {
        //[UserButtonCode_textButton7] -- add your button handler code here..
        //[/UserButtonCode_textButton7]
    }
    else if (buttonThatWasClicked == toggleButton3)
    {
        //[UserButtonCode_toggleButton3] -- add your button handler code here..
        //[/UserButtonCode_toggleButton3]
    }
}

void DasButtons::sliderValueChanged (Slider* sliderThatWasMoved)
{
    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DasButtons" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="Play" memberName="textButton1" pos="168 24 56 24" bgColOff="ffbbbbff"
              bgColOn="ff4444ff" textCol="ff000000" buttonText="Play" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="Play" memberName="textButton4" pos="360 24 56 24" bgColOff="ffbbbbff"
              bgColOn="ff4444ff" textCol="ff000000" buttonText="&lt;" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="Play" memberName="textButton2" pos="232 24 56 24" bgColOff="ffbbbbff"
              bgColOn="ff4444ff" textCol="ff000000" buttonText="Stop" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="Play" memberName="textButton5" pos="424 24 56 24" bgColOff="ffbbbbff"
              bgColOn="ff4444ff" textCol="ff000000" buttonText="&gt;" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="Play" memberName="textButton6" pos="488 24 56 24" bgColOff="ffbbbbff"
              bgColOn="ff4444ff" textCol="ff000000" buttonText="Undo" connectedEdges="0"
              needsCallback="1"/>
  <TEXTBUTTON name="Play" memberName="textButton7" pos="552 48r 56 24" bgColOff="ffbbbbff"
              bgColOn="ff4444ff" textCol="ff000000" buttonText="Redo" connectedEdges="0"
              needsCallback="1"/>
  <TOGGLEBUTTON name="new toggle button" memberName="toggleButton3" pos="288 24 63 24"
                buttonText="Zoom" connectedEdges="0" needsCallback="1" state="0"/>
  <SLIDER name="new slider" memberName="slider" pos="8 24 152 24" min="0"
          max="100" int="0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
