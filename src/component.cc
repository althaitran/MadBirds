#include "component.h"

using namespace std;

Graphics *Component::graphics = 0;  //Set the graphics to be 0, initially.

//Constructor
Component::Component(int x, int y): x(x), y(y) {}

//Destructor
Component::~Component(){}

//Method to set what kind of display would be used to
//draw this component.
void Component::setGraphics(Graphics *g) {
  graphics = g;
}

//Method to get the display used to draw this component.
Graphics *Component::getGraphics() {
  return graphics;
}

//Method to set the x position for a component
void Component::setXPos(int x) {
  this->x = x;
}

//Method to set the y position for a component
void Component::setYPos(int y) {
  this->y = y;
}

//Method to get the x position for a component
int Component::getXPos(){
  return x;
}

//Method to get the y position for a component
int Component::getYPos(){
  return y;
}

