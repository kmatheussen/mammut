/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "mammut.h"
#include "juce.h"
#include "juceplay.h"
//[/Headers]

#include "Prefs.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Prefs::Prefs ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (soundonoffButton = new ToggleButton ("new toggle button"));
    soundonoffButton->setButtonText (TRANS("Startup Sound"));
    soundonoffButton->addListener (this);

    addAndMakeVisible (movingcameraButton = new ToggleButton ("new toggle button"));
    movingcameraButton->setButtonText (TRANS("Moving Camera"));
    movingcameraButton->addListener (this);
    movingcameraButton->setToggleState (true, dontSendNotification);

    addAndMakeVisible (animationButton = new ToggleButton ("new toggle button"));
    animationButton->setButtonText (TRANS("Animation"));
    animationButton->addListener (this);
    animationButton->setToggleState (true, dontSendNotification);

    addAndMakeVisible (pictureButton = new ToggleButton ("new toggle button"));
    pictureButton->setButtonText (TRANS("Background Picture"));
    pictureButton->addListener (this);
    pictureButton->setToggleState (true, dontSendNotification);

    addAndMakeVisible (loopButton = new ToggleButton ("new toggle button"));
    loopButton->setButtonText (TRANS("Loop playing"));
    loopButton->addListener (this);
    loopButton->setToggleState (true, dontSendNotification);

    addAndMakeVisible (audioSettingsButton = new TextButton ("new button"));
    audioSettingsButton->setButtonText (TRANS("Audio Settings"));
    audioSettingsButton->addListener (this);
    audioSettingsButton->setColour (TextButton::buttonColourId, Colour (0x21bbbbff));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 230);


    //[Constructor] You can add your own custom stuff here..
    PropertiesFile::Options options;
    options.applicationName = "mammut";
    options.filenameSuffix = ".prefs";
    options.storageFormat = PropertiesFile::StorageFormat::storeAsXML;
    propertiesfile = new PropertiesFile(options);
      //PropertiesFile::createDefaultAppPropertiesFile("mammut",".prefs",String::empty,false,0,PropertiesFile::storeAsXML);

    //propertiesfile->setValue("tes",54);
    //printf("get: -%d-\n",propertiesfile->getIntValue("tes"));
    //printf("Getting: %d\n",propertiesfile->getBoolValue(soundonoffButton->getButtonText(),true)==true?1:0);

    soundonoffButton->setToggleState(propertiesfile->getBoolValue(soundonoffButton->getButtonText().replaceCharacters(String(" "),String("_")),prefs_soundonoff),true);
    pictureButton->setToggleState(propertiesfile->getBoolValue(pictureButton->getButtonText().replaceCharacters(String(" "),String("_")),prefs_picture),true);
    movingcameraButton->setToggleState(propertiesfile->getBoolValue(movingcameraButton->getButtonText().replaceCharacters(String(" "),String("_")),prefs_movingcamera),true);
    animationButton->setToggleState(propertiesfile->getBoolValue(animationButton->getButtonText().replaceCharacters(String(" "),String("_")),prefs_animation),true);
    loopButton->setToggleState(propertiesfile->getBoolValue(loopButton->getButtonText().replaceCharacters(String(" "),String("_")),prefs_loop),true);
    //[/Constructor]
}

Prefs::~Prefs()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    soundonoffButton = nullptr;
    movingcameraButton = nullptr;
    animationButton = nullptr;
    pictureButton = nullptr;
    loopButton = nullptr;
    audioSettingsButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Prefs::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x9cb1886c));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Prefs::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    soundonoffButton->setBounds (32, 24, 150, 24);
    movingcameraButton->setBounds (32, 120, 150, 24);
    animationButton->setBounds (32, 88, 150, 24);
    pictureButton->setBounds (32, 56, 150, 24);
    loopButton->setBounds (32, 152, 150, 24);
    audioSettingsButton->setBounds (24, 192, 158, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Prefs::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == soundonoffButton)
    {
        //[UserButtonCode_soundonoffButton] -- add your button handler code here..
      prefs_soundonoff=buttonThatWasClicked->getToggleState();
      //sleep(1);
      propertiesfile->setValue(buttonThatWasClicked->getButtonText().replaceCharacters(String(" "),String("_")),buttonThatWasClicked->getToggleState());
      propertiesfile->save();
        //[/UserButtonCode_soundonoffButton]
    }
    else if (buttonThatWasClicked == movingcameraButton)
    {
        //[UserButtonCode_movingcameraButton] -- add your button handler code here..
      prefs_movingcamera=buttonThatWasClicked->getToggleState();
      //sleep(1);
      propertiesfile->setValue(buttonThatWasClicked->getButtonText().replaceCharacters(String(" "),String("_")),buttonThatWasClicked->getToggleState());
      propertiesfile->save();
        //[/UserButtonCode_movingcameraButton]
    }
    else if (buttonThatWasClicked == animationButton)
    {
        //[UserButtonCode_animationButton] -- add your button handler code here..
      prefs_animation=buttonThatWasClicked->getToggleState();
      //sleep(1);
      propertiesfile->setValue(buttonThatWasClicked->getButtonText().replaceCharacters(String(" "),String("_")),buttonThatWasClicked->getToggleState());
      propertiesfile->save();
        //[/UserButtonCode_animationButton]
    }
    else if (buttonThatWasClicked == pictureButton)
    {
        //[UserButtonCode_pictureButton] -- add your button handler code here..
      prefs_picture=buttonThatWasClicked->getToggleState();
      //sleep(1);
#if 0
      if(prefs_picture==false){
	movingcameraButton->setToggleState(false,true);
	animationButton->setToggleState(false,true);
      }
#endif
      //      sleep(1);
      propertiesfile->setValue(buttonThatWasClicked->getButtonText().replaceCharacters(String(" "),String("_")),buttonThatWasClicked->getToggleState());
      propertiesfile->save();
        //[/UserButtonCode_pictureButton]
    }
    else if (buttonThatWasClicked == loopButton)
    {
        //[UserButtonCode_loopButton] -- add your button handler code here..
      prefs_loop=buttonThatWasClicked->getToggleState();
      propertiesfile->setValue(buttonThatWasClicked->getButtonText().replaceCharacters(String(" "),String("_")),buttonThatWasClicked->getToggleState());
      propertiesfile->save();
        //[/UserButtonCode_loopButton]
    }
    else if (buttonThatWasClicked == audioSettingsButton)
    {
        //[UserButtonCode_audioSettingsButton] -- add your button handler code here..
      juceplay_prefs();
      propertiesfile->save();
        //[/UserButtonCode_audioSettingsButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
bool Prefs::firstRun_questionmark(){
  static bool ret=propertiesfile->getBoolValue("firstrun",true);
  return ret;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Prefs" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="200"
                 initialHeight="230">
  <BACKGROUND backgroundColour="9cb1886c"/>
  <TOGGLEBUTTON name="new toggle button" id="b8fcca0d7071dd4c" memberName="soundonoffButton"
                virtualName="" explicitFocusOrder="0" pos="32 24 150 24" buttonText="Startup Sound"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="8336b82cb369b836" memberName="movingcameraButton"
                virtualName="" explicitFocusOrder="0" pos="32 120 150 24" buttonText="Moving Camera"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="fcb13aab9ea5bd22" memberName="animationButton"
                virtualName="" explicitFocusOrder="0" pos="32 88 150 24" buttonText="Animation"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="5af8568366e23286" memberName="pictureButton"
                virtualName="" explicitFocusOrder="0" pos="32 56 150 24" buttonText="Background Picture"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="7236fe3a917c1716" memberName="loopButton"
                virtualName="" explicitFocusOrder="0" pos="32 152 150 24" buttonText="Loop playing"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTBUTTON name="new button" id="b7a94adafb3d0fe" memberName="audioSettingsButton"
              virtualName="" explicitFocusOrder="0" pos="24 192 158 24" bgColOff="21bbbbff"
              buttonText="Audio Settings" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
