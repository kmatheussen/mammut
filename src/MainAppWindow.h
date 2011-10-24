/*
  ==============================================================================

   JUCE library : Starting point code, v1.26
   Copyright 2005 by Julian Storer. [edited by haydxn, 3rd March 2006]

  ------------------------------------------------------------------------------

  MainAppWindow.h :

  This file is just a declaration of the MainAppWindow class. For more
  detailed information of its purpose, examine the MainAppWindow.cpp
  file.

  Having it as a separate header file may seem pointless, but it could
  save a bit of effort should you be embarking on a complex project and
  wish to still use this fileset as a starting point.

  ------------------------------------------------------------------------------

  Please feel free to do whatever you like with this code, bearing in mind that
  it's not guaranteed to be bug-free!

  ==============================================================================
*/

#ifndef _fMainAppWindow_H__
#define _fMainAppWindow_H__

#include "juce.h"

//==============================================================================
class MainAppWindow  : public DocumentWindow
{
public:
    //==============================================================================
  //MainAppWindow();
    MainAppWindow(const String& commandLine);
    ~MainAppWindow();

    //==============================================================================
    // called when the close button is pressed or esc is pushed
    void closeButtonPressed();
};


#endif
