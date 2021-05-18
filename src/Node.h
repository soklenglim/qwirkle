
#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"
#include <memory>

class Node {
public:
   Node();
   ~Node();
   
   std::shared_ptr<Tile> tile;
   std::shared_ptr<Node> next; 
};

#endif // ASSIGN2_NODE_H
