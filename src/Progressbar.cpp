
#include "mammut.h"
#include "juce.h"
#include "undo.h"


static void (*func)(void)=NULL;

class MyTask  : public ThreadWithProgressWindow
{
public:
  MyTask()    : ThreadWithProgressWindow (T("busy..."), true, false)
  {
  }
  
  ~MyTask()
  {
  }
  
  void run()
  {
    //setPriority(0);
    isprocessing=true;
    func ();
    isprocessing=false;
    //sleep(200);
  }
private:

};


static MyTask *mytask=NULL;

static void create_new_mytask(){
  fprintf(stderr,"mytask: %p\n",mytask);

  if(mytask!=NULL)
    delete mytask;

  mytask=new MyTask();
}



class MyProgressBar : public Thread
{

public:
  MyProgressBar() : Thread(T("myprogressbar")) {
    is_running=false;
    above_curr=0;
    above_max=1;
  }

  void run()
  {
    //setPriority(10);
    while(is_running==true){
      sleep(60);
      if(valtocheck!=NULL){
	double percent;
	percent=(((float)above_curr)/((float)above_max))  +   ((float)(*valtocheck-minvalue))/((float)above_max*(maxvalue-minvalue));
	mytask->setProgress(percent);
	//printf("progress: %d/%d, %d/%d/%d, %f/100.0\n",above_curr,above_max,minvalue,*valtocheck,maxvalue,(float)percent);
	//printf("Percent: %f, Val: %d\n",percent,*valtocheck);
      }
    }
  }
  void stop_me(){
    //mytask->setStatusMessage("Gakk gakk gakk!\n");
    is_running=false;
    stopThread(1000);
    above_curr=0;
    above_max=1;
    mytask->setProgress(1.0);
  }
  void start_me(
		int das_minvalue,
		int *das_valtocheck,
		int das_maxvalue)
  {
    printf("I am started! %d, %d, %d\n",das_minvalue,*das_valtocheck,das_maxvalue);
    minvalue=das_minvalue;
    valtocheck=das_valtocheck;
    maxvalue=das_maxvalue;
    is_running=true;
    startThread();
  }

  int above_curr;
  int above_max;

private:
  bool is_running;
  int minvalue;
  int *valtocheck;
  int maxvalue;

};


static MyProgressBar *myprogressbar;


void GUI_aboveprogressbar(int curr,int maxvalue){
  if(mytask==NULL)
    mytask=new MyTask();
  if(myprogressbar==NULL)
    myprogressbar=new MyProgressBar();
  myprogressbar->above_curr=curr;
  myprogressbar->above_max=maxvalue;
}


void GUI_startprogressbar(int minvalue,int *valtocheck,int maxvalue){
  //if(mytask==NULL)
  //  mytask=new MyTask();
  if(myprogressbar==NULL)
    myprogressbar=new MyProgressBar();
  myprogressbar->start_me(minvalue,valtocheck,maxvalue);
}


void GUI_stopprogressbar(void){
  myprogressbar->stop_me();
}


void GUI_progressbar(int minvalue,int newvalue,int maxvalue){
  static double last=0;
  static double lastpercent=0;
  double percent;

  if(mytask==NULL)
    mytask=new MyTask();

  if(newvalue==last) return;

  percent=((float)(newvalue-minvalue))/((float)(maxvalue-minvalue));
  if(percent==lastpercent) return;

  last=newvalue;
  lastpercent=percent;

  mytask->setProgress(percent);
  //  interface->updateProgressBar(percent);
  //printf("progress: %f/100.0\n",(float)percent);
}


void GUI_newprocess(void das_func(void)){
  create_new_mytask();

  mytask->setProgress(0.0);

  func=das_func;
  mytask->runThread();
}


void Transformit(void das_func(void)){
  //CriticalSection *cs=new CriticalSection();

  create_new_mytask();

  MC_stop();

  mytask->setProgress(0.0);

  MC_addUndo();
  GUI_addUndo();

  func=das_func;  

  //cs->enter();
  mytask->runThread();
  //cs->exit();

  RedrawWin();

  func=NULL;
}

void ReTransformit(void das_func(void)){

  create_new_mytask();


  MC_stop();

  UNDO_do_noredraw();

  mytask->setProgress(0.0);

  MC_addUndo();
  //GUI_addUndo();

  func=das_func;  
  mytask->runThread();

  RedrawWin();

  func=NULL;
}




