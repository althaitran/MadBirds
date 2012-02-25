#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include "hittable.h"
#define terrainMass 10

//Class to define all Terrain objects in the game. Terrain includes the
//ground, wall, or ceiling (essentially, things that shouldn't be subject to
//gravity, or move upon getting hit. They also have variable size.
class Terrain: public Hittable{

public:
  Terrain(int, int, int, int);   //Constructor
  ~Terrain();  //Destructor

  virtual void Draw();    //Method to draw this component.
};

#endif

