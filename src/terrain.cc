#include "terrain.h"

//Constructor
Terrain::Terrain(int x, int y, int width, int height):
  Hittable(x, y, width, height, terrainMass){} 

//Destructor
Terrain::~Terrain() {}

//Method to draw this component.
void Terrain::Draw() {
  Component::getGraphics()->DrawTerrain(x, y, width, height);
}

