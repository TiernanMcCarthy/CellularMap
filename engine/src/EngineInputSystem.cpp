#include "EngineInputSystem.h"

EngineInputSystem* EngineInputSystem::InputSystem = nullptr;

void EngineInputSystem::PollInputs()
{

}

void EngineInputSystem::CleanInputs()
{
	scrollWheelDelta = 0;
}

EngineInputSystem::EngineInputSystem()
{
	InputSystem = this;
	scrollWheelDelta = 0;
}
