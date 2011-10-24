
#include "mammut.h"
#include "undo.h"

#include "juce.h"
#include "juceplay.h"
//#define g.fillall black 
//Color(50,60,70,80)

#define doit(func) do{bool wasplaying=jp_isplaying;Transformit(func);if(wasplaying)MC_play();}while(0)
#define redoit(func) do{bool wasplaying=jp_isplaying;if(UNDO_allowedUndo())ReTransformit(func); else Transformit(func);if(wasplaying)MC_play();}while(0)

#define resetval(class,varname) class##_##varname=class##_##varname##_default; \
       varname##slider->setValue(class##_##varname##_default)

#define setval(class,varname) class##_##varname=varname##slider->getValue();

//#define fillit() g.fillAll (Colour ((uint8)0xff,(uint8)0xcf,(uint8)0xc2,(uint8)0x00));
//#define fillit() g.fillAll (Colour ((uint8)0x30,(uint8)0x20,(uint8)0x10,(uint8)0x00));
//#define fillit() g.fillAll (Colour (0xfddedfd2));
#define fillit() /* */




class DasSlider  : public Slider
{
 public:
  DasSlider(const String &componentName)
    : Slider(componentName)
    {
    }
    
    double getValueFromText (const String &text){
      //printf("gakk: -%s-\n",text.toUTF8());
      double newval=text.getDoubleValue();
      if(newval<getMinimum()){
	setRange(newval,getMaximum());
      }else if(newval>getMaximum()){
	setRange(getMinimum(),newval);
      }
      return newval;
    }

};

