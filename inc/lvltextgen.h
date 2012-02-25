#ifndef __LVLTEXTGEN_H__
#define __LVLTEXTGEN_H__

#include <string>
#include <list>
#include "sling.h"
#include "bird.h"
#include "target.h"
#include "block.h"
#include "terrain.h"
//#include "levelgenerator.h"

//Level file names should include the following
const std::string lvlFolder = "level/";
const std::string lvlPrefix = "level_";
const std::string lvlSuffix = ".lvl";

//Class to create levels in a game by generating the spawn points
//of slings, birds, blocks, terrain, and targets via reading a
//.lvl file.
class LvlTextGen /*: public LevelGenerator*/ { 

public:
  LvlTextGen();   //Constructor
  ~LvlTextGen();  //Destructor

  //Generates a level by setting the spawn points of the Sling, Bird, Target,
  //Terrain, and Block objects. Also, return whether or not a level was
  //actually generated.
  bool Generate(int, int, int, Sling **, Bird **, std::list<Target *> &,
                std::list<Terrain *> &, std::list<Block *> &);
};

#endif

