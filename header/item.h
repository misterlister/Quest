//
// Created by Hayden Lister on 2022-06-14.
//

#ifndef QUEST_ITEM_H
#define QUEST_ITEM_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class Item {
    private:
        string itemKey;
        string name;
        string description;
        int value;
        int damage;
        int armour;
        int equipSlot;
        bool equipped;
    public:
        Item(string nam, string desc, int iKey, int val, int dam, int arm, \
            int equip);
        ~Item() {}
        string iKey();
        string iName();
        string iDesc();
        int iValue();
        int iDam();
        int iArm();
        int eqSlot();
        bool isEquipped();
};

class ItemGroup {
    private:
        vector<Item>list;
    public:
        ItemGroup(){}
        ~ItemGroup(){}
        int numOfItems();
        int findItem(int key);
        void addItem(Item toAdd);
        bool removeItem(int key);
        void printGroup();
        friend class charSheet;
};


#endif //QUEST_ITEM_H