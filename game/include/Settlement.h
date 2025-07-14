//
// Created by tiernan on 7/14/25.
//

#ifndef SETTLEMENT_H
#define SETTLEMENT_H

#endif //SETTLEMENT_H

class TerrainTile;

class Settlement
{
    public:


    Settlement(TerrainTile* newHome);

    ~Settlement();

    TerrainTile& GetHome();

    private:

    TerrainTile* home;
};