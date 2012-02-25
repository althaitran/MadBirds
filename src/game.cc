#include "game.h"

using namespace std;

//Constructor
Game::Game(Graphics * g, int spring_c, int gravity, int level) {
  lvlGen = new LvlTextGen;

  physics = new Physics(gravity, spring_c);

  curScore = new Score(30, 30);

  graphics = g;
  Component::setGraphics(g);

  //Generate the level with the level generator. Also, if a level can't be set,
  //then it is assumed all levels have been completed
  gameEnd = (!setLevel(level));
}

//Destructor
Game::~Game() {
  Clear();
  delete curScore;
  delete physics;
  delete lvlGen;

  //Only delete bird and sling if they have already been initialized
  if (sling != 0) delete sling;
  if (bird != 0) delete bird;
}

//Method to clear the current game, clearing all lists and deleting any
//hittable object and the sling.
void Game::Clear() {
  list<Terrain *>::iterator terrain_it;
  list<Block *>::iterator block_it;
  list<Target *>::iterator target_it;

  //delete all terrain.
  for (terrain_it = terrain.begin(); terrain_it != terrain.end();
       terrain_it ++) {
    delete (*terrain_it);
  }
  terrain.clear();

  //delete all blocks.
  for (block_it = blocks.begin(); block_it != blocks.end(); block_it ++) {
    delete (*block_it);
  }
  blocks.clear();

  //delete all targetss.
  for (target_it = targets.begin(); target_it != targets.end(); target_it ++) {
    delete (*target_it);
  }
  targets.clear();
}

//Method to setup a game based on the level.
bool Game::setLevel(int level) {
  this->level = level;
  return lvlGen->Generate(level, physics->getSpring(), physics->getGravity(),
                          &sling, &bird, targets, terrain, blocks); 
}

//Method to execute one step of htis game (one step means all objects call 
//"move").
void Game::Step(){
  if (!gameEnd) {
    list<Terrain *>::iterator terrain_it;
    list<Block *>::iterator block_it;
    list<Target *>::iterator target_it;
    list<Target *>::iterator target_tmp;   //Points to current item in targets.
                                           //Needed because targets can be deleted

    //First, see if the bird made contact with another object
    physics->Hit(bird, terrain);
    physics->Hit(bird, blocks);
    physics->Hit(bird, targets);

    //See if any targets made any contact with other objects (other than bird)
    for (target_it = targets.begin(); target_it != targets.end(); target_it ++) {
      physics->Hit((*target_it), terrain);
      physics->Hit((*target_it), blocks);
    }

    //See if any blocks made any contact with other objects (other than bird)
    for (block_it = blocks.begin(); block_it != blocks.end(); block_it ++) {
      physics->Hit((*block_it), terrain);
      physics->Hit((*block_it), blocks);
    }
 
    //See if the bird is still on the sling (only happens when sling is released).
    //Then, try to move the bird.
    if (sling->getState() == Released) {
      bird->setOnSling(false);
    }
    bird->Move();

    //Move the sling.
    sling->Move();

    //Move the blocks.
    for (block_it = blocks.begin(); block_it != blocks.end(); block_it ++) {
      (*block_it)->Move();
    }

    //Move the targets
    for (target_it = targets.begin(); target_it != targets.end(); ) {
      //Update the next target_it value, and store the old one in target_tmp.
      target_tmp = target_it;
      target_it++;

      //See if the target is dead; if so, remove it from the list, and delete it.
      if (!(*target_tmp)->isAlive()) {
        targets.remove(*target_tmp);
        delete (*target_tmp);
        curScore->addPoints(targetPoints);
      } else {
        (*target_tmp)->Move();
      }
    }

    //Move the terrain
    for (terrain_it = terrain.begin(); terrain_it != terrain.end();
         terrain_it ++) {
      (*terrain_it)->Move();
    }

    //If no more targets, try to change the level.
    if (targets.size() == 0) {
      Clear();
      gameEnd = (!setLevel(level + 1));
    }
  }
}

//Similar to Step, except it handles mouse hold.
void Game::StepHold(int x, int y) {
  sling->Hold();
  sling->setXPos(x);
  sling->setYPos(y);

  //When holding sling, bird also moves.
  bird->setOnSling(true);
  bird->setXPos(sling->getXPos() - bird->getWidth() / 2);
  bird->setYPos(sling->getYPos() - bird->getWidth() / 2);

  Step();
}

//Similar to Step, except it handles mouse release.
void Game::StepRelease(int x, int y) {
  sling->Release();

  //Bird starts moving at the same velocity as the sling.
  bird->setXSpeed(sling->getXSpeed());
  bird->setYSpeed(sling->getYSpeed());

  //Since the bird is being launched, subtract the score by the
  //bird's point worth.
  curScore->subPoints(birdPoints);

  Step();
}

//Method to draw all components in this game.
void Game::Draw(){
  graphics->DrawBackground();
  //If the game's over, draw the game over screen. Otherwise,
  //draw the game playing out.
  if (gameEnd) {
    graphics->DrawGameEnd();
  } else {
    sling->Draw();  

    list<Terrain *>::iterator terrain_it;
    list<Block *>::iterator block_it;
    list<Target *>::iterator target_it;

    //Draw the terrain
    for (terrain_it = terrain.begin(); terrain_it != terrain.end();
         terrain_it ++) {
      (*terrain_it)->Draw();
    }

    //Draw the blocks
    for (block_it = blocks.begin(); block_it != blocks.end(); block_it ++) {
      (*block_it)->Draw();
    }

    //Draw the targets
    for (target_it = targets.begin(); target_it != targets.end(); target_it ++) {
      (*target_it)->Draw();
    }

    //Draw the bird
    bird->Draw();
  }
  //Here, all foreground objects (score and level text) are drawn. 
  graphics->DrawForeground();
  graphics->DrawLevel(150,30,level);
  curScore->Draw();
}
