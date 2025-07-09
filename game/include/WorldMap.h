//
// Created by tiernan on 7/9/25.
//
#pragma once

#include "Behaviour.h"
#include "BoxRenderer.h"

class WorldMap : public Behaviour {
public:

    WorldMap();
    ~WorldMap()= default;

    void Start() override;
    void Update(float deltatime) override;

    bool LoadMap(std::string path);

private:

    BoxRenderer* worldMapVisual;
};
