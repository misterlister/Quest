
#include <iostream>
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
                break;
            case 2:
                if (playerC.possessions() == 0) {
                    cout << "You have no worldly possessions to speak of" << endl;
                } else {
                    cout << "Your possessions are as follows:" << endl;
                    playerC.printInventory();
                }
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
        if(!done) {
            cout << "Press Enter to continue...";
            cin.get(); 
            cout << endl;
        }
    }

}