#ifndef __TARGET_H__
#define __TARGET_H__

#include "hittable.h"

#define targetWidth 30
#define targetHeight 30
#define targetMass 1

//Class to define all target objects in the game.
class Target: public Hittable{
  bool alive;  //living status of this target (if a bird hasn't hit it yet)
public:
  Target(int, int);   //Constructor
  ~Target();  //Destructor

  //Setter/getter of alive status
  void setAliveStatus(bool);
  bool isAlive();

  virtual void Draw();    //Method to draw this component.
};

#endif

