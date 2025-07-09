//
// Created by tiernan on 7/9/25.
//
#include "WorldMap.h"

#include "GameObject.h"
#include "Constants.h"

#include <iostream>
#include <utility>

 WorldMap::WorldMap()
{

}


void WorldMap::Start()
{
     worldMapVisual= gameObject->AddBehaviour<BoxRenderer>();
     gameObject->transform.localPosition=sf::Vector2f(DISPLAYWIDTH/2,DISPLAYHEIGHT/2);
}

bool WorldMap::LoadMap(std::string path)
{
    worldMapVisual->ApplyImage(std::move(path));
    sf::Vector2u dimensions = worldMapVisual->renderTexture->getSize();
     gameObject->transform.localScale=sf::Vector2f(dimensions.x,dimensions.y);
     worldMapVisual->UpdateVisualComponents();
    return false;
}

void WorldMap::Update(float deltatime)
{

}

