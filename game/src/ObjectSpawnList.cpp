//
// Created by Tiern on 25/06/2025.
//

#include "ObjectSpawnList.h"
#include "GameObject.h"
#include "Constants.h"
#include "Engine.h"
#include "SceneCamera.h"

#include "AABBCollider.h"

#include "BoxRenderer.h"
#include "Button.h"
#include "FunctionSubscriber.h"
#include "TestScript.h"

ObjectSpawnList::ObjectSpawnList()
{

}

void EPICPRINTING()
{
    std::cout << "WE HAVE BEEN PRESSED" << std::endl;
}


void ObjectSpawnList::Execute()
{
    //TestScript *temp = (TestScript*)new GameObject("EpicTestObject").AddBehaviour<TestScript>();

   // temp->gameObject.transform.localScale=sf::Vector2<float>(1280, 720);

     GameObject* temp= new GameObject("Our First Button");

    TestScript* testButton = temp->AddBehaviour<TestScript>();

    //temp->AddBehaviour<TestScript>();

     //TestScript* ourButton= temp->AddBehaviour<TestScript>();
     //Generate Camera
     GameObject *cameraTemp= new GameObject("CameraTest");

     SceneCamera* camera = cameraTemp->AddBehaviour<SceneCamera>();

     camera->minBounds = sf::Vector2f(0, 0);

     camera->maxBounds = sf::Vector2f(DISPLAYWIDTH, DISPLAYHEIGHT);
     camera->minBounds = sf::Vector2f(0, 0);

     camera->maxBounds = sf::Vector2f(DISPLAYWIDTH, DISPLAYHEIGHT);

     camera->renderTarget = &Engine::GEngine->GetRenderWindow();

     camera->cameraView = camera->renderTarget->getView();



     //FunctionSubscriber functionTest= FunctionSubscriber();

    //functionTest.Subscribe(std::bind(&SceneCamera::PrintTest, camera));

    //functionTest.Activate();



    //functionTest.PassFunction(*camera->PrintTest);



}
