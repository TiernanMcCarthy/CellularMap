//
// Created by tiernan on 7/14/25.
//
#include "Settlement.h"


 Settlement::Settlement(TerrainTile *newHome)
{
    home=newHome;
}

 Settlement::~Settlement()
{
    home=nullptr;
}

