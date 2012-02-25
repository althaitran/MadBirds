#include "target.h"

//Constructor
Target::Target(int x, int y): Hittable(x, y, targetWidth, targetHeight,
                              targetMass), alive(true){} 

//Destructor
Target::~Target() {}

//Setter of alive status
void Target::setAliveStatus(bool alive) {
  this->alive = alive;
}

//Getter of alive status
bool Target::isAlive() {
  return alive;
}

//Method to draw this component.
void Target::Draw() {
  Component::getGraphics()->DrawTarget(x, y, alive);
}

