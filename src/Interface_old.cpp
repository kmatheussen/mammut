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

//[Headers] You can add your own extra header files here...

// TODO!
/*
 * Keyboard shortcuts
 * Fix undo/redo buttons.
 * Fix reload button
 * jpgegify pictures. (less important)
 * Add juce/libsamplerate/libsndfile/libvorbis into ABOUT.
 * Add credit for picture.
 */


#include "mammut.h"
#include "PictureHolder.h"
#include "Interface.h"
#include "juceplay.h"

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
Interface::Interface ()
    : Component (T("Interface")),
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
      internalCachedImage3 (0)
{
    addAndMakeVisible (groupComponent5 = new GroupComponent (T("new group"),
                                                             T("About")));
    groupComponent5->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (groupComponent4 = new GroupComponent (T("new group"),
                                                             T("Save")));
    groupComponent4->setColour (GroupComponent::outlineColourId, Colour (0xb0000000));

    addAndMakeVisible (groupComponent3 = new GroupComponent (T("new group"),
                                                             T("Play")));
    groupComponent3->setColour (GroupComponent::outlineColourId, Colour (0xb2000000));
    groupComponent3->setColour (GroupComponent::textColourId, Colours::black);

    addAndMakeVisible (groupComponent1 = new GroupComponent (T("new group"),
                                                             T("Load & Analyze")));
    groupComponent1->setColour (GroupComponent::outlineColourId, Colour (0xb2000000));
    groupComponent1->setColour (GroupComponent::textColourId, Colours::black);

    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Undo/Redo")));
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xb2000000));

    addAndMakeVisible (stopbutton = new TextButton (T("Play")));
    stopbutton->setButtonText (T("Stop"));
    stopbutton->addButtonListener (this);
    stopbutton->setColour (TextButton::buttonColourId, Colour (0x5cabba2a));
    stopbutton->setColour (TextButton::buttonOnColourId, Colour (0xff4444ff));
    stopbutton->setColour (TextButton::textColourId, Colours::black);

    addAndMakeVisible (tabbedComponent = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    tabbedComponent->setTabBarDepth (20);
    tabbedComponent->addTab (T("Stretch"), Colour (0x3bf8f4c6), new Stretch(), true);
    tabbedComponent->addTab (T("Wobble"), Colour (0x95e0cce6), new Wobble(), true);
    tabbedComponent->addTab (T("Multiply Phase"), Colour (0x6aa9e2d8), new MultiplyPhase(), true);
    tabbedComponent->addTab (T("Derivate Amp"), Colour (0x65fb95ca), new DerivativeAmp(), true);
    tabbedComponent->addTab (T("Filter"), Colour (0xb2e6c3c3), new Filter(), true);
    tabbedComponent->addTab (T("Invert"), Colour (0x617ae7e4), new Invert(), true);
    tabbedComponent->addTab (T("Threshold"), Colour (0x70f7f1f7), new Threshold(), true);
    tabbedComponent->addTab (T("Spectrum Shift"), Colour (0x7dc5e3f9), new SpectrumShift(), true);
    tabbedComponent->addTab (T("Block Swap"), Colour (0x499affee), new BlockSwap(), true);
    tabbedComponent->addTab (T("Mirror"), Colour (0x91d9daff), new Mirror(), true);
    tabbedComponent->addTab (T("Keep Peaks"), Colour (0x84f7e1e1), new KeepPeaks(), true);
    tabbedComponent->addTab (T("Amplitude->Phase"), Colour (0x82e5f8e3), new AmplitudeToPhase(), true);
    tabbedComponent->addTab (T("Gain"), Colour (0x6ef1f2d1), new Gain(), true);
    tabbedComponent->addTab (T("CombSplit"), Colour (0x7bc4ffef), new CombSplit(), true);
    tabbedComponent->addTab (T("Split Real/Imag"), Colour (0x98d6d5ea), new SplitRealImag(), true);
    tabbedComponent->addTab (T("Stereo"), Colour (0xa3d3d3d3), new Stereo(), true);
    tabbedComponent->addTab (T("Zoom"), Colour (0xb0f5f5dc), new Zoom(), true);
    tabbedComponent->setCurrentTabIndex (0);

    addAndMakeVisible (undoredoinc = new Slider (T("new slider")));
    undoredoinc->setRange (0, 5, 1);
    undoredoinc->setSliderStyle (Slider::IncDecButtons);
    undoredoinc->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    undoredoinc->setColour (Slider::backgroundColourId, Colour (0x0));
    undoredoinc->setColour (Slider::thumbColourId, Colours::black);
    undoredoinc->setColour (Slider::trackColourId, Colour (0x79000000));
    undoredoinc->setColour (Slider::textBoxTextColourId, Colours::black);
    undoredoinc->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    undoredoinc->setColour (Slider::textBoxHighlightColourId, Colour (0x401a1aa8));
    undoredoinc->addListener (this);

    addAndMakeVisible (undoredoslider = new Slider (T("new slider")));
    undoredoslider->setRange (0, 0, 1);
    undoredoslider->setSliderStyle (Slider::LinearBar);
    undoredoslider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    undoredoslider->setColour (Slider::backgroundColourId, Colour (0x5ce5f4f5));
    undoredoslider->setColour (Slider::thumbColourId, Colour (0x5c8d8f92));
    undoredoslider->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    undoredoslider->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Duration Doubling")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0x0));
    label->setColour (Label::textColourId, Colours::black);
    label->setColour (Label::outlineColourId, Colour (0x0));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (groupComponent2 = new GroupComponent (T("new group"),
                                                             T("Load & Multiply")));
    groupComponent2->setColour (GroupComponent::outlineColourId, Colour (0xb4000000));

    addAndMakeVisible (correlatebutton = new TextButton (T("new button")));
    correlatebutton->setButtonText (T("Correlate"));
    correlatebutton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    correlatebutton->addButtonListener (this);
    correlatebutton->setColour (TextButton::buttonColourId, Colour (0x88b26134));
    correlatebutton->setColour (TextButton::buttonOnColourId, Colour (0x371ed220));

    addAndMakeVisible (funbutton = new TextButton (T("new button")));
    funbutton->setButtonText (T("Fun"));
    funbutton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    funbutton->addButtonListener (this);
    funbutton->setColour (TextButton::buttonColourId, Colour (0x8ab26134));
    funbutton->setColour (TextButton::buttonOnColourId, Colour (0x3b6eff44));

    addAndMakeVisible (abbutton = new TextButton (T("new button")));
    abbutton->setButtonText (T("A^B"));
    abbutton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    abbutton->addButtonListener (this);
    abbutton->setColour (TextButton::buttonColourId, Colour (0x8ab26135));
    abbutton->setColour (TextButton::buttonOnColourId, Colour (0x3944ff64));

    addAndMakeVisible (hyperlinkButton = new HyperlinkButton (T("http://www.notam02.no"),
                                                              URL (T("http://www.notam02.no"))));
    hyperlinkButton->setTooltip (T("http://www.notam02.no"));
    hyperlinkButton->setColour (HyperlinkButton::textColourId, Colour (0x930004ff));

    addAndMakeVisible (savebutton = new TextButton (T("new button")));
    savebutton->setButtonText (T("Save"));
    savebutton->addButtonListener (this);
    savebutton->setColour (TextButton::buttonColourId, Colour (0x6ed58d00));

    addAndMakeVisible (playbutton = new TextButton (T("Play")));
    playbutton->setButtonText (T("Start"));
    playbutton->addButtonListener (this);
    playbutton->setColour (TextButton::buttonColourId, Colour (0x7da9a335));
    playbutton->setColour (TextButton::textColourId, Colours::black);

    addAndMakeVisible (loadbrowse = new TextButton (T("new button")));
    loadbrowse->setButtonText (T("browse"));
    loadbrowse->addButtonListener (this);
    loadbrowse->setColour (TextButton::buttonColourId, Colour (0x469bd243));

    addAndMakeVisible (loadmulbrowse = new TextButton (T("new button")));
    loadmulbrowse->setButtonText (T("browse"));
    loadmulbrowse->addButtonListener (this);
    loadmulbrowse->setColour (TextButton::buttonColourId, Colour (0x449bd2d7));

    addAndMakeVisible (loadcomboBox = new ComboBox (T("new combo box")));
    loadcomboBox->setEditableText (true);
    loadcomboBox->setJustificationType (Justification::centredLeft);
    loadcomboBox->setTextWhenNothingSelected (T("(choose a soundfile)"));
    loadcomboBox->setTextWhenNoChoicesAvailable (T("(choose a soundfile)"));
    loadcomboBox->addListener (this);

    addAndMakeVisible (reload = new TextButton (T("new button")));
    reload->setButtonText (T("reload"));
    reload->addButtonListener (this);
    reload->setColour (TextButton::buttonColourId, Colour (0x449bd243));

    addAndMakeVisible (convolvebutton = new TextButton (T("new button")));
    convolvebutton->setButtonText (T("Convolve"));
    convolvebutton->setConnectedEdges (Button::ConnectedOnRight);
    convolvebutton->addButtonListener (this);
    convolvebutton->setColour (TextButton::buttonColourId, Colour (0x8aa64f15));
    convolvebutton->setColour (TextButton::buttonOnColourId, Colour (0x3b66ff44));

    addAndMakeVisible (reloadmul = new TextButton (T("new button")));
    reloadmul->setButtonText (T("reload"));
    reloadmul->addButtonListener (this);
    reloadmul->setColour (TextButton::buttonColourId, Colour (0x449bd2d7));

    addAndMakeVisible (loadmulcomboBox = new ComboBox (T("new combo box")));
    loadmulcomboBox->setEditableText (true);
    loadmulcomboBox->setJustificationType (Justification::centredLeft);
    loadmulcomboBox->setTextWhenNothingSelected (T("(choose a soundfile)"));
    loadmulcomboBox->setTextWhenNoChoicesAvailable (T("(choose a soundfile)"));
    loadmulcomboBox->addListener (this);

    addAndMakeVisible (phaseampbutton = new TextButton (T("new button")));
    phaseampbutton->setButtonText (T("Phase/Amp"));
    phaseampbutton->setConnectedEdges (Button::ConnectedOnLeft);
    phaseampbutton->addButtonListener (this);
    phaseampbutton->setColour (TextButton::buttonColourId, Colour (0x4bd8530a));
    phaseampbutton->setColour (TextButton::buttonOnColourId, Colour (0x4284ff44));

    addAndMakeVisible (durationdoublingslider = new Slider (T("new slider")));
    durationdoublingslider->setRange (0, 4, 1);
    durationdoublingslider->setSliderStyle (Slider::IncDecButtons);
    durationdoublingslider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    durationdoublingslider->setColour (Slider::backgroundColourId, Colour (0x0));
    durationdoublingslider->setColour (Slider::thumbColourId, Colours::white);
    durationdoublingslider->setColour (Slider::textBoxBackgroundColourId, Colour (0x37ffffff));
    durationdoublingslider->setColour (Slider::textBoxHighlightColourId, Colour (0x40421bdc));
    durationdoublingslider->addListener (this);

    addAndMakeVisible (infotext = new Label (T("infotext"),
                                             T("Start by loading and analyzing a soundfile")));
    infotext->setFont (Font (55.9000f, Font::plain));
    infotext->setJustificationType (Justification::centredLeft);
    infotext->setEditable (false, false, false);
    infotext->setColour (Label::backgroundColourId, Colour (0x0));
    infotext->setColour (Label::textColourId, Colour (0x72000000));
    infotext->setColour (Label::outlineColourId, Colour (0x0));
    infotext->setColour (TextEditor::textColourId, Colours::black);
    infotext->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (playposslider = new Slider (T("playprogress")));
    playposslider->setRange (0, 1000, 0);
    playposslider->setSliderStyle (Slider::LinearBar);
    playposslider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    playposslider->setColour (Slider::backgroundColourId, Colour (0xffffff));
    playposslider->setColour (Slider::thumbColourId, Colour (0x23ebed9d));
    playposslider->setColour (Slider::trackColourId, Colour (0x58000000));
    playposslider->setColour (Slider::textBoxBackgroundColourId, Colour (0x14ffffff));
    playposslider->addListener (this);

    addAndMakeVisible (normalizebutton = new ToggleButton (T("new toggle button")));
    normalizebutton->setTooltip (T("Also works for playing"));
    normalizebutton->setButtonText (T("normalize"));
    normalizebutton->addButtonListener (this);

    addAndMakeVisible (saveasbutton = new TextButton (T("new button")));
    saveasbutton->setButtonText (T("Save As"));
    saveasbutton->addButtonListener (this);
    saveasbutton->setColour (TextButton::buttonColourId, Colour (0x6ac18400));

    addAndMakeVisible (aboutbutton = new TextButton (T("aboutbutton")));
    aboutbutton->setButtonText (T("Mammut is a product of Notam"));
    aboutbutton->addButtonListener (this);
    aboutbutton->setColour (TextButton::buttonColourId, Colour (0x1fbbbbff));
    aboutbutton->setColour (TextButton::buttonOnColourId, Colour (0x86a15f5f));
    aboutbutton->setColour (TextButton::textColourId, Colour (0xc4000000));

    internalCachedImage3 = ImageCache::getFromMemory (mammut_zerlegentmp_jpg, mammut_zerlegentmp_jpgSize);
    setSize (900, 800);

    //[Constructor] You can add your own custom stuff here..
    /*************************************************************/

    //addAndMakeVisible(graphcomponent=new GraphComponent(componentplace->getX(),componentplace->getY(),componentplace->getWidth(),componentplace->getHeight()));
    addAndMakeVisible(graphcomponent=new GraphComponent(0,0,20,20));
    graphcomponent->setName (T("gnew component"));
    //componentplace->setVisible(false);


    GUI_init(graphcomponent,this);
    //graphcomponent->setBounds(0,0,650,550);
    //graphcomponent->setTopRightPosition(0,0);

    undolevel=0;
    undocurrent=0;
    filename=NULL;

    loadcomboBox->setColour(ComboBox::backgroundColourId,Colour    (0x47422222));//Colour (0x809bd243));
    loadmulcomboBox->setColour(ComboBox::backgroundColourId,Colour (0x47422222));//Colour (0x809bd243));

    //tabbedComponent->getTabContentComponent(0)->setSize(100,200);
    //printf("%p\n",tabbedComponent->tabs);

    tabbedComponent->getTabContentComponent(tabbedComponent->getNumTabs()-2)->setEnabled(samps_per_frame>=2?true:false);

    tabbedComponent->setEnabled(false);
    tabbedComponent->setOutline(Colour(0x00ddf1ee),0);
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

    pic_x=150;
    pic_y=50;
    pic_x2=872-150;
    pic_y2=738-150;
    internalCachedImage3=PictureHolder::getImage(0);

    startTimer(50);



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
  printf("exitgakk0\n");
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
    ImageCache::release (internalCachedImage3);

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

    GradientBrush gradient_1 (Colours::red,
                              50.0f, 50.0f,
                              Colours::green,
                              744.0f, 576.0f,
                              false);
    g.setBrush (&gradient_1);
    g.fillRoundedRectangle (0.0f, 448.0f, 960.0f, 384.0f, 21.5000f);

    GradientBrush gradient_2 (Colour (0x7bf98f33),
                              664.0f, 40.0f,
                              Colour (0xd78c8c8c),
                              720.0f, 560.0f,
                              false);
    g.setBrush (&gradient_2);
    g.fillRect (-8, -24, 976, 864);

    g.setColour (Colours::black.withAlpha (0.2700f));
#if 1
#if 0
    g.drawImage(internalCachedImage3,
		0, 0, 872, 738,
		pic_x,pic_y,pic_width,pic_height,
		false);
#endif
#else
    g.drawImageWithin (internalCachedImage3,
                       0, 0, 872, 738,
                       RectanglePlacement::centred,
                       false);
#endif
#if 1
    GradientBrush gradient_4 (Colour (0x219d2323),
                              16.0f, 736.0f,
                              Colour (0x5f0f1615),
                              696.0f, 752.0f,
                              true);
    g.setBrush (&gradient_4);
    g.fillRoundedRectangle (0.0f, 584.0f, 960.0f, 304.0f, 21.5000f);
#endif

    //[UserPaint] Add your own custom paint stuff here..
#if 1
    g.drawImage(internalCachedImage3,
		0, 0, 872, 738,
		pic_x,pic_y,pic_x2-pic_x,pic_y2-pic_y,
		false);
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
    hyperlinkButton->setBounds (653, 623, 190, 22);
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
    durationdoublingslider->setBounds (153, 667, 144, 24);
    infotext->setBounds (32, 216, 800, 64);
    playposslider->setBounds (168, 612, 256, 24);
    normalizebutton->setBounds (760, 704, 72, 24);
    saveasbutton->setBounds (761, 687, 71, 21);
    aboutbutton->setBounds (664, 600, 168, 26);
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
      MC_synthAndSave(filename);
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
      FileChooser myChooser ("Please choose file to load and analyze...",
			     File::nonexistent,
			     String::empty);

      if (myChooser.browseForFileToOpen())
        {
	  File mooseFile (myChooser.getResult());
	  filename=(char*)mooseFile.getFullPathName().toUTF8();
	  printf("Filename: %s\n",filename);
	  loadcomboBox->setText(mooseFile.getFullPathName(),false);
	  //loadcomboBox->addItem(mooseFile.getFullPathName(),loadcomboBox->getNumItems()+1);

        }

        //[/UserButtonCode_loadbrowse]
    }
    else if (buttonThatWasClicked == loadmulbrowse)
    {
        //[UserButtonCode_loadmulbrowse] -- add your button handler code here..
      FileChooser myChooser ("Please choose file to load and multiply...",
			     File::nonexistent,
			     String::empty);

      if (myChooser.browseForFileToOpen())
        {
	  File mooseFile (myChooser.getResult());
	  filename=(char*)mooseFile.getFullPathName().toUTF8();
	  printf("Mul Filename: %s\n",filename);
	  loadmulcomboBox->setText(mooseFile.getFullPathName(),false);
	  //loadcomboBox->addItem(mooseFile.getFullPathName(),loadcomboBox->getNumItems()+1);

        }
        //[/UserButtonCode_loadmulbrowse]
    }
    else if (buttonThatWasClicked == reload)
    {
        //[UserButtonCode_reload] -- add your button handler code here..
      if(filename==NULL){
	buttonClicked(loadbrowse);
      }else{
	loadFile(filename);
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
      loadFileMul((char*)loadmulcomboBox->getText().toUTF8());
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
      FileChooser myChooser ("Please choose file to save...",
			     File::nonexistent,
			     String::empty);

      if (myChooser.browseForFileToSave(true))
        {
	  File mooseFile (myChooser.getResult());
	  filename=(char*)mooseFile.getFullPathName().toUTF8();
	  printf("Filename: %s\n",filename);
	  char *error=MC_synthAndSave(filename);
	  if(error!=NULL){
	    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
					 T("Mammut"),
					 String(error) + T(" (") + String((const char*)filename) + T(")"));
	  }else{
	    filewasjustsaved=true;
	    loadcomboBox->setText(mooseFile.getFullPathName(),false);
	  }
        }
        //[/UserButtonCode_saveasbutton]
    }
    else if (buttonThatWasClicked == aboutbutton)
    {
        //[UserButtonCode_aboutbutton] -- add your button handler code here..
      AlertWindow::showMessageBox(AlertWindow::InfoIcon,T("Mammut"),
				  String("Mammut is a program for experimental\n"
					 "audio processing, using mammut FFT.\n"
					 "\n"
					 "Signal processing programming by Oyvind Hammer.\n"
					 "User interface programming by Kjetil Matheussen.\n"
					 "\n"
					 "Background picture painted by (help!).\n"
					 "Animation by Kjetil Matheussen.\n"
					 "\n"
					 "Send your comments to k.s.matheussen@notam02.no.\n"));
        //[/UserButtonCode_aboutbutton]
    }
}

void Interface::sliderValueChanged (Slider* sliderThatWasMoved)
{
    if (sliderThatWasMoved == undoredoinc)
    {
        //[UserSliderCode_undoredoinc] -- add your slider handling code here..
      printf("Hepp, %d\n",(int)undoredoinc->getValue());
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
        //[/UserSliderCode_undoredoinc]
    }
    else if (sliderThatWasMoved == undoredoslider)
    {
        //[UserSliderCode_undoredoslider] -- add your slider handling code here..
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
      jp_playpos=N*playposslider->getValue()/1000.0f;
        //[/UserSliderCode_playposslider]
    }
}

void Interface::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == loadcomboBox)
    {
        //[UserComboBoxCode_loadcomboBox] -- add your combo box handling code here..
      static char *lastvalid=NULL;

      if(lastvalid==NULL){
	lastvalid=(char*)calloc(1,1024);
	sprintf(lastvalid,"");
      }

      //printf("Gakk! %s %d\n",loadcomboBox->getText().toUTF8(),loadcomboBox->getSelectedId());

      if(filewasjustsaved==false && loadFile((char*)loadcomboBox->getText().toUTF8())==false){
	if(strcmp("",lastvalid))
	  loadcomboBox->setText(lastvalid,true);
	return;
      }
      filewasjustsaved=false;

      if(loadcomboBox->getSelectedId()==0)
	loadcomboBox->addItem(loadcomboBox->getText(),loadcomboBox->getNumItems()+1);

      sprintf(lastvalid,loadcomboBox->getText().toUTF8());

        //[/UserComboBoxCode_loadcomboBox]
    }
    else if (comboBoxThatHasChanged == loadmulcomboBox)
    {
        //[UserComboBoxCode_loadmulcomboBox] -- add your combo box handling code here..
      static char *lastvalid=NULL;

      if(lastvalid==NULL){
	lastvalid=(char*)calloc(1,1024);
	sprintf(lastvalid,"");
      }

      //printf("Gakk! %s %d\n",loadmulcomboBox->getText().toUTF8(),loadmulcomboBox->getSelectedId());

      char *error=loadFileMul((char*)loadmulcomboBox->getText().toUTF8());
      if(error!=NULL){
	if(strcmp("",lastvalid))
	  loadmulcomboBox->setText(lastvalid,true);
	return;
      }

      if(loadmulcomboBox->getSelectedId()==0)
	loadmulcomboBox->addItem(loadmulcomboBox->getText(),loadmulcomboBox->getNumItems()+1);

      sprintf(lastvalid,loadmulcomboBox->getText().toUTF8());

        //[/UserComboBoxCode_loadmulcomboBox]
    }
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Interface::addUndo(void){
  undocurrent++;
  undolevel=undocurrent;
  undoredoinc->setRange(0,undolevel,1);
  undoredoinc->setValue(undolevel);
  undoredoslider->setRange(0,undolevel,1);
  undoredoslider->setValue(undolevel);
  printf("ai? %d %d %d\n",undolevel,(int)undoredoinc->getMaxValue(),(int)undoredoslider->getMaxValue());
}

char *Interface::loadFileMul(char *das_filename){
  MC_stop();
  char *error=MC_addUndo();
  if(error!=NULL){
    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
				 T("Mammut"),
				 String((const char*)error) + T(" (") + loadmulcomboBox->getText() + T(")."));
    return error;
  }

  error=load_and_multiply_ok(das_filename);
  if(error==NULL){
    graphcomponent->repaint();
    GUI_addUndo();
  }else{
    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
				 T("Mammut"),
				 String((const char*)error) + T(" (") + loadmulcomboBox->getText() + T(")."));
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
  filename=das_filename;
#endif
  char *error=MC_loadAndAnalyze(filename);

  if(error!=NULL){
    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
				 T("Mammut"),
				 String((const char*)error) + T(" (") + filename + T(")"));
    return false;
  }

  MC_resetUndo();
  tabbedComponent->getTabContentComponent(tabbedComponent->getNumTabs()-2)->setEnabled(samps_per_frame>=2?true:false);

  if(samps_per_frame>0)
    tabbedComponent->setEnabled(true);
  graphcomponent->repaint();

  savebutton->setEnabled(true);
  saveasbutton->setEnabled(true);

  infotext->setVisible(false);

  return true;
}

void Interface::timerCallback(){
  static bool wasplaying=false;
  static Image *ims[3]={
    PictureHolder::getImage(0),
    PictureHolder::getImage(1),
    PictureHolder::getImage(2)
  };
  static Random *random=new Random(Time::currentTimeMillis());
  static int countdown=0;

  if(jp_isplaying){
    playposslider->setValue(1000*jp_playpos/N,false);
    wasplaying=true;
  }else if(wasplaying){
    playposslider->setValue(0.0);
    wasplaying=false;
  }

  bool mustpaint=false;

  int time=Time::getMillisecondCounter();

  static int nexttime2=0;
  if(time>=nexttime2){
    const int addval=1;    
    int newpic_x=pic_x+random->nextInt(2*addval+1)-addval;
    if(newpic_x<0)newpic_x=0;
    if(newpic_x>200)newpic_x=200;
    int newpic_y=pic_y+random->nextInt(2*addval+1)-addval;
    if(newpic_y<0)newpic_y=0;
    if(newpic_y>200)newpic_y=200;
    int sizeadd=random->nextInt(2*addval+1)-addval;
    int newpic_x2=pic_x2+sizeadd;
    int newpic_y2=pic_y2+sizeadd;
    if(newpic_x2<872
       && newpic_x2>500
       && newpic_y2<738
       && newpic_y2>500){
      pic_x2=newpic_x2;
      pic_y2=newpic_y2;
    }
    pic_x=newpic_x;
    pic_y=newpic_y;

    mustpaint=true;
    nexttime2=time+300;
  }



#if 1
  static int nexttime=0;
  if(time>=nexttime){
    for(int i=0;i<1000;i++){
      Image *newim=ims[random->nextInt(3)];
      if(newim!=internalCachedImage3){
	internalCachedImage3=newim;
	mustpaint=true;
	break;
      }
    }
    nexttime=time+300+random->nextInt(300);
  }
#else
  if(countdown==0){
    Image *newim=ims[random->nextInt(3)];
    if(newim!=internalCachedImage3){
      internalCachedImage3=newim;
      //repaint();
    }
    countdown=(100/50)+random->nextInt(100/50);
  }else
    countdown--;
#endif

  if(mustpaint==true)
    repaint();
}




//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Interface" componentName="Interface"
                 parentClasses="public Component, public Timer" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.329999983" fixedSize="1" initialWidth="900"
                 initialHeight="800">
  <BACKGROUND backgroundColour="ffddf1ee">
    <TEXT pos="408 312 200 30" fill="solid: ff000000" hasStroke="0" text=""
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <ROUNDRECT pos="0 448 960 384" cornerSize="21.5" fill="linear: 50 50, 744 576, 0=ffff0000, 1=ff008000"
               hasStroke="0"/>
    <RECT pos="-8 -24 976 864" fill="linear: 664 40, 720 560, 0=7bf98f33, 1=d78c8c8c"
          hasStroke="0"/>
    <IMAGE pos="0 0 872 738" resource="mammut_zerlegentmp_jpg" opacity="0.27"
           mode="1"/>
    <ROUNDRECT pos="0 584 960 304" cornerSize="21.5" fill=" radial: 16 736, 696 752, 0=219d2323, 1=5f0f1615"
               hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" memberName="groupComponent5" pos="649 587 200 64"
                  outlinecol="b0000000" title="About"/>
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
          textboxbkgd="ffffffff" textboxhighlight="401a1aa8" min="0" max="5"
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
              bgColOff="88b26134" bgColOn="371ed220" buttonText="Correlate"
              connectedEdges="3" needsCallback="1"/>
  <TEXTBUTTON name="new button" memberName="funbutton" pos="497 667 48 24"
              bgColOff="8ab26134" bgColOn="3b6eff44" buttonText="Fun" connectedEdges="3"
              needsCallback="1"/>
  <TEXTBUTTON name="new button" memberName="abbutton" pos="545 667 48 24" bgColOff="8ab26135"
              bgColOn="3944ff64" buttonText="A&#94;B" connectedEdges="3" needsCallback="1"/>
  <HYPERLINKBUTTON name="new hyperlink" memberName="hyperlinkButton" pos="653 623 190 22"
                   tooltip="http://www.notam02.no" textCol="930004ff" buttonText="http://www.notam02.no"
                   connectedEdges="0" needsCallback="0" url="http://www.notam02.no"/>
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
  <SLIDER name="new slider" memberName="durationdoublingslider" pos="153 667 144 24"
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
          min="0" max="1000" int="0" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20"/>
  <TOGGLEBUTTON name="new toggle button" memberName="normalizebutton" pos="760 704 72 24"
                tooltip="Also works for playing" buttonText="normalize" connectedEdges="0"
                needsCallback="1" state="0"/>
  <TEXTBUTTON name="new button" memberName="saveasbutton" pos="761 687 71 21"
              bgColOff="6ac18400" buttonText="Save As" connectedEdges="0" needsCallback="1"/>
  <TEXTBUTTON name="aboutbutton" memberName="aboutbutton" pos="664 600 168 26"
              bgColOff="1fbbbbff" bgColOn="86a15f5f" textCol="c4000000" buttonText="Mammut is a product of Notam"
              connectedEdges="0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: mammut_zerlegentmp_jpg, 23648, "/div/notam02/u2/kjetism/localdomain/newmammut/Mammut_zerlegen-tmp.jpg"
static const unsigned char resource_Interface_mammut_zerlegentmp_jpg[] = { 255,216,255,224,0,16,74,70,73,70,0,1,1,1,0,72,0,72,0,0,255,225,0,22,69,120,105,102,0,0,77,77,0,42,0,0,0,8,0,0,0,0,0,0,255,219,
0,67,0,67,46,50,58,50,42,67,58,54,58,75,71,67,79,100,166,108,100,92,92,100,204,146,154,121,166,241,212,254,250,237,212,233,229,255,255,255,255,255,255,255,255,229,233,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,219,0,67,1,71,75,75,100,87,100,196,108,108,196,255,255,233,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,192,0,17,8,2,226,3,104,3,1,34,0,2,17,1,3,17,1,255,196,0,25,0,0,3,1,1,1,0,0,0,0,0,0,0,0,0,
0,0,0,1,2,3,4,5,255,196,0,44,16,0,2,2,2,2,1,5,1,0,2,3,0,2,3,0,0,0,1,2,17,3,33,18,49,65,4,19,34,81,97,50,20,113,35,51,66,36,129,82,98,145,255,196,0,22,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,255,196,0,
26,17,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,17,1,49,33,18,65,255,218,0,12,3,1,0,2,17,3,17,0,63,0,209,3,19,96,70,140,24,188,131,232,5,200,57,63,161,1,80,237,253,3,149,120,21,141,43,1,115,252,14,66,106,135,
26,242,16,249,11,147,28,149,9,244,69,53,38,198,221,25,222,199,96,55,49,169,16,52,81,78,67,140,173,236,81,139,126,10,140,46,93,4,108,177,68,61,168,150,150,130,246,21,30,210,31,181,18,192,34,61,168,135,
181,19,65,1,30,212,67,218,137,96,4,123,81,15,106,37,128,17,237,68,61,168,150,0,71,183,16,246,226,88,1,30,220,126,131,219,143,209,64,4,251,113,14,17,250,40,0,158,17,250,14,17,250,40,2,167,132,126,131,132,
126,138,0,39,132,126,131,130,250,40,0,158,11,232,56,71,232,160,32,158,17,250,14,43,232,96,2,226,190,131,138,250,24,0,169,125,10,144,193,0,169,9,43,236,180,130,128,92,85,17,42,52,19,138,96,98,210,240,20,
107,73,9,174,76,42,20,44,56,26,113,99,81,8,201,192,78,6,237,33,113,86,6,45,181,228,35,55,228,210,80,70,115,141,48,20,178,62,133,202,84,5,169,38,128,139,109,81,59,93,22,218,176,208,82,82,147,65,201,142,
190,129,69,176,137,185,118,82,182,90,142,138,81,10,201,93,150,157,13,192,43,96,22,194,129,43,101,48,49,155,222,140,231,108,219,138,187,23,7,32,140,98,153,124,89,172,49,168,149,72,14,119,22,134,162,206,
142,42,133,74,192,194,81,105,232,81,82,179,165,130,136,4,122,43,160,67,1,0,1,64,2,178,30,68,165,64,91,96,153,27,125,143,164,65,77,236,137,187,20,165,98,160,32,83,94,75,100,207,249,2,177,191,136,10,31,
200,237,5,40,186,145,163,149,25,94,236,37,43,160,41,207,97,203,147,34,155,101,164,215,128,38,82,118,36,205,28,83,19,133,1,54,27,160,233,154,70,164,186,8,206,49,189,154,56,150,162,151,67,41,89,172,123,
177,183,90,45,144,192,207,109,129,77,129,4,48,93,9,189,9,48,170,93,131,19,99,237,0,144,50,148,71,196,35,38,9,150,209,45,20,23,98,79,97,66,242,68,104,197,162,83,99,160,164,215,208,169,150,48,33,34,163,
21,123,26,84,48,54,84,150,135,118,103,210,41,73,80,26,38,26,102,47,38,201,230,238,202,55,218,101,35,31,119,91,43,28,236,35,81,12,0,64,48,1,12,4,0,3,0,16,0,0,0,0,0,0,128,27,164,11,99,0,16,12,0,64,48,10,
64,0,2,1,129,2,10,24,20,32,24,145,3,240,2,176,228,3,98,21,219,31,146,129,71,236,117,65,97,96,4,182,57,116,100,219,32,214,193,180,66,118,15,160,9,61,25,201,219,41,221,16,213,0,152,146,108,174,46,173,130,
250,69,13,70,135,197,13,68,27,209,20,149,94,203,84,115,228,154,240,107,137,220,66,52,161,5,133,160,160,98,208,216,2,24,144,194,19,66,76,161,104,0,6,32,25,45,108,119,66,78,216,15,178,144,134,152,12,66,
114,38,82,226,81,77,209,15,36,87,146,147,228,137,113,76,131,57,228,189,35,55,125,134,95,140,169,34,226,151,29,128,162,219,242,90,187,160,164,56,47,32,12,16,73,108,18,1,72,140,157,23,39,178,101,22,250,
0,93,34,100,217,74,45,118,134,162,219,64,39,141,241,180,40,223,147,161,42,51,154,169,0,38,187,27,122,49,109,166,94,57,238,152,80,249,118,83,118,138,109,86,140,27,109,132,54,84,19,177,69,155,66,158,192,
161,160,17,80,50,30,139,108,199,36,128,57,32,50,228,128,138,108,0,0,96,133,97,96,104,152,89,9,141,48,170,178,88,10,194,19,51,95,209,183,102,117,83,2,146,45,32,74,198,20,104,6,160,219,41,193,164,4,208,
120,38,232,86,16,219,104,148,198,36,128,60,143,192,0,2,42,23,100,151,14,192,232,93,12,148,81,80,0,0,0,0,0,8,96,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,136,0,0,0,4,48,96,75,21,132,190,133,95,100,81,99,178,84,
105,141,254,0,236,118,102,237,50,30,70,81,183,32,114,71,63,54,208,115,109,4,173,155,178,82,162,32,223,34,228,194,138,250,23,42,8,177,75,176,46,47,150,134,227,187,35,10,185,89,121,27,232,130,91,176,72,
85,162,171,64,38,201,148,146,67,146,51,146,214,202,50,149,120,55,195,43,137,207,202,219,69,97,127,58,34,99,168,87,186,20,229,197,19,23,108,42,249,34,147,33,87,34,130,174,197,100,248,4,194,14,64,158,196,
149,178,148,107,97,76,150,39,145,38,82,146,146,8,148,84,80,212,71,65,83,187,236,206,92,156,180,106,163,78,217,90,8,136,69,255,0,232,167,20,208,192,8,227,93,17,43,52,108,150,173,129,157,114,237,21,198,
145,162,73,34,56,185,79,240,12,224,156,165,214,141,28,163,22,162,205,18,72,202,73,115,186,176,45,198,250,34,78,145,167,36,144,167,30,75,64,99,219,53,199,209,155,77,104,211,18,117,176,44,18,72,98,242,80,
50,100,172,161,88,24,74,52,193,124,93,154,79,110,136,122,91,32,181,216,165,142,222,132,166,146,216,60,155,92,64,165,136,210,42,144,71,173,140,168,9,146,181,161,74,117,209,60,219,90,236,2,49,105,17,147,
27,108,210,204,231,54,221,32,169,142,36,128,210,61,108,8,172,223,96,210,162,27,26,149,149,42,168,77,7,33,166,4,143,101,42,29,1,42,202,72,105,34,173,34,9,173,145,61,72,167,50,39,82,87,228,43,69,37,64,223,
21,102,49,149,105,154,79,112,236,37,103,254,67,76,188,126,163,147,166,114,201,83,8,90,145,81,215,55,178,68,157,161,162,41,160,232,104,24,5,128,129,0,202,136,146,26,84,192,218,12,208,197,89,164,94,138,
40,0,2,0,0,0,0,16,0,0,0,0,12,4,3,0,1,12,0,64,48,0,0,0,0,0,0,16,192,4,196,250,24,128,148,190,199,69,0,82,104,146,153,12,128,150,204,229,72,166,67,86,2,109,34,75,164,199,72,162,19,166,87,97,86,28,90,216,
15,164,17,92,153,105,41,32,110,56,227,108,129,197,113,20,182,204,253,248,253,237,138,89,100,221,36,81,171,236,45,81,138,148,237,162,148,92,170,200,45,171,71,54,73,110,188,29,90,138,166,102,212,31,130,
142,53,47,145,174,57,164,203,225,4,250,7,141,61,164,67,21,41,69,246,68,38,147,118,14,59,20,161,101,53,164,103,22,244,105,102,24,227,193,236,215,154,178,2,89,18,116,84,118,97,53,82,179,72,100,77,80,27,
42,66,155,117,162,84,173,179,62,77,201,160,33,233,236,120,229,76,114,131,144,163,141,175,0,116,167,104,108,206,23,209,165,0,32,122,29,104,77,1,60,172,92,153,92,82,13,1,22,39,61,210,41,197,182,56,194,157,
176,162,41,213,178,132,222,133,203,226,17,87,100,170,90,39,19,109,236,183,29,216,11,75,67,189,104,77,39,216,226,146,0,171,118,87,66,25,66,98,111,86,57,58,49,147,154,181,90,2,165,150,41,118,102,178,164,
204,156,108,20,120,176,141,212,211,118,197,57,223,70,107,102,145,131,162,43,38,153,209,138,9,69,4,113,253,150,214,180,80,236,27,162,28,184,163,55,145,176,45,213,216,86,180,103,182,107,18,8,216,227,10,
219,42,168,10,0,11,2,14,86,128,108,10,132,199,122,19,208,128,171,41,76,202,202,74,192,209,76,46,201,106,135,18,41,180,75,209,161,18,232,12,165,217,60,154,117,102,208,141,187,125,6,124,105,52,226,84,99,
37,108,22,129,118,18,232,13,99,208,236,207,28,172,178,42,147,41,43,38,37,166,2,170,1,177,20,52,90,37,20,145,5,196,209,25,196,209,0,192,0,168,0,0,0,67,0,16,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,16,88,
88,0,49,89,46,64,55,216,153,46,77,244,9,178,40,113,208,168,37,34,28,168,6,213,3,18,118,13,148,36,217,112,124,137,130,179,104,165,20,2,174,38,121,97,206,52,205,27,94,72,114,253,32,199,30,21,7,111,101,93,
177,221,139,95,101,20,169,13,77,162,83,143,216,165,63,162,7,46,79,98,232,57,203,232,77,191,162,132,193,78,188,133,57,46,132,210,90,173,132,85,183,210,5,109,151,139,147,237,104,219,130,10,230,226,216,112,
149,116,117,82,16,24,60,109,160,142,42,118,109,66,167,100,19,197,46,132,163,82,177,202,208,248,234,192,87,189,13,75,123,26,78,182,28,98,150,192,105,110,203,48,150,104,199,72,112,207,25,107,160,54,16,174,
198,0,26,64,43,176,6,193,237,0,208,18,227,97,196,160,3,41,220,54,136,134,70,229,177,229,82,148,169,25,52,226,202,142,150,180,17,235,100,225,147,146,166,83,214,219,209,21,73,216,156,218,189,25,60,180,244,
75,201,40,189,244,81,173,242,86,97,147,44,164,234,43,162,229,146,41,124,123,102,106,122,232,9,169,190,203,127,24,174,91,98,93,237,132,149,244,65,15,35,229,164,116,99,114,109,89,156,49,54,250,54,225,24,
45,178,163,79,4,78,94,17,14,77,173,116,17,95,100,84,187,110,152,212,54,91,91,5,216,13,34,146,16,89,67,37,149,118,75,219,2,64,114,64,65,206,232,73,137,130,42,27,86,193,133,141,43,1,70,38,137,82,4,141,35,
141,181,176,172,228,180,74,116,116,251,72,199,38,55,29,144,43,19,98,0,8,219,105,27,101,143,196,140,105,45,178,229,146,45,80,28,174,146,34,237,26,207,139,100,168,81,81,158,55,82,55,71,59,212,206,132,5,
13,9,13,5,48,31,17,209,2,76,184,189,153,151,18,141,98,82,20,86,138,32,6,33,149,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,0,0,0,0,0,0,0,33,49,178,91,34,134,196,221,137,160,90,0,216,49,209,50,187,1,93,0,157,209,60,
130,155,86,197,40,80,185,108,165,63,12,34,106,144,127,178,230,233,25,57,20,53,145,69,232,111,51,125,25,85,179,162,48,74,180,17,147,230,217,50,83,93,157,77,82,21,41,45,130,57,226,164,251,52,134,27,237,
154,42,64,230,144,11,217,143,150,15,20,73,228,219,236,168,178,42,148,80,248,199,232,87,69,121,1,113,191,2,246,246,88,57,34,131,72,78,72,206,121,18,232,205,205,180,65,179,154,37,228,137,149,48,171,232,
163,85,49,114,147,232,35,18,212,82,232,131,55,111,182,60,113,147,118,222,141,20,82,84,52,169,80,5,28,249,231,186,55,110,145,193,234,39,242,116,202,6,196,221,108,195,155,189,142,82,181,216,101,188,61,75,
135,123,55,143,170,82,232,243,155,178,177,167,39,72,69,122,75,42,151,146,185,175,7,47,167,139,82,124,141,164,146,218,123,34,182,72,163,40,100,251,52,229,96,54,79,36,14,217,155,78,192,218,52,201,148,35,
45,178,98,220,66,77,180,3,131,138,149,34,115,45,105,132,41,49,229,138,171,40,231,105,80,219,184,80,157,131,77,4,74,67,73,177,197,54,206,152,99,75,100,86,112,196,218,217,164,113,197,22,50,137,111,138,48,
200,236,218,102,109,88,16,158,141,17,157,124,141,8,166,12,16,61,132,36,219,99,21,11,167,101,26,37,160,160,64,2,146,1,128,28,148,58,209,73,7,45,210,2,18,217,164,98,219,22,151,101,195,37,45,32,52,80,81,
86,197,44,209,137,158,92,141,163,149,201,223,97,29,145,206,164,203,202,211,198,113,65,239,70,210,157,194,136,169,18,123,23,128,64,92,164,146,164,96,231,77,216,231,42,145,148,221,178,226,104,230,236,214,
51,209,206,82,101,69,181,115,54,93,25,67,187,54,68,85,34,151,100,174,130,200,173,27,160,93,17,122,42,44,1,233,142,61,131,28,86,192,218,35,18,232,96,49,137,12,168,0,0,0,0,64,48,1,0,0,5,128,192,86,0,48,
21,133,128,192,86,22,3,2,108,153,74,128,208,76,136,74,251,45,129,44,85,99,96,136,164,250,37,20,208,36,0,152,118,58,14,32,42,51,156,87,130,228,152,130,177,161,81,163,141,147,21,78,130,26,220,76,148,92,
157,35,101,105,254,26,65,70,173,20,76,49,46,42,251,47,160,191,163,41,229,169,83,3,70,236,150,232,193,229,108,209,62,81,0,114,111,162,93,190,203,81,101,168,95,100,25,34,238,145,124,104,206,86,21,46,78,
198,178,203,161,43,234,135,194,79,97,18,231,38,28,157,118,87,23,229,23,237,254,1,146,218,31,9,62,145,186,138,94,7,96,100,177,58,216,248,197,22,193,129,47,93,19,200,122,68,216,86,144,118,172,163,60,108,
208,34,103,180,121,153,105,73,175,211,212,104,227,205,135,109,165,217,112,220,113,210,96,226,239,72,233,134,30,45,54,180,78,121,197,75,224,17,207,77,23,138,212,147,68,171,110,205,240,197,74,84,192,237,
140,84,161,126,76,100,234,102,142,92,98,114,100,155,108,138,234,74,150,252,144,178,251,114,167,209,140,243,252,18,242,57,181,40,132,174,213,37,37,104,155,57,61,62,86,165,197,189,29,138,33,69,62,201,87,
39,69,213,13,0,70,41,13,211,236,65,64,68,177,167,180,53,143,91,45,12,162,84,18,240,88,8,33,145,39,69,25,205,236,41,57,108,164,180,70,187,42,233,17,82,214,198,133,217,75,64,1,96,196,130,2,39,52,145,108,
195,36,93,148,111,142,92,145,102,56,109,45,155,54,0,4,182,0,101,29,118,69,252,180,116,52,140,84,87,34,46,224,201,92,80,241,73,116,78,88,91,236,150,227,10,167,178,161,102,151,23,71,60,165,108,232,207,242,
138,104,229,46,38,183,193,217,111,82,163,44,111,137,179,218,178,104,66,110,144,54,41,116,6,45,219,37,232,166,159,208,156,95,209,81,35,31,6,84,49,54,194,175,18,209,170,208,163,30,42,134,64,198,32,34,134,
198,38,244,102,228,251,42,55,76,184,237,156,139,35,251,52,134,122,123,5,118,174,138,35,28,185,43,44,0,98,24,0,0,0,8,0,0,1,1,0,73,66,10,64,0,0,0,0,2,176,102,115,97,68,166,71,38,201,123,28,66,52,131,166,
109,218,50,84,205,23,64,20,58,0,0,97,72,79,98,144,21,104,102,91,42,18,213,48,40,137,233,22,41,45,1,141,219,215,98,171,97,36,147,215,97,23,242,191,0,21,36,246,84,31,104,153,228,183,72,88,211,121,59,3,100,
184,236,202,110,18,191,179,102,79,180,173,254,129,148,49,114,143,225,180,33,72,184,197,37,67,40,149,87,67,109,34,101,36,158,182,197,193,202,86,192,92,165,46,180,10,41,189,246,90,138,76,173,16,74,138,250,
42,132,22,0,0,0,38,45,13,136,2,232,137,59,42,93,17,77,133,46,194,49,178,148,44,209,42,1,70,41,20,38,233,108,159,113,120,8,178,101,85,179,63,113,147,60,141,160,27,138,118,188,28,185,241,46,107,233,157,
56,153,159,171,215,16,107,154,120,156,63,73,141,169,166,142,216,211,138,19,196,175,72,82,22,75,112,179,146,118,153,223,36,163,29,156,57,164,156,180,92,77,100,95,55,84,74,86,83,141,32,20,101,82,179,178,
62,166,248,163,136,105,236,15,89,109,12,140,47,150,52,205,8,164,144,196,221,19,38,5,88,204,236,164,192,161,10,196,5,17,53,96,230,56,187,64,103,180,56,166,217,162,136,0,180,137,109,88,77,209,148,173,244,
6,183,96,68,116,135,96,49,210,242,9,0,12,119,161,8,161,128,128,138,118,99,43,79,94,74,149,166,74,147,186,125,12,53,13,73,173,153,112,118,109,145,87,147,7,45,149,150,137,214,152,170,15,100,118,137,79,96,
108,177,166,28,184,233,144,166,197,55,96,171,114,86,82,106,94,14,116,237,154,227,116,192,210,113,168,218,70,13,201,157,50,119,19,24,238,192,198,86,152,241,183,125,149,146,62,73,199,169,21,29,11,161,161,
164,184,216,25,104,134,2,110,144,10,77,81,15,107,177,73,182,86,52,164,202,136,75,78,136,242,109,43,229,81,90,50,122,123,40,239,244,141,184,29,7,7,165,202,227,46,62,25,222,64,192,0,0,0,0,64,0,64,0,196,
80,0,3,32,64,0,20,9,140,64,77,110,201,156,108,182,70,71,65,89,202,52,17,69,36,218,218,23,65,21,214,205,33,36,204,89,88,238,192,212,104,79,176,1,137,161,128,25,59,176,141,149,40,137,84,123,2,236,153,202,
162,67,157,179,60,205,181,72,5,185,78,145,183,179,241,35,211,193,199,108,222,202,48,120,169,87,147,76,120,212,54,251,41,180,182,103,57,218,32,185,52,250,96,167,209,204,155,251,52,198,165,64,116,137,171,
242,98,167,145,186,170,53,132,93,111,178,160,81,72,99,0,34,118,17,78,138,160,34,138,1,57,25,207,52,82,123,216,26,216,28,112,205,41,74,226,255,0,250,58,99,145,48,27,39,145,119,98,164,192,75,101,40,141,
42,0,0,25,18,96,70,106,113,236,201,235,162,242,127,36,66,60,157,0,83,162,90,55,156,227,8,52,114,99,205,114,124,152,27,166,160,140,61,70,94,77,42,41,73,75,109,153,228,106,77,69,118,6,248,238,145,109,208,
241,66,162,135,56,166,21,151,168,119,138,206,6,142,239,81,252,81,203,12,114,127,36,92,103,89,160,179,121,225,122,116,99,37,76,5,21,201,149,56,241,236,215,210,227,229,43,52,245,56,155,118,8,126,143,47,
254,14,203,60,204,18,227,149,29,252,239,162,40,147,183,161,162,65,48,40,44,145,133,59,176,100,222,193,236,5,219,46,42,133,20,172,108,10,108,86,32,189,132,70,85,107,70,113,179,118,42,216,17,76,164,58,7,
160,160,116,36,202,240,16,128,86,52,180,2,1,208,5,92,162,142,124,177,181,163,169,153,77,81,81,193,150,79,163,43,55,205,22,217,139,77,23,25,52,197,228,16,48,46,27,9,119,178,96,234,72,211,47,218,2,34,173,
232,214,16,149,237,15,211,83,123,58,165,74,36,213,204,114,207,72,33,7,198,199,47,147,72,233,199,26,136,49,203,40,63,163,26,169,30,140,162,153,193,56,212,216,195,113,211,138,60,160,141,22,52,133,131,254,
180,104,69,101,40,35,57,42,84,110,221,178,50,181,90,3,158,168,92,184,190,131,149,200,83,122,162,178,165,150,157,163,41,62,82,178,74,139,166,138,55,244,180,178,83,61,4,113,227,143,41,169,35,173,17,84,0,
0,0,0,0,0,0,2,0,0,19,23,45,208,155,75,201,20,165,58,20,114,125,145,55,98,174,128,223,149,129,156,89,160,8,77,38,13,209,156,164,21,86,145,45,167,34,46,193,32,53,208,67,82,116,66,122,28,30,194,54,108,73,
138,193,1,67,18,29,232,12,167,58,209,156,164,228,57,46,82,191,5,168,104,9,132,13,28,2,42,139,3,54,248,162,110,76,185,118,41,54,163,164,2,106,214,200,104,45,215,233,88,211,242,4,168,111,108,211,26,167,
70,114,140,158,79,195,107,81,64,88,38,74,182,53,162,161,138,130,201,150,68,144,12,156,143,138,50,150,102,250,34,121,126,59,34,150,79,84,214,146,48,82,114,109,253,153,74,73,206,252,21,25,171,42,31,25,69,
242,76,95,228,100,79,178,165,43,70,13,20,119,122,111,85,205,241,151,103,98,60,88,183,22,153,235,97,159,44,105,153,86,194,110,129,7,96,77,216,158,138,147,163,57,61,0,165,178,63,151,104,124,137,110,194,
177,245,28,158,206,127,229,52,214,206,156,145,125,163,158,78,251,69,103,81,21,41,58,71,102,12,28,93,200,159,72,147,111,71,67,150,232,154,184,209,50,114,77,69,11,146,138,217,205,57,115,149,32,106,50,229,
114,209,183,167,85,143,139,68,123,84,191,78,140,13,85,121,64,44,213,12,71,159,253,51,171,213,201,179,28,80,180,228,84,117,250,88,212,44,121,191,144,196,234,9,15,46,224,69,121,205,212,172,235,197,59,138,
103,36,255,0,166,117,250,104,243,198,191,11,169,141,111,64,152,220,82,66,93,17,84,222,133,97,197,177,168,133,17,47,137,61,108,57,187,2,150,129,139,144,251,64,71,108,105,14,134,128,84,3,96,2,100,178,159,
70,110,65,14,202,87,68,69,171,53,1,81,84,43,14,64,48,23,36,0,104,41,43,67,2,142,124,152,190,140,165,135,240,236,104,78,41,129,193,44,26,209,147,214,154,61,62,30,12,61,70,4,213,161,72,225,242,93,218,216,
156,26,237,8,168,211,20,248,51,165,207,156,116,206,52,53,201,116,7,78,56,255,0,201,179,169,42,56,241,100,173,190,206,152,101,139,252,34,169,171,57,178,226,124,173,29,100,180,65,24,215,24,36,19,149,34,
158,140,114,108,1,202,204,167,34,186,100,79,171,42,50,79,176,110,200,125,133,149,12,4,187,42,74,153,71,103,166,190,10,142,165,209,201,232,221,170,59,12,168,24,134,0,0,0,0,4,182,3,16,152,89,20,53,102,114,
137,169,50,216,24,174,246,83,65,199,101,46,194,132,129,206,138,252,51,146,8,115,150,140,89,174,171,68,168,182,21,41,21,37,161,109,51,69,180,6,105,21,24,236,174,8,20,92,93,132,85,14,40,21,131,146,138,182,
3,9,58,71,52,253,67,78,162,67,156,165,217,82,182,156,212,81,49,207,110,140,93,49,85,43,3,186,59,69,28,216,115,166,168,232,187,34,145,50,116,90,20,163,96,96,223,203,70,137,241,91,34,113,226,244,75,110,
182,5,207,39,132,94,54,229,217,140,90,189,157,16,170,208,20,76,164,151,99,147,168,217,207,41,57,48,42,83,109,210,14,26,217,23,69,202,87,16,37,197,38,140,253,68,46,22,141,113,174,79,99,203,173,1,230,56,
180,202,80,250,123,58,222,40,201,166,75,198,177,202,153,82,48,113,146,84,39,138,85,102,217,36,156,106,47,100,127,203,24,95,128,49,151,209,221,232,114,235,131,56,227,23,54,118,122,108,46,18,182,52,199,
104,158,128,76,138,151,217,156,222,139,153,148,157,133,72,14,173,21,28,109,129,41,89,57,240,174,23,84,116,198,9,10,113,231,22,152,28,120,254,43,226,135,146,124,118,187,22,69,40,58,107,68,198,167,145,32,
135,31,115,43,252,52,197,4,164,206,134,148,32,233,28,152,38,222,87,250,6,217,31,21,102,24,243,113,203,248,87,168,145,62,159,23,57,91,232,12,243,77,206,70,152,229,255,0,31,20,182,206,143,241,147,150,250,
46,24,35,0,70,56,211,164,60,146,211,70,141,113,147,57,51,77,217,112,209,135,26,201,57,89,209,134,15,26,164,101,232,191,166,117,45,48,98,101,23,216,70,59,53,237,11,162,5,224,60,131,98,160,164,251,38,75,
99,117,216,71,228,194,28,98,85,133,82,16,3,1,110,202,75,65,72,104,84,79,42,96,91,232,198,107,69,243,180,101,41,88,69,99,73,179,115,28,63,209,171,1,49,48,97,86,21,32,85,0,27,176,0,43,32,67,0,16,154,180,
80,130,178,150,24,201,83,68,47,74,147,58,0,131,7,233,226,68,189,53,45,29,64,202,56,161,133,182,108,176,170,217,178,73,1,4,70,46,58,187,40,0,9,145,140,187,53,155,48,149,167,96,41,19,46,138,110,208,53,162,
163,150,93,146,107,56,179,54,138,133,101,203,249,76,165,130,78,41,162,150,39,237,59,240,22,43,210,79,140,233,249,61,8,179,200,77,166,122,24,50,115,130,126,73,166,58,6,68,100,85,128,192,64,216,0,136,150,
68,136,121,95,128,173,64,80,124,163,101,16,4,182,134,250,57,164,219,147,3,117,216,250,100,99,186,217,160,1,155,76,208,24,25,113,99,86,180,93,0,86,109,54,246,135,20,209,67,232,12,218,147,102,180,235,101,
46,137,201,37,21,176,132,228,151,108,229,205,149,201,215,128,201,36,250,179,59,82,116,84,75,5,38,151,67,234,105,29,78,17,88,250,4,114,243,70,115,155,95,232,218,56,92,182,186,20,241,43,167,36,81,131,146,
77,56,157,190,146,78,80,109,156,144,132,92,233,244,118,227,227,24,84,73,166,54,82,72,57,166,99,82,99,170,68,83,155,182,68,162,214,198,148,158,223,70,188,121,198,138,57,150,244,145,172,50,43,226,251,53,
142,56,197,25,168,71,221,228,128,121,29,170,50,170,52,155,182,43,85,178,9,148,147,66,91,76,206,115,183,241,52,193,110,59,42,8,182,137,205,146,209,121,34,215,71,46,75,79,96,214,216,154,78,219,50,245,51,
228,237,19,22,211,177,201,41,116,182,6,49,109,22,242,201,199,139,54,143,166,125,180,101,40,212,218,40,223,209,197,61,209,221,71,39,164,254,89,209,108,202,170,76,207,109,208,227,114,108,169,70,150,187,
3,57,116,129,65,178,212,87,146,194,161,66,139,210,1,53,176,134,33,131,210,3,41,164,211,82,56,103,23,139,37,163,186,123,70,57,113,243,135,234,40,156,153,249,97,215,102,24,109,124,145,13,53,163,76,111,138,
8,38,156,166,151,217,221,138,10,16,72,227,198,249,102,86,119,214,137,171,134,12,16,1,142,109,43,57,167,7,145,95,71,94,72,220,93,28,210,109,42,46,26,159,73,172,142,44,238,164,121,216,229,199,42,103,162,
159,37,97,48,18,223,208,73,210,102,113,144,85,254,146,230,146,161,74,78,140,152,20,228,219,54,198,170,38,7,68,53,20,64,54,33,131,96,33,161,118,29,0,204,154,249,51,70,201,187,10,206,159,69,123,105,118,
29,178,234,192,168,164,150,132,219,5,125,20,144,17,228,164,134,196,130,4,128,36,233,1,70,194,21,133,132,48,21,131,96,49,18,242,37,42,108,119,123,10,100,242,75,177,217,199,154,78,50,108,14,152,229,140,
165,197,61,154,28,30,149,55,146,206,233,58,67,66,98,110,149,161,71,201,51,214,54,69,24,242,114,187,42,111,71,62,57,82,41,202,194,41,190,70,121,37,197,81,172,18,84,199,56,70,64,114,115,107,180,92,38,106,
241,69,43,96,163,2,145,155,166,101,40,95,70,211,133,116,204,220,171,177,137,171,197,54,151,22,107,253,42,163,158,50,76,214,25,60,48,35,252,107,118,105,142,30,222,147,28,167,72,201,230,216,95,27,221,17,
44,206,15,240,35,37,40,153,100,65,29,144,200,165,11,21,242,103,62,11,166,145,175,58,97,86,224,154,253,51,80,119,69,65,190,91,52,75,109,144,68,95,13,26,221,153,201,34,163,210,1,100,117,19,10,54,205,210,
50,176,54,198,244,81,16,212,81,73,128,49,173,162,28,215,69,193,166,128,104,37,72,25,20,228,192,105,161,249,26,73,14,138,3,44,241,110,58,53,232,77,166,17,201,142,47,202,34,120,234,223,71,99,70,25,34,152,
87,62,40,57,74,254,141,114,122,133,31,137,88,226,162,158,206,60,223,223,97,29,49,245,9,45,163,22,189,217,182,180,140,121,51,171,211,97,121,21,182,81,190,47,79,20,172,213,198,49,233,21,24,241,138,67,163,
42,206,165,47,20,92,96,146,42,134,84,67,133,148,149,42,24,172,9,155,255,0,248,115,225,200,189,201,35,103,36,236,230,113,79,112,238,192,223,36,126,140,170,205,177,207,146,169,118,55,15,160,174,119,20,139,
198,210,39,55,196,49,238,32,109,38,146,56,164,220,242,52,145,190,86,248,179,15,79,146,48,155,230,19,90,195,210,233,89,180,48,198,30,13,33,53,53,104,162,41,120,60,252,250,202,232,244,25,195,234,226,227,
59,240,92,77,63,77,145,69,180,252,157,105,114,71,152,153,223,233,50,114,142,198,153,174,132,169,0,9,176,18,40,72,108,138,154,249,20,32,176,11,161,61,141,236,16,25,76,88,250,217,89,62,42,204,150,104,197,
109,129,143,169,199,198,92,151,70,60,180,116,123,209,200,218,125,24,56,168,205,95,69,65,142,214,68,207,67,220,73,109,156,82,105,201,40,141,218,237,129,215,239,71,236,181,36,252,156,23,69,41,181,180,66,
187,78,108,145,92,197,28,204,187,229,178,171,159,133,182,117,96,149,194,153,18,164,103,12,170,19,105,244,17,211,34,28,117,161,188,145,107,176,230,171,178,42,73,125,142,82,85,161,46,138,28,85,200,216,198,
29,154,217,3,108,158,216,155,216,226,5,36,41,116,48,237,129,12,81,219,45,196,80,84,194,149,80,39,177,176,170,216,13,21,100,167,176,8,114,118,136,140,154,101,8,2,237,128,0,13,101,76,126,226,186,57,85,133,
180,202,142,206,73,146,242,36,115,169,49,113,148,152,82,203,55,41,90,28,50,62,13,54,53,133,253,15,217,107,192,34,176,100,114,147,76,121,48,115,201,111,161,96,131,140,246,116,48,34,24,212,22,133,145,209,
118,70,71,106,145,20,66,122,39,35,184,153,38,211,216,228,244,4,136,98,160,141,113,109,236,165,42,109,51,40,203,136,91,187,40,182,236,117,162,19,43,149,17,83,36,210,57,242,109,126,155,100,204,170,145,139,
151,34,227,58,205,90,52,140,140,228,56,178,163,102,237,23,143,2,171,145,148,90,179,89,101,213,34,42,190,49,210,51,105,201,146,231,70,152,167,22,6,248,97,197,21,44,118,236,19,208,211,35,76,221,169,81,110,
84,134,213,187,20,163,244,4,57,90,47,19,209,155,84,107,143,160,132,223,39,70,50,95,42,54,151,197,182,100,246,236,11,139,113,211,232,209,244,77,124,80,219,72,43,38,169,141,55,30,130,78,216,175,236,35,72,
202,205,34,169,24,226,254,205,103,42,210,2,172,5,118,41,202,145,80,73,236,75,178,108,92,168,138,210,93,24,73,171,166,84,167,163,12,146,249,38,80,77,52,157,51,146,93,236,236,154,227,6,251,179,158,113,184,
114,242,139,137,172,142,207,67,146,159,6,113,26,98,159,9,41,13,71,174,37,26,109,223,100,98,202,178,69,52,246,91,127,68,85,9,186,39,147,19,118,129,13,202,209,46,75,161,165,93,131,73,236,138,230,201,53,
138,117,246,101,57,113,149,197,145,234,91,121,127,209,155,147,127,253,21,26,190,107,228,153,81,245,179,81,166,183,246,99,238,54,111,143,26,148,46,128,151,151,221,74,94,108,209,100,80,86,99,60,124,94,140,
242,234,122,96,122,48,148,114,35,12,254,155,255,0,81,57,177,102,148,89,213,15,81,203,176,167,233,103,74,159,103,82,118,115,184,197,187,142,153,164,100,250,34,173,153,229,140,114,65,175,37,54,210,186,57,
114,228,149,218,77,4,97,40,56,202,142,143,77,202,15,107,76,120,87,63,233,27,99,187,106,169,10,66,158,105,194,245,163,63,127,36,186,70,238,158,164,31,8,104,12,241,229,159,148,95,184,254,132,242,68,202,
121,64,222,50,27,157,51,134,94,161,174,136,126,166,76,21,232,185,163,57,206,73,105,28,95,228,201,178,227,234,221,164,208,11,54,105,75,91,57,219,126,79,66,81,199,145,90,163,147,54,46,44,181,33,225,143,
40,72,81,149,174,18,237,116,111,233,163,199,27,108,229,203,188,141,160,54,196,212,91,190,199,57,38,115,219,66,114,96,107,202,187,232,30,106,84,140,91,177,1,172,114,239,103,86,41,242,129,192,116,250,87,
224,13,242,61,156,153,37,242,58,115,202,169,28,114,219,40,110,114,251,26,203,46,52,72,4,92,114,201,26,195,50,125,156,218,2,43,182,25,23,46,206,139,209,230,38,209,180,61,67,170,144,133,117,119,228,168,
232,231,89,146,54,134,72,201,118,69,105,99,138,20,82,123,40,1,177,120,20,157,25,207,39,22,6,141,104,26,184,144,167,161,198,64,84,86,134,218,39,145,18,151,208,26,90,162,28,136,82,26,216,26,71,96,16,208,
0,70,17,123,20,160,155,42,10,133,37,242,40,35,137,121,45,65,33,196,96,2,108,109,153,205,164,64,148,210,144,242,75,225,104,231,156,182,53,54,227,69,26,71,37,192,46,217,138,145,73,144,173,25,18,232,232,
73,56,163,28,202,144,82,140,83,136,165,26,98,132,252,14,114,208,68,7,58,84,67,144,185,22,37,91,145,14,78,129,182,75,101,25,183,108,34,193,246,34,162,164,201,78,134,32,43,144,249,179,59,24,13,187,236,21,
173,161,80,1,182,63,81,56,249,180,118,226,159,56,217,230,163,191,210,180,224,103,87,29,1,166,58,21,125,17,67,138,98,138,226,255,0,4,229,196,165,37,37,160,38,75,145,139,211,58,58,70,21,108,43,85,184,131,
90,28,87,196,52,6,124,29,18,213,61,155,90,37,211,1,67,110,209,82,187,51,111,139,208,212,235,176,141,19,38,108,78,86,68,164,211,2,221,184,153,74,236,107,51,75,104,20,212,128,205,203,93,152,228,147,53,203,
133,255,0,81,50,140,28,158,205,51,174,136,111,26,179,12,207,225,69,169,241,84,99,145,242,100,93,70,56,57,221,118,132,211,93,157,62,146,59,108,215,46,5,61,174,197,35,147,22,73,99,118,153,232,225,204,178,
199,93,158,116,241,202,46,154,53,244,174,167,67,76,122,8,26,51,182,152,71,42,186,122,34,181,240,38,208,211,19,216,30,103,169,105,229,116,100,206,159,85,15,249,21,118,204,38,156,85,53,179,72,149,118,119,
122,125,42,103,10,214,206,172,57,52,77,49,190,72,42,56,115,65,169,89,232,39,201,25,101,199,104,152,186,243,198,155,71,92,61,55,40,74,215,250,57,229,142,81,151,22,141,36,92,51,184,213,157,152,114,194,125,
118,114,98,244,210,147,217,191,177,28,123,78,136,185,93,84,68,163,23,166,115,175,82,210,106,204,253,233,114,181,178,66,186,241,227,227,43,52,148,146,71,28,125,68,188,132,243,54,132,42,50,103,151,39,76,
135,154,79,182,38,173,216,184,149,15,220,146,20,166,228,14,134,149,244,6,77,48,226,110,177,54,203,94,153,200,82,57,120,138,142,229,232,254,216,63,74,144,164,113,169,201,116,205,22,121,61,73,89,187,244,
233,2,197,143,200,84,47,84,170,156,76,229,145,55,168,154,75,28,111,72,94,218,68,240,103,105,246,133,237,242,233,81,178,130,162,225,22,186,86,129,28,82,143,23,66,58,229,133,54,219,50,150,58,42,49,58,125,
42,50,148,126,141,189,61,199,99,66,245,45,242,57,142,140,205,202,93,24,241,216,18,5,112,14,32,72,21,196,78,52,81,73,216,234,197,26,43,68,18,211,64,164,227,209,117,104,138,216,27,99,245,14,39,76,51,169,
121,60,250,4,218,16,122,82,154,50,147,228,114,172,143,236,223,27,228,232,138,180,56,247,217,162,196,168,203,44,120,53,64,18,158,202,132,92,135,12,124,149,179,104,164,150,128,201,194,145,113,138,75,70,
148,152,82,72,163,58,160,44,8,18,41,8,10,45,9,176,93,10,76,9,148,190,250,48,201,149,114,252,30,118,244,252,28,227,19,85,54,159,65,141,219,161,69,88,162,235,41,67,150,164,92,106,140,243,42,98,131,232,131,
208,143,240,140,179,189,23,117,141,24,102,122,68,86,118,76,164,15,232,205,154,100,219,182,32,26,40,105,232,85,177,163,69,29,16,101,237,185,49,74,14,39,71,65,75,36,63,69,88,228,17,164,226,226,232,138,42,
16,194,130,128,113,139,110,145,111,27,30,6,148,182,116,55,18,85,142,54,154,103,71,166,155,82,39,34,82,122,8,194,81,118,128,244,83,180,51,44,77,241,217,175,131,42,206,108,206,50,113,127,134,146,51,96,107,
39,240,35,26,37,63,6,139,93,5,82,208,169,187,27,16,68,77,53,228,113,139,41,198,202,227,160,38,144,156,74,166,12,8,162,36,169,154,180,103,145,211,2,26,70,107,227,146,139,148,210,71,60,167,242,178,163,182,
46,213,19,197,89,206,178,183,77,27,70,86,136,172,179,70,182,140,59,104,234,204,254,39,47,76,210,59,177,195,140,85,26,165,162,113,111,26,46,140,170,39,141,77,83,71,51,198,241,78,215,71,89,50,216,18,178,
38,137,146,82,102,89,26,131,34,25,190,91,232,66,186,20,165,14,158,138,247,173,25,115,82,116,152,227,56,244,251,2,114,62,82,78,90,98,88,158,73,219,232,185,37,146,54,133,9,56,87,208,11,47,165,85,113,57,
213,227,123,59,63,202,135,146,92,113,230,235,178,137,199,146,205,155,229,18,35,134,17,242,110,146,93,17,112,177,218,91,7,142,50,118,209,98,180,187,1,73,198,8,226,200,229,57,63,163,108,205,185,108,138,
164,17,154,198,168,165,142,138,64,221,0,184,162,100,53,58,123,67,151,86,128,28,46,168,61,150,252,21,142,232,210,228,192,193,250,118,94,44,20,205,225,22,251,52,73,32,38,56,210,240,93,12,207,38,69,4,3,147,
73,28,243,201,186,65,60,209,102,77,216,20,237,190,202,80,104,136,187,123,53,186,242,69,67,66,113,44,76,12,232,184,58,4,137,150,152,69,228,106,142,105,178,229,38,103,87,162,137,108,188,82,104,92,6,146,
136,69,77,145,69,57,42,33,200,184,31,20,52,136,228,90,151,216,65,192,37,2,185,137,176,172,101,26,37,27,74,153,156,145,64,155,67,21,104,126,8,135,68,180,82,123,24,25,26,99,155,132,172,124,67,136,29,47,
212,233,87,101,227,124,190,83,103,15,91,45,100,117,66,45,122,73,166,180,15,163,31,79,43,142,205,91,34,154,14,199,224,69,5,0,208,0,130,201,147,163,37,38,228,65,209,224,206,115,209,51,157,68,194,82,114,
101,43,118,185,227,57,232,232,244,251,77,51,60,176,227,38,17,29,45,24,221,77,51,86,244,99,39,187,42,54,204,174,41,153,69,155,75,229,134,204,240,43,154,76,139,171,121,157,82,221,25,203,36,164,246,116,100,
199,24,201,81,134,74,228,2,187,19,1,149,8,97,67,160,28,75,109,36,71,66,109,176,27,147,147,164,109,138,60,86,204,241,82,43,36,188,34,41,102,143,45,163,158,154,123,71,68,27,242,104,241,41,255,0,176,117,
201,193,191,0,227,71,114,198,146,57,115,38,164,90,68,112,125,160,183,102,216,182,169,162,229,139,233,18,144,176,171,123,71,79,5,71,60,126,38,177,157,198,136,171,210,90,28,101,122,49,114,166,94,57,114,
125,20,92,145,139,236,232,107,70,50,212,136,39,255,0,72,222,142,121,186,105,155,167,201,38,138,4,82,236,145,162,6,218,19,147,240,58,176,226,128,202,83,144,226,219,70,188,80,171,232,4,147,39,44,126,38,
130,154,184,176,56,50,239,70,114,131,72,221,173,216,221,56,236,169,28,208,116,246,111,23,70,83,135,148,17,158,183,217,81,211,81,154,51,158,37,122,50,230,211,211,52,142,69,72,145,107,124,82,226,169,155,
38,159,147,149,101,76,175,114,36,86,243,210,179,154,121,107,94,77,61,205,85,152,229,138,150,209,77,103,57,169,118,98,218,93,14,113,104,205,45,149,150,184,211,110,205,36,152,176,155,81,53,83,9,56,170,45,
180,208,184,143,137,26,102,241,166,17,139,131,180,107,90,19,66,164,85,243,141,174,201,140,165,25,118,40,183,9,90,42,84,254,75,200,27,172,145,251,38,82,79,163,62,55,20,209,54,192,188,171,228,79,130,226,
249,70,159,102,110,211,0,161,52,59,11,42,39,137,112,165,167,209,61,249,42,9,73,208,26,40,83,215,70,145,141,4,99,74,139,68,80,101,147,35,143,70,143,72,231,200,254,208,21,28,255,0,102,89,166,178,58,34,114,
64,146,227,105,236,8,106,138,84,68,155,93,149,22,152,23,162,147,182,37,77,13,34,41,187,37,182,141,18,20,146,10,205,200,77,218,160,146,161,6,81,76,116,90,19,94,80,164,67,98,101,215,216,168,163,39,100,211,
54,113,176,227,162,212,100,145,92,74,170,21,128,150,134,43,37,187,42,42,246,18,90,36,118,2,2,146,27,68,19,69,37,171,8,161,254,0,239,84,75,123,7,209,13,129,84,67,236,57,10,202,55,195,149,197,164,119,39,
113,71,151,23,76,238,193,59,138,178,46,55,147,209,14,84,138,115,70,111,97,85,25,129,49,210,2,5,60,148,68,103,178,105,191,2,166,138,141,39,36,209,149,236,24,168,163,124,18,73,215,217,94,175,254,179,8,58,
105,155,101,126,228,40,131,153,74,226,100,95,86,137,93,149,29,24,183,138,133,129,86,81,122,119,218,52,196,170,109,145,85,145,220,142,105,110,76,218,239,147,49,242,48,210,161,150,227,171,18,69,68,161,143,
72,0,1,208,127,162,212,120,171,96,76,93,45,148,164,155,217,207,57,220,180,28,218,90,17,93,154,100,115,225,45,51,44,109,181,217,19,158,196,74,235,247,211,14,42,123,56,84,153,182,44,173,58,178,69,174,168,
165,16,148,236,81,223,144,113,34,156,18,108,115,74,61,121,37,38,182,107,26,146,216,25,101,198,220,19,70,158,157,53,13,154,82,106,131,174,128,118,99,145,236,183,35,41,189,129,50,219,47,211,203,110,38,109,
217,126,157,165,50,163,167,66,160,108,19,34,154,6,194,200,106,228,80,167,57,39,73,25,94,91,54,148,184,246,56,180,192,33,38,227,190,197,38,246,83,38,82,81,142,217,7,58,113,182,154,31,24,184,153,44,205,
73,218,180,44,153,29,234,139,18,156,223,132,115,228,105,165,93,132,156,251,102,109,219,42,11,31,38,72,5,107,142,87,36,174,142,135,138,109,90,218,56,142,207,73,234,20,126,18,232,128,229,197,124,173,48,
139,179,175,38,40,228,142,143,63,42,150,41,83,1,229,107,164,68,113,201,171,162,82,150,71,163,183,6,23,199,98,145,142,56,52,236,221,38,196,213,58,42,44,116,224,170,2,187,14,33,82,58,84,82,141,148,160,154,
32,194,74,209,10,210,163,163,129,18,198,4,39,46,138,226,218,180,77,52,202,228,215,64,43,166,39,43,99,147,242,34,161,89,18,150,202,155,94,12,212,92,165,72,168,34,165,39,72,236,193,143,130,223,101,97,196,
161,29,173,154,25,107,10,87,197,215,98,199,106,27,31,37,78,133,205,85,203,64,85,94,204,178,85,236,83,245,48,138,211,57,178,103,228,192,89,35,111,68,108,210,50,82,236,50,69,37,174,202,137,110,214,197,25,
37,163,54,221,130,177,7,66,101,38,204,241,191,179,75,85,162,42,148,218,23,53,228,134,246,76,169,244,69,173,116,209,155,34,218,232,78,110,132,42,249,32,191,163,30,67,82,217,98,86,190,66,201,187,37,182,
33,86,216,185,17,98,178,196,166,217,54,22,34,160,24,146,42,128,18,5,216,232,8,26,236,100,244,48,26,211,6,196,186,6,20,61,146,214,152,236,82,117,22,6,96,0,84,84,123,58,112,183,76,228,58,48,206,149,19,85,
188,109,150,145,148,27,147,209,186,84,136,166,213,32,19,96,6,145,199,21,224,37,142,45,116,95,66,40,194,120,126,136,150,23,224,234,160,96,112,56,184,246,92,46,72,223,36,57,68,195,27,169,184,253,129,132,
213,73,145,30,205,51,42,145,11,178,178,188,46,178,81,210,169,38,115,71,82,76,221,180,227,162,106,226,101,168,235,201,156,99,187,101,201,161,38,0,229,162,65,142,42,192,65,79,207,70,181,20,182,99,151,39,
136,128,60,138,61,118,67,155,149,219,34,172,117,69,68,213,178,148,82,237,141,47,36,183,101,23,238,37,26,70,126,64,8,0,10,41,68,163,76,25,92,93,62,142,213,79,179,143,4,62,103,111,7,90,51,173,97,74,53,208,
224,129,92,147,191,3,198,154,236,129,197,239,101,208,171,200,155,160,20,209,207,45,51,119,63,179,12,178,86,49,53,54,56,95,53,68,94,203,199,253,163,72,235,255,0,200,45,33,13,25,104,208,0,20,41,199,151,
98,140,120,244,80,136,19,57,61,76,238,213,232,235,103,159,234,37,242,105,23,19,89,70,110,35,201,53,39,105,18,144,81,80,155,127,100,151,66,106,128,144,24,5,34,160,155,146,72,147,92,46,49,151,39,224,131,
211,199,240,196,173,156,30,174,106,115,77,109,34,50,122,137,207,205,35,37,38,128,223,14,101,141,255,0,39,67,245,127,29,42,56,163,182,116,168,115,143,243,177,160,89,57,154,39,163,157,227,158,39,109,21,
25,216,29,49,101,221,232,231,140,210,52,82,6,53,232,45,153,185,137,100,17,107,97,54,132,164,188,147,63,187,33,132,218,178,27,166,75,116,198,182,6,152,234,110,153,150,84,224,218,26,180,197,146,92,150,251,
42,50,118,117,250,124,85,30,79,179,154,10,228,143,66,58,136,211,5,137,131,105,118,200,148,226,188,145,77,233,82,48,201,20,221,202,69,60,177,107,179,28,146,176,34,92,23,242,136,106,198,226,216,40,190,168,
168,34,154,45,111,76,18,113,236,82,146,76,13,56,38,186,37,197,120,37,100,97,205,94,209,49,77,82,20,147,91,64,213,137,38,152,66,229,125,131,99,113,251,10,176,39,177,52,95,6,28,29,129,149,80,209,183,11,
68,184,81,105,19,29,20,246,133,66,2,73,99,107,98,42,16,232,105,26,113,170,96,37,29,5,90,255,0,70,158,9,233,232,138,20,108,110,63,18,162,83,86,136,50,146,164,132,139,159,72,132,244,80,131,176,4,0,251,39,
33,77,153,73,219,2,64,0,161,154,226,86,204,77,176,63,153,7,102,56,113,86,88,71,161,54,69,0,20,5,29,32,77,142,192,116,75,29,137,128,173,25,75,18,190,75,178,246,46,187,34,185,125,68,109,152,197,108,234,
205,76,230,138,217,113,157,93,22,214,213,10,10,228,141,156,87,33,171,140,38,74,52,113,229,42,72,214,24,43,177,72,231,226,199,20,215,131,175,132,82,23,199,194,37,35,151,132,164,39,128,221,201,41,11,38,
69,21,96,241,205,195,140,168,39,63,20,138,114,228,238,136,147,86,105,16,219,162,70,194,172,33,13,33,164,82,69,9,36,107,138,28,229,68,36,118,122,88,174,55,228,154,184,112,195,196,217,116,49,209,149,77,
88,234,144,232,0,150,101,146,84,105,35,159,38,192,92,173,147,48,90,216,174,217,81,78,63,27,65,143,250,53,154,172,41,163,158,14,164,7,119,132,78,236,34,244,85,145,73,182,129,91,40,16,13,45,12,86,34,130,
74,207,59,212,99,227,38,122,70,30,163,23,56,54,187,67,19,94,106,209,182,24,242,123,50,148,105,155,224,122,42,58,97,233,160,151,68,229,244,241,173,35,76,83,189,51,73,109,25,105,228,228,135,25,16,118,103,
199,118,206,70,169,154,66,17,73,88,56,211,8,144,29,8,42,162,233,217,233,250,105,198,112,253,60,179,127,79,151,219,154,250,32,244,178,99,82,139,77,30,124,240,202,50,103,163,25,41,43,76,156,145,82,95,164,
87,12,96,215,102,169,3,84,193,58,42,69,113,42,17,94,65,83,66,78,130,170,80,213,163,22,218,209,208,166,168,199,35,86,65,157,142,47,100,190,202,8,166,200,171,29,154,98,141,187,125,32,167,135,21,62,76,218,
82,73,24,207,50,78,145,28,219,2,114,55,38,246,200,132,36,222,206,136,227,242,203,81,75,160,68,71,10,107,99,120,81,110,106,40,206,121,117,97,82,212,98,246,87,24,241,179,147,38,102,205,189,60,249,99,105,
149,154,203,212,207,124,81,130,118,246,205,179,65,185,25,44,109,129,74,155,53,225,107,68,70,20,109,29,16,137,140,124,50,168,180,172,18,10,154,177,113,162,220,93,130,79,200,18,145,84,54,128,138,84,41,68,
180,63,5,24,113,23,19,103,29,137,199,97,35,9,199,70,77,29,78,38,126,223,101,70,113,232,210,254,36,168,236,181,16,135,90,33,166,91,208,170,213,133,40,186,102,137,144,144,252,16,41,116,38,170,37,10,76,162,
40,86,50,36,192,82,100,13,178,74,0,0,0,47,27,169,34,10,143,100,30,140,37,113,208,45,178,48,186,129,105,236,43,74,208,18,231,160,3,79,35,125,3,84,45,178,41,114,162,121,132,244,101,202,202,141,57,236,153,
228,34,82,163,55,43,9,68,157,145,211,47,192,154,217,69,225,254,209,179,254,153,24,177,187,179,87,19,58,184,49,197,45,151,41,82,37,124,81,156,228,20,229,43,33,202,136,114,38,82,9,74,83,42,189,200,43,50,
237,157,24,213,104,169,133,237,165,19,9,197,62,142,201,87,26,57,38,169,177,134,167,219,174,194,168,105,136,168,84,58,216,38,59,3,124,24,185,59,125,29,80,130,135,70,30,154,122,163,166,204,180,104,98,24,
0,152,200,156,169,21,19,146,116,140,29,189,142,86,217,164,99,241,34,185,164,201,186,46,81,219,20,98,228,232,168,219,149,225,70,17,237,26,77,241,84,96,229,91,3,189,105,33,153,99,201,25,69,91,43,156,126,
209,21,97,116,102,242,71,255,0,200,46,250,2,236,119,74,201,64,5,242,177,88,147,29,88,28,190,171,26,81,228,145,207,134,92,89,221,234,99,255,0,19,60,213,42,209,113,53,220,174,45,53,209,178,153,205,134,126,
25,167,42,116,200,43,34,179,135,52,41,157,146,146,163,28,170,209,112,212,44,53,198,75,166,107,60,41,228,143,250,53,244,245,40,71,240,219,138,187,37,87,14,95,76,214,209,207,40,184,246,143,82,115,138,253,
57,115,99,231,190,139,154,142,49,142,112,112,123,34,202,58,48,250,137,99,213,232,232,121,213,118,112,88,249,106,137,7,106,151,62,134,114,250,124,148,235,236,218,232,138,211,149,7,43,57,231,144,188,115,
183,69,70,182,68,153,105,88,56,18,172,103,69,81,106,37,56,82,37,88,201,45,132,164,250,69,75,226,140,146,114,101,69,168,89,180,96,162,133,20,162,182,246,97,60,255,0,48,113,213,96,218,50,197,62,65,146,105,
17,81,154,116,232,207,36,223,26,38,77,202,86,70,75,52,203,55,182,116,224,212,89,150,56,114,102,253,42,67,67,230,155,166,76,210,75,68,74,59,176,108,129,114,41,76,206,64,139,6,235,33,75,42,179,157,200,150,
196,43,183,220,67,230,142,46,116,30,227,16,175,67,82,68,241,163,151,30,102,145,188,114,166,136,181,77,133,153,202,72,74,65,27,7,100,38,82,97,69,18,209,77,211,19,118,6,117,176,93,49,177,116,17,37,71,161,
37,118,202,136,10,132,244,104,200,145,68,221,17,38,91,50,147,8,19,211,34,76,119,72,135,178,128,67,0,164,3,16,0,208,2,3,171,20,180,105,200,231,198,205,81,17,78,86,4,88,1,222,221,177,167,72,197,74,135,201,
134,147,147,228,204,218,226,111,106,140,178,116,6,82,118,36,134,162,80,66,163,76,120,173,219,30,60,119,182,111,209,20,146,165,160,97,100,206,73,32,172,231,38,97,41,59,43,38,75,232,198,221,236,185,140,
238,155,147,33,182,55,216,138,135,19,88,206,140,83,26,96,108,242,17,39,100,216,0,132,198,20,80,168,101,251,114,113,178,8,52,199,42,145,221,9,90,60,232,247,103,92,30,147,38,174,58,80,19,25,90,42,200,166,
115,229,149,121,55,108,226,207,53,202,128,210,27,217,114,151,24,232,136,82,198,153,148,167,108,20,114,187,12,114,169,25,183,177,91,76,169,91,250,134,171,93,156,179,122,43,38,78,76,201,187,42,14,77,121,
4,229,246,36,90,104,4,185,89,219,142,105,65,35,153,14,218,3,174,45,22,113,115,149,21,28,210,68,139,93,107,101,116,142,120,231,69,74,110,74,211,34,140,214,224,209,193,40,212,168,211,46,103,202,147,33,77,
57,39,36,84,117,123,127,4,215,104,202,83,125,51,120,206,46,41,222,140,242,198,50,122,236,26,199,220,149,108,209,59,128,148,47,95,69,172,117,26,42,43,14,78,41,175,37,185,74,71,58,168,206,153,79,58,90,68,
86,213,173,147,39,173,25,251,181,217,147,204,216,133,105,52,164,190,71,44,149,51,84,219,51,159,101,68,128,1,20,226,233,217,219,24,123,152,249,35,132,244,125,34,172,46,201,171,142,73,227,119,209,174,28,
116,205,154,216,226,182,42,197,194,37,208,147,81,70,82,200,249,90,34,174,74,153,156,242,87,68,201,202,76,133,23,123,43,59,163,114,255,0,69,57,44,104,110,161,27,103,44,242,41,48,30,76,142,244,204,249,54,
237,137,129,164,117,226,154,81,187,35,46,78,79,70,10,250,58,49,194,210,108,200,188,113,92,122,48,202,238,84,142,153,124,96,206,69,253,108,163,88,124,81,77,218,51,114,217,74,90,32,77,146,250,177,190,236,
150,252,20,12,4,1,12,150,50,89,64,196,49,0,89,74,109,18,32,173,86,70,92,38,154,48,26,116,65,213,25,20,164,115,70,91,52,76,131,86,236,17,49,101,216,3,232,206,122,70,158,8,146,176,4,244,17,149,9,232,153,
104,163,89,73,25,202,102,124,236,77,216,69,169,89,18,236,19,37,178,132,217,35,0,0,0,0,0,0,0,64,52,6,176,52,236,207,25,178,68,16,5,240,1,72,214,246,57,51,21,38,216,229,38,158,202,181,106,123,19,123,51,
78,199,202,129,84,216,224,185,61,144,157,162,226,232,138,233,74,186,6,16,118,144,217,21,134,76,174,46,168,201,185,204,223,44,121,18,149,99,176,142,118,168,134,105,47,228,205,51,76,165,246,34,154,10,40,
145,142,133,64,3,10,27,64,35,108,88,249,51,36,142,204,107,140,81,53,113,113,138,74,140,51,96,221,163,162,236,59,84,101,92,60,105,211,58,224,151,19,44,208,167,104,81,200,210,162,245,56,209,201,193,217,
113,207,25,121,163,41,54,227,97,28,74,80,180,69,94,92,181,211,56,228,219,144,100,140,163,45,145,200,214,51,173,249,190,21,100,9,59,44,9,171,6,139,122,68,48,51,113,216,113,41,177,120,2,26,166,47,38,170,
14,75,64,177,211,218,2,21,173,148,185,51,120,194,47,193,162,132,80,171,28,201,75,232,190,14,95,134,244,134,74,71,63,181,244,95,182,218,166,218,47,201,94,9,86,57,255,0,197,191,34,126,155,125,157,59,66,
98,145,154,198,163,26,18,143,203,65,41,171,163,69,29,88,3,141,108,125,45,137,191,179,28,249,26,248,160,50,205,183,104,201,58,118,57,49,108,211,38,221,187,1,8,10,177,61,160,74,221,27,71,18,160,172,0,114,
143,23,66,32,168,43,103,124,31,255,0,25,165,224,243,226,234,71,126,11,246,229,125,52,4,66,86,169,130,147,82,102,46,116,218,69,227,231,45,136,55,143,41,45,154,40,36,137,138,104,167,42,70,90,13,34,37,72,
78,100,43,147,42,82,204,212,177,213,237,28,148,109,150,53,38,68,171,73,26,196,66,67,81,216,21,16,139,132,45,157,41,113,137,56,97,74,217,89,26,170,50,212,99,149,217,133,27,79,102,114,209,81,45,80,211,33,
130,123,40,213,58,19,65,29,171,27,122,162,8,98,45,170,68,209,80,155,16,217,32,0,0,0,2,0,166,2,2,10,78,138,82,250,51,26,116,7,68,89,74,71,58,155,69,198,119,217,32,221,48,178,20,180,22,154,0,178,38,202,
100,75,162,162,47,97,100,176,178,138,178,88,88,0,0,0,0,0,5,0,0,16,193,8,0,223,17,209,5,103,46,29,200,236,130,51,173,98,212,80,0,20,68,113,167,209,51,199,189,154,39,64,221,176,51,88,91,232,153,96,146,54,
183,90,28,114,107,96,114,171,90,104,28,141,167,87,162,92,20,149,132,86,25,186,217,186,118,114,241,113,218,54,199,43,10,209,152,228,117,10,55,70,121,113,242,141,162,43,149,255,0,38,116,106,211,74,136,163,
76,4,42,42,130,128,148,62,35,161,164,4,214,192,190,12,165,141,253,10,66,197,21,203,103,77,81,148,113,181,224,210,164,101,165,33,160,140,95,148,55,23,122,2,50,58,93,24,37,187,173,29,50,141,163,12,175,142,
146,3,72,164,215,225,164,82,74,145,207,142,84,141,227,43,65,89,228,130,145,201,147,19,142,207,65,164,204,231,11,66,166,227,129,58,99,228,217,121,113,113,118,140,214,153,166,86,155,0,93,0,9,161,23,42,37,
1,215,131,26,224,180,78,120,164,94,44,139,219,95,102,121,101,200,138,133,37,66,229,39,209,20,223,72,168,166,152,69,197,201,61,154,173,138,49,252,25,26,135,66,21,131,116,20,219,163,60,153,41,10,121,18,
137,207,57,114,118,92,103,117,174,8,115,157,248,58,50,61,168,163,63,78,248,227,43,245,145,81,150,73,35,154,115,178,242,187,118,101,78,79,72,211,41,52,198,173,244,84,61,60,159,103,84,61,58,138,37,88,205,
97,139,93,9,250,111,163,116,212,65,228,65,124,115,251,20,75,140,163,228,214,121,82,221,156,249,50,185,189,4,44,141,56,254,153,21,76,18,42,8,233,217,179,207,57,71,138,210,34,49,76,223,30,36,77,84,99,199,
103,78,56,210,28,98,145,77,232,150,181,153,10,76,205,216,57,17,41,132,212,201,238,141,161,241,137,207,27,229,103,67,151,196,106,99,44,149,185,51,153,59,145,209,40,74,111,240,210,30,157,37,178,210,57,90,
111,193,112,134,246,116,184,197,120,49,158,186,20,145,171,154,140,82,70,82,200,140,164,239,201,12,66,174,83,179,54,216,210,27,142,138,136,98,24,80,85,99,149,74,188,29,14,9,236,230,73,223,71,92,83,113,
86,65,140,145,12,218,72,201,208,193,12,67,109,8,160,11,16,0,0,1,0,0,0,0,0,0,82,76,72,44,163,68,235,177,217,144,226,65,179,127,19,57,48,178,91,42,16,0,0,0,0,8,6,1,72,98,0,1,136,0,96,0,17,182,15,236,235,
137,197,139,250,58,226,201,170,209,0,144,5,32,15,33,97,2,31,98,41,116,21,14,54,21,170,46,209,23,176,138,130,211,7,26,218,42,14,180,57,133,16,149,154,89,141,106,209,164,31,199,100,84,228,196,164,173,25,
60,31,166,147,155,233,19,109,32,136,120,154,5,137,191,5,251,159,36,116,170,162,158,57,225,233,254,205,22,24,163,96,5,102,177,69,120,43,130,250,40,2,21,32,161,128,8,40,96,2,162,94,56,190,209,96,6,47,10,
240,67,199,40,189,29,32,69,172,98,223,146,154,180,93,32,160,87,60,241,218,57,165,134,153,232,56,144,225,176,117,195,84,20,118,60,113,126,9,112,130,45,72,227,98,54,201,137,167,107,104,199,253,149,27,98,
135,35,119,137,81,30,151,104,232,102,90,198,17,130,69,40,164,44,141,167,162,20,237,108,13,109,17,61,34,28,235,100,188,156,149,8,84,188,180,232,156,153,126,140,228,157,178,120,179,81,144,228,216,135,73,
33,172,109,248,3,163,19,255,0,141,21,41,106,137,138,168,164,103,146,84,69,26,150,68,142,184,98,138,87,70,30,154,31,250,103,76,165,162,106,224,109,71,163,57,77,176,147,213,179,155,46,103,210,6,140,153,
90,117,19,39,57,63,36,216,127,179,76,139,1,81,73,126,88,5,50,227,138,79,101,66,18,126,14,156,88,223,146,110,174,99,44,120,119,179,162,48,163,69,20,136,201,42,232,207,90,224,108,205,133,178,89,83,117,50,
100,37,102,138,46,93,27,67,26,143,108,169,24,70,15,232,214,56,155,236,217,56,162,37,55,122,102,90,10,20,57,53,68,57,74,78,139,81,75,182,6,50,182,103,40,73,157,111,141,25,205,164,82,57,189,150,201,150,
38,141,156,131,149,138,145,135,31,193,52,206,165,76,78,40,82,57,184,223,130,163,140,210,146,24,168,81,138,47,164,77,138,76,43,60,178,222,140,168,169,81,13,154,100,218,72,155,6,196,20,0,1,0,0,0,0,3,101,
8,0,0,0,0,0,105,136,0,118,33,161,241,8,64,149,140,112,236,1,65,249,27,137,178,68,180,65,131,2,165,26,100,148,2,24,5,33,136,96,3,16,194,43,31,244,142,168,51,146,61,157,24,229,162,13,211,3,39,32,10,218,
75,100,149,62,194,40,41,40,182,105,24,82,216,47,136,249,125,1,46,8,154,44,150,64,226,139,106,209,49,139,102,202,52,6,75,27,99,148,56,195,70,160,10,227,114,73,147,60,155,248,157,25,48,41,109,24,60,50,139,
232,168,48,37,41,83,59,82,164,115,195,11,77,72,232,176,24,19,201,11,154,2,192,142,104,94,226,3,64,50,247,3,220,3,80,50,247,3,220,34,181,3,37,144,126,226,4,104,4,41,166,28,209,81,96,74,144,236,6,0,0,42,
70,114,199,102,160,7,43,140,160,255,0,12,179,66,246,142,230,147,33,227,86,78,43,155,211,70,75,181,163,166,190,217,50,154,130,209,146,148,164,192,215,34,74,22,112,74,109,189,29,62,162,109,66,145,198,159,
217,113,53,84,223,108,190,36,169,43,52,147,74,54,130,37,197,71,108,149,82,125,210,37,202,83,102,152,241,62,217,69,71,28,126,141,41,80,212,75,227,163,45,48,147,209,130,78,115,58,103,13,104,207,28,56,207,
101,196,141,163,240,142,129,111,177,178,94,136,165,146,84,153,195,55,108,235,154,179,158,113,162,226,107,48,6,50,162,147,75,193,180,58,50,132,121,51,166,16,81,38,174,47,26,251,52,229,196,207,149,9,200,
204,106,173,205,182,39,179,59,14,85,228,177,42,201,105,177,65,55,216,178,73,221,32,31,54,245,29,26,40,58,219,51,130,226,172,209,101,87,176,29,22,177,153,169,167,35,165,53,68,90,205,198,140,164,232,215,
36,254,140,36,193,67,145,148,164,18,145,155,150,139,152,155,167,97,202,140,220,132,228,88,141,212,193,229,57,249,48,228,32,213,205,177,198,108,199,144,114,3,161,75,236,153,72,199,155,23,38,32,166,201,
21,129,64,0,0,0,0,0,0,4,0,196,5,0,12,0,64,3,1,0,0,21,17,176,72,109,4,73,164,17,153,164,24,27,36,14,33,30,129,217,21,156,213,25,51,89,217,147,69,68,128,0,8,96,0,3,1,164,0,138,140,168,73,13,32,47,149,128,
227,141,181,208,16,117,201,108,112,170,96,208,36,70,131,118,56,161,121,52,138,176,39,139,101,44,127,102,137,80,202,82,74,134,2,8,98,177,57,17,41,145,86,217,46,72,205,204,206,83,3,103,144,151,144,195,144,
91,108,165,104,230,46,68,165,178,168,7,200,86,22,144,114,137,3,216,108,92,227,246,15,34,1,236,1,77,48,228,128,54,27,26,101,166,130,179,218,66,182,141,233,49,74,9,129,151,39,101,44,140,30,58,232,150,154,
3,120,205,22,153,204,147,53,199,117,176,141,64,68,202,84,84,55,42,49,201,144,156,153,60,34,99,27,219,34,132,156,182,205,35,26,28,81,113,137,23,142,60,241,155,119,90,57,154,105,158,195,138,107,104,202,
120,35,37,209,172,214,94,101,179,72,198,83,71,79,248,252,95,86,141,32,163,21,208,164,97,143,26,138,235,102,177,198,223,101,221,62,139,82,84,70,145,195,101,53,162,180,39,64,96,237,61,145,40,219,209,208,
208,40,160,57,91,154,236,165,43,71,67,130,100,60,95,66,164,96,228,115,228,109,179,174,88,239,193,140,176,63,5,205,55,28,160,105,44,114,139,232,154,104,172,174,15,90,41,101,105,152,166,59,3,127,119,66,
228,236,156,112,148,223,225,213,28,113,81,216,88,202,48,156,247,209,162,132,99,182,246,18,203,90,70,113,82,155,252,32,217,201,86,142,118,220,166,109,37,198,36,99,135,38,232,26,137,229,113,84,187,38,45,
211,147,22,104,181,146,135,20,228,210,240,138,141,112,69,183,111,163,92,179,117,161,165,198,26,49,157,179,45,33,229,119,177,123,182,130,81,73,24,189,61,22,34,165,54,200,114,177,49,21,14,196,0,20,0,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,192,67,1,0,0,26,69,148,214,140,225,217,173,232,35,38,138,128,72,75,176,58,35,208,204,226,203,162,9,145,140,147,53,150,136,108,163,48,27,16,0,0,192,99,0,0,70,216,
49,243,151,225,138,236,237,135,195,6,187,99,87,21,146,81,140,42,32,99,59,164,1,29,41,131,104,206,83,80,70,113,148,167,34,70,171,166,17,182,108,180,76,35,73,20,13,48,16,54,16,54,68,164,41,72,205,200,138,
114,145,155,144,49,85,129,45,177,83,101,208,158,144,9,32,114,140,72,148,157,104,198,77,182,106,37,108,243,125,17,238,201,249,35,98,42,41,201,191,32,164,195,64,154,64,84,77,53,70,46,95,67,140,155,100,27,
33,209,48,116,105,200,5,177,166,208,237,8,138,181,147,236,181,36,250,102,53,101,199,28,130,174,246,85,88,227,142,187,47,72,133,74,130,67,109,33,74,105,24,100,204,188,1,172,242,28,243,200,228,233,19,242,
155,52,140,40,18,166,49,242,205,99,27,26,138,14,84,69,226,214,139,70,105,162,211,42,106,128,65,116,84,13,164,182,99,38,187,69,202,113,163,157,164,221,173,17,90,41,254,15,146,33,12,42,155,73,118,10,86,
103,39,98,139,216,70,173,141,50,27,18,149,1,115,186,209,49,147,233,137,228,167,248,84,100,159,64,63,35,73,63,3,208,148,145,26,15,26,126,12,231,233,227,36,108,154,24,71,159,147,210,201,61,116,24,253,51,
238,71,161,65,73,162,221,73,140,35,24,165,164,55,27,69,184,53,209,60,89,21,159,180,188,148,146,138,27,139,38,105,129,50,249,46,200,77,194,69,36,217,92,23,108,181,35,25,46,114,186,46,17,162,157,37,208,
147,176,52,147,209,140,153,119,70,83,144,195,81,54,98,202,156,136,102,153,43,16,196,20,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,16,202,16,0,0,26,41,25,148,187,8,166,8,105,128,23,20,104,180,
103,18,164,233,16,55,76,198,75,122,9,76,155,178,132,192,2,192,69,33,34,144,0,48,5,176,28,86,206,217,43,132,81,150,31,79,202,164,206,137,170,141,17,92,249,52,128,89,94,232,10,136,156,156,164,116,250,88,
106,217,202,183,45,30,134,21,81,67,87,26,128,1,0,75,101,145,36,69,198,114,102,70,178,68,52,21,52,62,150,192,206,77,202,85,224,168,190,200,101,164,76,157,48,48,157,153,155,207,229,209,139,84,205,99,37,
96,0,144,64,192,116,20,2,52,199,27,100,168,55,224,232,199,137,232,155,171,152,153,71,136,210,118,116,44,86,182,105,28,73,18,172,115,71,28,153,172,112,179,116,146,11,3,56,226,72,211,72,153,77,35,41,228,
10,213,205,35,25,230,250,51,114,108,35,11,123,2,92,165,33,198,27,53,142,51,72,194,137,72,136,66,139,232,167,162,123,34,162,79,232,131,103,20,200,112,162,132,138,82,104,134,154,11,3,104,201,50,180,204,
19,161,243,104,11,112,167,248,99,37,76,83,204,218,51,77,201,246,17,105,131,154,68,75,240,201,178,196,173,156,210,68,123,180,204,156,136,189,150,37,117,251,138,75,244,92,206,116,232,174,66,21,171,146,107,
177,70,77,116,101,118,53,38,128,232,142,70,135,41,121,48,82,27,146,102,98,214,209,203,69,44,167,48,214,159,98,21,215,238,90,46,51,251,57,98,218,47,153,26,116,169,2,166,97,9,253,154,235,195,2,154,72,151,
66,148,209,28,175,200,4,191,8,101,146,232,42,4,216,217,45,21,150,115,157,25,74,108,214,80,49,148,75,140,165,182,197,76,186,19,69,18,20,58,16,8,6,1,64,48,0,16,12,0,64,0,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
12,64,80,0,192,0,0,64,93,142,200,11,8,213,72,167,43,50,76,44,7,45,146,12,0,0,0,0,126,4,54,0,52,33,160,61,15,78,239,16,231,228,61,58,172,72,39,217,21,205,37,121,0,209,71,229,96,8,194,31,218,61,28,127,202,
60,200,118,143,71,23,240,139,166,53,25,40,162,0,77,12,0,134,140,154,55,37,193,50,45,115,190,140,182,157,157,82,198,71,180,239,161,72,73,124,108,202,111,103,79,7,198,140,222,22,193,174,103,222,137,104,
234,255,0,28,165,233,215,146,212,142,46,45,148,177,201,248,59,86,8,162,214,52,133,38,56,227,233,219,53,135,166,251,58,106,130,201,85,17,195,24,248,45,69,32,177,57,32,40,44,205,204,135,32,52,115,34,83,
37,216,36,4,187,97,198,203,80,178,212,2,179,140,13,84,6,149,3,146,64,58,72,78,95,68,221,141,32,0,161,137,178,9,110,138,78,194,147,41,36,138,132,226,153,156,160,106,68,230,163,216,25,52,194,93,20,178,66,
78,147,39,51,227,0,174,89,201,242,164,105,13,25,69,252,173,154,185,36,86,74,127,134,18,187,52,150,68,101,41,89,113,9,146,62,194,138,0,65,69,194,13,144,40,217,162,140,154,232,184,67,237,27,40,232,155,171,
152,230,246,228,28,26,58,184,18,225,100,171,28,220,93,20,147,53,112,14,58,45,72,155,209,81,64,162,90,68,107,48,210,13,208,3,100,82,104,64,216,172,7,108,77,137,177,88,67,176,177,9,186,8,100,184,166,53,
47,177,232,162,56,34,92,18,53,180,39,176,57,230,168,138,58,28,83,33,192,210,50,104,69,202,36,208,66,24,33,128,132,80,128,66,24,5,32,24,128,0,0,128,0,0,0,0,0,0,0,0,0,0,0,0,26,0,2,128,0,64,48,16,194,24,
0,88,0,0,0,0,12,2,135,67,138,43,136,17,67,138,249,34,212,77,33,13,129,217,141,124,16,112,182,60,127,202,44,141,51,148,52,5,54,0,121,113,211,59,176,207,226,142,6,116,224,149,170,46,166,59,19,217,86,98,
153,77,232,202,181,177,153,41,20,164,82,40,100,242,29,132,48,21,138,192,97,66,176,178,41,129,60,137,114,2,236,12,249,146,230,6,188,146,37,204,207,147,98,176,171,115,23,34,70,149,129,44,105,89,162,135,
217,84,144,25,168,178,210,11,11,2,186,19,146,68,74,68,216,20,230,216,47,209,34,128,164,22,77,138,192,182,254,132,150,197,108,151,54,6,186,68,172,151,42,51,148,245,182,103,238,171,236,35,169,179,155,59,
209,75,34,146,236,199,212,127,55,96,96,185,57,104,214,115,248,84,157,153,70,235,68,54,205,50,180,194,82,33,9,176,6,196,29,141,34,129,20,172,20,91,240,105,28,82,126,8,38,49,111,193,172,34,215,130,161,138,
72,210,48,126,73,186,214,96,130,179,120,197,81,149,52,251,41,77,153,85,184,146,213,7,43,11,176,169,226,75,70,162,123,3,22,128,214,131,84,4,173,138,75,65,37,68,185,1,45,18,91,146,37,132,210,21,142,130,
232,168,125,131,66,82,76,27,209,20,154,4,180,36,239,177,241,42,19,65,180,62,33,65,10,244,75,40,137,50,136,145,12,166,236,77,21,18,52,130,130,192,108,144,236,0,0,0,40,0,0,16,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
0,0,5,0,0,0,12,64,3,24,134,16,32,1,128,13,32,69,194,54,192,34,141,84,116,53,3,69,18,42,84,44,215,30,61,141,35,72,34,42,146,160,99,20,138,136,110,144,7,96,21,231,37,101,65,241,145,40,26,52,203,173,61,90,
41,72,231,199,58,211,54,84,250,51,173,102,174,195,149,11,96,69,90,145,73,153,34,128,210,197,100,88,62,128,174,66,114,35,97,176,170,114,209,60,131,136,81,2,176,29,15,69,66,74,198,144,114,84,75,200,151,
144,52,73,14,210,48,121,146,34,89,155,122,17,43,174,201,180,103,9,55,17,171,97,84,229,244,10,218,176,72,174,128,138,11,6,246,38,192,118,53,178,162,173,20,146,64,77,13,85,13,210,236,151,37,224,129,182,
136,147,66,147,108,135,101,68,100,154,234,140,36,215,132,105,40,182,197,197,35,76,140,73,173,151,145,57,194,140,219,147,116,142,156,88,254,54,201,171,142,124,112,175,232,202,106,164,206,217,164,142,76,
173,55,161,134,178,176,96,193,108,210,4,172,218,16,117,208,162,165,225,27,69,76,154,167,8,86,217,105,168,137,69,148,226,188,25,104,189,199,244,53,201,130,137,73,94,136,68,121,19,149,35,101,20,140,228,
173,232,17,139,156,219,46,57,41,109,131,129,47,29,21,38,180,247,44,165,53,228,230,105,166,82,144,43,169,52,199,70,56,221,189,179,114,52,135,27,51,148,104,218,204,166,172,131,39,217,45,149,35,54,205,51,
166,152,72,139,217,105,149,16,199,25,106,134,213,153,221,120,3,106,208,209,17,153,162,232,138,0,106,130,136,172,230,232,201,239,163,105,152,182,209,172,103,75,143,216,54,137,111,237,134,145,80,152,134,
216,153,20,95,208,8,0,96,32,1,216,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,1,128,0,12,0,33,140,18,53,134,59,20,76,33,108,222,48,166,56,194,141,20,76,214,162,82,45,33,164,93,0,145,113,36,168,162,
138,34,76,182,103,32,21,128,152,1,231,173,13,59,37,233,135,91,52,202,217,80,200,226,66,96,208,29,112,200,159,102,159,22,112,43,75,178,150,73,39,217,34,215,114,72,40,229,142,118,187,31,249,4,139,93,52,
20,96,179,143,221,178,66,182,160,162,33,59,236,210,194,166,246,68,157,26,81,207,157,208,52,222,66,94,83,6,221,141,109,163,81,154,213,201,213,153,57,51,162,117,28,103,40,196,211,177,195,108,147,108,81,
177,166,55,130,209,104,75,161,153,108,208,164,194,232,93,129,62,71,104,106,23,228,165,10,0,91,232,165,250,20,22,0,246,77,33,182,75,145,2,100,141,255,0,178,89,80,74,54,71,18,155,34,82,162,161,198,42,206,
148,210,84,114,65,183,35,76,179,81,143,233,34,214,126,163,38,221,28,205,142,78,246,36,172,211,33,43,236,219,28,87,209,49,70,171,160,45,82,69,166,102,154,122,52,138,50,214,45,37,216,54,129,170,23,27,34,
139,182,82,105,19,73,34,27,10,183,43,21,163,25,73,162,22,70,221,22,37,116,242,68,202,72,194,121,41,87,145,66,127,98,31,77,90,178,101,16,230,22,16,67,226,205,150,84,115,201,147,201,161,11,29,126,226,96,
218,104,229,83,102,176,149,146,46,105,77,24,201,59,58,89,13,12,211,113,204,236,123,52,146,252,37,246,106,178,112,111,166,18,66,69,181,104,131,36,139,140,235,68,181,250,36,81,175,52,10,118,102,246,132,
175,236,13,36,102,203,189,18,216,25,180,254,137,42,77,253,147,162,132,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,10,0,1,132,3,74,216,226,172,214,17,37,15,30,58,236,222,42,133,20,81,26,
80,211,37,118,80,83,76,118,36,1,13,109,154,46,136,130,217,161,66,34,76,182,101,38,2,96,32,32,224,154,216,85,196,188,170,164,37,252,155,101,11,67,177,177,36,5,41,46,138,163,58,217,162,1,164,168,18,1,160,
26,141,178,214,58,20,22,236,221,35,58,214,98,18,163,75,164,13,19,86,232,138,124,181,103,54,103,108,215,62,146,72,194,101,196,212,7,144,10,164,105,149,78,109,164,136,76,4,5,35,167,23,242,115,46,209,213,
143,162,106,227,75,14,90,13,34,91,217,150,131,118,56,198,193,43,46,128,58,14,65,66,96,28,172,57,9,232,139,182,17,165,162,31,97,98,228,132,41,61,10,194,82,76,158,73,21,20,221,35,25,200,82,157,144,217,81,
81,157,72,210,107,146,57,226,246,117,198,154,26,57,212,57,74,188,26,172,101,168,164,205,35,18,85,140,214,52,182,199,198,203,162,162,69,137,134,52,153,162,105,8,40,141,6,236,60,18,244,75,144,42,223,68,
113,208,185,7,58,69,137,82,227,100,78,60,86,141,57,162,27,228,17,204,238,194,232,232,224,136,150,53,224,181,35,62,76,124,216,154,98,42,52,82,27,102,86,28,128,180,210,45,76,196,45,129,212,164,54,99,142,
70,166,117,172,212,186,51,148,190,141,36,140,164,198,9,114,99,82,100,88,209,81,77,236,87,176,100,129,109,145,97,98,101,22,164,14,70,118,22,64,49,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
12,4,48,25,66,24,2,8,210,14,141,99,43,49,137,113,84,200,174,136,150,140,226,106,186,35,88,105,13,10,244,8,6,82,91,38,40,209,32,129,42,1,137,148,38,244,102,83,100,0,0,186,0,57,243,173,217,151,131,163,52,
108,194,180,205,99,58,143,37,174,132,145,73,4,10,129,186,7,164,84,49,185,109,133,40,219,53,142,61,23,12,102,177,141,25,221,107,49,48,133,23,69,80,136,164,62,182,38,18,254,64,206,95,39,108,231,201,217,
183,134,46,5,196,215,56,234,205,158,36,208,189,170,45,72,201,193,146,227,90,103,76,33,122,98,203,2,82,57,210,217,215,143,163,24,227,103,68,85,33,186,185,130,93,132,99,108,124,108,181,26,70,84,37,69,9,
3,216,9,179,57,89,109,25,77,178,129,177,116,75,116,75,145,89,83,102,114,123,38,83,35,153,81,110,68,185,18,228,159,68,48,41,200,150,196,0,85,155,225,151,38,115,27,250,103,242,3,178,49,46,181,72,152,26,
25,109,10,53,216,232,161,36,64,170,132,247,209,76,151,160,169,113,108,206,72,210,78,137,74,202,140,233,153,201,51,167,138,161,56,170,21,35,151,99,77,155,56,89,46,5,169,17,201,143,144,156,4,213,0,221,17,
36,159,66,108,92,130,38,74,129,13,187,17,67,176,36,119,64,92,109,116,107,25,28,252,199,25,81,21,208,221,153,77,108,124,140,229,61,128,49,10,197,96,85,137,177,88,89,65,96,216,128,128,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,29,5,104,4,3,161,208,19,67,162,180,58,2,40,105,22,161,108,165,142,128,206,134,160,205,99,143,236,209,71,98,145,130,198,197,193,217,212,163,108,56,108,149,99,40,99,217,175,183,
69,198,59,52,151,65,99,52,138,0,0,67,170,4,13,128,227,217,161,156,59,45,176,129,177,57,9,178,27,182,80,219,16,134,0,2,108,8,22,72,232,198,49,71,77,92,12,87,108,214,38,165,194,133,73,38,217,169,158,109,
71,65,25,69,114,145,217,8,210,48,195,29,29,49,26,184,164,134,132,152,204,168,96,38,192,41,72,43,148,65,244,76,114,36,232,6,177,125,149,194,138,83,77,5,130,161,196,201,246,110,250,49,146,1,193,162,228,
148,140,74,132,152,20,161,69,40,253,130,145,87,171,32,150,232,19,108,82,98,76,163,81,50,84,132,229,96,18,102,82,123,42,82,49,108,38,233,189,25,206,67,109,145,45,26,101,12,145,182,72,0,134,0,32,0,0,47,
19,169,162,13,112,171,200,130,189,28,107,226,138,122,5,164,52,188,179,13,4,133,39,75,69,17,41,1,155,155,65,110,135,37,109,18,222,138,15,232,105,80,241,173,17,55,86,0,222,193,244,66,232,165,208,5,208,156,
140,242,79,193,143,55,98,38,235,166,211,19,73,152,71,35,93,149,238,170,16,167,40,38,97,37,70,142,127,68,93,246,86,80,3,104,69,2,29,8,105,128,134,158,194,128,10,229,100,176,232,79,96,32,24,136,160,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,9,23,24,54,192,154,213,141,69,190,141,227,139,84,203,142,52,137,72,231,142,54,223,69,188,125,35,161,69,14,144,88,229,148,54,47,109,157,60,55,99,80,42,57,227,139,
236,185,99,209,178,136,248,232,138,202,48,162,148,118,90,69,40,133,66,137,74,37,36,80,16,163,65,69,50,108,10,67,100,174,134,192,150,48,240,32,31,144,4,8,11,138,6,53,209,45,132,75,126,9,20,251,31,130,128,
167,208,162,173,142,122,2,27,164,4,101,149,32,8,222,59,77,24,75,82,102,241,254,140,114,175,147,24,186,151,58,70,83,151,34,148,109,154,44,105,175,211,76,158,15,228,217,19,8,210,43,193,150,141,20,182,70,
236,209,42,68,11,136,233,34,22,74,116,202,148,213,0,74,54,180,96,240,187,187,52,231,199,161,169,114,3,40,167,29,23,207,192,218,68,52,190,192,57,49,114,31,18,92,64,164,208,210,87,163,58,253,41,88,85,187,
79,66,109,190,193,189,19,200,6,217,60,172,79,98,65,26,88,54,75,208,185,47,44,1,178,27,28,164,140,165,34,166,155,102,114,96,228,67,101,64,216,129,136,0,0,0,0,1,5,56,171,103,103,167,197,78,206,108,106,230,
143,75,12,126,36,211,21,69,118,20,23,70,84,164,233,24,54,219,42,114,182,9,89,84,127,228,202,86,91,238,131,141,128,177,202,180,18,219,4,169,137,176,18,64,250,0,106,192,202,81,178,99,139,201,183,17,214,
133,72,231,120,252,153,52,117,53,102,79,29,150,164,96,192,169,42,98,42,11,6,32,176,1,160,0,6,8,98,1,49,88,48,34,139,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,10,0,0,160,0,26,4,138,81,216,21,8,217,209,24,
6,56,124,81,172,85,34,106,225,36,80,36,48,164,194,134,251,0,130,180,23,161,88,120,40,107,104,24,33,232,129,34,172,84,11,176,167,224,67,37,128,201,104,113,101,80,18,180,3,19,1,222,132,75,154,23,185,16,
149,165,142,36,69,223,70,177,64,55,209,13,148,217,156,152,19,39,178,147,180,102,246,205,98,180,81,81,209,51,219,41,145,46,128,231,204,246,4,228,236,10,203,169,61,147,151,106,197,41,81,154,109,133,171,
199,29,26,209,156,29,23,96,85,232,68,130,34,181,130,242,84,157,34,97,33,74,105,58,100,25,206,222,204,237,163,73,187,235,163,61,216,11,150,205,35,54,140,218,21,148,110,221,237,16,219,51,121,26,23,185,246,
33,87,41,126,147,206,136,119,46,130,159,144,141,121,13,72,205,69,208,93,1,163,108,68,242,161,74,118,33,87,104,151,42,50,114,37,204,66,180,121,62,200,115,217,14,86,75,101,69,185,18,228,77,136,10,177,8,
2,152,8,0,98,3,71,141,168,219,3,50,162,155,97,70,184,213,38,194,30,8,92,172,244,161,252,163,151,12,117,116,116,227,127,19,58,215,226,136,189,179,67,57,42,118,69,103,228,104,94,88,144,81,212,141,17,15,
193,77,235,65,25,207,189,18,209,163,37,148,74,42,194,171,177,121,32,2,180,23,176,176,165,68,209,86,34,162,28,23,108,197,210,125,27,200,198,104,184,206,178,144,134,201,40,97,98,0,29,136,0,128,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,26,86,107,8,94,128,202,139,134,57,55,209,188,49,124,142,149,20,188,10,177,206,189,43,125,177,63,72,252,51,177,42,21,59,209,7,4,176,202,50,218,52,142,61,157,82,113,122,104,201,
174,59,64,82,73,42,27,162,91,181,102,113,201,30,84,202,54,25,60,147,233,147,100,20,216,211,33,205,46,216,212,147,101,137,84,196,216,155,66,114,75,178,139,93,5,153,60,169,105,2,149,174,200,173,57,50,147,
49,199,43,116,84,237,170,3,78,65,217,140,19,93,179,101,164,64,210,208,54,103,41,253,11,147,41,85,41,145,110,65,254,198,128,92,70,177,38,12,20,168,33,40,56,74,252,29,49,146,104,197,78,203,90,68,83,110,
217,51,41,17,145,148,212,65,92,141,186,35,26,165,108,171,1,246,201,159,67,78,137,155,208,28,217,94,192,89,123,2,178,221,171,5,19,94,34,160,212,36,129,149,21,108,109,16,66,6,85,19,37,176,18,149,25,77,202,
236,218,48,177,60,64,140,121,176,82,99,148,104,85,101,65,201,203,161,56,179,84,148,80,185,34,12,212,27,7,140,183,36,188,153,203,35,240,81,81,92,94,202,147,77,24,75,35,97,205,136,86,158,229,42,35,149,145,
98,176,141,57,18,217,60,132,216,13,178,108,0,0,64,0,32,24,80,82,10,41,68,169,65,210,253,3,49,164,91,198,213,14,49,249,80,10,49,218,58,38,174,162,144,161,15,149,151,105,59,32,206,88,246,149,4,163,77,81,
164,166,168,30,210,96,107,15,227,70,176,209,207,25,82,52,82,232,154,214,55,76,82,232,87,162,100,244,65,43,200,147,208,73,232,133,45,81,69,62,137,82,180,87,254,72,93,128,238,199,100,135,96,55,33,88,168,
170,2,91,182,58,29,26,70,36,25,113,21,27,241,66,112,64,97,70,114,133,163,121,42,51,109,34,164,114,206,13,108,131,166,84,204,103,26,101,68,0,0,0,0,0,0,2,86,0,6,208,194,217,94,192,28,244,55,22,142,152,225,
161,203,21,129,203,199,67,80,111,163,165,225,180,79,178,215,64,97,193,253,3,139,76,235,140,52,41,226,82,64,114,211,178,212,45,109,83,46,56,154,116,205,163,29,83,3,149,99,111,162,92,29,157,139,26,79,64,
241,160,57,177,195,229,179,95,229,232,114,106,38,106,228,236,13,240,219,149,157,40,231,133,70,54,106,166,168,138,210,210,26,105,153,114,180,52,3,156,19,48,201,9,46,153,188,165,250,97,150,82,255,0,201,
70,112,158,233,150,225,23,224,230,124,174,217,174,60,190,24,66,106,81,150,141,20,181,178,169,49,52,128,230,200,223,39,244,37,54,141,103,93,24,184,138,69,123,178,94,67,155,100,81,166,40,219,216,164,84,
215,193,51,59,145,210,163,104,78,8,139,19,138,205,174,200,74,141,18,208,33,197,14,110,162,29,17,55,122,2,74,72,159,38,138,217,80,113,10,161,244,23,100,84,52,42,45,180,145,13,128,27,127,229,25,45,154,46,
128,171,164,71,27,101,1,65,208,155,7,182,79,76,6,153,51,116,52,70,75,3,12,159,208,4,208,6,94,133,9,244,83,21,6,137,104,116,30,74,240,4,209,18,236,210,200,146,2,225,164,12,149,42,68,57,145,78,113,84,114,
183,76,222,83,209,205,45,178,227,58,191,115,70,110,78,196,34,161,178,65,178,74,24,8,0,24,128,8,0,0,40,40,6,20,65,32,82,139,126,11,142,25,48,34,42,203,227,81,95,172,218,56,84,69,56,181,37,173,32,164,161,
167,163,85,142,226,191,11,138,180,139,74,136,177,147,199,126,9,142,26,217,208,157,171,161,214,153,8,231,122,50,191,7,79,183,166,97,193,242,6,226,26,217,113,122,217,124,63,1,194,154,20,128,78,117,160,107,
116,79,180,242,54,7,78,41,220,66,77,178,33,30,10,134,221,17,73,178,30,129,236,26,168,149,21,23,96,213,50,98,154,217,77,145,72,43,69,37,161,88,4,85,151,64,157,11,144,83,160,229,68,221,128,67,228,196,228,
197,65,64,75,147,50,153,191,29,19,40,38,84,220,114,203,68,55,102,243,138,70,50,85,209,81,0,0,0,0,0,6,184,35,202,70,70,222,158,124,103,176,61,44,88,210,143,65,56,34,241,201,74,54,138,146,180,69,174,55,
253,80,204,125,68,158,60,246,141,33,53,36,81,84,58,208,245,65,209,4,213,14,172,160,160,39,136,170,138,176,116,4,141,128,62,128,226,203,47,249,11,139,84,44,184,219,147,100,164,210,42,53,79,84,105,29,152,
93,175,210,241,75,100,86,253,104,118,67,144,212,128,25,156,165,70,140,203,38,209,80,157,73,90,50,146,160,131,166,84,222,128,152,101,107,70,202,106,72,230,242,116,66,41,70,192,153,82,102,125,178,170,228,
84,99,178,42,125,187,52,199,142,153,79,93,4,27,176,47,192,168,170,10,1,37,178,214,132,162,58,10,153,186,70,124,149,236,210,104,205,196,172,170,52,228,93,209,154,208,249,236,11,6,210,86,67,100,91,147,252,
3,69,114,217,74,54,76,77,58,86,69,79,146,145,156,165,101,199,160,44,76,23,99,173,128,168,147,73,116,101,210,40,58,20,182,135,217,155,123,3,44,128,44,143,96,17,232,142,130,192,42,124,141,189,19,110,250,
6,1,96,246,2,96,103,150,84,168,231,115,102,153,147,48,178,166,169,201,180,74,118,22,192,32,178,88,250,0,36,67,104,77,20,0,1,100,3,16,1,64,138,81,18,26,123,3,72,226,179,72,227,174,203,199,252,151,70,107,
89,136,81,70,137,38,133,194,203,140,120,162,42,90,216,154,179,74,10,216,4,34,54,9,208,114,77,128,252,8,98,108,1,147,74,193,200,142,64,95,146,90,18,149,7,43,1,21,13,33,198,43,137,52,236,2,82,174,132,157,
246,84,160,218,39,131,64,38,139,164,241,171,240,46,209,105,92,80,16,222,168,130,167,253,82,38,74,152,22,186,38,90,97,203,68,183,96,170,76,104,130,211,248,128,116,84,118,69,154,193,17,79,136,165,162,155,
33,187,8,150,200,110,202,107,177,38,154,42,49,201,22,204,220,116,117,82,104,206,81,42,71,43,139,68,157,18,142,140,100,168,9,0,42,17,182,1,237,179,72,99,217,188,98,184,209,74,32,107,233,157,104,233,179,
137,54,158,141,86,86,69,114,250,239,251,12,112,205,167,217,183,171,249,108,229,93,149,30,132,101,228,187,179,12,46,226,104,152,86,181,161,116,9,232,167,180,65,44,60,12,58,1,80,81,78,171,68,129,155,138,
100,188,72,183,216,20,100,240,38,136,120,229,13,163,171,84,75,162,14,39,41,26,99,203,173,134,92,116,237,24,211,42,58,125,212,217,150,76,157,164,101,176,239,176,21,150,164,232,154,21,128,219,47,28,164,
254,38,102,248,33,229,141,26,198,20,82,130,27,116,79,184,136,161,232,151,42,69,57,88,146,182,1,28,141,155,37,163,26,73,155,99,216,20,144,165,37,210,45,233,24,190,202,19,98,27,68,221,4,54,140,100,218,149,
154,115,76,206,91,2,185,90,42,8,206,43,102,241,105,45,144,90,73,45,132,159,196,158,86,196,216,84,179,92,127,201,132,229,244,116,99,255,0,173,3,22,144,0,216,18,201,145,79,72,201,59,40,46,136,154,42,93,
132,186,8,230,159,96,57,173,128,30,136,5,0,82,98,108,108,165,141,86,192,206,215,216,118,57,65,33,39,64,76,227,106,142,89,197,197,213,29,157,146,225,96,112,236,108,215,38,61,90,50,72,172,156,99,125,131,
136,214,134,216,16,227,68,81,175,130,31,96,77,8,186,209,52,80,130,138,226,53,22,244,2,132,92,158,141,86,38,139,199,30,43,162,210,109,153,170,33,7,70,177,84,76,98,199,222,136,170,72,126,69,186,4,236,41,
137,140,82,210,2,91,216,116,75,141,143,131,160,7,49,57,88,74,52,42,213,128,118,9,21,13,109,130,146,178,5,198,138,140,80,114,7,36,130,168,25,159,39,101,114,10,171,209,45,55,228,78,66,230,236,129,56,178,
241,54,180,193,38,203,112,173,149,9,164,174,70,50,217,179,250,102,89,21,21,53,148,157,34,99,49,228,209,156,74,203,100,244,28,140,211,240,48,86,169,217,110,84,140,83,166,85,217,21,106,77,178,174,137,90,
86,76,165,96,18,150,255,0,5,91,180,37,189,26,70,13,0,147,176,113,47,72,77,216,25,184,163,57,65,51,86,133,196,14,92,144,81,38,50,226,206,153,69,121,57,166,169,149,29,24,242,198,187,54,77,61,163,207,42,
57,37,30,152,29,235,236,40,203,22,117,45,61,26,249,211,10,153,197,73,28,175,20,185,81,218,201,173,132,70,24,53,29,154,208,45,20,130,146,236,110,84,172,43,97,40,220,104,9,89,83,102,139,110,204,35,4,187,
53,142,130,46,137,21,254,130,10,82,236,134,155,101,190,194,61,132,46,46,136,113,125,27,137,164,194,177,107,91,49,154,75,84,117,74,34,142,14,93,144,112,181,177,172,82,151,72,244,163,233,160,187,70,138,
17,93,32,143,50,30,158,94,81,170,244,150,119,241,95,66,150,144,245,92,63,226,108,167,141,98,93,155,183,173,153,168,115,149,53,160,49,247,19,149,120,47,130,54,120,113,195,108,206,212,165,241,1,40,38,202,
113,75,72,169,42,84,43,93,32,35,137,75,93,20,10,128,78,84,36,41,109,146,229,72,168,89,101,70,60,156,134,231,109,217,156,157,61,0,219,226,79,50,101,43,16,27,99,118,202,147,182,101,7,197,13,48,54,83,75,
67,230,102,151,198,201,114,2,164,246,118,99,255,0,173,30,125,219,61,8,127,214,129,138,76,28,145,22,74,149,176,173,103,252,153,69,108,181,43,84,42,160,38,104,159,6,143,100,214,130,50,146,216,6,87,72,0,
238,17,66,10,113,69,19,17,182,17,50,104,151,20,202,226,137,109,47,33,80,147,140,183,209,73,216,57,42,51,115,73,232,34,165,20,209,203,147,27,139,181,209,183,55,38,90,86,182,83,174,59,21,157,50,244,233,
152,203,4,151,64,103,98,41,193,197,108,80,131,147,8,22,222,141,35,137,190,205,177,226,81,255,0,102,157,10,177,138,198,144,227,13,244,105,86,82,84,65,42,35,181,17,180,233,217,18,164,187,10,209,73,81,147,
149,76,73,49,202,47,176,138,148,154,216,66,105,228,163,9,100,110,215,209,24,219,150,68,208,133,122,2,106,193,116,50,52,132,168,181,208,168,111,72,9,146,180,77,90,29,222,129,1,46,58,209,42,45,27,16,254,
128,205,13,43,101,241,41,36,6,110,52,82,72,114,90,20,96,217,20,214,59,45,98,69,198,52,138,44,102,165,69,33,208,192,168,206,112,242,142,124,159,167,89,207,158,55,209,21,203,147,100,37,199,255,0,176,228,
212,169,141,181,69,64,149,176,155,23,50,92,147,1,242,46,19,174,204,109,15,144,29,18,158,137,187,48,115,8,200,66,186,224,141,28,180,115,115,74,37,66,118,34,214,182,4,38,87,34,20,49,49,133,1,156,250,49,
148,44,233,105,17,37,162,163,146,81,104,70,242,70,82,141,1,55,70,248,179,52,234,93,24,0,30,146,118,172,14,92,25,95,242,206,128,41,34,186,38,37,0,175,99,125,104,134,10,78,128,135,201,178,226,165,228,105,
171,52,77,1,147,140,134,180,141,30,250,19,139,10,207,182,85,80,40,187,28,149,32,132,165,178,162,156,131,22,59,118,206,132,146,232,12,227,141,46,205,42,128,207,38,78,17,111,232,13,2,206,104,122,174,72,
79,53,204,14,171,50,202,245,73,147,44,169,70,211,49,247,57,1,170,105,127,67,121,162,151,91,49,166,199,196,138,207,46,73,100,232,188,49,226,144,248,164,56,202,153,69,100,122,51,135,123,49,205,158,165,72,
22,93,91,8,222,82,216,165,36,151,103,43,204,249,90,20,178,57,62,193,93,46,90,179,57,201,56,246,100,242,58,163,55,38,192,182,201,108,86,32,1,161,13,1,72,104,72,118,5,243,248,81,155,123,42,173,17,64,53,
182,122,48,95,241,165,248,112,226,131,228,143,65,116,129,140,158,147,20,22,139,154,208,146,248,128,151,244,84,157,25,197,252,138,155,1,93,178,151,66,140,117,99,128,24,231,90,3,89,199,150,128,14,161,0,
172,40,110,140,167,145,164,91,51,156,109,4,101,44,178,126,73,228,223,144,167,23,180,54,190,141,33,242,105,118,71,59,99,227,162,29,216,71,70,42,106,205,109,28,145,114,163,72,54,69,173,222,208,168,34,254,
193,205,45,121,35,76,178,69,54,94,56,165,224,156,137,214,137,247,56,246,130,53,242,26,35,157,162,121,94,128,222,59,20,165,70,74,110,61,13,182,227,96,18,155,100,197,9,187,64,166,214,145,70,240,133,246,
104,234,49,216,161,184,166,25,23,40,209,149,113,103,95,58,143,70,248,113,84,83,107,101,44,107,201,162,208,164,58,160,176,39,200,85,88,155,19,4,3,72,116,43,11,176,24,169,54,82,67,81,216,19,192,20,89,160,
8,149,60,45,236,164,168,96,84,0,32,108,0,9,114,164,68,178,17,99,70,204,50,79,99,231,102,82,219,3,12,240,191,146,48,228,234,142,214,151,19,154,120,234,127,133,196,214,86,22,57,70,137,42,6,33,213,136,40,
0,2,10,229,161,198,84,64,1,209,25,150,187,57,226,205,35,58,96,116,32,178,83,29,133,15,98,171,40,2,49,154,162,18,82,54,154,180,96,211,139,208,19,56,209,6,146,149,163,48,28,93,59,58,241,79,146,217,198,107,
138,84,192,237,138,6,232,152,202,208,216,14,59,102,170,10,140,224,246,108,152,86,51,198,211,177,114,58,29,52,101,40,164,194,28,118,138,34,44,167,65,73,186,19,149,137,246,32,58,49,255,0,37,17,142,73,198,
134,228,144,65,57,82,56,167,38,228,247,217,209,146,73,163,10,86,6,120,215,22,219,21,242,110,135,149,171,171,161,98,171,8,36,159,72,210,10,144,248,149,20,23,13,20,20,34,52,76,77,19,60,138,46,138,77,53,
97,28,153,225,82,179,27,59,178,71,146,209,203,44,77,91,42,51,24,128,6,32,161,208,8,13,33,141,190,203,246,208,24,12,210,88,254,132,161,176,36,164,173,150,176,254,154,67,21,48,26,199,241,48,226,249,29,169,
19,40,39,178,44,78,40,244,116,25,227,164,104,2,100,201,210,42,93,17,37,104,162,19,242,13,216,212,111,72,190,42,33,2,210,166,53,81,77,138,77,51,41,73,185,80,26,93,128,146,0,58,0,96,21,44,145,182,72,19,
40,217,28,93,154,216,138,136,113,34,81,77,155,10,144,35,53,26,101,164,129,14,190,129,13,25,102,132,162,212,145,162,116,18,249,42,32,152,207,144,56,166,74,141,75,70,137,121,3,47,111,122,23,6,157,217,171,
123,5,180,8,206,139,255,0,200,80,159,96,37,16,227,178,212,74,81,216,164,86,54,212,74,177,36,85,34,52,65,216,55,224,91,1,254,2,91,160,227,38,236,168,199,118,194,37,119,65,193,217,167,20,48,84,40,20,162,
80,21,41,12,0,0,64,43,1,133,146,228,67,153,22,45,202,136,148,204,229,50,27,2,165,59,33,176,31,16,13,143,160,19,77,133,38,236,20,45,91,46,24,239,179,71,85,64,114,188,92,140,101,133,157,244,103,40,132,143,
61,167,18,78,201,226,181,209,205,40,83,162,162,0,110,46,172,64,0,0,0,84,94,201,46,11,96,111,11,104,209,16,180,138,176,24,155,99,143,232,62,192,155,209,140,205,90,217,51,90,3,6,73,76,150,0,56,246,32,64,
118,227,122,52,70,56,159,197,26,114,2,211,217,106,70,41,141,50,141,212,137,147,179,59,161,167,100,20,144,61,13,3,216,84,160,108,84,62,32,60,110,164,86,77,244,75,64,165,225,144,75,77,153,202,227,223,147,
110,113,94,8,202,212,218,175,5,28,115,110,246,107,132,83,199,111,70,152,227,197,13,76,198,177,43,84,74,26,35,70,2,232,86,7,55,168,95,43,66,197,54,157,27,202,54,101,194,152,101,191,104,82,138,97,14,139,
10,231,150,4,204,229,135,116,142,182,20,128,228,142,39,127,35,71,4,151,70,173,81,15,96,76,82,42,128,0,154,51,148,124,155,50,36,244,49,52,177,221,157,8,231,199,35,120,189,5,197,174,128,0,41,199,178,200,
93,150,17,51,33,216,230,246,40,237,148,92,23,24,153,206,91,46,111,71,59,149,200,35,71,213,132,33,171,99,138,228,104,214,128,152,254,129,90,0,173,4,221,0,159,96,38,236,134,139,161,208,25,117,217,69,52,
188,137,68,4,149,142,134,144,192,207,160,186,41,162,90,216,8,165,176,72,117,64,39,72,86,36,155,182,20,0,82,68,213,22,128,134,182,37,27,102,141,9,42,100,85,37,72,104,6,162,1,176,226,217,105,34,180,18,179,
88,254,203,81,67,181,246,22,190,202,128,98,181,246,22,190,192,98,23,37,246,28,151,216,12,9,114,95,98,228,190,192,187,21,153,185,126,146,230,69,141,28,137,115,51,114,100,216,85,202,68,55,96,20,4,142,49,
177,73,191,8,148,229,101,70,182,144,211,229,163,56,167,123,53,130,73,246,69,37,29,150,162,85,199,236,77,175,176,29,80,80,185,33,242,143,216,8,151,18,173,125,133,175,176,51,226,68,240,169,27,90,21,160,
142,103,233,244,101,60,21,209,218,228,171,70,114,182,81,196,241,48,80,221,29,92,24,123,127,129,24,44,105,22,162,146,53,224,39,6,4,81,72,124,24,56,176,11,222,130,193,65,162,92,37,224,5,123,34,108,181,142,
94,80,158,41,191,0,100,213,171,50,55,120,50,11,252,105,129,136,27,127,141,48,255,0,26,96,86,39,163,82,33,134,81,102,234,52,2,138,27,210,42,168,40,8,14,138,161,113,2,227,209,68,173,8,42,188,140,155,6,200,
7,177,52,49,5,67,65,69,80,81,81,52,58,29,12,129,36,48,2,128,79,177,137,160,6,75,69,80,80,129,37,67,10,41,107,192,9,69,178,156,7,207,240,57,254,16,71,182,217,50,196,226,141,57,176,230,32,231,173,141,26,
74,41,177,112,16,75,86,97,53,110,145,191,181,255,0,236,194,56,146,149,221,148,78,60,45,109,155,70,9,0,18,42,148,80,220,17,54,62,76,68,62,33,76,92,152,114,101,10,80,108,136,39,25,108,209,201,177,1,51,223,
70,107,27,114,53,160,90,1,173,33,137,187,16,5,128,0,23,98,0,0,11,0,2,101,224,118,0,1,108,44,0,0,64,0,3,0,1,0,0,12,64,0,0,0,1,97,111,236,0,2,223,216,91,251,0,8,45,253,133,191,176,0,11,96,0,0,0,1,64,0,0,
0,0,0,0,0,0,0,0,0,4,0,0,20,0,0,0,0,0,0,0,0,0,4,0,0,20,0,1,64,0,4,0,0,0,0,0,0,0,0,0,1,64,0,4,64,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,31,255,217,0,0};

const char* Interface::mammut_zerlegentmp_jpg = (const char*) resource_Interface_mammut_zerlegentmp_jpg;
const int Interface::mammut_zerlegentmp_jpgSize = 23648;
