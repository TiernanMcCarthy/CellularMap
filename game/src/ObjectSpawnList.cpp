//
// Created by Tiern on 25/06/2025.
//

//Engine
#include "ObjectSpawnList.h"
#include "GameObject.h"
#include "Constants.h"
#include "Engine.h"
#include "BoxRenderer.h"

//Game
#include "SceneCamera.h"
#include "TestScript.h"
#include "WorldMap.h"

ObjectSpawnList::ObjectSpawnList()
{

}

void EPICPRINTING()
{
    std::cout << "WE HAVE BEEN PRESSED" << std::endl;
}


void ObjectSpawnList::Execute()
{
     GameObject* temp= new GameObject("Our First Button");

     TestScript* testButton = temp->AddBehaviour<TestScript>();


     //Generate Camera
     GameObject *cameraTemp= new GameObject("CameraTest");

     SceneCamera* camera = cameraTemp->AddBehaviour<SceneCamera>();

     camera->minBounds = sf::Vector2f(0, 0);

     camera->maxBounds = sf::Vector2f(DISPLAYWIDTH, DISPLAYHEIGHT);
     camera->minBounds = sf::Vector2f(0, 0);

     camera->maxBounds = sf::Vector2f(DISPLAYWIDTH, DISPLAYHEIGHT);

     camera->renderTarget = &Engine::GEngine->GetRenderWindow();

     camera->cameraView = camera->renderTarget->getView();

     //Create World Map
     GameObject *worldObject = new GameObject("WorldMap");
     WorldMap* worldMap = worldObject->AddBehaviour<WorldMap>();
     worldMap->LoadMap("assets/map.png");

}
