#pragma once


class EngineInputSystem
{
public:
	static EngineInputSystem* InputSystem;

	float scrollWheelDelta;
	

	void PollInputs();

	void CleanInputs();
	EngineInputSystem();
};