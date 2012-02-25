#ifndef __SLING_H__
#define __SLING_H__

#include "movable.h"

//States in which the sling could be in. Mostly used
//to see if it should be subject to a x- and y- speed.
enum SlingState {
  Idle,
  Held,
  Released,
};

//Class to define all sling objects in the game.
class Sling: public Movable{
  //origin = original placement of the center of the sling.
  int origin_x;
  int origin_y;

  //release = where the sling is released at.
  int release_x;
  int release_y;

  int spring_const; //Used as the multiplier for how fast the sling will
                    //toss a bird

  SlingState state;  //Indicates the current state of the sling (idle, held,
                     //or released.

public:
  Sling(int, int, int);   //Constructor
  ~Sling();  //Destructor

  void Hold();       //Method to set the state member to Held

  void Release();    //Method to set the state member to Released

  void UnRelease();  //Method to set the state member to Idle

  SlingState getState();  //Getter for released bool member

  //Overrides Component's setters so as to enforce a -50 to 50 difference range
  //for x and y from origin
  void setXPos(int);
  void setYPos(int);

  void Move();  //Movement of sling differs from regular movable in that it
                //elastically (will move back and forth about the origin).

  void Draw();    //Method to draw this component.
};

#endif

