//
// Created by tiernan on 7/9/25.
//

#include "WorldMap.h"

#include "Constants.h"
#include "GameObject.h"
#include "TerrainTile.h"

#include <iostream>
#include <utility>

sf::Color terrainColour=sf::Color(51, 204, 0, 255);

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
     mapImage= sf::Image();
     //Load image and set cosmetics
     if (!mapImage.loadFromFile(path))
        {
            std::cout<<"Cannot load map "<<path<<std::endl;
            return false;
        }
     worldMapVisual->ApplyImage(mapImage);
     sf::Vector2u dimensions = worldMapVisual->renderTexture->getSize();

     gameObject->transform.localScale=sf::Vector2f(dimensions.x,dimensions.y);
     worldMapVisual->UpdateVisualComponents();

     //Create Tilemap

     for (int y=0; y<dimensions.y; y++)
     {
        for (int x=0; x<dimensions.x; x++)
        {
            world.push_back(new TerrainTile(
                mapImage.getPixel(sf::Vector2u(x,y))==terrainColour));
        }

     }
     return true;
}

void WorldMap::Update(float deltatime)
{

}

