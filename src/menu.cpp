
#include <iostream>
#include <cctype>
#include "../header/macros.h"
#include "../header/charSheet.h"
#include "../header/item.h"
#include "../header/menu.h"
#include "../header/objectlist.h"

using namespace std;



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

void menu(charSheet playerC) {
    bool done = false;
    while(!done) {
        system("clear");
        cout << "What would you like to do?" << endl;
        cout << "1. Take stock of my condition" << endl;
        cout << "2. Examine my possessions" << endl;
        cout << "3. Change what I am holding or wearing" << endl;
        cout << "4. Reflect, and save a memory of my progress" << endl;
        cout << "5. Resume my travels" << endl;
        int itemChoice = makeChoice(5);
        switch (itemChoice) {
            case 1:
                printSheet(playerC);
                press_enter();
                cout << endl;
                break;
            case 2:
                system("clear");
                if (playerC.possessions() == 0) {
                    cout << "You have no worldly possessions to speak of" << endl;
                } else {
                    cout << "Your possessions are as follows:" << endl << endl;
                    playerC.printInventory();
                    if(playerC.numArrows() != 0) {
                        cout << "A quiver holding " << playerC.numArrows();
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
                //save
                break;
            default:
                done = true;
                break;
        }
    }
}

void press_enter()
{
    cin.ignore();
    cout << "Press Enter to Continue...";
    cin.get();
}