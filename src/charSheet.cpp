//
// Created by Hayden Lister on 2022-06-14.
//

#include <iostream>
#include <cctype>
#include "../header/macros.h"
#include "../header/charSheet.h"
#include "../header/item.h"
#include "../header/menu.h"
#include "../header/objectlist.h"

using namespace std;


charSheet::charSheet() {
    name = "";
    maxHP = 0;
    curHP = 0;
    armour = 0;
    toughness = AVG;
    nimbleness = AVG;
    intellect = AVG;
    arrows = 0;
    CP = 0;
    ItemGroup inventory;
    lHand = NULL;
    rHand = NULL;
    body = NULL;
    head = NULL;
    feet = NULL;
    hands = NULL;
    lFinger = NULL;
    rFinger = NULL;
}

void charSheet::setName(string charName) {
    name = charName;
}

string charSheet::getName() {
    return name;
}

void charSheet::setMaxHP(int newMax) {
    if (newMax < 1) {
        cerr << ERR << "HP" << STATERR << endl;
    } else {
        maxHP = newMax;
    }
}

bool charSheet::changeMaxHP(int modifier) {
    if (modifier > maxHP) {
        //character is dead
        return true;
    } else {
        maxHP += modifier;
        return false;
    }
}

int charSheet::getMaxHP() {
    return maxHP;
}

bool charSheet::changeCurHP(int modifier) {
    curHP += modifier;
    if (curHP > 0) {
        return false;
    } else {
        //character is dead
        return true;
    }
}

void charSheet::healHP() {
    curHP = maxHP;
}

int charSheet::getCurHP() {
    return curHP;
}

void charSheet::setTough(int tough) {
    if (tough < 1) {
        cerr << ERR << TN << STATERR << endl;
    } else {
        toughness = tough;
    }
}

bool charSheet::changeTough(int modifier) {
    toughness += modifier;
    if (toughness > 0) {
        return false;
    } else {
        //character is dead
        return true;
    }
}

int charSheet::getTough() {
    return toughness;
}

void charSheet::setNimb(int nimb) {
    if (nimb < 1) {
        cerr << ERR << TN << STATERR << endl;
    } else {
        nimbleness = nimb;
    }
}

bool charSheet::changeNimb(int modifier) {
    nimbleness += modifier;
    if (nimbleness > 0) {
        return false;
    } else {
        //character is dead
        return true;
    }
}

int charSheet::getNimb() {
    return nimbleness;
}

void charSheet::setIntel(int intel) {
    if (intel < 1) {
        cerr << ERR << IT << STATERR << endl;
    } else {
        intellect = intel;
    }
}

bool charSheet::changeIntel(int modifier) {
    intellect += modifier;
    if (intellect > 0) {
        return false;
    } else {
        //character is dead
        return true;
    }
}

int charSheet::getIntel() {
    return intellect;
}

int charSheet::possessions() {
    return inventory.numOfItems();
}

void charSheet::printInventory() {
    inventory.printGroup();
    cout << endl;
}

bool charSheet::inInventory(int key) {
    if(inventory.findItem(key) == -1) {
        return false;
    } else {
        return true;
    }
}

void charSheet::addItem(Item toAdd) {
    inventory.addItem(toAdd);
}

bool charSheet::removeItem(int toRemove) {
    if(inventory.removeItem(toRemove)) {
        return true;
    } else {
        return false;
    }
}

int charSheet::numArrows() {
    return arrows;
}

bool charSheet::changeArrow(int modifier) {
    if ((arrows + modifier) < 0) {
        return false;
    } else {
        arrows += modifier;
        return true;
    }
}

int charSheet::getCP() {
    return CP;
}

bool charSheet::changeCP(int modifier) {
    if ((CP + modifier) < 0) {
        return false;
    } else {
        CP += modifier;
        return true;
    }
}

void charSheet::changeEquip() {
    bool hold = false;
    bool body = false;
    bool head = false;
    bool feet = false;
    bool hands = false;
    bool finger = false;
    if(checkEquip(HOLD1)) {
        hold = true;

    } else if(checkEquip(HOLD2)) {
        hold = true;
    }
    if(checkEquip(BODY)) {
        body = true;
    }
    if(checkEquip(HEAD)) {
        head = true;
    }
    if(checkEquip(FEET)) {
        feet = true;
    }
    if(checkEquip(HANDS)) {
        hands = true;
    }
    if(checkEquip(FINGER)) {
        finger = true;
    }
    int number = 1;
    system("clear");
    if(hold|body|head|feet|hands|finger) {
        bool valid = false;
        while(!valid) {
            cout << "What would you like to change?:" << endl;
            if(hold) cout << "E - What I have equipped in my hands" << endl;
            if(body) cout << "B - What I am wearing on my body" << endl;
            if(head) cout << "H - What I wear upon my head" << endl;
            if(feet) cout << "S - The shoes upon my feet" << endl;
            if(hands) cout << "G - The gloves I wear" << endl;
            if(finger) cout << "R - A ring upon my finger" << endl;
            char choice = '0';
            cin >> choice;
            choice = toupper(choice);
            cin >> choice;
            choice = toupper(choice);
            switch (choice) {
                case E:
                    if(hold) {
                        valid = true;
                        equipItem(HOLD1);
                        break;
                    }
                case B:
                    if(body) {
                        valid = true;
                        equipItem(BODY);
                        break;
                    }
                case H:
                    if(head) {
                        valid = true;
                        equipItem(HEAD);
                        break;
                    }
                case S:
                    if(feet) {
                        valid = true;
                        equipItem(FEET);
                        break;
                    }
                case G:
                    if(hands) {
                        valid = true;
                        equipItem(HANDS);
                        break;
                    }
                case R:
                    if(finger) {
                        valid = true;
                        equipItem(FINGER);
                        break;
                    }
                default:
                    break;
            }
            if(!valid) {
                cout << INVALID << endl;
            }
        }
    } else {
        cout << "You have nothing with which to equip yourself" << endl;
        return;
    }
}

bool charSheet::checkEquip(int slot) {
    for(vector<Item>::iterator it = inventory.begin(); it != inventory.end(); it++) {
        if(it->equipSlot == slot) {
            return true;
        }
    }
    return false;
}

void charSheet::equipItem(int slot) {
    system("clear");
    vector<Item>::iterator it = inventory.begin();
    if(slot == 1) {
        if(rHand == NULL) {
            cout << "You hold nothing in your right hand" << endl;
        } else if (rHand == lHand) {
            cout << "You hold " << rHand.iName() << " in both hands" << endl; 
        } else {
            cout << "You hold " << rHand.iName() << " in your right hand" << endl;
        }
        if(lHand == NULL) {
            cout << "You hold nothing in your left hand" << endl;
        } else if (lHand != rHand) {
            cout << "You hold " << lHand.iName() << " in your left hand" << endl;
        }
        cout << "You may equip:" << endl << endl;
        for(it; it != inventory.end(); it++) {
            if(it->eqSlot() == 1 | it->eqSlot() == 2) {
                cout << it->iName();
                if(it->eqSlot() == 1) {
                    cout << " in one hand" << endl;
                }
                if(it->eqSlot() == 2) {
                    cout << " in both hands" << endl;
                }
            }
        }
        cout << endl;
        it = inventory.begin();
        char entry = '0';
        cout << "Select the item to equip (Enter Y/N to make a choice)" << endl;
        for(it; it != inventory.end(); it++) {
            
        }    
    }
    

}

void makeCharacter(charSheet &playerC)
{
   int entry = -1;
   bool confirmed = false;
   while (!confirmed) {
      cout << "What is your name?" << endl;
      string input;
      cin >> input;
      playerC.setName(input);
      system("clear");
      cout << playerC.getName() << ", is this correct?" << endl;
      cout << "1 - Yes" << endl << "2 - No" << endl;
      entry = makeChoice(2);
      if (entry == 1) {
         confirmed = true;
      }
   }
   chooseStats(playerC);
   startingItems(playerC);
}

void chooseStats(charSheet &playerC)
{
   system("clear");
   int entry = -1;
   cout << "Which do you wish to be your greatest strength?:" << endl;
   cout << "1 - Toughness" << endl << "2 - Nimbleness" << endl << "3 - Intellect" << endl;
   entry = makeChoice(3);
   system("clear");
   switch (entry) {
      case 1:
         playerC.setTough(STR);
         cout << "Very well. Now which do you wish to be your greatest weakness?:" << endl;
         cout << "1 - Nimbleness" << endl << "2 - Intellect" << endl;
         entry = makeChoice(2);
         if (entry == 1) {
            playerC.setNimb(WK);
         } else { 
            playerC.setIntel(WK);
         }
         break;
      case 2:
         playerC.setNimb(STR);
         cout << "Very well. Now which do you wish to be your greatest weakness?:" << endl;
         cout << "1 - Toughness" << endl << "2 - Intellect" << endl;
         entry = makeChoice(2);
         if (entry == 1) {
            playerC.setTough(WK);
         } else { 
            playerC.setIntel(WK);
         }
         break;
      case 3:
         playerC.setIntel(STR);
         cout << "Very well. Now which do you wish to be your greatest weakness?:" << endl;
         cout << "1 - Toughness" << endl << "2 - Nimbleness" << endl;
         entry = makeChoice(2);
         if (entry == 1) {
            playerC.setTough(WK);
         } else { 
            playerC.setNimb(WK);
         }
         break;
   }  
   playerC.setMaxHP(10+playerC.getTough());
   playerC.healHP();
}

void resetE(int &number, bool &confirm)
{
   number = -1;
   confirm = false;
}

void printSheet(charSheet playerC)
{
    cout << "Your name is " << playerC.getName() << endl;
    cout << endl;
    if (((playerC.getCurHP()*10)/playerC.getMaxHP()) == 10) {
       cout << "You are unharmed and in good health" << endl;
    } else if (((playerC.getCurHP()*10)/playerC.getMaxHP()) >= 8) {
       cout << "You have suffered injury, but it is not a threat to your survival" << endl;
    } else if (((playerC.getCurHP()*10)/playerC.getMaxHP()) >= 5) {
       cout << "You have endured a substantial injury, and are suffering its effects" << endl;
    } else if (((playerC.getCurHP()*10)/playerC.getMaxHP()) >= 3) {
       cout << "Your wounds are severe, things are beginning to look grim" << endl;
    } else if (((playerC.getCurHP()*10)/playerC.getMaxHP()) >= 1) {
       cout << "You cling to life by a very thread" << endl;
    }
    cout << endl;
    if (playerC.getTough() == STR) {
       cout << "Your strength is heroic, your endurance legendary" << endl;
    } else if (playerC.getTough() == WK) {
       cout << "Your body is frail and sickly" << endl;
    } else { 
       cout << "Your strength is of average performance" << endl;
    }
    if (playerC.getNimb() == STR) {
       cout << "Your speed is blinding, your hands nimble" << endl;
    } else if (playerC.getNimb() == WK) {
       cout << "Your reflexes are slow and clumsy" << endl;
    } else { 
       cout << "Your agility is typical of your peers" << endl;
    }
    if (playerC.getIntel() == STR) {
       cout << "Your mind is a keenly honed instrument, your wit a sharpened blade" << endl;
    } else if (playerC.getIntel() == WK) {
       cout << "Your mind is a dull and lumbering thing" << endl;
    } else { 
       cout << "Your intelligence is unremarkable, neither great nor poor" << endl;
    }
    cout << endl;
    if(playerC.numArrows() != 0) {
       cout << "a quiver holding " << playerC.numArrows() << " arrows" << endl;
    }
    cout << endl;
    if(playerC.getCP() == 0) {
       cout << "You have not a copper to your name" << endl << endl;
    } else {
       cout << "Your coinpurse contains " << playerC.getCP() << " copper coins" << endl << endl;
    } 
}

void startingItems(charSheet &playerC)
{
    Item weap01(WEAP01);
    Item tool01(TOOL01);
    Item weap02(WEAP02);
    Item magi01(MAGI01);
    Item weap03(WEAP03);
    Item magi02(MAGI02);
    system("clear");
    cout << "You have only one possession of value. What is it?" << endl;
    cout << "1 - A jewel-encrusted dagger" << endl;
    cout << "2 - A coinpurse containing 200 copper pieces" << endl;
    cout << "3 - A magical torch that will never burn out" << endl;
    cout << "4 - The worn and battered sword of your ancestors" << endl;
    cout << "5 - A gnarled wand that may contain magical power" << endl;
    cout << "6 - A sturdy hunting bow paired with a quiver holding 10 arrows" << endl;
    cout << "7 - An ominous statuette that haunts your dreams, promising glory" << endl;
    int itemChoice = makeChoice(7);
    switch (itemChoice) {
        case 1:
            playerC.addItem(weap01);
            break;
        case 2:
            playerC.changeCP(200);
            break;
        case 3:
            playerC.addItem(tool01);
            break;
        case 4:
            playerC.addItem(weap02);
            break;
        case 5:
            playerC.addItem(magi01);
            break;
        case 6:
            playerC.addItem(weap03);
            playerC.changeArrow(10);
            break;
        case 7:
            playerC.addItem(magi02);
            break;
    }
}

