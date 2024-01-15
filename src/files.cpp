
#include "../header/files.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <filesystem>
#include <regex>

using std::filesystem::path;
using std::filesystem::directory_iterator;
using std::cout;
using std::endl;
using std::ofstream;
using std::to_string;
using std::regex;
using std::regex_replace;


void checkSaveDir(path saveDir) {
    if(!is_directory(saveDir)) {
        create_directory(saveDir);
    }
}

void printSaves(path saveDir) {
    string currentSave = "";
    int count = 0;
    cout << "\nSave Games:" << endl;
    regex path(SAVEREG);
    for(const auto &file : directory_iterator(saveDir)) {
        currentSave = file.path();
        currentSave = regex_replace(currentSave, path, "");
        if(currentSave[0] != '.') {
            count++;
            cout << currentSave << endl;
        }
    }
    if(count == 0) {
        cout << "None currently exist" << endl;
    }
    cout << endl;
}


bool writeData(charSheet playerC, WorldState wState, string saveName) {
    bool valid = true;
    string writeLoc = SAVEDIR;
    string saveFileName = writeLoc + saveName;
    cout << saveFileName;
    ofstream saveFile;
    saveFile.open(saveFileName);
    string characterData = "";
    string worldData = "";
    string completeData = "";
    //cancel save if the character data is invalid
    if(!writeCharacter(playerC, characterData)) {
        //ERROR
        valid = false;
    //cancel save if the world data is invalid
    /*} else if(!writeWorld(wState, worldData)) {
        //ERROR
        valid = false;
    //concatenate both data sections and write them to the save file
    */
    } else {
        completeData = characterData + worldData;
        saveFile << completeData;
    }
    saveFile.close();
    return true;
}

bool writeCharacter(charSheet playerC, string &data) {
    data = "$name: " + playerC.getName() + "\n";
    data += "$maxHP: " + to_string(playerC.getMaxHP()) + "\n";
    data += "$curHP: " + to_string(playerC.getCurHP()) + "\n";
    data += "$toughness: " + to_string(playerC.getTough()) + "\n";
    data += "$nimbleness: " + to_string(playerC.getNimb()) + "\n";
    data += "$intellect: " + to_string(playerC.getIntel()) + "\n";
    data += "$arrows: " + to_string(playerC.getArrows()) + "\n";
    data += "$CP: " + to_string(playerC.getCP()) + "\n";
    //data += "$inventory: \n" + to_string(playerC.getCurHP()) + "\n";
    /*
    data += "lHand: " + to_string(playerC.getCurHP()) + "\n";
    data += "rHand: " + to_string(playerC.getCurHP()) + "\n";
    data += "body: " + to_string(playerC.getCurHP()) + "\n";
    data += "head: " + to_string(playerC.getCurHP()) + "\n";
    data += "feet: " + to_string(playerC.getCurHP()) + "\n";
    data += "hands: " + to_string(playerC.getCurHP()) + "\n";
    data += "lFinger: " + to_string(playerC.getCurHP()) + "\n";
    data += "lFinger: " + to_string(playerC.getCurHP()) + "\n";
    */
    return true;
}

bool writeWorld(WorldState wState, string &data) {

}

