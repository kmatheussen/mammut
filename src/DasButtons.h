/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-6 by Raw Material Software ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the
   GNU General Public License, as published by the Free Software Foundation;
   either version 2 of the License, or (at your option) any later version.

   JUCE is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with JUCE; if not, visit www.gnu.org/licenses or write to the
   Free Software Foundation, Inc., 59 Temple Place, Suite 330,
   Boston, MA 02111-1307 USA

  ------------------------------------------------------------------------------

   If you'd like to release a closed-source product which uses JUCE, commercial
   licenses are also available: visit www.rawmaterialsoftware.com/juce for
   more information.

  ==============================================================================
*/

#ifndef __JUCER_COMPONENTTEMPLATE_JUCEHEADER__
#define __JUCER_COMPONENTTEMPLATE_JUCEHEADER__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
//[/Headers]


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DasButtons  : 
  public ButtonListener,
  public SliderListener,
  public Component
				
{
public:
    //==============================================================================
    DasButtons ();
    ~DasButtons();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    GroupComponent *gc;
    TextButton* textButton1;
    TextButton* textButton4;
    TextButton* textButton2;
    TextButton* textButton5;
    TextButton* textButton6;
    TextButton* textButton7;
    ToggleButton* toggleButton3;
    Slider* slider;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    DasButtons (const DasButtons&);
    const DasButtons& operator= (const DasButtons&);
};


#endif   // __JUCER_COMPONENTTEMPLATE_JUCEHEADER__
