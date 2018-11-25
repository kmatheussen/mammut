/*
  ==============================================================================

   JUCE library : Starting point code, v1.26
   Copyright 2005 by Julian Storer. [edited by haydxn, 3rd March 2006]

  ------------------------------------------------------------------------------

  AppSettings.h :

  This just provides a convenient place to keep most of the settings for
  the application, so that you can change them easily without having to
  hunt for them within the standard application startup file.

  ------------------------------------------------------------------------------

  Please feel free to do whatever you like with this code, bearing in mind that
  it's not guaranteed to be bug-free!

  ==============================================================================
*/

#ifndef _APPSETTINGS_H_
#define _APPSETTINGS_H_

// include the JUCE headers..
#include "juce.h"

namespace AppSettings
{
	const String appName		=	"My Test Application";
	const String appVersion		=	"0.0";

	const int appWidth			=	700;
	const int appHeight			=	400;

	const int titleBarHeight	=	20;
}

#endif//_APPSETTINGS_H_
