
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
