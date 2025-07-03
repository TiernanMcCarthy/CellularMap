#include "EngineInputSystem.h"
#include "Engine.h"
#include <iostream>
EngineInputSystem* EngineInputSystem::InputSystem = nullptr;

void EngineInputSystem::PollInputs()
{

}

void EngineInputSystem::CleanInputs()
{
    inputEvents.clear();
	scrollWheelDelta = 0;
}

EngineInputSystem::EngineInputSystem()
{
	InputSystem = this;
	scrollWheelDelta = 0;
    inputEvents=std::vector<sf::Event>();
}

void EngineInputSystem::AddInputEvent(sf::Event::KeyPressed)
{
    inputEvents.push_back(sf::Event::KeyPressed());
}

void EngineInputSystem::AddInputEvent(sf::Event::MouseButtonPressed)
{
    inputEvents.push_back(sf::Event::MouseButtonPressed());
}

