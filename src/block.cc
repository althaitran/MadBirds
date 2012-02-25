#include "block.h"

//Constructor
Block::Block(int x, int y): Hittable(x, y, blockWidth, blockHeight, blockMass){}

//Destructor
Block::~Block() {}

//Method to draw this component.
void Block::Draw() {
  Component::getGraphics()->DrawBlock(x, y);
}

