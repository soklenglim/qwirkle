#include "Player.h"


Player::Player(string playerName)
{
    this->playerName = playerName;
    this->score = 0;
}

Player::Player(){
    this->score = 0;
}


Player::~Player()
{
}

void Player::setPlayerHand(shared_ptr<LinkedList> playerHand)
{
    this->hand = playerHand;
}

string Player::printHandSave()
{
    return "";
}

std::shared_ptr<LinkedList> Player::getHand(){

    return hand;
}

string Player::getHandString()
{
    string printHand = "";

    for(int i = 0; i < hand->size(); i++) {
        if(i == (hand->size() - 1))
        {
            printHand = printHand + hand->get(i)->colour + std::to_string(hand->get(i)->shape);
        }
        else
            printHand = printHand + hand->get(i)->colour + std::to_string(hand->get(i)->shape) + ",";
    }

    return printHand;
}

string Player::getName()
{
    return playerName;
}

void Player::setName(string name){
    this->playerName = name;
}

int Player::getScore(){
    return score;
}

void Player::addScore(int score){
    this->score = score;
}