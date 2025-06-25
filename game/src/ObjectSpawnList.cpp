//
// Created by Tiern on 25/06/2025.
//

#include "ObjectSpawnList.h"
#include "Constants.h"
#include "Engine.h"

#include "AABBCollider.h"

#include "BoxRenderer.h"

 ObjectSpawnList::ObjectSpawnList()
{

}

void ObjectSpawnList::Execute()
{
    GameObject *temp = new GameObject("EpicTestObject");

    temp->transform.localScale=sf::Vector2<float>(1280, 720);
    temp->AddBehaviour<AABBCollider>();

    temp->transform.SetPosition(sf::Vector2f(DISPLAYWIDTH/2, DISPLAYHEIGHT/2));


    BoxRenderer* boxR = temp->AddBehaviour<BoxRenderer>();

    boxR->color = sf::Color::Blue;

    boxR->UpdateVisualComponents();

}
