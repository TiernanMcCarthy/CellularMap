//
// Created by tiernan on 7/9/25.
//
#pragma once

#include "Behaviour.h"
#include "BoxRenderer.h"
#include "Settlement.h"

class TerrainTile;

class WorldMap : public Behaviour {
public:

    WorldMap();
    ~WorldMap()= default;

    void Start() override;
    void Update(float deltatime) override;

    bool LoadMap(std::string path);

private:

    BoxRenderer* worldMapVisual;

    sf::Image mapImage;

    std::vector<TerrainTile*> world;


};
