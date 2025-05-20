#include "Engine.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "TestScript.h"
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
    sf::RenderWindow gameWindow = sf::RenderWindow(sf::VideoMode(sf::Vector2u(DISPLAYWIDTH, DISPLAYHEIGHT)), "Tiernan Engine");

    //Clock for calculating Delta Time
    sf::Clock clock;

    GameObject* temp = new GameObject("My epic Object");

    temp->AddBehaviour<TestScript>();
    
    TestScript* epicType = temp->GetBehaviour<TestScript>();

    gameWindow.setFramerateLimit(60);

    Destroy(epicType);

    //Main Game Loop
    while (gameWindow.isOpen())
    {
        //Handle Events
        while (const std::optional event = gameWindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                gameWindow.close();
                break;
            }

        }

        //Get Delta Time
        deltaTime = clock.restart().asSeconds();

        for (int i = 0; i < gameObjects.size(); i++)
        {
            //Update all GameObjects
            gameObjects[i]->Update(deltaTime);

            //Update all Gameobject Transforms (Visual Elements e.t.c)
            gameObjects[i]->UpdateTransform();
        }

        //Clear Screen and Draw New Scene
        gameWindow.clear();

        for (int i = 0; i < gameObjects.size(); i++)
        {
            gameObjects[i]->visualElements.Draw(gameObjects[i]);
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

void Engine::RemoveObjectFromList(GameObject* g)
{
    if (g)
    {
        gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), g), gameObjects.end());
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

