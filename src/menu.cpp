
#include <iostream>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <string>
#include <filesystem>
#include <regex>
#include "../header/macros.h"
#include "../header/charSheet.h"
#include "../header/item.h"
#include "../header/menu.h"
#include "../header/objectlist.h"
#include "../header/worldState.h"
#include "../header/files.h"




using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::filesystem::exists;
using std::filesystem::create_directory;
using std::filesystem::path;
using std::filesystem::current_path;
using std::filesystem::is_regular_file;
using std::filesystem::directory_iterator;
using std::filesystem::is_empty;
using std::ofstream;
using std::to_string;
using std::regex;
using std::regex_replace;



int makeChoice(int numCh)
{
    int input;
    bool valid = false;
    do {
        cin >> input; 
        if ((input > 0)&&(input <= numCh)) {
            valid = true;
        } else {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(LINELEN, '\n');
            }
            cerr << INVALID << endl;
        }
    } while (!valid);
    return input;
}

char yesNo() {
    char input = '0';
    bool valid = false;
    do {
        cin >> input; 
        input = toupper(input);
        if ((input == 'Y')||(input == 'N')) {
            valid = true;
        } else {
            cerr << INVALID << endl;
        }
    } while (!valid);
    return input;
}

bool menu(charSheet playerC, WorldState wState) {
    bool done = false;
    bool quit = false;
    while(!done) {
        system("clear");
        cout << "What would you like to do?" << endl
             << "1. Take stock of my condition" << endl
             << "2. Examine my possessions" << endl
             << "3. Change what I am holding or wearing" << endl
             << "4. Reflect, and save a memory of my progress" << endl
             << "5. End my travels for now" << endl
             << "6. Resume my travels" << endl;
        int itemChoice = makeChoice(6);
        int endChoice = 0;
        switch (itemChoice) {
            case 1:
                printSheet(playerC);
                press_enter();
                cout << endl;
                break;
            case 2:
                system("clear");
                if (playerC.possessionNum() == 0) {
                    cout << "You have no worldly possessions to speak of" << endl;
                } else {
                    cout << "Your possessions are as follows:" << endl << endl;
                    playerC.printInventory();
                    if(playerC.getArrows() != 0) {
                        cout << "A quiver holding " << playerC.getArrows();
                        cout << " arrows" << endl;
                    }
                }
                if(playerC.getCP() == 0) {
                    cout << "You have not a copper to your name" << endl << endl;
                } else {
                    cout << "Your coinpurse contains " << playerC.getCP(); 
                    cout << " copper coins" << endl << endl;
                }
                press_enter();
                cout << endl;
                break;
            case 3:
                playerC.changeEquip();
                break;
            case 4:
                saveGame(playerC, wState);
                break;
            case 5:
                system("clear");
                cout << "Would you like to save your progress before quitting?" << endl
                     << "1. Yes, save my progress" << endl
                     << "2. No, don't save my progress" << endl
                     << "3. Return to the menu instead" << endl;
                endChoice = makeChoice(3);
                switch(endChoice) {
                    case 1:
                        saveGame(playerC, wState);
                        quit = true;
                        done = true;
                        break;
                    case 2:
                        quit = true;
                        done = true;
                        break;
                    default:
                        break;
                }
                break;
            default:
                done = true;
                break;
        }
    }
    return quit;
}

void press_enter() {
    cin.ignore();
    cout << "Press Enter to Continue...";
    cin.get();
}




bool saveGame(charSheet playerC, WorldState wState) {
    string saveDirName = SAVEDIR;
    path saveLocation = saveDirName;
    checkSaveDir(saveLocation);
    printSaves(saveLocation); // CUT
    bool confirmed = false;
    bool cancel = false;
    string saveName = "";
    while(!confirmed) {
        cout << "Enter the name for this saved memory" << endl << endl;
        cin >> saveName;
        int input = 0;
        if (is_regular_file(saveDirName+saveName)) {
            cout << saveName << " already exists. Overwrite?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "3. Cancel" << endl << endl;
            input = makeChoice(3);
            switch(input) {
                case 1: //overwrite save
                    confirmed = true;
                    break;
                case 3: //cancel saving process
                    confirmed = true;
                    cancel = true;
                    break;
                default: //ask user for save name again
                    break;
            }
        } else { //file doesn't already exist with this name
            confirmed = true;
        }
    }
    if(!cancel) {
        if(writeData(playerC, wState, saveName)) {
            cout << "Successfully saved a memory of your progress" << endl;
        } else {
            cout << "Something went wrong, this memory is not saved" << endl;
        }
        press_enter();
    } else {
        cout << "Decided not to save a memory" << endl;
        press_enter();
    }
    return true;
}



bool loadSave(charSheet &playerC, WorldState &wState) {
    string saveDirName = SAVEDIR;
    path saveLocation = saveDirName;
    checkSaveDir(saveDirName);
    void printSaves(path saveDir);
    if(!loadCharacter(playerC)) {
        //ERROR MESSAGE
        return false;
    }
    if(!loadWorld(wState)) {
        //ERROR MESSAGE
        return false;
    }
    press_enter();
    return true;
}