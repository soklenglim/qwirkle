
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H
#include <string>
#include "Node.h"
#include "map"
#include <sstream>
#include "TileCodes.h"



using std::string; 

class LinkedList {
public:


    LinkedList();
    ~LinkedList();
    LinkedList(LinkedList& other);

    int size();

    std::shared_ptr<Tile> get(int index);

    void addFront(std::shared_ptr<Tile> data);
    void addBack(std::shared_ptr<Tile> data);

    std::shared_ptr<Tile> removeFront();
    void removeBack();
    void removeIndex(int index);
    int checkTile(string inputTile);
    void clear();
    std::string toStringColourAndShape(bool tiles);

private:
    std::shared_ptr<Node> head;
};

#endif // ASSIGN2_LINKEDLIST_H
