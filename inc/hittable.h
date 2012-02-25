#ifndef __HITTABLE_H__
#define __HITTABLE_H__

#include "movable.h"

//Indicates the different areas that an object could be hit
//from (top, left, bottom, right, corners, or none).
enum HitSection{
  None,
  Top,
  TopLeft,
  Left,
  BottomLeft,
  Bottom,
  BottomRight,
  Right,
  TopRight
};

//Class to define all objects possessing a hitbox.
class Hittable: public Movable{
protected:
  //The following define the size of the object's hitbox.
  int width;
  int height;

  int mass;  //This is for purposes of calculating effects of friction

public:
  Hittable(int, int, int, int, int);   //Constructor
  virtual ~Hittable() = 0;  //Destructor

  //Getters
  int getWidth();
  int getHeight();
  int getMass();

  //Setters
  void setWidth(int);
  void setHeight(int);

  //Tells where this Hittable was hit by another, and returns that section.
  virtual HitSection GotHit(Hittable *);

  virtual void Draw() = 0;    //Method to draw this component.
};

#endif

