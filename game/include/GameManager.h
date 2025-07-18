//
// Created by tiernan on 7/18/25.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "../../engine/include/Behaviour.h"

#endif //GAMEMANAGER_H

class WorldMap;

//The Game Manager exists to maintain and manage the tile simulation
// It should contain and Manage the WorldMap and the Settler Managers
class GameManager : public Behaviour
{
public:

    GameManager();

    ~GameManager() = default;




private:
    WorldMap* worldMap;
};