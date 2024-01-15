//
// Created by Hayden Lister on 2022-06-14.
//

#ifndef QUEST_CHARSHEET_H
#define QUEST_CHARSHEET_H

#include <string>
#include "../header/item.h"
#include "../header/macros.h"

using std::string;



class charSheet {
    private:
        string name;
        int maxHP;
        int curHP;
        int armour;
        int toughness;
        int nimbleness;
        int intellect;
        int arrows;
        int CP;
        ItemGroup inventory;
        Item* lHand;
        Item* rHand;
        Item* body;
        Item* head;
        Item* feet;
        Item* hands;
        Item* lFinger;
        Item* rFinger;

    public:
        charSheet();
        ~charSheet(){}
        void setName(string charName);
        string getName();
        void setMaxHP(int newMax);
        bool changeMaxHP(int modifier);
        int getMaxHP();
        bool changeCurHP(int modifier);
        void healHP();
        int getCurHP();
        void setTough(int tough);
        bool changeTough(int modifier);
        int getTough();
        void setNimb(int nimb);
        bool changeNimb(int modifier);
        int getNimb();
        void setIntel(int intel);
        bool changeIntel(int modifier);
        int getIntel();
        int possessionNum();
        void printInventory();
        //void printItemCodes();
        bool inInventory(int key);
        void addItem(Item toAdd);
        bool removeItem(int toRemove);
        int getArrows();
        bool changeArrow(int modifier);
        int getCP();
        bool changeCP(int toAdd);
        void changeEquip();
        bool checkEquip(int slot);
        void equipItem(int slot);
};

void makeCharacter(charSheet &playerC);

void chooseStats(charSheet &playerC);

void resetE(int &number, bool &confirm);

void printSheet(charSheet playerC);

void startingItems(charSheet &playerC);

bool loadCharacter(charSheet &playerC);

#endif //QUEST_CHARSHEET_H
