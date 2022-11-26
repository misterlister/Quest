//
// Created by Hayden Lister on 2022-06-14.
//


#include <iostream>
#include <string>
#include "../header/item.h"
#include "../header/macros.h"


using std::string;
using std::cout;
using std::endl;


Item::Item(string nam, string desc, int iKey, int val, int dam, int arm, \
    int equip) {
    name = nam;
    description = desc;
    key = iKey;
    value = val;
    damage = dam;
    armour = arm;
    equipSlot = equip;
    equipped = false;
}

string Item::iName() {
    return name;
}

string Item::iDesc() {
    return description;
}

int Item::iKey() {
    return key;
}

int Item::iValue() {
    return value;
}

int Item::iDam() {
    return damage;
}

int Item::iArm() {
    return armour;
}

int Item::eqSlot() {
    return equipSlot;
}

bool Item::isEquipped() {
    return equipped;
}

int ItemGroup::numOfItems() {
    return list.size();
}

int ItemGroup::findItem(int key) {
    for(unsigned long i = 0; i < list.size(); i++) {
        if(list[i].iKey() == key) {
            return i;
        }
    }
    return -1;
}

void ItemGroup::addItem(Item toAdd) {
    list.push_back(toAdd);
}

bool ItemGroup::removeItem(int key) {
    int search = findItem(key);
    if(search >= 0) {
        list.erase(list.begin()+search);
        return true;
    }
    return false;
}

void ItemGroup::printGroup() {
    for(unsigned long i = 0; i < list.size(); i++) {
        cout << list[i].iName() << endl;
    }
}
