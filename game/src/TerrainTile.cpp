//
// Created by tiernan on 7/13/25.
//

#include "TerrainTile.h"

 TerrainTile::TerrainTile(bool land)
{
    isLand=land;
     owner=nullptr;
}


void TerrainTile::ClearSettlement()
{
    owner=nullptr;
}

void TerrainTile::SetOwner(Settlement* newOwner)
{
    if (owner!=nullptr)
    {
        owner=newOwner;
    }
}

Settlement& TerrainTile::GetOwner()
{
    return *owner;
}