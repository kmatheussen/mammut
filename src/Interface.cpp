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

//[Headers] You can add your own extra header files here...

// TODO!
/*
 * Fix the undo+play bug. (and remove the sleep(1) workaround) Debug-build crash, probably related to this.
 * Fix debug-build problems. (check web-board,)
 * Saveas-thing (?)
 * Cancel processing knapp.
 */

#include <unistd.h>

#include "mammut.h"
#include "PictureHolder.h"
#include "Interface.h"
#include "juceplay.h"

static uint32 paintduration=0;
static uint32 lastrepaint=0;


extern void GUI_init(GraphComponent *das_graphcomponent,Interface *das_interface);

class DasTabbedComponent  : public TabbedComponent
{
 public:
  DasTabbedComponent(TabbedButtonBar::Orientation orientation)
    : TabbedComponent(orientation)
  {
  }

  // Overriding the paint method in TabbedComponent to prevent it from painting various things.
  void paint (Graphics& g){
  }
};


#define TabbedComponent DasTabbedComponent
//[/Headers]

#include "Interface.h"
#include "Stretch.h"
#include "Wobble.h"
#include "MultiplyPhase.h"
#include "DerivativeAmp.h"
#include "Filter.h"
#include "Invert.h"
#include "Threshold.h"
#include "SpectrumShift.h"
#include "BlockSwap.h"
#include "Mirror.h"
#include "KeepPeaks.h"
#include "AmplitudeToPhase.h"
#include "Gain.h"
#include "CombSplit.h"
#include "SplitRealImag.h"
#include "Stereo.h"
#include "Zoom.h"



//==============================================================================
Interface::Interface (DocumentWindow *mainwindow, const String& commandLine)
    : Component (("Interface")),
      groupComponent5 (0),
      groupComponent4 (0),
      groupComponent3 (0),
      groupComponent1 (0),
      groupComponent (0),
      stopbutton (0),
      tabbedComponent (0),
      undoredoinc (0),
      undoredoslider (0),
      label (0),
      groupComponent2 (0),
      correlatebutton (0),
      funbutton (0),
      abbutton (0),
      hyperlinkButton (0),
      savebutton (0),
      playbutton (0),
      loadbrowse (0),
      loadmulbrowse (0),
      loadcomboBox (0),
      reload (0),
      convolvebutton (0),
      reloadmul (0),
      loadmulcomboBox (0),
      phaseampbutton (0),
      durationdoublingslider (0),
      infotext (0),
      playposslider (0),
      normalizebutton (0),
      saveasbutton (0),
      aboutbutton (0),
      prefsbutton (0)
{
    addAndMakeVisible (groupComponent5 = new GroupComponent (("new group"),
                                                             ("Misc")));
    groupComponent5->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (groupComponent4 = new GroupComponent (("new group"),
                                                             ("Save")));
    groupComponent4->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (groupComponent3 = new GroupComponent (("new group"),
                                                             ("Play")));
    groupComponent3->setColour (GroupComponent::outlineColourId, Colour (0xb2000000));
    groupComponent3->setColour (GroupComponent::textColourId, Colours::black);

    addAndMakeVisible (groupComponent1 = new GroupComponent (("new group"),
                                                             ("Load & Analyze")));
    groupComponent1->setColour (GroupComponent::outlineColourId, Colour (0xb2000000));
    groupComponent1->setColour (GroupComponent::textColourId, Colours::black);

    addAndMakeVisible (groupComponent = new GroupComponent (("new group"),
                                                            ("Undo/Redo")));
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb2000000));

    addAndMakeVisible (stopbutton = new TextButton (("Play")));
    stopbutton->setButtonText (("Stop"));
    stopbutton->addListener (this);
    stopbutton->setColour (TextButton::buttonColourId, Colour (0x5cabba2a));
    stopbutton->setColour (TextButton::buttonOnColourId, Colour (0xff4444ff));
    stopbutton->setColour (TextButton::textColourOnId, Colours::black);
    stopbutton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (tabbedComponent = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    tabbedComponent->setTabBarDepth (20);
    tabbedComponent->addTab (("Stretch"), Colour (0x3bf8f4c6), new Stretch(), true);
    tabbedComponent->addTab (("Wobble"), Colour (0x95e0cce6), new Wobble(), true);
    tabbedComponent->addTab (("Multiply Phase"), Colour (0x6aa9e2d8), new MultiplyPhase(), true);
    tabbedComponent->addTab (("Derivate Amp"), Colour (0x65fb95ca), new DerivativeAmp(), true);
    tabbedComponent->addTab (("Filter"), Colour (0xb2e6c3c3), new Filter(), true);
    tabbedComponent->addTab (("Invert"), Colour (0x617ae7e4), new Invert(), true);
    tabbedComponent->addTab (("Threshold"), Colour (0x70f7f1f7), new Threshold(), true);
    tabbedComponent->addTab (("Spectrum Shift"), Colour (0x7dc5e3f9), new SpectrumShift(), true);
    tabbedComponent->addTab (("Block Swap"), Colour (0x499affee), new BlockSwap(), true);
    tabbedComponent->addTab (("Mirror"), Colour (0x91d9daff), new Mirror(), true);
    tabbedComponent->addTab (("Keep Peaks"), Colour (0x84f7e1e1), new KeepPeaks(), true);
    tabbedComponent->addTab (("Amplitude->Phase"), Colour (0x82e5f8e3), new AmplitudeToPhase(), true);
    tabbedComponent->addTab (("Gain"), Colour (0x6ef1f2d1), new Gain(), true);
    tabbedComponent->addTab (("CombSplit"), Colour (0x7bc4ffef), new CombSplit(), true);
    tabbedComponent->addTab (("Split Real/Imag"), Colour (0x98d6d5ea), new SplitRealImag(), true);
    tabbedComponent->addTab (("Stereo"), Colour (0xa3d3d3d3), new Stereo(), true);
    tabbedComponent->addTab (("Zoom"), Colour (0xb0f5f5dc), new Zoom(), true);
    tabbedComponent->setCurrentTabIndex (0);

    addAndMakeVisible (undoredoinc = new Slider (("new slider")));
    undoredoinc->setRange (0, 0, 1);
    undoredoinc->setSliderStyle (Slider::IncDecButtons);
    undoredoinc->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    undoredoinc->setColour (Slider::backgroundColourId, Colour (0x0));
    undoredoinc->setColour (Slider::thumbColourId, Colours::black);
    undoredoinc->setColour (Slider::trackColourId, Colour (0x79000000));
    undoredoinc->setColour (Slider::textBoxTextColourId, Colours::black);
    undoredoinc->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    undoredoinc->setColour (Slider::textBoxHighlightColourId, Colour (0x401a1aa8));
    undoredoinc->addListener (this);

    addAndMakeVisible (undoredoslider = new Slider (("new slider")));
    undoredoslider->setRange (0, 0, 1);
    undoredoslider->setSliderStyle (Slider::LinearBar);
    undoredoslider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    undoredoslider->setColour (Slider::backgroundColourId, Colour (0x5ce5f4f5));
    undoredoslider->setColour (Slider::thumbColourId, Colour (0x5c8d8f92));
    undoredoslider->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    undoredoslider->addListener (this);

    addAndMakeVisible (label = new Label (("new label"),
                                          ("Duration Doubling")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0x0));
    label->setColour (Label::textColourId, Colours::black);
    label->setColour (Label::outlineColourId, Colour (0x0));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (groupComponent2 = new GroupComponent (("new group"),
                                                             ("Load & Multiply")));
    groupComponent2->setColour (GroupComponent::outlineColourId, Colour (0xb4000000));

    addAndMakeVisible (correlatebutton = new TextButton (("new button")));
    correlatebutton->setTooltip (("Correlate. Will simply complex-multiply two spectra, giving the correlation."));
    correlatebutton->setButtonText (("Correlate"));
    correlatebutton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    correlatebutton->addListener (this);
    correlatebutton->setColour (TextButton::buttonColourId, Colour (0x88b26134));
    correlatebutton->setColour (TextButton::buttonOnColourId, Colour (0x371ed220));

    addAndMakeVisible (funbutton = new TextButton (("new button")));
    funbutton->setTooltip (("Fun. Simple complex multiplication, with intended programming \"errors\" (sign reversals and coefficient swaps)."));
    funbutton->setButtonText (("Fun"));
    funbutton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    funbutton->addListener (this);
    funbutton->setColour (TextButton::buttonColourId, Colour (0x8ab26134));
    funbutton->setColour (TextButton::buttonOnColourId, Colour (0x3b6eff44));

    addAndMakeVisible (abbutton = new TextButton (("new button")));
    abbutton->setTooltip (("A^B. Raise spectrum A to the power of spectrum B. Useless (?)"));
    abbutton->setButtonText (("A^B"));
    abbutton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    abbutton->addListener (this);
    abbutton->setColour (TextButton::buttonColourId, Colour (0x8ab26135));
    abbutton->setColour (TextButton::buttonOnColourId, Colour (0x3944ff64));

    addAndMakeVisible (hyperlinkButton = new HyperlinkButton (("http://www.notam02.no"),
                                                              URL (("http://www.notam02.no/notam02/prod-prg-mammuthelp.html"))));
    hyperlinkButton->setTooltip (("http://www.notam02.no/notam02/prod-prg-mammuthelp.html"));
    hyperlinkButton->setColour (HyperlinkButton::textColourId, Colour (0x930004ff));

    addAndMakeVisible (savebutton = new TextButton (("new button")));
    savebutton->setButtonText (("Save"));
    savebutton->addListener (this);
    savebutton->setColour (TextButton::buttonColourId, Colour (0x6ed58d00));

    addAndMakeVisible (playbutton = new TextButton (("Play")));
    playbutton->setButtonText (("Start"));
    playbutton->addListener (this);
    playbutton->setColour (TextButton::buttonColourId, Colour (0x7da9a335));
    playbutton->setColour (TextButton::textColourOnId, Colours::black);
    playbutton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (loadbrowse = new TextButton (("new button")));
    loadbrowse->setButtonText (("browse"));
    loadbrowse->addListener (this);
    loadbrowse->setColour (TextButton::buttonColourId, Colour (0x469bd243));

    addAndMakeVisible (loadmulbrowse = new TextButton (("new button")));
    loadmulbrowse->setButtonText (("browse"));
    loadmulbrowse->addListener (this);
    loadmulbrowse->setColour (TextButton::buttonColourId, Colour (0x449bd2d7));

    addAndMakeVisible (loadcomboBox = new ComboBox (("new combo box")));
    loadcomboBox->setEditableText (true);
    loadcomboBox->setJustificationType (Justification::centredLeft);
    loadcomboBox->setTextWhenNothingSelected (("(choose a soundfile)"));
    loadcomboBox->setTextWhenNoChoicesAvailable (("(choose a soundfile)"));
    loadcomboBox->addListener (this);

    addAndMakeVisible (reload = new TextButton (("new button")));
    reload->setButtonText (("reload"));
    reload->addListener (this);
    reload->setColour (TextButton::buttonColourId, Colour (0x449bd243));

    addAndMakeVisible (convolvebutton = new TextButton (("new button")));
    convolvebutton->setTooltip (("Will complex-multiply with the spectrum of the reversed sound. Use this for standard, high-quality convolution with eg. a room response."));
    convolvebutton->setButtonText (("Convolve"));
    convolvebutton->setConnectedEdges (Button::ConnectedOnRight);
    convolvebutton->addListener (this);
    convolvebutton->setColour (TextButton::buttonColourId, Colour (0x8aa64f15));
    convolvebutton->setColour (TextButton::buttonOnColourId, Colour (0x3b66ff44));

    addAndMakeVisible (reloadmul = new TextButton (("new button")));
    reloadmul->setButtonText (("reload"));
    reloadmul->addListener (this);
    reloadmul->setColour (TextButton::buttonColourId, Colour (0x449bd2d7));

    addAndMakeVisible (loadmulcomboBox = new ComboBox (("new combo box")));
    loadmulcomboBox->setEditableText (true);
    loadmulcomboBox->setJustificationType (Justification::centredLeft);
    loadmulcomboBox->setTextWhenNothingSelected (("(choose a soundfile)"));
    loadmulcomboBox->setTextWhenNoChoicesAvailable (("(choose a soundfile)"));
    loadmulcomboBox->addListener (this);

    addAndMakeVisible (phaseampbutton = new TextButton (("new button")));
    phaseampbutton->setButtonText (("Phase/Amp"));
    phaseampbutton->setConnectedEdges (Button::ConnectedOnLeft);
    phaseampbutton->addListener (this);
    phaseampbutton->setColour (TextButton::buttonColourId, Colour (0x4bd8530a));
    phaseampbutton->setColour (TextButton::buttonOnColourId, Colour (0x4284ff44));

    addAndMakeVisible (durationdoublingslider = new Slider (("new slider")));
    durationdoublingslider->setTooltip (("You may select a number of duration doublings in order to zero-pad your sound to progressively higher powers of 2. This may be useful to increase the duration of silence at the end of a sound. Some transforms may insert interesting sound in this region. You will have to run a new analysis after this value has been changed. CAREFUL! A duration doubling of 3 means that your sound will get 8 times longer. Processing time will increase even more."));
    durationdoublingslider->setRange (0, 4, 1);
    durationdoublingslider->setSliderStyle (Slider::IncDecButtons);
    durationdoublingslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    durationdoublingslider->setColour (Slider::backgroundColourId, Colour (0x0));
    durationdoublingslider->setColour (Slider::thumbColourId, Colours::white);
    durationdoublingslider->setColour (Slider::textBoxBackgroundColourId, Colour (0x37ffffff));
    durationdoublingslider->setColour (Slider::textBoxHighlightColourId, Colour (0x40421bdc));
    durationdoublingslider->addListener (this);

    addAndMakeVisible (infotext = new Label (("infotext"),
                                             ("Start by loading and analyzing a soundfile")));
    infotext->setFont (Font (55.9000f, Font::plain));
    infotext->setJustificationType (Justification::centredLeft);
    infotext->setEditable (false, false, false);
    infotext->setColour (Label::backgroundColourId, Colour (0x0));
    infotext->setColour (Label::textColourId, Colour (0x72000000));
    infotext->setColour (Label::outlineColourId, Colour (0x0));
    infotext->setColour (TextEditor::textColourId, Colours::black);
    infotext->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (playposslider = new Slider (("playprogress")));
    playposslider->setRange (0, 256, 1);
    playposslider->setSliderStyle (Slider::LinearBar);
    playposslider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    playposslider->setColour (Slider::backgroundColourId, Colour (0xffffff));
    playposslider->setColour (Slider::thumbColourId, Colour (0x23ebed9d));
    playposslider->setColour (Slider::trackColourId, Colour (0x58000000));
    playposslider->setColour (Slider::textBoxBackgroundColourId, Colour (0x14ffffff));
    playposslider->addListener (this);

    addAndMakeVisible (normalizebutton = new ToggleButton (("new toggle button")));
    normalizebutton->setTooltip (("Also works when playing"));
    normalizebutton->setButtonText (("normalize"));
    normalizebutton->addListener (this);

    addAndMakeVisible (saveasbutton = new TextButton (("new button")));
    saveasbutton->setButtonText (("Save As"));
    saveasbutton->addListener (this);
    saveasbutton->setColour (TextButton::buttonColourId, Colour (0x6ac18400));

    addAndMakeVisible (aboutbutton = new TextButton (("aboutbutton")));
    aboutbutton->setButtonText (("About"));
    aboutbutton->addListener (this);
    aboutbutton->setColour (TextButton::buttonColourId, Colour (0x1fbbbbff));
    aboutbutton->setColour (TextButton::buttonOnColourId, Colour (0x86a15f5f));
    aboutbutton->setColour (TextButton::textColourOnId, Colour (0xc4000000));
    aboutbutton->setColour (TextButton::textColourOffId, Colour (0xc4000000));

    addAndMakeVisible (prefsbutton = new TextButton (("prefsbutton")));
    prefsbutton->setButtonText (("Prefs"));
    prefsbutton->addListener (this);
    prefsbutton->setColour (TextButton::buttonColourId, Colour (0x1fbbbbff));
    prefsbutton->setColour (TextButton::buttonOnColourId, Colour (0x86a15f5f));
    prefsbutton->setColour (TextButton::textColourOnId, Colour (0xc4000000));
    prefsbutton->setColour (TextButton::textColourOffId, Colour (0xc4000000));

    setSize (900, 800);

    //[Constructor] You can add your own custom stuff here..
    /*************************************************************/

    //addAndMakeVisible(graphcomponent=new GraphComponent(componentplace->getX(),componentplace->getY(),componentplace->getWidth(),componentplace->getHeight()));
    addAndMakeVisible(graphcomponent=new GraphComponent(0,0,20,20));
    graphcomponent->setName (("gnew component"));
    //componentplace->setVisible(false);


    GUI_init(graphcomponent,this);
    //graphcomponent->setBounds(0,0,650,550);
    //graphcomponent->setTopRightPosition(0,0);

    undolevel=0;
    undocurrent=0;
    filename=NULL;
    mulfilename=NULL;
    savefilename=NULL;

    loadcomboBox->setColour(ComboBox::backgroundColourId,Colour    (0x47422222));//Colour (0x809bd243));
    loadmulcomboBox->setColour(ComboBox::backgroundColourId,Colour (0x47422222));//Colour (0x809bd243));

    //tabbedComponent->getTabContentComponent(0)->setSize(100,200);
    //printf("%p\n",tabbedComponent->tabs);

    tabbedComponent->getTabContentComponent(tabbedComponent->getNumTabs()-2)->setEnabled(samps_per_frame>=2?true:false);

    tabbedComponent->setEnabled(false);
    tabbedComponent->setColour(TabbedComponent::outlineColourId, Colour(0x00ddf1ee));
    tabbedComponent->setOutline(0);
    tabbedComponent->setIndent(0);

    //->setClickingTogglesState (true);
    convolvebutton->setClickingTogglesState (true);
    correlatebutton->setClickingTogglesState (true);
    funbutton->setClickingTogglesState (true);
    abbutton->setClickingTogglesState (true);
    phaseampbutton->setClickingTogglesState (true);

    convolvebutton->setRadioGroupId (23456);
    correlatebutton->setRadioGroupId (23456);
    funbutton->setRadioGroupId (23456);
    abbutton->setRadioGroupId (23456);
    phaseampbutton->setRadioGroupId (23456);

    convolvebutton->setToggleState(true,true);

    filewasjustsaved=false;

    savebutton->setEnabled(false);
    saveasbutton->setEnabled(false);

    prefscomponent=new Prefs();
    juceplay_init(prefscomponent->propertiesfile);

    pic_x=15;
    pic_y=5;
    pic_x2=872-15;
    pic_y2=738-15;
    internalCachedImage3=PictureHolder::getImage(0);


#if 0
    tempimage=internalCachedImage3->createCopy();
    startThread();
#endif

    startTimer(20);

    this->commandLine=new String(commandLine.toRawUTF8());
    this->mainwindow=mainwindow;
    //loadFile((char*)commandLine.toRawUTF8());
    //MC_loadAndAnalyze((char*)commandLine.toRawUTF8());


    //setBufferedToImage(true);

#if 0
    zoomtoggle->toFront(true);
    zoomleft->toFront(true);
    zoomright->toFront(true);
#endif
    //[/Constructor]
}

Interface::~Interface()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
  printf("exitgakk0 %d\n",(int)sizeof(float));
  printf("exitgakk\n");
    //[/Destructor_pre]

    deleteAndZero (groupComponent5);
    deleteAndZero (groupComponent4);
    deleteAndZero (groupComponent3);
    deleteAndZero (groupComponent1);
    deleteAndZero (groupComponent);
    deleteAndZero (stopbutton);
    deleteAndZero (tabbedComponent);
    deleteAndZero (undoredoinc);
    deleteAndZero (undoredoslider);
    deleteAndZero (label);
    deleteAndZero (groupComponent2);
    deleteAndZero (correlatebutton);
    deleteAndZero (funbutton);
    deleteAndZero (abbutton);
    deleteAndZero (hyperlinkButton);
    deleteAndZero (savebutton);
    deleteAndZero (playbutton);
    deleteAndZero (loadbrowse);
    deleteAndZero (loadmulbrowse);
    deleteAndZero (loadcomboBox);
    deleteAndZero (reload);
    deleteAndZero (convolvebutton);
    deleteAndZero (reloadmul);
    deleteAndZero (loadmulcomboBox);
    deleteAndZero (phaseampbutton);
    deleteAndZero (durationdoublingslider);
    deleteAndZero (infotext);
    deleteAndZero (playposslider);
    deleteAndZero (normalizebutton);
    deleteAndZero (saveasbutton);
    deleteAndZero (aboutbutton);
    deleteAndZero (prefsbutton);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Interface::paint (Graphics& g)
{
    g.fillAll (Colour (0xffddf1ee));

    g.setColour (Colours::black);
    g.setFont (Font (15.0000f, Font::plain));
    g.drawText (String::empty,
                408, 312, 200, 30,
                Justification::centred, true);

    const ColourGradient gradient_1 (Colours::red,
                              50.0f, 50.0f,
                              Colours::green,
                              744.0f, 576.0f,
                              false);
    g.setGradientFill (gradient_1);
    g.fillRoundedRectangle (0.0f, 448.0f, 960.0f, 384.0f, 21.5000f);

    const ColourGradient gradient_2 (Colour (0x7bf98f33),
                              664.0f, 40.0f,
                              Colour (0xd78c8c8c),
                              720.0f, 560.0f,
                              false);
    g.setGradientFill (gradient_2);
    g.fillRect (-8, -24, 976, 864);
    
    const ColourGradient gradient_3 (Colour (0x219d2323),
                              16.0f, 736.0f,
                              Colour (0x5f0f1615),
                              696.0f, 752.0f,
                              true);
    g.setGradientFill (gradient_3);
    g.fillRoundedRectangle (0.0f, 584.0f, 960.0f, 304.0f, 21.5000f);

    //[UserPaint] Add your own custom paint stuff here..
#if 1
    uint32 starttime=Time::getMillisecondCounter();

    if(lyd==NULL && prefscomponent->firstRun_questionmark()==true){
      static Image internalCachedImage4 = ImageCache::getFromMemory (temp_png, temp_pngSize);
      g.setColour (Colours::black.withAlpha (1.0f));//0.5140f));
      g.drawImage (internalCachedImage4,
		   -8, 640, 384, 104,
		   0, 0, internalCachedImage4.getWidth(), internalCachedImage4.getHeight());
    }

    g.setImageResamplingQuality(Graphics::lowResamplingQuality);
    if(prefs_picture==true){
      g.setColour (Colours::black.withAlpha (0.2700f));
      if(prefs_movingcamera==true){
#if 0
	g.drawImageAt(tempimage,0,0,false);
#else
	g.drawImage(internalCachedImage3,
		    0, 0, 872, 738,
		    pic_x,pic_y, pic_x2-pic_x, pic_y2-pic_y,
		    false);
#endif
      }else{
	g.drawImageAt(internalCachedImage3,0,0,false);
      }
    }
    lastrepaint=Time::getMillisecondCounter();
    paintduration=lastrepaint-starttime;
#endif
#if 0
    GradientBrush gb (Colour((juce::uint8)0xcd,(juce::uint8)0xd1,(juce::uint8)0xce,(juce::uint8)0xee),
		      getWidth() * 0.3f, getHeight() * 0.3f,
		      Colour((juce::uint8)0xc0,(juce::uint8)0xc8,(juce::uint8)0xde,(juce::uint8)0x5e),
		      getWidth() * 0.91f, getHeight() * 0.7f,
		      1);

    g.setBrush (&gb);
	    //            g.fillPath (shape, getTransform());
    g.fillAll ();
#endif
    //graphcomponent->repaint();
#if 0
    zoomtoggle->toFront(true);
    zoomleft->toFront(true);
    zoomright->toFront(true);
#endif
    //[/UserPaint]
}

void Interface::resized()
{
    groupComponent5->setBounds (649, 587, 200, 64);
    groupComponent4->setBounds (745, 651, 104, 80);
    groupComponent3->setBounds (9, 587, 424, 64);
    groupComponent1->setBounds (9, 651, 368, 80);
    groupComponent->setBounds (433, 587, 216, 64);
    stopbutton->setBounds (87, 604, 71, 40);
    tabbedComponent->setBounds (7, 450, 848, 136);
    undoredoinc->setBounds (449, 611, 56, 24);
    undoredoslider->setBounds (513, 611, 120, 24);
    label->setBounds (17, 667, 160, 24);
    groupComponent2->setBounds (377, 651, 368, 80);
    correlatebutton->setBounds (441, 667, 56, 24);
    funbutton->setBounds (497, 667, 48, 24);
    abbutton->setBounds (545, 667, 48, 24);
    hyperlinkButton->setBounds (656, 624, 184, 22);
    savebutton->setBounds (761, 667, 72, 20);
    playbutton->setBounds (17, 603, 71, 40);
    loadbrowse->setBounds (305, 699, 64, 24);
    loadmulbrowse->setBounds (673, 699, 64, 24);
    loadcomboBox->setBounds (17, 699, 280, 24);
    reload->setBounds (305, 667, 64, 24);
    convolvebutton->setBounds (385, 667, 56, 24);
    reloadmul->setBounds (673, 667, 64, 24);
    loadmulcomboBox->setBounds (385, 699, 280, 24);
    phaseampbutton->setBounds (593, 667, 72, 24);
    durationdoublingslider->setBounds (153, 667, 148, 24);
    infotext->setBounds (32, 216, 800, 64);
    playposslider->setBounds (168, 612, 256, 24);
    normalizebutton->setBounds (760, 704, 72, 24);
    saveasbutton->setBounds (761, 687, 71, 21);
    aboutbutton->setBounds (664, 604, 80, 22);
    prefsbutton->setBounds (752, 604, 80, 22);
    //[UserResized] Add your own custom resize handling here..
    //    if(graphcomponent)
    // graphcomponent->setBounds(0,0,600,550);
    //[/UserResized]
}

void Interface::buttonClicked (Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == stopbutton)
    {
        //[UserButtonCode_stopbutton] -- add your button handler code here..
      MC_stop();
        //[/UserButtonCode_stopbutton]
    }
    else if (buttonThatWasClicked == correlatebutton)
    {
        //[UserButtonCode_correlatebutton] -- add your button handler code here..
      loadandmultiply_convolve=false;
      loadandmultiply_correlate=true;
      loadandmultiply_fun=false;
      loadandmultiply_a_b=false;
      loadandmultiply_phase_amp=false;

        //[/UserButtonCode_correlatebutton]
    }
    else if (buttonThatWasClicked == funbutton)
    {
        //[UserButtonCode_funbutton] -- add your button handler code here..
      loadandmultiply_convolve=false;
      loadandmultiply_correlate=false;
      loadandmultiply_fun=true;
      loadandmultiply_a_b=false;
      loadandmultiply_phase_amp=false;
        //[/UserButtonCode_funbutton]
    }
    else if (buttonThatWasClicked == abbutton)
    {
        //[UserButtonCode_abbutton] -- add your button handler code here..
      loadandmultiply_convolve=false;
      loadandmultiply_correlate=false;
      loadandmultiply_fun=false;
      loadandmultiply_a_b=true;
      loadandmultiply_phase_amp=false;
        //[/UserButtonCode_abbutton]
    }
    else if (buttonThatWasClicked == savebutton)
    {
        //[UserButtonCode_savebutton] -- add your button handler code here..
      if(savefilename==NULL)
	buttonClicked(saveasbutton);
      else{
	MC_stop();
	MC_synthAndSave(savefilename);
      }
        //[/UserButtonCode_savebutton]
    }
    else if (buttonThatWasClicked == playbutton)
    {
        //[UserButtonCode_playbutton] -- add your button handler code here..
      MC_play();
        //[/UserButtonCode_playbutton]
    }
    else if (buttonThatWasClicked == loadbrowse)
    {
        //[UserButtonCode_loadbrowse] -- add your button handler code here..
      isprocessing=true;
      FileChooser myChooser ("Please choose file to load and analyze...",
			     File::nonexistent,
			     String::empty);

      if (myChooser.browseForFileToOpen())
        {

	  File mooseFile (myChooser.getResult());

	  filename=(char*)mooseFile.getFullPathName().toRawUTF8();

	  printf("Filename2: %s\n",filename);
	  loadcomboBox->setText(mooseFile.getFullPathName(),false);

	  //loadcomboBox->addItem(mooseFile.getFullPathName(),loadcomboBox->getNumItems()+1);

        }

      isprocessing=false;

        //[/UserButtonCode_loadbrowse]
    }
    else if (buttonThatWasClicked == loadmulbrowse)
    {
        //[UserButtonCode_loadmulbrowse] -- add your button handler code here..
      if(savebutton->isEnabled()==false)
	return;
      isprocessing=true;
      FileChooser myChooser ("Please choose file to load and multiply...",
			     File::nonexistent,
			     String::empty);

      if (myChooser.browseForFileToOpen())
        {
	  File mooseFile (myChooser.getResult());
	  mulfilename=(char*)mooseFile.getFullPathName().toRawUTF8();
	  printf("Mul Filename: %s\n",mulfilename);
	  loadmulcomboBox->setText(mooseFile.getFullPathName(),false);
	  //loadcomboBox->addItem(mooseFile.getFullPathName(),loadcomboBox->getNumItems()+1);

        }
      isprocessing=false;
        //[/UserButtonCode_loadmulbrowse]
    }
    else if (buttonThatWasClicked == reload)
    {
        //[UserButtonCode_reload] -- add your button handler code here..
      if(filename==NULL){
	buttonClicked(loadbrowse);
      }else{
	savefilename=NULL;
	loadFile((char*)loadcomboBox->getText().toRawUTF8());
      }
        //[/UserButtonCode_reload]
    }
    else if (buttonThatWasClicked == convolvebutton)
    {
        //[UserButtonCode_convolvebutton] -- add your button handler code here..
      loadandmultiply_convolve=true;
      loadandmultiply_correlate=false;
      loadandmultiply_fun=false;
      loadandmultiply_a_b=false;
      loadandmultiply_phase_amp=false;
        //[/UserButtonCode_convolvebutton]
    }
    else if (buttonThatWasClicked == reloadmul)
    {
        //[UserButtonCode_reloadmul] -- add your button handler code here..
      if(savebutton->isEnabled()==true)
	loadFileMul((char*)loadmulcomboBox->getText().toRawUTF8());
        //[/UserButtonCode_reloadmul]
    }
    else if (buttonThatWasClicked == phaseampbutton)
    {
        //[UserButtonCode_phaseampbutton] -- add your button handler code here..
      loadandmultiply_convolve=false;
      loadandmultiply_correlate=false;
      loadandmultiply_fun=true;
      loadandmultiply_a_b=false;
      loadandmultiply_phase_amp=true;
        //[/UserButtonCode_phaseampbutton]
    }
    else if (buttonThatWasClicked == normalizebutton)
    {
        //[UserButtonCode_normalizebutton] -- add your button handler code here..
      synthandsave_normalize_gain=normalizebutton->getToggleState();
        //[/UserButtonCode_normalizebutton]
    }
    else if (buttonThatWasClicked == saveasbutton)
    {
        //[UserButtonCode_saveasbutton] -- add your button handler code here..
      isprocessing=true;
      FileChooser myChooser ("Please choose file to save...",
			     File::nonexistent,
			     String::empty);

      if (myChooser.browseForFileToSave(true))
        {
	  File mooseFile (myChooser.getResult());
	  savefilename=(char*)mooseFile.getFullPathName().toRawUTF8();
	  printf("Filename: %s\n",savefilename);
	  MC_stop();
	  char *error=MC_synthAndSave(savefilename);
	  if(error!=NULL){
	    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
					 ("Mammut"),
					 String(error) + (" (") + String((const char*)savefilename) + (")"));
	  }else{
	    filewasjustsaved=true;
	    mainwindow->setName(mooseFile.getFullPathName());
	    //loadcomboBox->setText(mooseFile.getFullPathName(),false);
	  }
        }
      isprocessing=false;
        //[/UserButtonCode_saveasbutton]
    }
    else if (buttonThatWasClicked == aboutbutton)
    {
        //[UserButtonCode_aboutbutton] -- add your button handler code here..
      const char *message[]={"V", VERSION, ", Notam 1995-2018.\n",
			     "\n",
			     "Mammut is a program for experimental\n",
			     "audio processing, using mammut FFT.\n",
			     "\n",
			     "Signal processing programming by Oyvind Hammer.\n",
			     "User interface programming by Kjetil Matheussen.\n",
			     "\n",
			     "Background picture painted by Zdenek Burian.\n",
			     "Animation by Kjetil Matheussen.\n",
			     "\n",
			     "The slightly crushed Mammoth Skull in the program's icon\n",
			     "can be observed in real life at the Palaeontological\n",
			     "Museum, University of Oslo. (and the incident causing this\n",
			     "injury, is realistically animated in the background of the\n",
			     "program)\n",
			     "\n",
			     "Mammut uses these libraries: libjack, libjuce, libsamplerate,\n",
			     "libsndfile and libvorbisfile.\n",
			     "\n",
			     "Send your comments to k.s.matheussen@notam02.no.\n"};

      AlertWindow::showMessageBox(AlertWindow::InfoIcon,("Mammut"),StringArray(message,sizeof(message)/sizeof(const char*)).joinIntoString(String::empty));

        //[/UserButtonCode_aboutbutton]
    }
    else if (buttonThatWasClicked == prefsbutton)
    {
        //[UserButtonCode_prefsbutton] -- add your button handler code here..
      DialogWindow::showModalDialog("Preferences",prefscomponent,this,Colour((uint8)0,(uint8)0,(uint8)0,(uint8)0x90),true);
        //[/UserButtonCode_prefsbutton]
    }
}

void Interface::sliderValueChanged (Slider* sliderThatWasMoved)
{
    if (sliderThatWasMoved == undoredoinc)
    {
        //[UserSliderCode_undoredoinc] -- add your slider handling code here..
      printf("Hepp, %d\n",(int)undoredoinc->getValue());
      bool wasplaying=jp_isplaying;
      MC_stop();
      while(undoredoinc->getValue()>undocurrent){
	MC_redo();
	undocurrent++;
      }
      while(undoredoinc->getValue()<undocurrent){
	MC_undo();
	undocurrent--;
      }
      undoredoslider->setValue(undocurrent);
      if(wasplaying)
	MC_play();

        //[/UserSliderCode_undoredoinc]
    }
    else if (sliderThatWasMoved == undoredoslider)
    {
        //[UserSliderCode_undoredoslider] -- add your slider handling code here..
      bool wasplaying=jp_isplaying;
      MC_stop();
      while(undoredoslider->getValue()>undocurrent){
	MC_redo();
	undocurrent++;
      }
      while(undoredoslider->getValue()<undocurrent){
	MC_undo();
	undocurrent--;
      }

      undoredoinc->setValue(undocurrent);

      if(wasplaying){
	sleep(1);
	MC_play();
      }

        //[/UserSliderCode_undoredoslider]
    }
    else if (sliderThatWasMoved == durationdoublingslider)
    {
        //[UserSliderCode_durationdoublingslider] -- add your slider handling code here..
      analysis_duration_doubling=(int)durationdoublingslider->getValue();
      analysis_ok();
        //[/UserSliderCode_durationdoublingslider]
    }
    else if (sliderThatWasMoved == playposslider)
    {
        //[UserSliderCode_playposslider] -- add your slider handling code here..
      jp_playpos=(int)((playposslider->getValue()/256.0f)*N);
        //[/UserSliderCode_playposslider]
    }
}

void Interface::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == loadcomboBox)
    {
        //[UserComboBoxCode_loadcomboBox] -- add your combo box handling code here..
      static char *lastvalid=NULL;

      fprintf(stderr,"Agakk gakk0!\n");

      if(lastvalid==NULL){
	lastvalid=(char*)erroralloc(1024);
	sprintf(lastvalid,"%s","");
      }

      //printf("Gakk! %s %d\n",loadcomboBox->getText().toRawUTF8(),loadcomboBox->getSelectedId());
      fprintf(stderr,"gakk gakk1!\n");
      if(filewasjustsaved==false && loadFile((char*)loadcomboBox->getText().toRawUTF8())==false){
	savefilename=NULL;
	fprintf(stderr,"gakk gakk2!\n");
	if(strcmp("",lastvalid))
	  loadcomboBox->setText(lastvalid,true);
	return;
      }
      fprintf(stderr,"gakk gakk3!\n");
      filewasjustsaved=false;

      if(loadcomboBox->getSelectedId()==0)
	loadcomboBox->addItem(loadcomboBox->getText(),loadcomboBox->getNumItems()+1);

      sprintf(lastvalid,loadcomboBox->getText().toRawUTF8());

        //[/UserComboBoxCode_loadcomboBox]
    }
    else if (comboBoxThatHasChanged == loadmulcomboBox)
    {
        //[UserComboBoxCode_loadmulcomboBox] -- add your combo box handling code here..
      static char *lastvalid=NULL;

      if(lastvalid==NULL){
	lastvalid=(char*)erroralloc(1024);
	sprintf(lastvalid,"%s","");
      }

      //printf("Gakk! %s %d\n",loadmulcomboBox->getText().toRawUTF8(),loadmulcomboBox->getSelectedId());

      if(savebutton->isEnabled()==true){
	char *error=loadFileMul((char*)loadmulcomboBox->getText().toRawUTF8());
	if(error!=NULL){
	  if(strcmp("",lastvalid))
	    loadmulcomboBox->setText(lastvalid,true);
	  return;
	}
      }else{
	loadmulcomboBox->setText(String::empty);
	return;
      }

      if(loadmulcomboBox->getSelectedId()==0)
	loadmulcomboBox->addItem(loadmulcomboBox->getText(),loadmulcomboBox->getNumItems()+1);

      sprintf(lastvalid,loadmulcomboBox->getText().toRawUTF8());

        //[/UserComboBoxCode_loadmulcomboBox]
    }
}

void Interface::filesDropped (const StringArray& filenames, int mouseX, int mouseY)
{
    //[UserCode_filesDropped] -- Add your code here...
  loadcomboBox->setText(filenames[0],true);
  loadFile((char*)filenames[0].toRawUTF8());
    //[/UserCode_filesDropped]
}

bool Interface::isInterestedInFileDrag (const StringArray& filenames)
{
  return true;
}

bool Interface::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
#if 0
  if key.string=="<": mammutc.MC_left();
  if key.string==">": mammutc.MC_right();
  if key.string=="+": mammutc.MC_zoom();
  if key.string=="-": mammutc.MC_zoom();
#endif
  //printf("%d\n",key.getKeyCode());
  if(key.isKeyCode(60)) MC_left();
  else if(key.isKeyCode(62)) MC_right();
  else if(key.isKeyCode('+')) MC_zoom();
  else if(key.isKeyCode('-')) MC_zoom();
  else if(key.isKeyCode(KeyPress::spaceKey)){
    if(jp_isplaying)
      stopbutton->triggerClick();
    //      MC_stop();
    else
      playbutton->triggerClick();
    //MC_play();
  }else
    return false;

  return true;
  
    //[/UserCode_keyPressed]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Interface::addUndo(void){
  undocurrent++;
  undolevel=undocurrent;
  undoredoinc->setRange(0,undolevel,1);
  undoredoinc->setValue(undolevel);
  undoredoslider->setRange(0,undolevel,1);
  undoredoslider->setValue(undolevel);
  //printf("ai? %d %d %d\n",undolevel,(int)undoredoinc->getMaxValue(),(int)undoredoslider->getMaxValue());
}

char *Interface::loadFileMul(char *das_filename){
  MC_stop();
  char *error=MC_addUndo();
  if(error!=NULL){
    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
				 ("Mammut"),
				 String((const char*)error) + (" (") + loadmulcomboBox->getText() + (")."));
    return error;
  }

  error=load_and_multiply_ok(das_filename);
  if(error==NULL){
    graphcomponent->repaint();
    GUI_addUndo();
  }else{
    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
				 ("Mammut"),
				 String((const char*)error) + (" (") + loadmulcomboBox->getText() + (")."));
    MC_undo();
  }
  return error;
}

bool Interface::loadFile(char *das_filename){
  MC_stop();
#if 0
  filename="/hom/kjetism/uio/t.wav";
  filename="/hom/kjetism/2_channel_short.wav";
  filename="/hom/kjetism/temp/mus2860/loop4.wav";
  filename="/hom/kjetism/ccrma_summer_concert/concert7.wav";
  filename="/home/kjetil/prosjekt/capture/TO/jack_capture_3.wav";
  filename="/home/kjetil/2_channel_short.wav";
  filename="/hom/kjetism/2_channel_short.wav";
  //      filename="/home/kjetil/Blub_mono.wav";
#else
  filename=strdup(das_filename);
#endif

  prefscomponent->propertiesfile->setValue("firstrun",false);

  char *error=MC_loadAndAnalyze(filename);

  if(error!=NULL){
    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
				 ("Mammut"),
				 String((const char*)error) + String(" (") + String(filename) + String(")"));
    return false;
  }

  mainwindow->setName(("Mammut"));

  MC_resetUndo();
  undoredoslider->setValue(0);
  undoredoinc->setValue(0);
  undoredoslider->setRange(0,0,1);
  undoredoinc->setRange(0,0,1);

  tabbedComponent->getTabContentComponent(tabbedComponent->getNumTabs()-2)->setEnabled(samps_per_frame>=2?true:false);

  if(samps_per_frame>0)
    tabbedComponent->setEnabled(true);
  graphcomponent->repaint();

  savebutton->setEnabled(true);
  saveasbutton->setEnabled(true);

  infotext->setVisible(false);

  return true;
}

#if 0
void Interface::run(){
  Graphics g(*tempimage);

  setPriority(0);
  setCurrentThreadPriority(10);

  for(;;){
      sleep(50);
    for(int x=0;x<870;x+=10){

      int dasx=pic_x+x*(pic_x2-pic_x)/87;
      int dasx2=dasx+(pic_x2-pic_x)/87;

      g.drawImage(internalCachedImage3,
		  x, 0, x+10, 738,
		  dasx,pic_y,dasx2,pic_y2-pic_y,
		  false);
    }

    //printf("RUN is called!\n");
  }
}
#endif

void Interface::timerCallback(){
  static bool wasplaying=false;
  static Image ims[3]={
    PictureHolder::getImage(0),
    PictureHolder::getImage(1),
    PictureHolder::getImage(2)
  };
  static Random *random=new Random(Time::currentTimeMillis());

#if 1
  static bool havedoneinit=false;
  if(havedoneinit==false && commandLine->length()>1){
    havedoneinit=true;
	if(commandLine->startsWithChar('-')==false){
		loadcomboBox->setText(*commandLine,true);
		loadFile((char*)commandLine->toRawUTF8());
	}
    printf("Im here\n");
  }
#endif

   uint32 time=Time::getMillisecondCounter();

   //printf("time-lastrepaint: %d, paintduration: %d, dtime: %d\n",time-lastrepaint,paintduration,paintduration-2*(time-lastrepaint));

  // Don't want the animation-stuff to stall the computer.
  if(time-lastrepaint<10 || (time-lastrepaint)<paintduration){
    return;
  }

  if(jp_isplaying){
    double playpos=256.0;
    playpos*=jp_playpos;
    playpos/=N;
    playposslider->setValue(playpos,dontSendNotification);
    wasplaying=true;
  }else if(wasplaying){
    playposslider->setValue(0.0);
    wasplaying=false;
  }

  bool mustpaint=false;


  { // Make sure picture dissappears if clicking prefs/picture
    static bool waspicture=false;
    if(prefs_picture){
      waspicture=true;
    }else if(waspicture){
      mustpaint=true;
      waspicture=false;
    }
  }

  {  // Make sure picture appears if clicking prefs/picture
    static bool wasnotpicture=false;
    if(!prefs_picture){
      wasnotpicture=true;
    }else if(wasnotpicture){
      mustpaint=true;
      wasnotpicture=false;
    }
  }

  if(isprocessing==false && prefs_picture==true && prefs_movingcamera==true){
    static uint32 nexttime2=0;
    if(1 || time>=nexttime2){
      static int addval_x=0;
      addval_x+=random->nextInt(3)-1;
      static int addval_y=0;
      addval_y+=random->nextInt(3)-1;
      static int addval_size=0;
      addval_size+=random->nextInt(3)-1;

#define MAXADDVAL 12
#define CORVAL 1
      if(addval_x>=MAXADDVAL)
	addval_x=MAXADDVAL;
      if(addval_x<=-MAXADDVAL)
	addval_x=-MAXADDVAL;
      if(addval_y>=MAXADDVAL)
	addval_y=MAXADDVAL;
      if(addval_y<=-MAXADDVAL)
	addval_y=-MAXADDVAL;
      if(addval_size>=MAXADDVAL)
	addval_size=MAXADDVAL;
      if(addval_size<=-MAXADDVAL)
	addval_size=-MAXADDVAL;

      //const int addval=random->nextInt(3)-1;
      int newpic_x=pic_x+addval_x;
      int newpic_y=pic_y+addval_y;

      if(newpic_x<0){addval_size+=CORVAL;newpic_y-=newpic_x;newpic_x=0;addval_x+=CORVAL;}
      if(newpic_x>350){addval_size-=CORVAL;newpic_y+=350-newpic_x;newpic_x=350;addval_x-=CORVAL;}

      if(newpic_y<0){newpic_y=0;addval_y+=CORVAL;}
      if(newpic_y>350){newpic_y=350;addval_y-=CORVAL;}
      //if(newpic_y<0){newpic_x-=newpic_y;newpic_y=0;addval_y+=CORVAL;}
      //if(newpic_y>350){newpic_x+=350-newpic_y;newpic_y=350;addval_y-=CORVAL;}

      //if(newpic_x<0){addval_size+=CORVAL;newpic_x=0;addval_x+=CORVAL;}
      // if(newpic_x>350){addval_size-=CORVAL;newpic_x=350;addval_x-=CORVAL;}

      //int sizeadd=random->nextInt(2*addval+1)-addval;
      int newpic_x2=pic_x2+addval_size;
      int newpic_y2=pic_y2+addval_size;
      if(newpic_x2>=872){newpic_x2-=addval_size;newpic_y2-=addval_size;}
      if(newpic_y2>=738){newpic_x2-=addval_size;newpic_y2-=addval_size;}
      if(newpic_x2<=400){newpic_x2+=addval_size;newpic_y2+=addval_size;}
      if(newpic_y2<=400){newpic_x2+=addval_size;newpic_y2+=addval_size;}
      if(newpic_x2<872
	 && newpic_x2>400
	 && newpic_y2<738
	 && newpic_y2>400){
	pic_x2=newpic_x2;
	pic_y2=newpic_y2;
      }else{
	addval_size=0;
      }
      //printf("pic_x2: %d, addval_size: %d\n",pic_x,addval_size);
      pic_x=newpic_x;
      pic_y=newpic_y;

      mustpaint=true;
      nexttime2=time+50;
    }
  }


  if(isprocessing==false && prefs_picture==true && prefs_animation==true){
    static uint32 nexttime=0;
    if(time>=nexttime){
      for(int i=0;i<1000;i++){
	Image newim=ims[random->nextInt(3)];
	if(newim!=internalCachedImage3){
	  internalCachedImage3=newim;
	  mustpaint=true;
	  break;
	}
      }
      nexttime=time+300+random->nextInt(300);
    }
  }

  if(mustpaint==true){
      repaint();
  }
}




//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Interface" componentName="Interface"
                 parentClasses="public Component, public Timer" constructorParams="DocumentWindow *mainwindow, const String&amp; commandLine"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.329999983" fixedSize="1" initialWidth="900"
                 initialHeight="800">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
    <METHOD name="filesDropped (const StringArray&amp; filenames, int mouseX, int mouseY)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffddf1ee">
    <TEXT pos="408 312 200 30" fill="solid: ff000000" hasStroke="0" text=""
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <ROUNDRECT pos="0 448 960 384" cornerSize="21.5" fill="linear: 50 50, 744 576, 0=ffff0000, 1=ff008000"
               hasStroke="0"/>
    <RECT pos="-8 -24 976 864" fill="linear: 664 40, 720 560, 0=7bf98f33, 1=d78c8c8c"
          hasStroke="0"/>
    <ROUNDRECT pos="0 584 960 304" cornerSize="21.5" fill=" radial: 16 736, 696 752, 0=219d2323, 1=5f0f1615"
               hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" memberName="groupComponent5" pos="649 587 200 64"
                  outlinecol="b0000000" title="Misc"/>
  <GROUPCOMPONENT name="new group" memberName="groupComponent4" pos="745 651 104 80"
                  outlinecol="b0000000" title="Save"/>
  <GROUPCOMPONENT name="new group" memberName="groupComponent3" pos="9 587 424 64"
                  outlinecol="b2000000" textcol="ff000000" title="Play"/>
  <GROUPCOMPONENT name="new group" memberName="groupComponent1" pos="9 651 368 80"
                  outlinecol="b2000000" textcol="ff000000" title="Load &amp; Analyze"/>
  <GROUPCOMPONENT name="new group" memberName="groupComponent" pos="433 587 216 64"
                  outlinecol="b2000000" title="Undo/Redo"/>
  <TEXTBUTTON name="Play" memberName="stopbutton" pos="87 604 71 40" bgColOff="5cabba2a"
              bgColOn="ff4444ff" textCol="ff000000" buttonText="Stop" connectedEdges="0"
              needsCallback="1"/>
  <TABBEDCOMPONENT name="new tabbed component" memberName="tabbedComponent" pos="7 450 848 136"
                   orientation="top" tabBarDepth="20" initialTab="0">
    <TAB name="Stretch" colour="3bf8f4c6" useJucerComp="1" contentClassName="Tabtest"
         constructorParams="" jucerComponentFile="Stretch.cpp"/>
    <TAB name="Wobble" colour="95e0cce6" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="Wobble.cpp"/>
    <TAB name="Multiply Phase" colour="6aa9e2d8" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="MultiplyPhase.cpp"/>
    <TAB name="Derivate Amp" colour="65fb95ca" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="DerivativeAmp.cpp"/>
    <TAB name="Filter" colour="b2e6c3c3" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="Filter.cpp"/>
    <TAB name="Invert" colour="617ae7e4" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="Invert.cpp"/>
    <TAB name="Threshold" colour="70f7f1f7" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="Threshold.cpp"/>
    <TAB name="Spectrum Shift" colour="7dc5e3f9" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="SpectrumShift.cpp"/>
    <TAB name="Block Swap" colour="499affee" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="BlockSwap.cpp"/>
    <TAB name="Mirror" colour="91d9daff" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="Mirror.cpp"/>
    <TAB name="Keep Peaks" colour="84f7e1e1" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="KeepPeaks.cpp"/>
    <TAB name="Amplitude-&gt;Phase" colour="82e5f8e3" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="AmplitudeToPhase.cpp"/>
    <TAB name="Gain" colour="6ef1f2d1" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="Gain.cpp"/>
    <TAB name="CombSplit" colour="7bc4ffef" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="CombSplit.cpp"/>
    <TAB name="Split Real/Imag" colour="98d6d5ea" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="SplitRealImag.cpp"/>
    <TAB name="Stereo" colour="a3d3d3d3" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="Stereo.cpp"/>
    <TAB name="Zoom" colour="b0f5f5dc" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="Zoom.cpp"/>
  </TABBEDCOMPONENT>
  <SLIDER name="new slider" memberName="undoredoinc" pos="449 611 56 24"
          bkgcol="0" thumbcol="ff000000" trackcol="79000000" textboxtext="ff000000"
          textboxbkgd="ffffffff" textboxhighlight="401a1aa8" min="0" max="0"
          int="1" style="IncDecButtons" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20"/>
  <SLIDER name="new slider" memberName="undoredoslider" pos="513 611 120 24"
          bkgcol="5ce5f4f5" thumbcol="5c8d8f92" textboxbkgd="ffffffff"
          min="0" max="0" int="1" style="LinearBar" textBoxPos="TextBoxAbove"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="new label" memberName="label" pos="17 667 160 24" bkgCol="0"
         textCol="ff000000" outlineCol="0" edTextCol="ff000000" edBkgCol="0"
         labelText="Duration Doubling" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="new group" memberName="groupComponent2" pos="377 651 368 80"
                  outlinecol="b4000000" title="Load &amp; Multiply"/>
  <TEXTBUTTON name="new button" memberName="correlatebutton" pos="441 667 56 24"
              tooltip="Correlate. Will simply complex-multiply two spectra, giving the correlation."
              bgColOff="88b26134" bgColOn="371ed220" buttonText="Correlate"
              connectedEdges="3" needsCallback="1"/>
  <TEXTBUTTON name="new button" memberName="funbutton" pos="497 667 48 24"
              tooltip="Fun. Simple complex multiplication, with intended programming &quot;errors&quot; (sign reversals and coefficient swaps)."
              bgColOff="8ab26134" bgColOn="3b6eff44" buttonText="Fun" connectedEdges="3"
              needsCallback="1"/>
  <TEXTBUTTON name="new button" memberName="abbutton" pos="545 667 48 24" tooltip="A&#94;B. Raise spectrum A to the power of spectrum B. Useless (?)"
              bgColOff="8ab26135" bgColOn="3944ff64" buttonText="A&#94;B" connectedEdges="3"
              needsCallback="1"/>
  <HYPERLINKBUTTON name="new hyperlink" memberName="hyperlinkButton" pos="656 624 184 22"
                   tooltip="http://www.notam02.no/notam02/prod-prg-mammuthelp.html"
                   textCol="930004ff" buttonText="http://www.notam02.no" connectedEdges="0"
                   needsCallback="0" url="http://www.notam02.no/notam02/prod-prg-mammuthelp.html"/>
  <TEXTBUTTON name="new button" memberName="savebutton" pos="761 667 72 20"
              bgColOff="6ed58d00" buttonText="Save" connectedEdges="0" needsCallback="1"/>
  <TEXTBUTTON name="Play" memberName="playbutton" pos="17 603 71 40" bgColOff="7da9a335"
              textCol="ff000000" buttonText="Start" connectedEdges="0" needsCallback="1"/>
  <TEXTBUTTON name="new button" memberName="loadbrowse" pos="305 699 64 24"
              bgColOff="469bd243" buttonText="browse" connectedEdges="0" needsCallback="1"/>
  <TEXTBUTTON name="new button" memberName="loadmulbrowse" pos="673 699 64 24"
              bgColOff="449bd2d7" buttonText="browse" connectedEdges="0" needsCallback="1"/>
  <COMBOBOX name="new combo box" memberName="loadcomboBox" pos="17 699 280 24"
            editable="1" layout="33" items="" textWhenNonSelected="(choose a soundfile)"
            textWhenNoItems="(choose a soundfile)"/>
  <TEXTBUTTON name="new button" memberName="reload" pos="305 667 64 24" bgColOff="449bd243"
              buttonText="reload" connectedEdges="0" needsCallback="1"/>
  <TEXTBUTTON name="new button" memberName="convolvebutton" pos="385 667 56 24"
              tooltip="Will complex-multiply with the spectrum of the reversed sound. Use this for standard, high-quality convolution with eg. a room response."
              bgColOff="8aa64f15" bgColOn="3b66ff44" buttonText="Convolve"
              connectedEdges="2" needsCallback="1"/>
  <TEXTBUTTON name="new button" memberName="reloadmul" pos="673 667 64 24"
              bgColOff="449bd2d7" buttonText="reload" connectedEdges="0" needsCallback="1"/>
  <COMBOBOX name="new combo box" memberName="loadmulcomboBox" pos="385 699 280 24"
            editable="1" layout="33" items="" textWhenNonSelected="(choose a soundfile)"
            textWhenNoItems="(choose a soundfile)"/>
  <TEXTBUTTON name="new button" memberName="phaseampbutton" pos="593 667 72 24"
              bgColOff="4bd8530a" bgColOn="4284ff44" buttonText="Phase/Amp"
              connectedEdges="1" needsCallback="1"/>
  <SLIDER name="new slider" memberName="durationdoublingslider" pos="153 667 148 24"
          tooltip="You may select a number of duration doublings in order to zero-pad your sound to progressively higher powers of 2. This may be useful to increase the duration of silence at the end of a sound. Some transforms may insert interesting sound in this region. You will have to run a new analysis after this value has been changed. CAREFUL! A duration doubling of 3 means that your sound will get 8 times longer. Processing time will increase even more."
          bkgcol="0" thumbcol="ffffffff" textboxbkgd="37ffffff" textboxhighlight="40421bdc"
          min="0" max="4" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <LABEL name="infotext" memberName="infotext" pos="32 216 800 64" bkgCol="0"
         textCol="72000000" outlineCol="0" edTextCol="ff000000" edBkgCol="0"
         labelText="Start by loading and analyzing a soundfile" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="55.9" bold="0" italic="0" justification="33"/>
  <SLIDER name="playprogress" memberName="playposslider" pos="168 612 256 24"
          bkgcol="ffffff" thumbcol="23ebed9d" trackcol="58000000" textboxbkgd="14ffffff"
          min="0" max="256" int="1" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <TOGGLEBUTTON name="new toggle button" memberName="normalizebutton" pos="760 704 72 24"
                tooltip="Also works when playing" buttonText="normalize" connectedEdges="0"
                needsCallback="1" state="0"/>
  <TEXTBUTTON name="new button" memberName="saveasbutton" pos="761 687 71 21"
              bgColOff="6ac18400" buttonText="Save As" connectedEdges="0" needsCallback="1"/>
  <TEXTBUTTON name="aboutbutton" memberName="aboutbutton" pos="664 604 80 22"
              bgColOff="1fbbbbff" bgColOn="86a15f5f" textCol="c4000000" buttonText="About"
              connectedEdges="0" needsCallback="1"/>
  <TEXTBUTTON name="prefsbutton" memberName="prefsbutton" pos="752 604 80 22"
              bgColOff="1fbbbbff" bgColOn="86a15f5f" textCol="c4000000" buttonText="Prefs"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: temp_png, 6283, "/div/notam02/u2/kjetism/localdomain/newmammut/temp.png"
static const unsigned char resource_Interface_temp_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,246,0,0,0,117,8,6,0,0,0,188,184,195,126,0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,
147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,215,2,15,19,53,42,134,166,211,72,0,0,0,29,116,69,88,116,67,111,109,109,101,110,116,0,67,114,101,97,116,101,100,32,119,
105,116,104,32,84,104,101,32,71,73,77,80,239,100,37,110,0,0,23,239,73,68,65,84,120,218,237,157,121,140,93,213,125,199,63,119,236,241,50,222,176,7,131,177,97,12,134,177,141,193,30,76,217,113,18,194,210,
134,173,105,66,90,66,10,37,149,138,34,161,180,21,73,160,109,162,182,105,144,218,40,10,137,69,211,74,148,164,34,162,68,133,224,0,101,77,217,83,108,179,152,197,54,120,197,6,198,11,198,44,94,102,236,177,
103,59,253,227,247,187,188,59,111,246,183,204,91,238,247,35,61,189,217,222,204,155,123,207,57,223,243,251,157,223,18,133,16,16,66,8,33,68,117,80,163,75,32,132,16,66,72,216,133,16,66,8,33,97,23,66,8,33,
132,132,93,8,33,132,16,18,118,33,132,16,34,109,140,214,37,16,162,138,136,162,57,192,44,96,46,208,0,76,0,14,0,219,129,13,192,203,132,112,88,23,74,8,9,187,168,204,69,190,9,88,8,52,250,98,63,17,24,75,198,
83,51,26,232,244,143,187,129,142,62,198,68,39,80,171,215,148,236,53,53,192,36,23,232,241,254,24,237,143,49,254,92,11,140,242,199,167,119,31,72,230,178,182,3,251,129,221,68,209,54,96,47,208,2,236,6,62,
246,231,125,192,30,255,124,47,33,236,210,36,18,162,2,151,126,229,177,87,173,168,95,7,124,9,56,29,152,153,16,145,200,159,67,98,241,239,235,107,12,242,125,189,166,112,175,137,70,120,116,244,245,62,187,19,
223,239,246,77,66,39,112,208,55,5,29,137,13,194,62,160,213,159,59,253,231,219,253,177,7,248,16,248,0,248,8,104,243,13,133,54,11,66,72,216,69,30,162,126,3,112,19,112,178,46,134,24,193,205,66,182,151,160,
59,107,35,51,202,197,191,13,56,156,216,44,180,185,7,97,143,111,2,58,220,155,240,62,208,12,108,2,118,16,194,86,93,102,33,36,236,105,20,245,223,7,150,74,212,69,5,111,16,146,31,215,248,6,33,248,243,135,192,
54,247,0,28,116,207,193,110,96,135,111,0,222,149,103,64,164,29,157,177,87,151,168,207,0,190,40,81,23,149,60,138,251,248,56,142,57,24,133,29,43,205,204,242,18,116,39,188,5,237,192,33,162,104,191,111,2,
62,114,111,64,171,139,255,102,96,45,33,172,214,165,22,18,118,81,9,28,1,92,160,203,32,82,182,9,168,73,124,62,206,31,71,96,89,1,201,13,64,248,244,243,40,58,228,98,223,226,226,191,221,173,253,102,89,254,
162,226,39,134,92,241,85,101,177,159,6,172,192,34,167,133,16,195,163,175,99,128,54,183,244,155,221,3,32,203,95,200,98,23,66,136,10,243,0,36,63,30,15,156,228,143,236,12,130,136,40,106,117,145,95,229,15,
213,10,16,178,216,69,65,45,246,249,192,50,96,129,46,134,16,37,179,248,15,98,174,252,181,152,91,95,145,253,66,22,187,200,153,189,192,115,18,118,33,74,106,241,79,0,78,241,71,108,229,183,99,197,129,54,186,
224,175,117,75,127,39,208,76,8,29,186,124,66,22,187,232,207,106,87,186,155,16,149,97,217,199,133,125,226,148,189,183,129,245,192,91,232,252,94,72,216,69,150,184,171,64,141,16,149,43,250,29,88,1,159,61,
192,22,23,250,53,232,252,94,72,216,83,47,238,149,92,82,86,20,207,74,212,181,174,220,251,23,185,224,111,7,86,3,111,162,243,123,33,97,79,157,184,39,155,192,28,139,157,253,197,77,96,34,50,141,73,226,170,
94,29,88,67,145,164,8,196,95,43,196,107,106,253,61,212,1,245,88,174,241,68,50,205,75,210,46,54,3,109,120,186,176,212,171,54,204,125,27,95,251,3,192,33,44,96,171,195,127,254,208,16,238,207,36,96,154,63,
38,249,247,106,252,94,140,195,162,193,187,252,231,227,234,111,201,54,207,253,109,214,196,200,143,151,120,108,28,192,106,244,111,117,235,94,46,125,9,187,16,5,223,88,204,112,241,94,4,92,9,156,11,28,69,166,
67,89,154,23,228,248,17,187,91,203,171,68,106,20,213,98,5,94,166,250,61,28,15,28,13,28,227,247,112,58,214,93,110,148,139,126,23,48,217,127,118,42,153,90,10,181,190,153,28,239,63,223,69,239,250,241,217,
139,144,54,8,133,27,99,145,143,169,173,216,249,189,162,244,37,236,66,12,91,196,231,2,167,1,167,186,167,96,142,91,132,105,91,172,147,214,212,33,183,166,118,251,2,251,38,230,74,125,157,16,54,167,112,140,
212,251,38,96,188,111,16,226,141,194,52,223,8,76,246,143,235,129,41,238,225,25,215,135,240,107,3,144,251,184,140,115,241,227,250,251,91,220,202,223,236,207,155,80,229,61,9,187,168,218,197,120,182,47,176,
177,72,55,0,199,185,245,118,180,139,118,93,194,26,171,73,217,162,59,144,101,180,205,159,183,203,50,202,123,28,54,96,158,159,121,62,14,235,125,220,77,4,142,244,141,193,36,247,14,140,206,242,2,104,3,48,
252,241,124,24,115,239,183,2,187,92,240,215,0,235,128,53,132,208,172,75,37,97,23,229,191,112,54,2,139,125,241,92,8,156,224,11,102,157,91,86,181,41,94,40,117,150,89,25,99,120,14,22,75,50,215,55,159,199,
184,216,79,246,77,232,177,190,33,136,99,6,70,73,252,135,69,119,98,62,124,2,108,148,149,47,97,23,229,39,226,167,3,103,186,152,79,77,161,181,61,144,136,103,71,31,203,250,174,158,241,63,152,23,42,118,255,
143,166,103,79,121,109,0,250,159,51,96,65,157,109,192,126,44,70,100,45,42,179,43,97,23,69,89,196,226,200,248,166,132,69,62,141,76,196,122,154,23,163,164,11,61,89,239,123,35,176,138,16,14,106,0,165,118,
222,212,1,103,96,174,255,70,96,6,150,209,81,143,121,179,102,144,241,98,73,236,7,182,242,227,76,140,247,125,147,188,17,120,15,117,209,147,176,139,97,137,248,249,192,217,190,32,77,72,8,88,26,93,232,241,
226,162,10,95,162,24,194,223,4,124,22,243,124,29,67,38,181,176,70,23,105,208,121,25,124,94,30,146,149,47,97,79,251,130,50,7,152,133,157,35,54,248,243,201,152,75,113,98,138,45,136,108,23,250,27,100,92,
232,155,137,91,111,170,38,183,24,25,43,255,12,236,168,171,193,231,229,24,212,155,99,168,243,184,29,171,161,191,30,248,95,224,177,84,101,143,72,216,171,114,113,232,239,252,239,56,44,45,40,59,242,55,74,
241,2,112,136,204,57,248,203,192,75,200,133,46,202,87,236,23,97,141,97,102,99,49,45,117,110,225,43,125,175,255,57,222,134,229,221,63,5,220,39,43,94,194,94,238,19,190,33,49,209,207,196,206,191,103,249,
206,62,118,229,5,77,248,79,57,228,214,247,219,100,34,209,55,2,219,8,225,61,93,30,81,97,243,63,206,233,63,30,152,239,235,192,124,224,68,44,117,79,213,24,123,210,133,229,219,175,2,30,1,30,87,202,157,132,
189,212,147,56,59,10,253,84,183,202,35,210,121,246,61,24,221,152,75,125,191,11,248,67,110,141,239,146,136,139,42,94,39,226,106,127,179,48,143,221,113,190,86,156,134,165,234,141,69,165,123,3,150,110,186,
25,120,20,184,95,49,50,18,246,225,90,211,39,98,57,176,237,196,129,29,67,25,68,118,14,222,136,5,177,125,193,127,207,4,183,198,37,226,189,39,42,88,212,236,78,224,85,224,21,226,142,86,218,149,11,209,215,
249,253,66,223,0,76,198,170,242,141,73,88,248,105,89,99,226,179,248,103,128,95,3,207,202,77,159,118,97,239,233,10,139,3,209,230,99,81,174,71,211,243,12,187,19,75,213,88,15,44,35,132,59,179,126,215,88,
224,44,224,60,96,137,91,231,241,239,16,189,233,194,106,163,175,5,94,0,158,7,94,210,217,184,16,5,91,199,78,37,61,81,250,113,165,188,88,228,127,73,8,47,72,216,171,123,224,199,162,59,191,64,59,221,67,216,
57,239,219,254,250,153,88,78,235,100,255,93,74,115,233,61,233,218,49,247,217,22,224,113,96,133,95,63,69,169,11,49,114,86,254,201,190,94,77,33,211,233,177,218,2,247,226,142,134,235,129,159,1,79,166,209,
235,87,29,194,158,57,155,58,201,7,241,241,100,2,82,102,20,105,215,170,179,174,158,31,215,144,169,60,213,130,229,139,111,39,173,13,79,132,40,255,117,51,142,253,105,114,11,191,191,50,210,149,186,206,117,
97,165,159,31,5,254,45,77,103,241,149,39,236,61,91,129,126,206,119,162,13,88,26,216,120,148,58,82,104,241,206,110,8,177,27,171,26,245,46,153,246,143,239,162,234,81,66,84,139,224,103,167,220,198,49,67,
11,200,84,173,172,164,53,54,96,45,145,95,2,126,74,8,143,72,216,203,99,160,53,96,189,188,47,192,34,203,231,187,144,75,192,11,47,226,123,48,55,214,70,23,109,53,119,16,66,244,103,229,207,193,210,243,38,82,
25,245,53,130,27,39,119,1,191,168,86,47,98,249,10,123,230,108,252,74,23,244,70,236,28,91,103,216,133,17,240,184,67,83,92,194,241,85,228,46,23,66,228,182,94,103,119,214,203,174,136,89,142,101,173,187,220,
104,185,7,248,45,214,224,169,42,140,151,242,19,118,171,119,126,61,150,38,214,128,185,215,37,230,185,139,56,88,84,255,46,172,58,155,82,201,132,16,35,189,166,47,36,83,132,103,14,189,171,104,150,154,3,192,
115,192,195,192,139,149,126,30,95,62,194,30,69,215,1,183,248,46,111,148,102,195,176,73,118,81,82,62,184,16,162,146,172,252,11,49,15,237,76,44,219,168,84,150,125,55,22,67,244,16,240,63,192,250,74,180,226,
75,43,236,118,118,126,53,240,77,183,206,197,224,214,247,64,29,145,212,110,84,8,81,169,66,223,8,92,6,92,142,157,227,39,3,245,74,193,97,44,222,232,69,183,230,87,86,138,129,84,26,97,55,65,191,6,248,51,223,
173,169,144,75,207,244,177,14,204,53,180,31,115,161,111,71,81,232,66,136,116,8,124,29,150,241,244,21,183,228,103,145,73,189,43,149,21,255,1,176,28,88,134,21,41,43,235,250,27,35,47,236,81,116,53,112,3,
112,14,86,36,33,205,66,222,141,69,161,91,158,183,61,171,63,184,16,66,152,94,52,185,192,95,142,5,80,79,160,116,110,250,0,236,5,30,0,150,18,194,90,9,187,89,233,223,2,174,195,92,44,105,20,242,3,152,107,103,
181,239,254,150,43,10,93,8,33,134,164,31,151,2,87,96,53,76,102,82,90,79,111,43,240,43,44,47,126,67,58,133,61,138,254,28,248,62,149,113,142,94,168,86,169,221,88,81,151,143,177,64,182,135,129,149,200,133,
46,132,16,185,106,73,92,38,247,92,224,243,88,93,147,35,75,104,197,183,96,129,118,63,46,39,79,107,241,132,221,242,208,47,3,254,18,235,114,54,166,204,196,59,194,242,24,219,220,146,254,0,216,138,21,100,217,
130,21,95,184,8,43,79,91,71,239,254,232,253,149,84,221,5,172,193,154,155,172,68,193,108,66,8,81,44,157,105,114,125,185,10,107,194,53,174,4,239,162,27,171,9,242,27,224,223,203,65,224,139,35,236,81,52,23,
248,58,112,45,150,206,80,202,51,145,152,86,23,238,245,88,0,218,54,127,222,78,8,91,251,249,63,226,246,173,243,176,220,203,122,50,173,87,59,124,99,208,130,117,126,27,252,247,9,33,132,40,134,230,28,235,214,
251,85,216,121,252,180,18,232,78,92,155,254,9,74,220,70,182,240,194,30,69,151,0,63,0,206,100,100,243,209,187,177,244,132,131,88,64,218,123,88,3,146,85,40,32,77,8,33,210,32,240,181,152,171,254,66,44,232,
238,20,74,23,81,127,24,203,104,122,195,181,168,25,216,140,213,25,41,106,103,203,194,9,187,89,183,223,196,34,222,143,24,129,139,214,233,34,190,21,43,7,248,44,106,5,42,132,16,194,52,105,54,118,164,122,41,
240,199,88,77,251,82,123,143,187,177,26,36,45,46,244,175,186,118,189,86,72,237,42,140,176,71,209,103,176,170,113,23,83,220,51,142,78,172,128,255,90,224,41,172,215,174,44,113,33,132,16,131,233,212,18,224,
102,44,118,170,156,82,173,147,105,207,175,96,177,89,175,231,83,12,39,127,97,143,162,155,253,98,77,47,226,78,103,63,230,82,127,1,120,30,120,73,1,105,66,8,33,114,208,172,6,224,18,204,195,188,0,115,213,151,
75,115,154,46,23,249,205,192,211,192,253,185,24,175,249,9,123,20,61,0,252,81,17,173,243,181,192,127,0,79,34,23,187,16,66,136,194,91,241,55,98,222,230,105,148,87,159,146,118,236,60,254,25,134,25,140,151,
155,176,71,209,76,224,191,176,60,194,66,211,129,21,111,185,157,16,30,208,200,19,66,8,49,2,86,252,31,98,165,206,23,81,218,10,119,125,209,141,165,82,223,135,165,212,109,46,172,176,71,209,2,224,14,96,73,
129,223,120,0,222,241,223,253,32,33,108,210,104,19,66,8,49,194,34,223,228,86,252,151,176,20,231,114,107,27,254,38,240,119,132,240,72,97,132,61,138,22,3,183,99,133,0,10,245,207,6,44,45,224,113,224,159,
20,12,39,132,16,162,76,4,254,219,216,113,243,164,50,123,119,107,129,239,246,39,238,67,23,118,43,58,243,67,204,93,81,168,115,136,46,223,125,124,159,16,30,212,72,18,66,8,81,102,2,63,31,184,9,248,26,48,177,
140,222,217,195,192,183,251,114,203,215,12,241,31,27,11,124,25,203,7,44,132,168,7,172,245,232,119,129,203,36,234,66,8,33,202,146,16,54,16,194,55,48,79,245,127,98,29,222,202,129,243,176,178,237,57,90,236,
150,167,126,23,86,86,53,95,14,98,81,238,75,9,225,57,141,26,33,132,16,21,98,189,215,98,101,107,175,197,90,143,79,165,116,103,240,1,59,194,254,114,118,180,252,80,133,253,97,172,254,110,190,81,130,187,129,
127,5,126,162,60,116,33,132,16,21,42,240,201,54,178,11,176,158,40,165,104,116,246,14,112,61,33,252,223,240,132,61,138,174,194,250,206,230,243,166,219,129,199,128,91,9,225,53,141,10,33,132,16,85,32,240,
113,27,217,121,88,166,216,185,88,123,242,177,100,186,136,22,147,3,192,77,132,112,231,208,133,221,118,37,207,146,159,11,126,27,240,61,66,184,91,163,64,8,33,68,138,196,126,17,48,31,56,14,75,157,155,232,
162,95,40,193,239,6,110,35,132,91,146,95,28,61,200,139,190,149,167,168,175,3,110,32,132,21,186,219,66,8,33,170,30,59,102,254,157,63,146,130,95,235,214,252,233,88,73,219,37,254,249,56,114,15,74,143,128,
25,217,95,28,61,192,174,227,106,44,64,32,215,93,196,10,224,106,66,216,169,59,45,132,16,34,229,130,223,1,108,241,199,175,93,103,155,176,246,178,151,3,39,51,252,38,106,129,62,142,201,71,247,35,234,13,46,
234,211,114,252,23,86,3,223,144,168,11,33,132,16,253,138,253,106,96,53,81,180,2,248,133,91,223,195,113,211,71,64,107,246,23,251,11,211,191,20,203,145,203,229,28,224,67,224,31,8,97,157,238,154,16,66,8,
49,144,52,71,231,0,183,230,32,234,96,69,222,118,12,46,236,86,140,230,10,44,63,47,23,238,24,168,134,173,16,66,8,33,128,40,186,16,248,57,118,238,158,171,33,221,171,242,92,95,174,248,179,176,188,188,92,254,
200,22,224,78,221,45,33,132,16,162,95,65,159,15,220,2,124,21,24,159,199,111,90,143,213,141,31,84,216,231,3,71,230,240,7,218,129,191,33,132,102,221,53,33,132,16,162,151,160,55,1,223,1,190,72,254,141,101,
218,128,199,250,106,156,214,151,176,79,199,122,209,14,151,223,17,194,50,221,57,33,132,16,162,151,160,223,136,245,92,153,70,97,202,208,62,9,220,223,215,55,250,75,119,203,197,13,95,79,20,45,38,132,215,117,
23,133,16,66,164,92,204,27,176,110,168,215,96,133,106,38,80,184,194,52,219,129,31,18,194,123,67,21,246,15,115,252,67,77,192,82,162,232,59,132,240,138,238,170,16,66,136,20,9,249,12,224,8,224,98,224,235,
192,66,138,83,63,126,31,240,35,66,88,217,223,15,244,37,236,27,114,116,19,212,0,231,3,183,18,69,127,47,113,23,66,8,81,229,98,222,232,186,119,30,112,26,112,42,249,5,195,13,70,59,214,105,245,191,7,124,91,
189,106,197,91,186,219,71,228,222,80,190,19,43,165,247,183,18,119,33,132,16,85,36,228,115,128,89,192,92,183,204,23,3,51,93,47,139,221,240,165,11,107,211,122,51,33,108,24,158,176,219,155,127,2,248,131,
60,222,64,39,240,52,32,203,93,8,33,68,37,136,118,3,118,22,62,15,235,145,82,143,69,174,215,99,77,92,166,99,158,233,136,145,239,193,30,151,105,255,171,161,196,177,245,39,236,151,1,143,22,96,119,177,2,248,
107,5,212,9,33,132,200,67,116,103,187,192,54,186,232,30,131,21,81,27,227,143,88,104,71,187,97,25,139,97,7,189,143,156,59,129,201,254,250,122,96,10,80,71,166,78,123,192,154,178,140,68,219,213,161,138,250,
211,88,123,214,183,134,116,185,250,109,219,26,69,247,0,95,203,243,13,5,172,104,205,15,128,251,8,225,176,70,168,16,66,8,215,153,164,107,187,33,241,124,180,11,238,56,50,103,214,217,130,27,101,137,111,24,
228,107,244,241,253,114,167,21,59,79,255,199,225,244,94,25,172,31,251,51,192,231,11,32,238,7,129,149,88,206,221,227,42,98,35,132,16,35,46,162,113,212,246,241,46,160,179,128,163,176,243,225,81,9,107,182,
54,7,11,120,160,215,116,37,44,228,169,254,247,198,211,51,253,171,166,194,4,183,216,116,1,219,128,159,17,194,109,195,190,213,131,8,251,76,224,94,44,226,47,223,51,133,0,236,113,129,191,155,16,238,213,189,
19,66,136,130,139,244,88,127,158,236,95,155,132,185,154,199,184,208,38,173,217,154,1,172,217,92,44,224,80,129,86,113,185,209,2,60,8,220,214,87,85,185,252,133,221,6,208,2,224,142,2,137,123,204,62,236,12,
255,231,192,122,66,216,165,123,41,132,16,159,174,187,77,88,30,244,41,88,153,239,99,49,247,244,80,68,90,130,90,153,180,2,191,2,126,58,88,212,123,254,194,110,131,108,49,176,20,203,215,27,85,192,127,228,
48,150,55,255,50,22,104,183,156,16,54,235,254,10,33,82,32,222,217,1,97,11,177,60,232,19,48,55,117,242,44,89,84,47,123,129,223,0,75,9,97,109,65,134,214,144,132,221,6,225,153,88,207,216,139,232,191,20,109,
174,4,223,173,188,11,60,15,220,7,188,172,96,59,33,68,149,136,120,50,72,44,182,194,79,192,210,168,234,226,159,210,133,74,13,221,192,7,192,114,96,25,176,140,16,58,10,54,220,134,44,236,54,56,207,2,254,5,
248,108,17,196,61,41,242,109,192,123,192,19,192,47,115,61,103,16,66,136,18,139,248,66,127,204,197,206,187,199,32,119,121,154,105,195,218,172,190,6,60,7,172,44,70,48,249,240,132,189,167,229,126,49,133,
117,203,247,183,171,57,12,108,2,30,2,94,0,54,245,87,248,94,8,33,70,80,192,107,177,212,172,147,176,24,164,243,49,183,250,84,183,194,203,41,23,90,148,142,118,23,243,187,128,167,128,189,197,142,43,27,190,
176,103,44,247,31,251,64,30,201,10,60,29,88,87,155,87,177,115,249,23,145,203,94,8,49,114,34,126,58,150,2,252,123,254,249,100,44,215,186,70,23,73,56,157,192,126,96,53,112,15,240,228,72,167,120,231,38,236,
54,208,23,3,183,3,231,80,60,183,252,96,187,160,93,192,26,224,17,148,31,47,132,200,95,192,199,2,103,97,103,224,139,252,249,56,172,135,246,36,44,149,76,22,184,72,18,48,207,242,251,88,48,248,111,129,199,
74,25,8,158,187,176,219,36,56,5,248,103,224,11,20,167,61,221,112,46,108,55,208,12,60,134,21,202,127,83,46,123,33,196,32,107,88,156,15,126,46,112,165,91,226,211,220,10,31,37,17,151,104,103,61,3,28,194,
138,174,237,3,118,2,235,129,85,192,70,96,21,33,28,44,249,176,206,75,216,109,98,204,4,174,5,254,2,56,145,242,112,73,117,2,59,128,87,144,203,94,8,209,91,196,47,193,218,108,198,5,92,106,37,226,21,43,188,
185,20,212,233,49,50,220,48,196,159,63,116,35,241,99,172,88,204,199,192,86,23,238,53,149,224,25,206,95,216,51,147,230,2,224,79,128,75,177,179,167,114,57,115,234,194,34,17,183,161,40,123,33,210,34,226,
179,129,25,192,217,192,231,128,5,88,206,248,100,204,187,40,17,175,12,193,238,78,124,126,192,215,242,86,224,19,44,255,123,63,230,89,137,187,174,197,229,108,99,47,110,135,111,218,146,194,222,225,186,208,
130,185,207,183,97,1,218,219,9,97,107,85,12,255,130,9,187,77,166,58,159,68,95,1,174,192,218,220,149,219,4,234,114,215,201,143,8,225,110,205,31,33,170,74,196,47,194,242,196,167,99,145,233,163,81,100,250,
112,132,180,24,37,101,67,31,127,167,139,76,165,188,54,204,189,189,15,203,237,110,118,161,173,58,193,173,76,97,239,57,217,154,128,239,97,125,221,39,82,158,81,163,109,88,46,225,189,88,42,93,115,33,139,4,
8,33,138,34,226,115,129,37,88,86,206,137,152,123,125,34,165,9,226,45,119,107,55,22,215,110,183,108,219,177,243,225,22,96,183,91,188,173,110,229,70,9,11,119,184,22,240,64,175,105,247,159,249,196,45,228,
173,192,102,224,99,197,65,85,154,176,103,38,226,18,224,70,223,73,79,163,60,3,82,130,15,244,181,88,148,253,235,88,116,227,78,137,189,16,37,19,241,57,88,94,248,249,88,158,248,137,190,134,76,160,248,53,52,
202,81,172,25,162,72,31,194,220,214,187,177,88,163,77,88,85,207,189,234,203,33,97,47,244,36,109,192,2,86,254,20,104,34,19,176,82,174,19,40,36,118,190,251,124,130,236,194,206,117,90,124,162,108,0,94,87,
125,123,33,242,90,27,178,27,158,204,193,26,158,196,237,61,211,150,35,30,175,65,157,152,107,122,181,175,53,205,18,105,81,94,194,222,115,34,55,2,151,97,105,114,77,216,121,216,232,10,154,116,81,66,248,33,
19,208,209,10,124,228,155,128,173,100,206,136,52,17,69,218,197,91,13,79,250,94,75,186,176,28,232,3,152,135,240,45,204,107,184,142,10,137,192,22,18,246,236,201,94,71,38,106,245,2,159,236,83,171,100,114,
15,199,117,22,127,253,3,223,12,108,4,222,70,199,0,162,50,69,92,13,79,250,166,211,231,122,171,91,223,175,81,102,249,207,66,194,94,232,197,160,214,23,129,179,129,203,129,207,0,83,82,178,0,100,71,154,198,
222,128,26,247,6,28,244,71,124,12,176,207,55,5,59,49,23,157,181,190,85,158,190,24,217,57,219,8,44,198,42,180,45,116,75,252,40,183,192,227,2,47,105,139,72,143,231,112,135,207,217,253,152,7,111,173,68,92,
164,79,216,123,46,24,51,124,199,127,62,230,174,95,132,185,241,84,206,177,247,2,18,47,156,29,88,196,233,155,232,60,78,20,110,46,102,187,208,227,128,182,5,88,32,91,68,186,123,134,7,50,169,90,205,46,222,
207,99,238,116,205,59,33,97,31,96,113,73,230,199,159,131,185,244,38,74,228,7,92,108,226,27,219,238,11,79,182,229,32,43,95,36,171,177,205,197,92,230,199,98,49,47,147,93,184,143,4,142,33,221,46,244,120,
46,117,251,92,106,193,142,204,94,193,210,101,95,67,199,102,66,194,158,215,66,20,71,208,54,185,200,55,73,228,115,90,168,34,44,104,167,25,88,137,229,241,75,236,43,79,144,235,177,184,148,41,152,27,188,222,
133,120,178,139,241,20,159,31,113,43,209,241,254,220,229,191,105,148,127,156,76,31,211,92,178,243,240,221,88,49,171,53,88,80,219,102,223,28,75,196,133,132,125,4,22,185,43,128,107,176,26,208,71,145,206,
20,153,66,89,37,29,88,90,223,59,88,141,228,154,196,181,140,11,79,196,214,75,7,189,179,25,58,201,20,171,208,107,242,127,205,24,44,53,116,10,153,28,238,184,162,90,87,214,56,175,65,85,214,114,161,27,139,
101,249,196,197,123,185,63,54,171,226,153,144,176,151,94,224,147,81,246,75,128,51,220,114,209,66,151,159,101,159,252,184,16,229,37,245,154,225,191,70,20,206,18,111,197,2,81,223,198,188,85,18,113,33,97,
175,16,145,175,197,154,209,44,1,190,234,98,63,94,183,92,136,84,137,248,1,172,182,196,91,192,211,192,75,192,46,149,50,21,18,246,234,17,251,235,128,91,128,147,73,95,73,74,33,170,149,128,29,111,180,96,45,
55,215,97,145,233,18,113,33,97,79,145,192,55,1,215,99,169,116,179,200,156,89,10,33,202,95,196,219,201,244,201,94,135,69,166,47,7,118,40,189,76,136,180,10,123,70,224,235,176,115,248,121,88,174,252,60,44,
162,120,26,22,73,92,71,239,34,27,58,243,20,162,248,226,29,47,76,135,177,66,47,187,129,55,128,39,177,115,113,229,136,11,33,97,207,91,248,231,3,51,177,180,161,233,110,233,215,147,9,114,74,110,0,36,254,66,
12,93,196,65,13,79,132,144,176,151,145,248,103,87,230,154,141,21,208,57,10,235,80,53,201,45,255,49,244,236,143,28,151,140,85,228,179,72,139,128,171,225,137,16,18,246,170,218,0,196,5,69,142,199,170,124,
205,114,241,159,232,226,127,4,150,154,55,149,76,17,145,56,87,57,187,120,136,54,3,162,220,45,240,118,44,55,92,181,210,133,144,176,139,62,54,3,113,185,207,6,172,196,231,24,223,4,204,240,175,77,68,199,0,
98,100,233,78,8,249,39,46,216,27,49,247,249,6,127,150,11,93,8,9,187,200,113,3,16,151,217,141,91,100,206,193,142,1,38,184,245,159,198,46,91,162,112,214,119,135,63,228,66,23,66,194,46,74,44,248,115,176,
166,30,115,177,115,255,83,177,218,250,199,98,157,242,36,246,213,47,204,201,10,119,144,57,218,137,107,197,215,96,81,231,109,254,232,175,53,176,92,232,66,72,216,69,25,11,126,50,218,255,12,127,52,146,113,
233,199,11,190,74,189,150,254,53,125,137,116,28,120,217,134,117,27,235,34,227,26,111,113,113,142,5,186,29,43,218,178,13,185,200,133,144,176,139,212,9,126,236,210,111,116,171,126,130,91,246,53,46,42,113,
99,146,64,166,153,73,109,150,64,197,95,211,107,10,243,154,195,46,210,59,92,156,213,97,76,8,33,97,23,66,8,33,210,130,90,155,10,33,132,16,18,118,33,132,16,66,72,216,133,16,66,8,81,84,254,31,159,193,142,
198,41,248,190,105,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* Interface::temp_png = (const char*) resource_Interface_temp_png;
const int Interface::temp_pngSize = 6283;
