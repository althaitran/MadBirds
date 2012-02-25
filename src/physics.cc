#include "physics.h"

using namespace std;

//Constructor
Physics::Physics(int gravity, int spring_c): gravity(gravity),
                                             spring_c(spring_c){}

//Destructor
Physics::~Physics(){}

//Method to cause the hitter to bounce off the hittee, if they make contact
void Physics::HitBounce(Hittable *hitter, Hittable *hittee) {
  //See where the hittee was hit by the hitter.
  HitSection hitteeHS = hittee->GotHit(hitter);

  //To account for friction, the speed in the opposite axis of contact is
  //reduced by 1/(1 + mass) (reduces cases like floor sliding. Also, contact
  //only counts if the hittable is moving TOWARDS the area of contact.
  if ((hitter->getXSpeed() >= 0 && hitteeHS == Left) ||
      (hitter->getXSpeed() <= 0 && hitteeHS == Right)) {
    hitter->setXSpeed(-1*hitter->getXSpeed()/(1 + hitter->getMass()));
    hitter->setYSpeed(hitter->getYSpeed());
  } else if (hitter->getYSpeed() >= 0 && hitteeHS == Top) {
    //For floor contact, also reduce y_speed by a factor of 1/5, as
    //birds don't bounce as high as they're dropped (unless they're thrown).
    hitter->setYSpeed(-1*hitter->getYSpeed()/(1 + hitter->getMass()));
    hitter->setXSpeed(hitter->getXSpeed()/(1 + hitter->getMass()));
  } else if (hitter->getYSpeed() <= 0 && hitteeHS == Bottom) {
    hitter->setYSpeed(-1*hitter->getYSpeed());
    hitter->setXSpeed(hitter->getXSpeed()/(1 + hitter->getMass()));
  } 
}

//Dictates what occurs when a bird hits targets
void Physics::Hit(Bird * bird, list<Target *> &targets) {
  list<Target *>::iterator it;
  HitSection targetHS;  //Indicates where the target was hit by the bird;

  //See if bird makes contact with any of the targets
  for (it = targets.begin(); it != targets.end(); it ++) {
    targetHS = (*it)->GotHit(bird);

    //If a bird hits a target, the target dies.
    if (targetHS != None) {
       (*it)->setAliveStatus(false);
    } 
  }
}

//Dictates what occurs when a hittable hits terrain. Essentially, whichever 
//axis the hittable was hit in, reverse its speed in that direction.
void Physics::Hit(Hittable *hitter, list<Terrain *> &terrain) {
  list<Terrain *>::iterator it;

  //See if hittable makes contact with any of the terrain
  for (it = terrain.begin(); it != terrain.end(); it ++) {
    HitBounce(hitter, (*it));
  }
}

//Dictates what occurs when a hittable hits blocks. Essentially, whichever 
//axis the hittable was hit in, reverse its speed in that direction.
void Physics::Hit(Hittable *hitter, list<Block *> &blocks) {
  list<Block *>::iterator it;

  //See if hittable makes contact with any of the terrain
  for (it = blocks.begin(); it != blocks.end(); it ++) {
    //Make sure not to check a hittable with itself (if it's a block, this
    //can happen).
    if (hitter != (*it)) {
      HitBounce(hitter, (*it));
    }
  }
}

//Setter for gravity
void Physics::setGravity(int gravity) {
  this->gravity = gravity;
}

//Getter for gravity
int Physics::getGravity() {
  return gravity;
}

//Setter for spring_c
void Physics::setSpring(int spring) {
  spring_c = spring;
}

//Getter for spring_c
int Physics::getSpring() {
  return spring_c;
}
