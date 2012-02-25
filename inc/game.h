#ifndef __GAME_H__
#define __GAME_H__

#include <list>
#include "graphics.h"
#include "lvltextgen.h"
#include "score.h"
#include "sling.h"
#include "bird.h"
#include "block.h"
#include "terrain.h"
#include "physics.h"
#include "target.h"

#define targetPoints 100
#define birdPoints 10

//This class holds all the data needed to run a game of MadBirds
class Game{
  Graphics *graphics;
  bool gameEnd;        //Indicates if all levels have been completed
  int level;           //Current level this game is in.
  LvlTextGen *lvlGen;  //Level generator for this game.
  Physics *physics;    //Physics engine used in this game.
  Score *curScore;     //Scorekeeper of this game
 
  //Every game should consist of a list of hittable objects, and a sling
  Sling *sling;
  Bird * bird;
  std::list<Terrain *> terrain;
  std::list<Block *> blocks;
  std::list<Target *> targets;

public:
  Game(Graphics *, int, int, int);  //Constructor
  ~Game();                          //Destructor

  void Clear(); //Method to clear the current game, clearing all lists and
                //deleting any hittable object and the sling.

  bool setLevel(int);  //Method to setup a game based on the level.

  void Step();  //Method to execute one step of this game (one step means all
                //object call "move").

  void StepHold(int, int);  //Similar to Step, except it handles mouse hold.

  void StepRelease(int, int); //Similar to Step, except it handles releases.

  void Draw();  //Method to draw all components in this game.
};

#endif
