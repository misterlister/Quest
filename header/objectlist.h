

#ifndef QUEST_OBJECTLIST_H
#define QUEST_OBJECTLIST_H

//Keys:
//Weapons   WEAP    01
//Tools     TOOL    02
//Magic     MAGI    03

//Parameters:
//Name, Description, Key, Value, Damage, Armour, Equip slot

//Equip slots:
//1         One hand
//2         Two hands
//3         Body
//4         Head
//5         Feet
//6         Hands
//7         Finger

#define WEAP01 "Jewel-Encrusted Dagger", "A dagger of fine make, with a hilt \
encrusted with small gems", 0101, 150, 4, -1, 1
#define WEAP02 "Heirloom Blade", "A worn and battered sword that has seen many\
 battles, \nyet it feels sturdy in your hand", 0102, 50, 7, -1, 1
#define WEAP03 "Hunting Bow", "A sturdy hunting bow made of yew, well made \
and reliable", 0103, 30, 5, -1, 2

#define TOOL01 "Everburning Torch", "A magical torch coated in a substance \
that burns when lit, \nand never seems to expire", 0201, 100, 3, -1, 1

#define MAGI01 "Gnarled Wand", "An old gnarled stick that seems to glow when \
the light hits it just so", 0301, 1, -1, -1, 1
#define MAGI02 "Ominous Statuette", "A small statuette of an unsettling \
creature shaped like a man, \nyet with no face. You see this figure every \
night in your dreams, \nand hear whispers of glory. Each morning you awake, \
\nfinding yourself cradling it in your hands again", 0302, -1, -1, -1, 1

#endif //QUEST_OBJECTLIST_H