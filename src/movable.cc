#include "movable.h"

//Constructor
Movable::Movable(int x, int y): Component(x, y),
                                x_speed(0),
                                y_speed(0),
                                x_accel(0),
                                y_accel(0), 
                                ticks(0),
                                x_period_speed(1),
                                y_period_speed(1),
                                x_period_accel(1),
                                y_period_accel(1){}

//Destructor
Movable::~Movable() {}

//Setter of x_speed. Also sets the period.
void Movable::setXSpeed(int x_speed) {
  this->x_speed = x_speed;

  //to ensure no division by 0 occurs, the following if-statement is made.
  if (x_speed > 0){
    //In the case where x_speed > maxTicks, set x_period to 1 to avoid period 0.
    if (x_speed <= maxTicks) {
      x_period_speed = maxTicks / x_speed;
    } else {
      x_period_speed = 1;
    }
  } else if (x_speed < 0) {
    //In the case where x_speed < maxTicks, set x_period to 1 to avoid period 0.
    if (x_speed >= -maxTicks) {
      x_period_speed = 0 - (maxTicks / x_speed);
    } else {
      x_period_speed = -1;
    }
  } else {
    x_period_speed = maxTicks;
  }
}

//getter for x_speed.
int Movable::getXSpeed() {
  return x_speed;
}

//setter for y_speed.
void Movable::setYSpeed(int y_speed) {
  this->y_speed = y_speed;

  //to ensure no division by 0 occurs, the following if-statement is made.
  if (y_speed > 0){
    //In the case where y_speed > maxTicks, set y_period to 1 to avoid period 0.
    if (y_speed <= maxTicks) {
      y_period_speed = maxTicks / y_speed;
    } else {
      y_period_speed = 1;
    }
  } else if (y_speed < 0) {
    //In the case where y_speed < maxTicks, set y_period to 1 to avoid period 0.
    if (y_speed >= -maxTicks) {
      y_period_speed = 0 - (maxTicks / y_speed);
    } else {
      y_period_speed = -1;
    }
  } else {
    y_period_speed = maxTicks;
  }
}

//getter for y_speed.
int Movable::getYSpeed() {
  return y_speed;
}

//setter for x_accel.
void Movable::setXAccel(int x_accel) {
  this->x_accel = x_accel;

  //to ensure no division by 0 occurs, the following if-statement is made.
  if (x_accel > 0){
    //In the case where x_accel > maxTicks, set x_period to 1 to avoid period 0.
    if (x_accel <= maxTicks) {
      x_period_accel = maxTicks / x_accel;
    } else {
      x_period_accel = 1;
    }
  } else if (x_accel < 0) {
    //In the case where x_accel < maxTicks, set x_period to 1 to avoid period 0.
    if (x_accel >= -maxTicks) {
      x_period_accel = 0 - (maxTicks / x_accel);
    } else {
      x_period_accel = -1;
    }
  } else {
    x_period_accel = maxTicks;
  } 
}

//getter for x_accel.
int Movable::getXAccel() {
  return x_accel;
}

//setter for y_accel.
void Movable::setYAccel(int y_accel) {
  this->y_accel = y_accel;

  //to ensure no division by 0 occurs, the following if-statement is made.
  if (y_accel > 0){
    //In the case where y_accel > maxTicks, set y_period to 1 to avoid period 0.
    if (y_accel <= maxTicks) {
      y_period_accel = maxTicks / y_accel;
    } else {
      y_period_accel = 1;
    }
  } else if (y_accel < 0) {
    //In the case where y_accel < maxTicks, set y_period to 1 to avoid period 0.
    if (y_accel >= -maxTicks) {
      y_period_accel = 0 - (maxTicks / y_accel);
    } else {
      y_period_accel = -1;
    }
  } else {
    y_period_accel = maxTicks;
  }
}

//getter for y_accel.
int Movable::getYAccel() {
  return y_accel;
}


//Method to change x- and y- speeds (if needed), and move
//according to such speeds. 
void Movable::Move() {
  //Check for position change in x-domain. If x_period is 0, just update
  //position every time (maximum speed).
  if (ticks % x_period_speed == 0 && ticks > 0) {
    //Check for which direction to move in x.
    if (x_speed > 0) {
      x += 1;
    } else if (x_speed < 0) {
      x -= 1;
    }
  }

  //Check for speed change in x_domain
  if (ticks % x_period_accel == 0 && ticks > 0) {
    //Check for which direction to change x's speed in.
    if (x_accel > 0) {
      setXSpeed(x_speed + 1);
    } else if (x_accel < 0) {
      setXSpeed(x_speed - 1);
    }
  }

  //Check for position change in y-domain.
  if (ticks % y_period_speed == 0 && ticks > 0) {
    //Check for which direction to move in y.
    if (y_speed > 0) {
      y += 1;
    } else if (y_speed < 0) {
      y -= 1;
    }
  }

  //Check for speed change in y-domain.
  if (ticks % y_period_accel == 0 && ticks > 0) {
    //Check for which direction to move in y.
    if (y_accel > 0) {
      setYSpeed(y_speed + 1);
    } else if (y_accel < 0) {
      setYSpeed(y_speed - 1);
    }
  }

  //If maxTicks is reached, reset the tick count
  if (ticks >= maxTicks) {
    ticks = 0;
  } else {
    ticks ++;  //Otherwise, just update the tick count
  }
}

