#ifndef _MAINHEADER_H_
#define _MAINHEADER_H_

//==============================================================================
//
// MainHeader.h
// ------------
//
//	this file holds a function that will create the main
//	component, which will sit inside the dialog window.
//
//	design your component, and make sure that the code file
//	is included in the '#include' section. 

//==============================================================================

#include <juce.h>					// include the JUCE library code

//	here you make sure that any files required for your
//	component are included. the main component must be
//	defined or at least declared inside one of these files.

namespace AppSettings
{
	const int appWidth			=	960;
	const int appHeight			=	600;

	bool resizable				=	false;
	bool resizeCorner			=	false;
#if 0
	const int appMinWidth		=	600;
	const int appMinHeight		=	600;
	const int appMaxWidth		=	800;
	const int appMaxHeight		=	800;
#endif
	const int titleBarHeight	=	20;
	const String appName		=	T("Tutorial App");
	const String appVersion		=	T("0.0");
	bool multipleInstances		=	false;
}

#include "MainComponent.h"

Component* createComp()
{

	//	this line creates the component. change the name
	//	of the instantiated class (here MidiHandlingComponent)
	//	to the name of the component you want created.

	return new MainComponent ();	// this line will create the component
}

#endif// _MAINHEADER_H_
