#ifndef __PHYSICS_H__
#define __PHYSICS_H__

#include <list>
#include "bird.h"
#include "block.h"
#include "target.h"
#include "terrain.h"

//This class acts as the physics engine of a game. Pretty much contains
//methods to handle different kinds of collisions, as well as physics constant
//like gravitational force or spring constant (for sling).
class Physics {
  int gravity;  //Indicates the graviational pull that the game will use.
  int spring_c; //Indicates the spring constant that will be used for sling.
public:
  Physics(int, int);   //Constructor
  ~Physics();  //Destructor

  void HitBounce(Hittable *, Hittable *); //Method to cause the 1st Hittable to
                                          //bounce off the 2nd (which stays put)

  void Hit(Bird *, std::list<Target *>&);  //Dictates what occurs when a bird
                                           //hits targets

  void Hit(Hittable *, std::list<Terrain *>&);  //Dictates what occurs when a 
                                                //hittable hits terrain.

  void Hit(Hittable *, std::list<Block *>&);  //Dictates what occurs when a 
                                              //hittable hits blocks.

  //Gravity getter/setter
  void setGravity(int);
  int getGravity();

  //Spring_c getter/setter
  void setSpring(int);
  int getSpring();
};

#endif

