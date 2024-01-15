#ifndef QUEST_WORLDST_H
#define QUEST_WORLDST_H

#include "../header/macros.h"
#include "../header/charSheet.h"
#include "../header/locations.h"


class WorldState {
    private:
        Location* CurrentLocation;

    public:
};

bool loadWorld(WorldState &wState);


#endif // QUEST_WORLDST_H