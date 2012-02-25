#include <iostream>
#include <sstream>
#include <fstream>
#include "lvltextgen.h"

using namespace std;

//Constructor
LvlTextGen::LvlTextGen() {}

//Destructor
LvlTextGen::~LvlTextGen() {}

//Generates a level by setting the spawn points of the Sling, Bird, Target,
//Terrain, and Block objects
bool LvlTextGen::Generate(int level, int spring_c, int gravity, Sling **sling,
                          Bird **bird, list<Target *> &targets,
                          list<Terrain *> &terrain, list<Block *> &blocks){
  bool createSling = false;      //Keeps track of if a sling was ever made.
  ifstream lvlReader;            //File to read level info from
  stringstream fileNameStream;   //Stream to store the name of the file to read.
  string fileName;               //Name of the file to read.

  //Obtain the level file's name
  fileNameStream << lvlFolder << lvlPrefix << level << lvlSuffix;
  fileName = fileNameStream.str();

  lvlReader.open(fileName.c_str());  //Start reading contents of the file

  //Only generate anything if the level file exists.
  if (lvlReader.is_open()) {
    string curWord;             //Current word from file being read.

    lvlReader >> curWord;  //Read a word from lvlReader

    while (!lvlReader.eof()) {
      //Now, depending on the word, create a certain object.
      if (curWord == "sling") {     //Generate sling and bird
        //Next 2 items should indicate the position of the sling.
        int x, y;
        lvlReader >> x;
        lvlReader >> y;

        //Only if there was no trouble getting x and y do the sling and
        //bird get made.
        if (!lvlReader.fail()) {
          createSling = true;
          //Either initialize or modify sling, depending on its existence.
          if (*sling != 0) {
            (*sling)->setXPos(x);
            (*sling)->setYPos(y);
          } else {
            *sling = new Sling(x,y, spring_c);
            (*sling)->Hold();
          }

          //Either initialize or modify bird, depending on its existence.
          if (*bird != 0) {
            (*bird)->setXPos(x - 10);
            (*bird)->setYPos(y - 10);
            (*bird)->setXSpeed(0);
            (*bird)->setYSpeed(0);
            (*bird)->setOnSling(true);
            (*bird)->setYAccel(gravity);
          } else {
            *bird = new Bird(x - 10,y - 10);
            (*bird)->setYAccel(gravity);
            (*bird)->setOnSling(true);
          }
        } else {  //Couldn't read sling parameters. Thus, file is invalid.
          lvlReader.close();
          cout << "Could not read sling parameters. Level not loaded." << endl;
          return false;
        }
      } else if (curWord == "terrain") {   //Generate terrain
        //Next 4 words should indicate the position and size of terrain.
        int x, y, width, height;
        lvlReader >> x;
        lvlReader >> y;
        lvlReader >> width;
        lvlReader >> height;

        //If no problems occurred getting x, y, width, and height, create
        //a new terrain object, and store it in the terrain list.
        if (!lvlReader.fail()){
          Terrain *newTerrain = new Terrain(x, y, width, height);
          terrain.push_back(newTerrain);
        } else {  //Couldn't read terrain parameters. Thus, file is invalid.
          lvlReader.close();
          cout << "Could not read terrain parameters. Level not loaded." << endl;
          return false;
        }
      } else if (curWord == "block") {     //Generate block
        //Next 2 words should indicate the position of the blocks.
        int x, y;
        lvlReader >> x;
        lvlReader >> y;

        //If no problems occurred getting x and y, create a new block
        //object, and store it in the block list.
        if (!lvlReader.fail()){
          Block *newBlock = new Block(x, y);
          newBlock->setYAccel(gravity);
          blocks.push_back(newBlock);
        } else {  //Couldn't read block parameters. Thus, file is invalid.
          lvlReader.close();
          cout << "Could not read block parameters. Level not loaded." << endl;
          return false;
        }
      } else if (curWord == "target"){    //Generate target
        //Next 2 words should indicate the position of the targets.
        int x, y;
        lvlReader >> x;
        lvlReader >> y;

        //If no problems occurred getting x and y, create a new target
        //object, and store it in the block list.
        if (!lvlReader.fail()){
          Target *newTarget = new Target(x, y);
          newTarget->setYAccel(gravity);
          targets.push_back(newTarget);
        } else {  //Couldn't read target parameters. Thus, file is invalid.
          lvlReader.close();
          cout << "Could not read target parameters. Level not loaded." << endl;
          return false;
        }
      } else {  //Couldn't identify word. File is, therefore, invalid.
        lvlReader.close();
        cout << "Could not read file. Level not loaded." << endl;
        return false;
      }
      lvlReader >> curWord;  //Read next word from lvlReader
    }
    lvlReader.close();  //Make sure to close the reader before exiting.
  } else {  //If the file can't be read, then a level wasn't generated.
    return false;
  }
  //If a sling wasn't generated, then this level is invalid
  if (!createSling) {
    cout << "The level file doesn't create a sling. It is, therefore, invalid." << endl;
    return false;
  }

  return true;
}

