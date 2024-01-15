//
// Created by Hayden Lister on 2022-06-14.
//

#include <iostream>
#include <cctype>
#include <vector>
#include "../header/macros.h"
#include "../header/charSheet.h"
#include "../header/item.h"
#include "../header/menu.h"
#include "../header/objectlist.h"

using namespace std;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::end;
using std::begin;


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

int charSheet::possessionNum() {
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

int charSheet::getArrows() {
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
            switch (choice) {
                case 'E':
                    if(hold) {
                        valid = true;
                        equipItem(HOLD1);
                        break;
                    }
                case 'B':
                    if(body) {
                        valid = true;
                        equipItem(BODY);
                        break;
                    }
                case 'H':
                    if(head) {
                        valid = true;
                        equipItem(HEAD);
                        break;
                    }
                case 'S':
                    if(feet) {
                        valid = true;
                        equipItem(FEET);
                        break;
                    }
                case 'G':
                    if(hands) {
                        valid = true;
                        equipItem(HANDS);
                        break;
                    }
                case 'R':
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
    for(vector<Item>::iterator it = inventory.list.begin(); \
    it != inventory.list.end(); it++) {
        if(it->eqSlot() == slot) {
            return true;
        }
    }
    return false;
}

void charSheet::equipItem(int slot) {
    system("clear");
    vector<Item>::iterator it = inventory.list.begin();
    if(slot == HOLD1) { /////// we want to equip a handheld item ///////
        if(rHand == NULL) { 
            cout << "You hold nothing in your right hand" << endl;
        } else if (rHand == lHand) {
            cout << "You hold " << rHand->iName() << " in both hands" << endl; 
        } else {
            cout << "You hold " << rHand->iName() << " in your right hand" << endl;
        }
        if(lHand == NULL) {
            cout << "You hold nothing in your left hand" << endl;
        } else if (lHand != rHand) {
            cout << "You hold " << lHand->iName() << " in your left hand" << endl;
        }
        cout << "You may equip:" << endl << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == HOLD1 || it->eqSlot() == HOLD2) { //print all holdable items
                cout << it->iName();
                if(it->eqSlot() == HOLD1) {
                    cout << " in one hand" << endl;
                }
                if(it->eqSlot() == HOLD2) {
                    cout << " in both hands" << endl;
                }
            }
        }
        cout << endl;
        it = inventory.list.begin();
        char entry = '0';
        cout << "Select the item to equip (Enter Y/N to make a choice)" << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == HOLD1 || it->eqSlot() == HOLD2) { //each holdable item
                cout << it->iName() << "?" << endl;
                entry = yesNo();
                if(toupper(entry) == 'Y') {
                    if(it->eqSlot() == HOLD2) { //the item is 2-handed
                        lHand = &*it;
                        rHand = &*it;
                        cout << "You are now holding " << lHand->iName() << " in";
                        cout << " both hands" << endl;
                        return;
                    } else {
                        cout << "In which hand do you want to hold " << it->iName();
                        cout << "?" << endl << "1 - Right hand" << endl;
                        cout << "2 - Left hand" << endl;
                        int choice = makeChoice(2);
                        if(choice == 1) { //hold it in right hand
                            rHand = &*it;
                            cout << "You are now holding " << rHand->iName();
                            cout << " in your right hand" << endl;
                            return;
                        } else { //hold it in left hand
                            lHand = &*it;
                            cout << "You are now holding " << lHand->iName();
                            cout << " in your left hand" << endl;
                            return;
                        }
                    }
                }
            }
        }
        char input = '0';
        if(rHand != NULL) {
            cout << "Would you like to stow your " << rHand->iName();
            cout << "? (Y/N)" << endl;
            input = yesNo();
            if(input == 'Y') {
                rHand = NULL;
            }
        }
        if(lHand != NULL) {
            if(lHand->eqSlot() != HOLD2) {
                cout << "Would you like to stow your " << lHand->iName();
                cout << "? (Y/N)" << endl;
                input = yesNo();
                if(input == 'Y') {
                    lHand = NULL;
                }
            }
        }
        return;
    }
    if(slot == BODY) { /////// we want to equip a body item ///////
        if(body == NULL) {
            cout << "You wear nothing but your ragged clothing" << endl;
        } else {
            cout << "You wear " << body->iName() << " on your body" << endl;
        }
        cout << "You may equip:" << endl << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == BODY) { //print all body-wearable items
                cout << it->iName() << endl;
            }
        }
        cout << endl;
        it = inventory.list.begin();
        char entry = '0';
        cout << "Select the item to equip (Enter Y/N to make a choice)" << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == BODY) { //each body-wearable item
                cout << it->iName() << "?" << endl;
                entry = yesNo();
                if(toupper(entry) == 'Y') {
                        body = &*it;
                        cout << "You are now wearing " << body->iName() << endl;
                        return;
                }
            }
        }
        char input = '0';
        if(body != NULL) {
            cout << "Would you like to remove your " << body->iName();
            cout << "? (Y/N)" << endl;
            input = yesNo();
            if(input == 'Y') {
                body = NULL;
            }
        }
        return;
    }
    if(slot == HEAD) { /////// we want to equip a head item ///////
        if(head == NULL) {
            cout << "You wear nothing upon your head" << endl;
        } else {
            cout << "You wear a " << head->iName() << " on your head" << endl;
        }
        cout << "You may equip:" << endl << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == HEAD) { //print all head-wearable items
                cout << it->iName() << endl;
            }
        }
        cout << endl;
        it = inventory.list.begin();
        char entry = '0';
        cout << "Select the item to equip (Enter Y/N to make a choice)" << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == HEAD) { //each head-wearable item
                cout << it->iName() << "?" << endl;
                entry = yesNo();
                if(toupper(entry) == 'Y') {
                        head = &*it;
                        cout << "You are now wearing a " << head->iName() << endl;
                        return;
                }
            }
        }
        char input = '0';
        if(head != NULL) {
            cout << "Would you like to remove your " << head->iName();
            cout << "? (Y/N)" << endl;
            input = yesNo();
            if(input == 'Y') {
                head = NULL;
            }
        }
        return;
    }
    if(slot == FEET) { /////// we want to equip a feet item ///////
        if(feet == NULL) {
            cout << "Your feet are bare" << endl;
        } else {
            cout << "You wear " << feet->iName() << " on your feet" << endl;
        }
        cout << "You may equip:" << endl << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == FEET) { //print all feet-wearable items
                cout << it->iName() << endl;
            }
        }
        cout << endl;
        it = inventory.list.begin();
        char entry = '0';
        cout << "Select the item to equip (Enter Y/N to make a choice)" << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == FEET) { //each feet-wearable item
                cout << it->iName() << "?" << endl;
                entry = yesNo();
                if(toupper(entry) == 'Y') {
                        feet = &*it;
                        cout << "You are now wearing a " << feet->iName() << endl;
                        return;
                }
            }
        }
        char input = '0';
        if(feet != NULL) {
            cout << "Would you like to remove your " << feet->iName();
            cout << "? (Y/N)" << endl;
            input = yesNo();
            if(input == 'Y') {
                feet = NULL;
            }
        }
        return;
    }
    if(slot == HANDS) { /////// we want to equip a hands item ///////
        if(hands == NULL) {
            cout << "You wear nothing upon your hands" << endl;
        } else {
            cout << "You wear " << hands->iName() << " on your hands" << endl;
        }
        cout << "You may equip:" << endl << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == HANDS) { //print all hands-wearable items
                cout << it->iName() << endl;
            }
        }
        cout << endl;
        it = inventory.list.begin();
        char entry = '0';
        cout << "Select the item to equip (Enter Y/N to make a choice)" << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == HANDS) { //each hands-wearable item
                cout << it->iName() << "?" << endl;
                entry = yesNo();
                if(toupper(entry) == 'Y') {
                        hands = &*it;
                        cout << "You are now wearing " << hands->iName() << endl;
                        return;
                }
            }
        }
        char input = '0';
        if(hands != NULL) {
            cout << "Would you like to remove your " << hands->iName();
            cout << "? (Y/N)" << endl;
            input = yesNo();
            if(input == 'Y') {
                hands = NULL;
            }
        }
        return;
    }
    if(slot == FINGER) { /////// we want to equip a finger item ///////
        if(rFinger == NULL) { 
            cout << "You have nothing on your right finger" << endl;
        } else {
            cout << "You have " << rFinger->iName() << " on your right finger" << endl;
        }
        if(lFinger == NULL) {
            cout << "You hold nothing on your left finger" << endl;
        } else {
            cout << "You have " << lFinger->iName() << " on your left finger" << endl;
        }
        cout << "You may equip:" << endl << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == FINGER) { //print all finger items
                cout << it->iName();
            }
        }
        cout << endl;
        it = inventory.list.begin();
        char entry = '0';
        cout << "Select the item to equip (Enter Y/N to make a choice)" << endl;
        for(; it != inventory.list.end(); it++) {
            if(it->eqSlot() == FINGER) { //each finger item
                cout << it->iName() << "?" << endl;
                entry = yesNo();
                if(toupper(entry) == 'Y') {
                    cout << "On which hand do you want to wear " << it->iName();
                    cout << "?" << endl << "1 - Right hand" << endl;
                    cout << "2 - Left hand" << endl;
                    int choice = makeChoice(2);
                    if(choice == 1) { //hold it in right hand
                        rFinger = &*it;
                        cout << "You are now wearing " << rFinger->iName();
                        cout << " on your right hand" << endl;
                        return;
                    } else { //hold it in left hand
                        lFinger = &*it;
                        cout << "You are now wearing " << lFinger->iName();
                        cout << " on your left hand" << endl;
                        return;
                    }
                }
            }
        }
        char input = '0';
        if(rFinger != NULL) {
            cout << "Would you like to remove your " << rFinger->iName();
            cout << "? (Y/N)" << endl;
            input = yesNo();
            if(input == 'Y') {
                rFinger = NULL;
            }
        }
        if(lFinger != NULL) {
            cout << "Would you like to remove your " << lFinger->iName();
            cout << "? (Y/N)" << endl;
            input = yesNo();
            if(input == 'Y') {
                lFinger = NULL;
            }
        }
        return;
    }
}

void makeCharacter(charSheet &playerC) {
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

void chooseStats(charSheet &playerC) {
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

void resetE(int &number, bool &confirm) {
   number = -1;
   confirm = false;
}

void printSheet(charSheet playerC) {
    system("clear");
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
}

void startingItems(charSheet &playerC) {
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

bool loadCharacter(charSheet &playerC) {
    //LOAD STUFF
}