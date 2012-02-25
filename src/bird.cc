#include "bird.h"

using namespace std;

//Constructor
Bird::Bird(int x, int y): Hittable(x, y, birdWidth, birdHeight, birdMass),
                          onSling(false){}

//Destructor
Bird::~Bird() {}

//This move differs from Movable's in that it accounts for if the bird is
//on the sling.
void Bird::Move() {
  if (!onSling) {
    Movable::Move();

    //Every once in a while, add a trajectory point ot the
    //trajectory list. Don't do so if the bird is stationary, though.
    if (ticks % maxTicks == 0 && (Movable::getYSpeed() != 0 ||
         Movable::getXSpeed() != 0)) {
      //To ensure there is no stack overflow, only allow
      //50 trajectory points to exist for a bird.
      if (tPoints.size() >= 50) {
        tPoints.pop_front();
      }
      TrajPoint ntPoint;
      ntPoint.x = x;
      ntPoint.y = y;
      tPoints.push_back(ntPoint);
    }
  } else {
    //Clear the trajectory points if the bird isn't airborne
    if (!tPoints.empty()) {
      tPoints.clear();
    }
  }
}

//Setter for onSling member.
void Bird::setOnSling(bool onSling) {
  this->onSling = onSling;
}

//Getter for onSling member.
bool Bird::getOnSling() {
  return onSling;
}

//Method to draw this component.
void Bird::Draw() {
  //Draw this bird's trajectory.
  list<TrajPoint>::iterator it;
  for (it = tPoints.begin(); it != tPoints.end(); it++) {
    Component::getGraphics()->DrawTrajectory((*it).x, (*it).y);
  }

  //After, draw the bird, itself
  Component::getGraphics()->DrawBird(x, y);
}

