/*
  ==============================================================================

   JUCE library : Starting point code, v1.26
   Copyright 2005 by Julian Storer. [edited by haydxn, 3rd March 2006]

  ------------------------------------------------------------------------------

  MainAppWindow.cpp :

  This file defines the configuration of the main application window, which
  is the class MainAppWindow.

  The JUCE class 'DocumentWindow' is the base for this class, so examine the
  documentation for any functions that you may wish to use, or any other
  configuration options you may wish to change.

  The 'window' is the main bit that the program sits within. That means 'the
  bit with the title bar and the overall size/shape of the program, but without
  the actual program on it yet'. Your program lives in the 'MainComponent' class,
  and is added to this window as the 'content component'.

  ------------------------------------------------------------------------------

  Please feel free to do whatever you like with this code, bearing in mind that
  it's not guaranteed to be bug-free!

  ==============================================================================
*/

#include "MainAppWindow.h"
#include "Interface.h"

//==============================================================================
MainAppWindow::MainAppWindow(const String& commandLine)
  :	DocumentWindow ("Mammut", 
			Colours::lightgrey, 
			DocumentWindow::allButtons,
			true)
{


#if 0
  //JUCE_WIN32
  setTitleBarHeight(20);
  centreWithSize(855,737+getTitleBarHeight());
#else
  if (true)
    setUsingNativeTitleBar(true);
  else
    setTitleBarHeight(20);
  centreWithSize(855,737);
#endif

  LookAndFeel::setDefaultLookAndFeel(new LookAndFeel_V1);
  //setLookAndFeel(new OldSchoolLookAndFeel());
  //setResizeLimits(855, 50, 855, 100000);
  
  //getConstrainer()->setFixedAspectRatio(855.0 / 737.0); // doesn't work on linux when native title bar is true. Might be true for other platforms as well.

  setResizable (true, false); // resizability is a property of ResizableWindow
  setVisible (true);

	// create the main component, which is described in MainComponent.h
  //  MainComponent* contentComponent = new Interface(commandLine);//MainComponent (commandLine);

    // sets the main content component for the window to be whatever MainComponent
    // is. This will be deleted when the window is deleted.
  _interface = new Interface(this,commandLine);//contentComponent);
  //setContentComponent (_interface);
  addAndMakeVisible(_interface);
}

MainAppWindow::~MainAppWindow()
{
    // our content component will get deleted by the DialogWindow base class, 
    // and that will clean up the other components.
}

void MainAppWindow::resized(void){
#if 1
  if (_interface!=NULL){
    AffineTransform aff;
    //printf("h: %d (%d). scale: %f\n", getHeight(), _interface->getHeight(), new_scale_factor);
    _interface->setTransform(aff.scaled((double)getWidth()/855.0, (double)getHeight()/737.0));
    //    _interface->setSize(855.0/getWidth(),737.0/getHeight());
  }
#else
  static int counter = 0;

  if (counter++ > 10 && getHeight() != 737){
    double scaleFactor = Desktop::getInstance().getGlobalScaleFactor();
    double ideal_height = 737;
    double now_height = getHeight() * scaleFactor;
    double new_scale_factor = now_height / ideal_height;
    if (getHeight() != 737){ //-ideal_height) > 1){//fabs(scaleFactor-new_scale_factor) > 0.001){
      //printf("scale: %f. height: %d\n", new_scale_factor, getHeight());
      Desktop::getInstance().setGlobalScaleFactor(new_scale_factor);
    }
  }
#endif
  ResizableWindow::resized();
}

void MainAppWindow::closeButtonPressed()
{
    // The correct thing to do when you want the app to quit is to call the
    // JUCEApplication::systemRequestedQuit() method.
    
    // That means that requests to quit that come from your own UI, or from other 
    // OS-specific sources (e.g. the dock menu on the mac) all get handled in the 
    // same way.

    JUCEApplication::getInstance()->systemRequestedQuit();
}
