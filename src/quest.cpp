#include <iostream>
#include <string>
#include <cctype>
#include "../header/charSheet.h"
#include "../header/item.h"
#include "../header/creature.h"
#include "../header/macros.h"
#include "../header/menu.h"
#include "../header/locations.h"

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void startGame(charSheet player, WorldState wState);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
   CLEAR;
   charSheet player;
   makeCharacter(player);
   WorldState(wState);
   CLEAR;
   bool quit = false;
   while(!quit) {
      quit = menu(player, wState);
      cout << "Game Stuff Happens" << endl;
      startGame(player, wState);
      press_enter();
   }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




void startGame(charSheet player, WorldState wState) {
   CLEAR;
   cout << "Here is where things will happen. Blah Blah." << endl;
   press_enter();
   CLEAR;
   cout << "More stuff here" << endl;
   press_enter();
}