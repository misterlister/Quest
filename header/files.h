
#ifndef QUEST_FILESYSTEM_H
#define QUEST_FILESYSTEM_H

#include "../header/macros.h"
#include "../header/charSheet.h"
#include "../header/worldState.h"
#include "../header/menu.h"
#include <filesystem>

using std::filesystem::path;

void checkSaveDir(path saveDir);
void printSaves(path saveDir);
bool writeData(charSheet playerC, WorldState wState, string saveName);
bool writeCharacter(charSheet playerC, string &data);
bool writeWorld(WorldState wState, string &data);

#endif //QUEST_FILESYSTEM_H