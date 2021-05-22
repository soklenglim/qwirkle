#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include "Type.h"
#include "map"
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <time.h>

class Tile {
public:
   Tile();
   Tile(Colour colour, Shape shape);
   Tile(Colour colour, Shape shape, Row row, Col col);
   Tile(const Tile &tile);
   ~Tile();

   Colour colour;
   Shape  shape;
   
   Row row;
   Col col;

   void setPosition(Row row, Col col);
   bool empty();
   Colour getColour();
   Shape getShape();
};

#endif // ASSIGN2_TILE_H
