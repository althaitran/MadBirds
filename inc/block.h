#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "hittable.h"

#define blockWidth 30
#define blockHeight 30 
#define blockMass 5

//Class to define all block objects in the game.
class Block: public Hittable{

public:
  Block(int, int);   //Constructor
  ~Block();  //Destructor

  virtual void Draw();    //Method to draw this component.
};

#endif

