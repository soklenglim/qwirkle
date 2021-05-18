#include "Menu.h"

#define NEWGAME 1
#define LOADGAME 2
#define SHOWCREDIT 3
#define QUIT 4

Menu::Menu(){}

Menu::~Menu() {}

void Menu::mainMenu() {
    int menuOption;
    //print menu
    std::cout   << "--------Menu--------\n"
                << "1. New Game\n"
                << "2. Load Game\n"
                << "3. Show Credits\n"
                << "4. Quit\n> ";
    do {
        //get user input
        std::cin >> menuOption;
        //check if user input ctrl+d
        if (std::cin.eof()) {
            quit();
        }else {
            //if user input anything else than number, this will run
            while (std::cin.fail()) {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a number...\n> ";
                std::cin >> menuOption;
                if (std::cin.eof()) {
                    quit();
                }
            }
            if (menuOption == NEWGAME) {
                newGame();
            } else if (menuOption == LOADGAME) {
                loadGame();
            } else if (menuOption == SHOWCREDIT) {
                showCredits();
            } else if (menuOption == QUIT) {
                quit();
            } else {
                std::cout<<"Sorry, invalid option...\n> ";
                continue;
            }
        }
    }while(menuOption != NEWGAME || menuOption != LOADGAME || menuOption != SHOWCREDIT || menuOption != QUIT);
}

void Menu::newGame() {
    std::cout << "Starting a new game...\n" << std::endl;
    //get both player names via std::cin
    for(int i=0; i < PLAYERS; i++){
        bool check = false;
        std::cout << "Enter a name for Player "<<i+1<<" (Uppercase characters only!)\n> ";
        std::cin >> playerName;
        if (std::cin.eof()) {
            quit();
        }else{
            while(check != true){
                //check if player name is valid
                if(checkPlayerName(playerName) != true){
                    std::cout<<"Sorry, Invalid Player's name\n> ";
                    std::cin >> playerName;
                    if (std::cin.eof()) {
                        quit();
                    }
                }else{
                    this->players[i] = new Player(playerName);
                    //if i > 0, it means current input is player 2 name
                    //so it will check if the name matches player one's
                    if(i>0){
                        if(this->players[i]->getName() == this->players[i-1]->getName()){
                            std::cout<<"Sorry, this name is already taken...\n> ";
                            std::cin >> playerName;
                            if (std::cin.eof()) {
                                quit();
                            }
                            this->players[i]->setName(playerName);
                        } else {
                            check = true;
                        }
                    } else {
                        check = true;
                    }
                }
            }
        }
    }
    e->startGame(players, PLAYERS);
    delete e;
    quit();
}

void Menu::loadGame() {
    std::string filename;
    bool validFile = false;

    //get file name via std::cin
    while(!validFile){
        std::ifstream in;
        std::cout << "Enter a file name to load from\n> ";
        std::cin >> filename;
        if (std::cin.eof()) {
            quit();
        }else{
            //open file from save_game folder
            in.open("save_game/" + filename);
            if(in.fail()){
                std::cout << "Please enter a correct file name..." << std::endl;
            } else{
                validFile = true;
            }
            in.close();
        }
    }
    e->loadGame(filename);
    quit();
}

void Menu::showCredits() {
    std::cout<<"------------------------------------\n"
             <<"-------------Team-MAST--------------\n"
             <<"------------------------------------\n"
             <<"Name: Monkolsophearith Prum\n"
             <<"Student ID: s3848409\n"
             <<"Email: s3848409@student.rmit.edu.au\n" 
             <<"------------------------------------\n" 
             <<"Name: Anmol Kumar\n"
             <<"Student ID: s3545259\n" 
             <<"Email: s3545259@student.rmit.edu.au\n" 
             <<"------------------------------------\n" 
             <<"Name: Sokleng Lim\n"
             <<"Student ID: s3813756\n" 
             <<"Email: s3813756@student.rmit.edu.au\n" 
             <<"------------------------------------\n" 
             <<"Name: Tony Peter Baker\n" 
             <<"Student ID: s3622250\n" 
             <<"Email: s3622250@student.rmit.edu.au\n" 
             <<"------------------------------------\n"<<std::endl;
    mainMenu();
}

void Menu::quit(){
  std::cout << "Goodbye!" <<std::endl;
  exit(0);
}

//check player name function
bool Menu::checkPlayerName(std::string name){
    bool check = false;
    //check if name is not empty and if it's all capital characters by counting the length of capital characters
    //in the name and compare it with the name's length
    if (!name.empty()){
        uint64_t count = 0;
        for(uint64_t i = 0; i < name.length(); i++){
            if(isCapital(name[i]) == true){
                ++count;
            }
        }
        if (count == name.length()){
            check = true;
        }
    }
    return check;
}

//check if a character is capital
bool Menu::isCapital(char x)
{
    bool cap = false;
    if (x >='A' && x <= 'Z')    cap = true;
    return cap;
}
