#ifndef __MOVABLE_H__
#define __MOVABLE_H__

#include "component.h"

//The following is the max number of ticks allowed to wait for an update to an
//object's position. Could be seen as the maximum period. If any speed is set
//to be greater than maxTicks, the affected period will just become 1. 
const int maxTicks = 1000;

//Class to define all movable objects in a game.
class Movable: public Component{
  //The speeds really indicate the frequency at which the Movable component
  //updates its position in terms of game logic. They're measured in
  //"pixel/maxTick".
  int x_speed;
  int y_speed;

  //The acceleration behaves just as expected with respect to real-world physics
  //, in that it indicates the change in speed. Change in speed only occurs when
  //maximum period (maxTicks) has been reached.
  int x_accel;
  int y_accel;

protected: 
  int ticks;  //Number of "ticks" that have been reached. It's reset to 0 once
              //it's reached maxTicks.

  //Number of "ticks" required to force an update in the object's position.
  int x_period_speed;
  int y_period_speed;

  //Number of "ticks" required to force an update in the object's speed.
  int x_period_accel;
  int y_period_accel;

public:
  Movable(int, int);       //Constructor
  virtual ~Movable() = 0;  //Destructor

  //Speed getters/setters
  void setXSpeed(int);
  int getXSpeed();
  void setYSpeed(int);
  int getYSpeed();

  //Acceleration getters/setters
  void setXAccel(int);
  int getXAccel();
  void setYAccel(int);
  int getYAccel();

  virtual void Move();    //Method to change x- and y- speeds (if needed), and
                          //move according to such speeds.

  virtual void Draw() = 0;    //Method to draw this component.

};

#endif

