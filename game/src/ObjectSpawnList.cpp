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

ObjectSpawnList::ObjectSpawnList()
{

}

void EPICPRINTING()
{
    std::cout << "WE HAVE BEEN PRESSED" << std::endl;
}


void ObjectSpawnList::Execute()
{
    GameObject *temp = new GameObject("EpicTestObject");

    temp->transform.localScale=sf::Vector2<float>(1280, 720);

    temp->transform.SetPosition(sf::Vector2f(DISPLAYWIDTH/2, DISPLAYHEIGHT/2));

    BoxRenderer* boxR = temp->AddBehaviour<BoxRenderer>();

    boxR->color = sf::Color::Blue;

    boxR->UpdateVisualComponents();

    //Button* button=temp->AddBehaviour<Button>();

    //button->OnPress.Subscribe(EPICPRINTING);



     //Generate Camera
     GameObject *cameraTemp= new GameObject("CameraTest");

     SceneCamera* camera = cameraTemp->AddBehaviour<SceneCamera>();

     camera->minBounds = sf::Vector2f(0, 0);

     camera->maxBounds = sf::Vector2f(DISPLAYWIDTH, DISPLAYHEIGHT);
     camera->minBounds = sf::Vector2f(0, 0);

     camera->maxBounds = sf::Vector2f(DISPLAYWIDTH, DISPLAYHEIGHT);

     camera->renderTarget = &Engine::GEngine->GetRenderWindow();

     camera->cameraView = camera->renderTarget->getView();

    // FunctionSubscriber functionTest= FunctionSubscriber();

   // functionTest.Subscribe(std::bind(&SceneCamera::PrintTest, camera));

    //functionTest.Activate();

    //functionTest.PassFunction(*camera->PrintTest);



}
