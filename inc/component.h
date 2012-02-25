#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "graphics.h"

//Class to define any component existing in a game (which should
//also be visible to the on the display used for the game).
class Component{
  static Graphics *graphics;
protected:
  //Coordinates on the display where the component will appear.
  int x;
  int y;

public:
  Component(int, int);   //Constructor
  virtual ~Component() = 0;  //Destructor

  static void setGraphics(Graphics *);//Method to set the display that would
                                      //draw out the component.
  static Graphics *getGraphics();     //Method to get the display used to draw
                                      //this component.

  //setter methods for x and y positions
  virtual void setXPos(int);
  virtual void setYPos(int);

  //getter methods for x and y positions
  int getXPos();
  int getYPos();

  virtual void Draw() = 0;        //Method to draw this component.
};

#endif

