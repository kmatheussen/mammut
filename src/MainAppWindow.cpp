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
  :	DocumentWindow (T("Mammut"), 
			Colours::lightgrey, 
			DocumentWindow::allButtons,
			true)
{


#if 0
  //JUCE_WIN32
  setTitleBarHeight(20);
  centreWithSize(855,737+getTitleBarHeight());
#else
  setUsingNativeTitleBar(true);
  centreWithSize(855,737);
#endif

  LookAndFeel::setDefaultLookAndFeel(new OldSchoolLookAndFeel());
  //setLookAndFeel(new OldSchoolLookAndFeel());
  setResizable (false, false); // resizability is a property of ResizableWindow
  setVisible (true);

	// create the main component, which is described in MainComponent.h
  //  MainComponent* contentComponent = new Interface(commandLine);//MainComponent (commandLine);

    // sets the main content component for the window to be whatever MainComponent
    // is. This will be deleted when the window is deleted.
  setContentComponent (new Interface(this,commandLine));//contentComponent);
}

MainAppWindow::~MainAppWindow()
{
    // our content component will get deleted by the DialogWindow base class, 
    // and that will clean up the other components.
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
