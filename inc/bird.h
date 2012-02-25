#ifndef __BIRD_H__
#define __BIRD_H__

#include "hittable.h"
#include <list>

#define birdWidth 30
#define birdHeight 30
#define birdMass 1
#define maxtPoints 10

//Trajectory point of a bird's flight
struct TrajPoint{
  int x;
  int y;
};

//Class to define all bird objects in the game.
class Bird: public Hittable{
  bool onSling;  //indicates if the Bird is still on the sling, and thus, tells
                 //if it should be falling.

  std::list<TrajPoint>tPoints;  //Tells what points in bird's trajectory to draw

public:
  Bird(int, int);   //Constructor
  ~Bird();  //Destructor

  void Move();  //This move differs from Movable's in that it accounts for if
                //acceleration should occur.

  void setOnSling(bool); //Setter for onSling member.
  bool getOnSling(); //Getter for onSling member.

  void Draw();    //Method to draw this component.
};

#endif

