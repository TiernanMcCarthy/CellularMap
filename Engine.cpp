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
    
    TestScript epicType = *temp->GetBehaviour<TestScript>();

    temp->RemoveBehaviour(&epicType);

    gameWindow.setFramerateLimit(60);
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

    }

    std::cout << "Closing Engine \n" << std::endl;
}


void Engine::AddGameObject(GameObject* newObject)
{
    gameObjects.push_back(newObject);
    gameObjects[gameObjects.size() - 1]->Start();
}

void Engine::Destroy()
{

}

float Engine::DeltaTime()
{
    return deltaTime;
}

