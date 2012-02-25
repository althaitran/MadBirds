#include "score.h"

//Constructor
Score::Score(int x, int y): Component(x, y), points(0){}; 

//Destructor
Score::~Score(){}; 

//Method to add onto the current number of points
void Score::addPoints(int pts) {
  points += pts;
}

//Method to subtract from the current number of points
void Score::subPoints(int pts) {
  points -= pts;
}

//Method to set the points for this game.
void Score::setPoints(int pts) {
  points = pts;
}

//Method to retrieve the current points for the game.
int Score::getPoints() {
  return points;
}

//Method to draw the score on the screen.
void Score::Draw() {
  Component::getGraphics()->DrawScore(x,y, points);
}

