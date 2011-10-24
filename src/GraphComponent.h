/*
  ==============================================================================

   JUCE library : Starting point code, v1.26
   Copyright 2005 by Julian Storer. [edited by haydxn, 3rd March 2006]

  ------------------------------------------------------------------------------

  MainComponent.h :

  This file defines the behaviour of the application. The main part of the 
  program that the user interacts with IS this MainComponent object. It is
  placed within the MainAppWindow instance, and so exists at whatever size
  the window provides in its content area.

  All of the widgets and controls that your main program window will display
  will be on this component (either directly or somewhere down the children
  hierarchy).

  ------------------------------------------------------------------------------

  Please feel free to do whatever you like with this code, bearing in mind that
  it's not guaranteed to be bug-free!

  ==============================================================================
*/
#ifndef _GRAPHCOMPONENT_H_
#define _GRAPHCOMPONENT_H_

#include "juce.h"

//#include "mammut.h"
extern void BlitWin(Graphics *g);

class GraphComponent  : public Component
{
public:
  //==============================================================================
  GraphComponent (int x,int y,int width,int height)
  {
    das_width=800;
    das_height=400;
    theheight=das_height;
    // thewidth=das_width;

    // create and add the rest of your components here!
    
    //addAndMakeVisible(new Interface());
    //setSize(das_width+150,das_height+150);
    setSize(920,456);
    //setSize(width,height);
  }
  
  ~GraphComponent ()
  {
    deleteAllChildren(); // removes all the components
  }
  
  //==============================================================================
  void resized ()
  {
    printf("gakk gakk\n");
  }
  

  void paint (Graphics& g)
  {    
    BlitWin(&g);
  }
  //==============================================================================
  
private:
  int das_width;
  int das_height;
  
};

#endif//_MAINCOMPONENT_H_
