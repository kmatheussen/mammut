/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  28 Jan 2007 11:31:33 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_INTERFACE_INTERFACE_8057BDDA__
#define __JUCER_HEADER_INTERFACE_INTERFACE_8057BDDA__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
#include "mammut.h"
#include "GraphComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Interface  : public Component,
                   public Timer,
                   public ButtonListener,
                   public SliderListener,
                   public ComboBoxListener
{
public:
    //==============================================================================
    Interface ();
    ~Interface();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void updateProgressBar(double val);
    void addUndo(void);
    bool loadFile(char *das_filename);
    char *loadFileMul(char *das_filename);
    bool filewasjustsaved;
    void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);

    // Binary resources:
    static const char* mammut_zerlegentmp_jpg;
    static const int mammut_zerlegentmp_jpgSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    GraphComponent *graphcomponent;
    ProgressBar *progressbar;
    FilenameComponent *loadcomponent;
    double progress;
    int undocurrent;
    int undolevel;
    char *filename;
    int pic_x;
    int pic_y;
    int pic_x2;
    int pic_y2;
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent5;
    GroupComponent* groupComponent4;
    GroupComponent* groupComponent3;
    GroupComponent* groupComponent1;
    GroupComponent* groupComponent;
    TextButton* stopbutton;
    TabbedComponent* tabbedComponent;
    Slider* undoredoinc;
    Slider* undoredoslider;
    Label* label;
    GroupComponent* groupComponent2;
    TextButton* correlatebutton;
    TextButton* funbutton;
    TextButton* abbutton;
    HyperlinkButton* hyperlinkButton;
    TextButton* savebutton;
    TextButton* playbutton;
    TextButton* loadbrowse;
    TextButton* loadmulbrowse;
    ComboBox* loadcomboBox;
    TextButton* reload;
    TextButton* convolvebutton;
    TextButton* reloadmul;
    ComboBox* loadmulcomboBox;
    TextButton* phaseampbutton;
    Slider* durationdoublingslider;
    Label* infotext;
    Slider* playposslider;
    ToggleButton* normalizebutton;
    TextButton* saveasbutton;
    TextButton* aboutbutton;
    Image* internalCachedImage3;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    Interface (const Interface&);
    const Interface& operator= (const Interface&);
};


#endif   // __JUCER_HEADER_INTERFACE_INTERFACE_8057BDDA__
