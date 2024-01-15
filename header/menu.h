
#ifndef QUEST_MENU_H
#define QUEST_MENU_H

#include "../header/macros.h"
#include "../header/charSheet.h"
#include "../header/worldState.h"
#include "../header/files.h"

#include <filesystem>

using std::filesystem::path;

int makeChoice(int numCh);
char yesNo();
bool menu(charSheet playerC, WorldState wState);
void press_enter();
bool saveGame(charSheet playerC, WorldState wState);
bool loadSave(charSheet &playerC, WorldState &wState);


#endif //QUEST_MENU_H