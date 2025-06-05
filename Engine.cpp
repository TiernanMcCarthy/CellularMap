#include "Engine.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.h"

#include "TestScript.h"
#include "RenderObject.h"
#include "BoxRenderer.h"
#include "AABBCollider.h"
#include "SceneCamera.h"
#include "EngineInputSystem.h"
Engine* Engine::GEngine = nullptr;

Engine::Engine(bool startEngine)
{
    Engine::GEngine = this;
    gameObjects = std::vector<GameObject*>();
    if (startEngine)
    {
        Start();
    }
    //renderContext->create(sf::VideoMode())
}

void Engine::Start()
{
    isRunning = true;
    EngineLoop();
}


void Engine::EngineLoop()
{
    if (!isRunning)
    {
        return;
    }

    //Create Game Window
    sf::RenderWindow gameWindow = sf::RenderWindow(sf::VideoMode({ DISPLAYWIDTH, DISPLAYHEIGHT }), WINDOW_NAME,sf::State::Windowed);

    //Create Input System
    EngineInputSystem engineInput = EngineInputSystem();

    //Clock for calculating Delta Time
    sf::Clock clock;

    //Create Background
    BoxRenderer* background = (new GameObject("Background"))->AddBehaviour<BoxRenderer>();

    float pixelCount = (DISPLAYWIDTH * DISPLAYHEIGHT)/1.5f;

    float pixelRatio = (pixelCount / (256 * 224));

    background->gameObject->transform.localScale = sf::Vector2f(256*pixelRatio, 224*pixelRatio);

    background->gameObject->transform.SetPosition(DISPLAYWIDTH / 2, DISPLAYHEIGHT / 2);

    background->ApplyImage("flatImage.png");

   // background->gameObject->transform.localScale = sf::Vector2<float>(500, 500);

    //Object Testing
    GameObject* temp = new GameObject("My epic Object");
    
    temp->transform.localScale = sf::Vector2<float>(1280, 720);
    //temp->AddBehaviour<TestScript>();
    temp->AddBehaviour<AABBCollider>();

    temp->transform.SetPosition(sf::Vector2f(DISPLAYWIDTH/2, DISPLAYHEIGHT/2));
    


    BoxRenderer* boxR = temp->AddBehaviour<BoxRenderer>();

    boxR->color = sf::Color::Blue;

    AABBCollider collider = *temp->AddBehaviour<AABBCollider>();

    sf::Vector2i mousePos=sf::Mouse::getPosition(gameWindow);

    temp->GetBehaviour<BoxRenderer>()->UpdateVisualComponents();

    //Camera Testing
    GameObject* cameraTest = new GameObject("CameraTest");

    SceneCamera* camera=cameraTest->AddBehaviour<SceneCamera>();

    camera->minBounds = sf::Vector2f(0, 0);

    camera->maxBounds = sf::Vector2f(DISPLAYWIDTH, DISPLAYHEIGHT);

    camera->renderTarget = &gameWindow;

    camera->cameraView = gameWindow.getView();

    gameWindow.setFramerateLimit(60);


    //Main Game Loop
    while (gameWindow.isOpen())
    {
        //clean last frame's inputs
        engineInput.CleanInputs();

        //Handle Events
        while (const std::optional event = gameWindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                gameWindow.close();
                break;
            }
            else if (const auto* scrollWheel = event->getIf<sf::Event::MouseWheelScrolled>()) //crap and needs to be improved
            {
                engineInput.scrollWheelDelta = scrollWheel->delta;
                    
            }

        }

        //Poll InputSystem
        engineInput.PollInputs();

        sf::Vector2i mousePos = sf::Mouse::getPosition(gameWindow);

        sf::Vector2f worldPos = gameWindow.mapPixelToCoords(mousePos);

        if (collider.IsPosInside(sf::Vector2<float>(worldPos.x, worldPos.y)))
        {
            boxR->color = sf::Color::Green;
        }
        else
        {
            boxR->color = sf::Color::Red;
        }
        //Get Delta Time
        deltaTime = clock.restart().asSeconds();

        for (int i = 0; i < gameObjects.size(); i++)
        {
            //Update all GameObjects
            gameObjects[i]->Update(deltaTime);
        }


        //Clear Screen and Draw New Scene
        gameWindow.clear();


        //Order Draw Stack for correct Render Order
        SortDrawStack();

        for (int i = 0; i < drawStack.size(); i++)
        {
            drawStack[i]->Render(&gameWindow);
        }
        
        gameWindow.display();

        //Clear Destruction Stack for Deleted Objects
        ClearDestructionStack();
    }

    std::cout << "Closing Engine \n" << std::endl;
}

void Engine::ClearDestructionStack()
{
    Object* targetPointer;
    for (int i = 0; i < destructionStack.size(); i++)
    {
        targetPointer = destructionStack[i];
        targetPointer->OnDestroy();
        delete targetPointer;
    }
    destructionStack.clear();
}

/// <summary>
/// Sorts Draw Stack to draw objects by depth priority
/// </summary>
void Engine::SortDrawStack()
{
    if (drawStack.size() > 1)
    {
        std::sort(drawStack.begin(), drawStack.end(), [](RenderObject* a, RenderObject* b)
            {
                return a->depth < b->depth;
            });
    }
}

void Engine::RemoveObjectFromList(GameObject* g)
{
    if (g)
    {
        gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), g), gameObjects.end());
    }
}

void Engine::RegisterDrawObject(RenderObject* object)
{
    if (object)
    {
        drawStack.push_back(object);
    }
}

void Engine::RemoveDrawObject(RenderObject* object)
{
    if (object)
    {
        drawStack.erase(std::remove(drawStack.begin(), drawStack.end(), object), drawStack.end());
    }
}


void Engine::AddGameObject(GameObject* newObject)
{
    gameObjects.push_back(newObject);
    gameObjects[gameObjects.size() - 1]->Start();
}

void Engine::Destroy(Object *target)
{
    //Destroy target if it's not a null pointer
    if (target)
    {
        destructionStack.push_back(target);
    }
}

float Engine::DeltaTime()
{
    return deltaTime;
}

