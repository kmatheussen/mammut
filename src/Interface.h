/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  15 Feb 2007 8:59:08 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_INTERFACE_INTERFACE_1D53D4E6__
#define __JUCER_HEADER_INTERFACE_INTERFACE_1D53D4E6__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
#include "mammut.h"
#include "GraphComponent.h"
#include "Prefs.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Interface  : public Component,
  public FileDragAndDropTarget,
  public Timer,
  public Button::Listener,
  public Slider::Listener,
  public ComboBox::Listener
{
public:
    //==============================================================================
    Interface (DocumentWindow *mainwindow, const String& commandLine);
    ~Interface();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void updateProgressBar(double val);
    void addUndo(void);
    bool loadFile(char *das_filename);
    char *loadFileMul(char *das_filename);
    bool filewasjustsaved;
    void timerCallback() override;
    void run();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void filesDropped (const StringArray& filenames, int mouseX, int mouseY) override;
    bool isInterestedInFileDrag (const StringArray& filenames) override;
    bool keyPressed (const KeyPress& key) override;

    // Binary resources:
    static const char* temp_png;
    static const int temp_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    GraphComponent *graphcomponent;
    ProgressBar *progressbar;
    FilenameComponent *loadcomponent;
    Image internalCachedImage3;
#if 0
    Image* tempimage;
#endif
    Prefs *prefscomponent;
    double progress;
    int undocurrent;
    int undolevel;
    char *filename;
    char *savefilename;
    char *mulfilename;
    int pic_x;
    int pic_y;
    int pic_x2;
    int pic_y2;
    String *commandLine;
    DocumentWindow *mainwindow;
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
    TextButton* prefsbutton;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    Interface (const Interface&);
    const Interface& operator= (const Interface&);
};


#endif   // __JUCER_HEADER_INTERFACE_INTERFACE_1D53D4E6__
