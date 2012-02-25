#include "application.h"
#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
using namespace std;

//Constructor
Application::Application(int fps, int frameskip, int spring_c, int gravity,
                         int level): fps(fps), frameskip(frameskip) {
  initXWindow(xinfo, 700, 500);
  graphics = new MainGraphics(&xinfo);
  game = new Game(graphics, spring_c, gravity, level);
}

//Destructor
Application::~Application() {
  delete game;
  delete graphics;
  freeXWindow(xinfo);
}

//Paint a frame of gameplay
void Application::paint() { 
    //Blank out the extra buffer
    XSetForeground(xinfo.disp, xinfo.gc, xinfo.colours[White]);
    XFillRectangle(xinfo.disp, xinfo.double_buffer, xinfo.gc, 0, 0,
                   xinfo.windAttr.width, xinfo.windAttr.height); 

    //Draw a blue background
    XSetForeground(xinfo.disp, xinfo.gc, xinfo.colours[SkyBlue]);
    XFillRectangle(xinfo.disp, xinfo.double_buffer, xinfo.gc, 0, 0,
                   xinfo.windAttr.width, xinfo.windAttr.height);

    //Draw everything to extra buffer, then copy over to main window.
    game->Draw();
    XCopyArea(xinfo.disp, xinfo.double_buffer, xinfo.wind, xinfo.gc, 0, 0,
              xinfo.windAttr.width, xinfo.windAttr.height, 0, 0);
}

//Run the game in a loop.
void Application::run() {
  XEvent event;
  KeySym key;        //Holds value of key pressed
  bool stopRunning = false;  //Indicates if the application should be stopped.

  //The following are for timing purposes. Time values are in microseconds.
  double init_time;          //Time at the beginning of a tick.
  double end_time;           //Time at the end of a tick involving painting.
  double desired_time;       //Desired time from a tick with painting to another
  double usleepSecs = 0;     //Time to sleep for a tick with painting.
  timeval te;                //Used to keep track of current time.
  int framecount = 0;        //Number of frames (mod frameSkip) gone through.

  //Desired time is how many microseconds per frame
  desired_time = 1000000.0 / fps;

  //Get the current time as the initial time.
  gettimeofday(&te, 0);
  init_time = te.tv_sec * 1000000.0 + te.tv_usec;

  while(true){
    //If any events, handle them.
    if (XPending(xinfo.disp) > 0){
      //XCheckWindowEvent(xinfo.disp, xinfo.wind, ButtonRelease, &event);  
      XNextEvent( xinfo.disp, &event );
      switch (event.type){
        case MotionNotify:
        case ButtonPress:
          game->StepHold(event.xbutton.x,event.xbutton.y);
          break;
        case ButtonRelease: 
          game->StepRelease(event.xbutton.x,event.xbutton.y);
      	  break;
        case KeyPress:
          key = XLookupKeysym((XKeyEvent *)&event,0);
      	  if (strcmp(XKeysymToString(key), "q") == 0) {
            stopRunning = true;
          } else {
            game->Step();
          }
      	  break;
      }
    } else {
      game->Step();
    }
    if (stopRunning) {
      break;  //End game when stopRunning is set to true
    }

    //If frameskips are enabled, only paint after a certain number of
    //frame drawing opportunities pass.
    if ((framecount + 1) % (frameskip + 1) == 0){
      framecount = 0;
      paint();
   
      //Should sleep until the desired time is reached. Sleep time is
      //the difference between desired time and the amount actually passed.
      gettimeofday(&te, 0);
      end_time = te.tv_sec * 1000000.0 + te.tv_usec;
      usleepSecs = desired_time - (end_time - init_time);

      //Only sleep if there's time left to sleep until the desired time.
      if (usleepSecs > 0) {
        usleep(usleepSecs);
      }
      init_time = end_time;  //Now, current time is new init_time.
    } else {
      framecount ++;
    }
    XFlush(xinfo.disp);
  }
}

