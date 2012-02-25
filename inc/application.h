#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "game.h"
#include "maingraphics.h"

//An Application is used to run a game, and handle certain
//aspects of the game that the game, itself, shouldn't really
//look into, such as what kind of graphics should be used.
class Application {
  Game *game;
  Graphics *graphics;
  XInfo xinfo;

  int fps;        //(desired) frames per second
  int frameskip;  //Amount of frames to skip before rendering.
  
public:
  Application(int, int, int, int, int);  //Constructor
  ~Application(); //Destructor

  void paint();  //Paint a frame of gameplay.

  void run();   //Run the game in a loop.
};

#endif

