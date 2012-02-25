#include "sling.h"
#include <iostream>
#include <string>
//Constructor
Sling::Sling(int x, int y, int spring): Movable(x,y), origin_x(x), origin_y(y),
                                        release_x(x), release_y(y),
                                        spring_const(spring), state(Held) {
}
//Destructor
Sling::~Sling() {}

//Method to set the state member to Held
void Sling::Hold() {
  state = Held;
}

//Method to set the state member to Released
void Sling::Release(){
  state = Released;

  release_y = y;
  release_x = x;

  //Calculate x- and y- speed, which are proportional to how far they've
  //been stretched from the origin.
  setXSpeed(-1 * spring_const * (release_x - origin_x));
  setYSpeed(-1 * spring_const * (release_y - origin_y));
}

void Sling::UnRelease() {
  state = Idle;
}

//Movement of sling differs from regular movable in that it elastically (will
//move back and forth about the origin). Hooke's Law is applied to calculate
//the accelerations per tick to achieve this effect.
void Sling::Move() {
  if (state == Released){
    //Released spring only moves until it reaches over the origin on the
    //opposide side of its release
    if ((release_x <= origin_x && x < origin_x) ||
        (release_x >= origin_x && x > origin_x) ||
        (release_y <= origin_y && y < origin_y) ||
        (release_y >= origin_y && y > origin_y)) { 
      Movable::Move();
    } else {
      x = origin_x;
      y = origin_y;
      UnRelease();
    }
  }
}

//Getter for released bool member
SlingState Sling::getState() {
  return state;
}

//Overrides Components setXPos to enforce a -50 to 50 range for the difference
//between x and origin_x
void Sling::setXPos(int x) {
  if (x - origin_x <= 50 && x - origin_x >= -50) {
    this->x = x;
  } else if (x- origin_x > 50) {
    this->x = origin_x + 50;
  } else {
    this->x = origin_x - 50;
  }
}

//Overrides Components setYPos to enforce a -50 to 50 range for the difference
//between y and origin_y
void Sling::setYPos(int y) {
  if (y - origin_y <= 50 && y - origin_y >= -50) {
    this->y = y;
  } else if (y - origin_y > 50) {
    this->y = origin_y + 50;
  } else {
    this->y = origin_y - 50;
  }
}

//Method to draw this component.
void Sling::Draw() {
  Component::getGraphics()->DrawSling(x, y, origin_x, origin_y);
}

