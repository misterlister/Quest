//
// Created by Hayden Lister on 2023-10-25.
//

#ifndef QUEST_LOCATIONS_H
#define QUEST_LOCATIONS_H


class Location {
    private:
        int entrances;
    public:
        Location();
        ~Location();
        bool enterLocation(int entrance);
};


#endif //QUEST_LOCATIONS_H
