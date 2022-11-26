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
        int possessions();
        void printInventory();
        bool inInventory(int key);
        void addItem(Item toAdd);
        bool removeItem(int toRemove);
        int numArrows();
        bool changeArrow(int modifier);
        int getCP();
        bool changeCP(int toAdd);
};

void makeCharacter(charSheet &playerC);

void chooseStats(charSheet &playerC);

void resetE(int &number, bool &confirm);

void printSheet(charSheet playerC);

void startingItems(charSheet &playerC);

#endif //QUEST_CHARSHEET_H
