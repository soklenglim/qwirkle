#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "Engine.h"
#include "Board.h"

class Menu {

public:
    /* constructor */
    Menu();

    /* Deconstructor */
    ~Menu();

    /* Game Menu */
    void mainMenu();

private:
    Engine* e = new Engine();
    Board* b = new Board();

    std::string playerName;
    Player* players[PLAYERS];
    
    /* Menu functions */
    void newGame();
    void loadGame();
    void showCredits();
    void quit();

    /* Extra Functions */
    bool checkPlayerName(std::string name);
    bool isCapital(char x);

};
#endif // ASSIGN2_MENU_H