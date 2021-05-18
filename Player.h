
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "LinkedList.h"
#include <iostream>
#include <memory>
#include <string>

using std::shared_ptr;
using std::string;  

class Player
{
private:
    shared_ptr<LinkedList> hand;
    
public:
    Player();
    Player(string playerName);
    ~Player();

    string playerName;
    int score;

    std::shared_ptr<LinkedList> getHand();

    void setPlayerHand(shared_ptr<LinkedList> playerHand);
    void addScore(int score);
    void setName(string playerName);

    string getHandString();
    string printHandSave();
    string getName();
    
    int getScore();
};

#endif // ASSIGN2_PLAYER_H