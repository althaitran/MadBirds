#include "hittable.h"
#include <iostream>
#include <string>

//Constructor
Hittable::Hittable(int x, int y, int w, int h, int m): Movable(x, y),
                                                width(w),
                                                height(h),
                                                mass(m) {}
//Destructor
Hittable::~Hittable(){}

//Width getter
int Hittable::getWidth() {
  return width;
}

//Height getter
int Hittable::getHeight() {
  return height;
}

//Mass getter
int Hittable::getMass() {
  return mass;
} 

//Width setter
void Hittable::setWidth(int width) {
  this->width = width;
}

//Height setter
void Hittable::setHeight(int height) {
  this->height = height;
}

//Tells where this Hittable was hit by another, and returns that section.
HitSection Hittable::GotHit(Hittable *hitter) {
  if (hitter->getXPos() + hitter->getWidth() == x && ((hitter->getYPos() >= y &&
      hitter->getYPos() <= y + height) ||
      (hitter->getYPos() + hitter->getHeight() >= y &&
      hitter->getYPos() + hitter->getHeight() <= y + height))) {  //Left
    return Left;
  } else if (hitter->getXPos() == x + width && ((hitter->getYPos() >= y &&
      hitter->getYPos() <= y + height) ||
      (hitter->getYPos() + hitter->getHeight() >= y &&
      hitter->getYPos() + hitter->getHeight() <= y + height))){  //Right
    return Right;
  } else if (hitter->getYPos() + hitter->getHeight() == y &&
      ((hitter->getXPos() >= x && hitter->getXPos() <= x + width) ||
      (hitter->getXPos() + hitter->getWidth() >= x &&
      hitter->getXPos() + hitter->getWidth() <= x + width))) {  //Top
    return Top;
  } else if (hitter->getYPos() == y + height && ((hitter->getXPos() >= x &&
      hitter->getXPos() <= x + width) ||
      (hitter->getXPos() + hitter->getWidth() >= x &&
      hitter->getXPos() + hitter->getWidth() <= x + width))) {  //Bottom
    return Bottom;
  }
  return None;  //If none of the above applied, hitter didn't hit this object.
}

