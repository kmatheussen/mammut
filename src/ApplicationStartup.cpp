/*
  ==============================================================================

   JUCE library : Starting point code, v1.26
   Copyright 2005 by Julian Storer. [edited by haydxn, 3rd March 2006]

  ------------------------------------------------------------------------------

  ApplicationStartup.cpp :

  This file describes how the application will be brought to life within the
  operating system. The basic order of things is...

  [OS] - creates the 'AppClass', which understands JUCE...
         ... the [AppClass] creates the MainAppWindow and puts it on the screen...
		     ... the [MainAppWindow] is a visible base for the program, and it
			     creates the program's MainComponent on itself...
				 ... the [MainComponent] then 'does' the 'program stuff'

  There's probably not much need for you to want to edit this file if you're
  only writing simple applications.

  ------------------------------------------------------------------------------

  Please feel free to do whatever you like with this code, bearing in mind that
  it's not guaranteed to be bug-free!

  ==============================================================================
*/

#include "AppSettings.h"
#include "MainAppWindow.h"

#include "mammut.h"


//==============================================================================
class AppClass : public JUCEApplication
{
    /* Important! NEVER embed objects directly inside your JUCEApplication class! Use
       ONLY pointers to objects, which you should create during the initialise() method 
       (NOT in the constructor!) and delete in the shutdown() method (NOT in the 
       destructor!)

       This is because the application object gets created before Juce has been properly
       initialised, so any embedded objects would also get constructed too soon.
   */
    MainAppWindow* theMainWindow;

public:
    //==============================================================================
    AppClass()
        : theMainWindow (0)
    {
        // NEVER do anything in here that could involve any Juce function being called
        // - leave all your startup tasks until the initialise() method.
    }

    ~AppClass()
    {
        // Your shutdown() method should already have done all the things necessary to 
        // clean up this app object, so you should never need to put anything in 
        // the destructor.

        // Making any Juce calls in here could be very dangerous...
    }

    //==============================================================================
    void initialise (const String& commandLine)
    {
      AVOIDDENORMALS;
        
        // just create the main window...
      theMainWindow = new MainAppWindow(commandLine);
	//theMainWindow->centreWithSize (AppSettings::appWidth, AppSettings::appHeight);
	//theMainWindow->setSize(855,716);
        theMainWindow->setVisible (true);

	MC_init();

        /*  on return from this method, the app will go into its the main event
            dispatch loop, and this will run until something calls
            JUCEAppliction::quit().

            In this case, JUCEAppliction::quit() will be called by the
            demo window when the user clicks on its close button.
        */
    }

    void shutdown()
    {
        delete theMainWindow;
        theMainWindow = 0;
    }

    //==============================================================================
    const String getApplicationName()
    {
		return AppSettings::appName;
    }

    const String getApplicationVersion()
    {
		return AppSettings::appVersion;
    }

    bool moreThanOneInstanceAllowed()
    {
		return true;
    }

    void anotherInstanceStarted (const String& commandLine)
    {
        // This will get called if the user launches another copy of the app, but
        // there's nothing to do here.
    }
};


//==============================================================================
// This macro creates the application's main() function..
START_JUCE_APPLICATION(AppClass)
