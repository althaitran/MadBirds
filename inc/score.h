#ifndef __SCORE_H__
#define __SCORE_H__

#include "component.h"

//Class to define the score of a game.
class Score: public Component{
  int points;  //Amount of points currently scored in the game.

public:
  Score(int, int);   //Constructor
  ~Score();  //Destructor

  //Adder/Subtractor of points
  void addPoints(int);
  void subPoints(int);

  //Getter/Setter of points
  void setPoints(int);
  int getPoints();

  void Draw();    //Method to draw this component.
};

#endif
