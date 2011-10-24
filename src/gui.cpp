
#include "mammut.h"
#include "gui.h"

#include "juce.h"

#  include "GraphComponent.h"
#  include "Interface.h"

#define STARTX 20

static GraphComponent *graphcomponent;
static Interface *interface;

static Image *image=NULL;

//extern ThreadWithProgressWindow das_mytask;

void GUI_addUndo(void){
  interface->addUndo();
}

#if 0
void GUI_progressbar(int minvalue,int newvalue,int maxvalue){
  static double last=0;
  static double lastpercent=0;
  double percent;

  if(newvalue==last) return;

  percent=((float)(newvalue-minvalue))/((float)(maxvalue-minvalue));
  if(percent==lastpercent) return;

  last=newvalue;
  lastpercent=percent;

  das_mytask.setProgress(percent/(float)100);
  //  interface->updateProgressBar(percent);
  //  printf("progress: %d/100.0\n",percent);
}
#endif


void drawscale(Graphics *g)
{
  int i, grafx, ch;
  char tall[10];
  bool havefile=samps_per_frame!=0?false:true;
  int startx=havefile==true?STARTX-10:STARTX;

  g->setColour(Colours::darkgrey);
    
  g->drawLine(startx,theheight+20,
	      850,theheight+20);
  g->drawLine(startx,theheight+20,
	      startx,10);

  for (i=0; i<=(int)(R/2000.); i++) {
    grafx=(int)(i*1600000./R)+STARTX+10;
    g->drawLine(grafx,theheight+15,grafx,theheight+25);
    if (zoom) {
      if ((i%2==0) && (i>0) && (i<22)) {
	sprintf(tall, "%d", i*100+leftkc*1000);
	g->drawSingleLineText(tall,grafx-14,theheight+40);
      }
    } else {
      sprintf(tall, "%d", i);
      g->drawSingleLineText(tall,grafx-6,theheight+40);
    }
  }
    
  for (ch=0; ch<samps_per_frame; ch++) {
    for (i=0; i<=10; i++) {
      grafx = (ch+1)*theheight/samps_per_frame - i*35./samps_per_frame + 10;
      g->drawLine(startx-5,grafx,startx+5,grafx);
      sprintf(tall, "%2d", i);
      g->drawSingleLineText(tall,0,grafx+5);
    }
  }

}





static void RestoreWin(int x1,int y1,int width,int height){
#if 1
  printf("RestoreWin(...)\n");
#else
  /*
  XCopyArea(theDisplay, bitmap, XtWindow(sketchpad),
    DefaultGCOfScreen(XtScreen(sketchpad)), 0, 0, 800+70, theheight+70, 0, 0);
  */

  gdk_draw_pixmap(drawing_area->window,
		  drawing_area->style->fg_gc[GTK_WIDGET_STATE (drawing_area)],
		  pixmap,
		  x1,y1,
		  x1,y1,
		  width,height
		  );
#endif
}

void RestoreWinAll(void){
#if 1
  printf("RestoreWinAll()\n");
#else
  RestoreWin(0,0,drawing_area->allocation.width,drawing_area->allocation.height);
#endif
}


static void DrawImage(void){

  long i;
  int c0=0, y, grafx, grafold=-1, start, range,ch;
  double real, imag, amp, maxamp=-1.;  

  Graphics g(*image);

  image->clear(0,0,image->getWidth(),image->getHeight());

  drawscale(&g);
  
  g.setColour(Colours::black);
  
  //RestoreWinAll();
  
  start=(zoom==0?0:1000.*leftkc*N/R);
  range=N/(zoom?20:2); if (start+range>=N/2) range=N/2-start-1;

  printf("I am drawing\n");
  
  for (ch=0; ch<samps_per_frame; ch++) {
    for (i=0; i<range; i++) {
      grafx = (int)(i*800./(N/(zoom?20.:2.)))+STARTX+10;
      real=lyd[(i+start)*2+ch*N]; imag=lyd[(i+start)*2+1+ch*N];
      amp=sqrt(real*real+imag*imag)*N;
      if (amp>maxamp) maxamp=amp;
      if (grafx!=grafold) {
	maxamp/=samps_per_frame;
	y = (ch+1)*theheight/samps_per_frame-(int)(maxamp/10.)+10;
	g.drawLine(grafx,(ch+1)*theheight/samps_per_frame+10,grafx,y);
	grafold=grafx;
	maxamp=-1.;
      }
    }
  }
  
  graphcomponent->repaint();
}



// Called from juce. (in graphcomponent.h)
void BlitWin(Graphics *g){
  //printf("painting\n");
  g->drawImageAt(image,0,0,false);
  //printf("restoring\n");
}



// Called from transforms, loaders, etc.
void RedrawWin(void){
  DrawImage();
}



//void GUI_init(GtkWidget *dasdrawing_area,GtkWidget *dasprogressbar){
void GUI_init(GraphComponent *das_graphcomponent,Interface *das_interface){
  graphcomponent=das_graphcomponent;
  interface=das_interface;
  image=new Image(Image::ARGB,das_graphcomponent->getWidth(),das_graphcomponent->getHeight(),false);
  RedrawWin();
  printf("GUI_init()\n");
}
