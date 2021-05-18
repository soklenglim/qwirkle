#include "TileCodes.h"
#include "Tile.h"

Tile::Tile(const Tile &tile)
{
    this->col = tile.col;
    this->row = tile.row;
    this->colour = tile.colour;
    this->shape = tile.shape;
}

Tile::Tile(Colour colour, Shape shape, Row row, Col col)
{
    this->col = col;
    this->row = row;
    this->colour = colour;
    this->shape = shape;
}

Tile::Tile(Colour colour, Shape shape)
{
    this->colour = colour;
    this->shape = shape;
}

Tile::~Tile(){
}

void Tile::setPosition(Row row, Col col)
{
    this->col = col;
    this->row = row;
}

Colour Tile::getColour(){
    return colour;
}

Shape Tile::getShape(){
    return shape;
}

std::string Tile::toString(){
  std::map<Colour, std::string> color_map;
  std::map<Shape, std::string> shape_map;
  color_map[RED] = "\033[31m";
  color_map[ORANGE] = "\u001b[31;1m";
  color_map[GREEN] = "\033[32m";
  color_map[BLUE] = "\033[34m";
  color_map[YELLOW] = "\033[33m";
  color_map[PURPLE] = "\033[35m";
  color_map[' '] = "\033[37m";

  
  shape_map[CIRCLE] = "\u25CB";
  shape_map[STAR_4] = "\u2606";
  shape_map[DIAMOND] = "\u2662";
  shape_map[SQUARE] = "\u25A1";
  shape_map[STAR_6] = "\u2736";
  shape_map[CLOVER] = "\u2663";


  std::stringstream stream;

    stream << color_map[this->colour] << this->colour << shape_map[this->shape] << color_map[' '];

  return stream.str();
}