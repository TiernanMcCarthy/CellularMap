#include "TestScript.h"
#include <iostream>
#include "GameObject.h"
#include "BoxRenderer.h"
#include <math.h>
#include <SFML/System/Clock.hpp>

static sf::Clock globalClock;

void TestScript::Start()
{
    std::cout << "TestScript Start called on GameObject: ";
    if (gameObject) {
        std::cout << gameObject->name << std::endl;
    }
    else {
        std::cout << "(no gameObject assigned!)" << std::endl;
    }

}

void TestScript::Update(float deltaTime)  
{  
    frameUpdates++;  

    float timeInSeconds = globalClock.getElapsedTime().asSeconds();
    gameObject->transform.localScale = sf::Vector2<float>(abs(100 * sinf(timeInSeconds)), 100);  

    // gameObject->transform.SetPosition(gameObject->transform.GetPosition() + sf::Vector2<float>(50 * deltaTime, 0));  
}
