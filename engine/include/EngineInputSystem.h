#pragma once
#include "SFML/System/Vector2.hpp"


class EngineInputSystem
{
public:
	static EngineInputSystem* InputSystem;

	float scrollWheelDelta;

	void PollInputs();

	void CleanInputs();
	EngineInputSystem();
};
