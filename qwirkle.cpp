
#include <iostream>
#include "Menu.h"

#define EXIT_SUCCESS 0

int main(void) {
   std::cout << "Welcome To Qwirkle!" << std::endl;

   Menu* menu = new Menu();
   menu->mainMenu();
   delete menu;

   return EXIT_SUCCESS;
}
