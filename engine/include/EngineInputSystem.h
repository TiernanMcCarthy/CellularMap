#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

#include <vector>



///Generic Base Input container for most actions,
class GenericInputContainer
{
public:
    GenericInputContainer();

    bool wasPerformedThisFrame;
    bool wasReleasedThisFrame;

    bool IsPerformed;

    virtual void Clean()
    {
        wasPerformedThisFrame = false;
        wasReleasedThisFrame = false;
        IsPerformed = false;
    }

    virtual void ProcessInput()
    {

    }

private:
    bool wasPerformedLastFrame;
};

///
class FloatInputContainer
{};


class EngineInputSystem
{
public:
	static EngineInputSystem* InputSystem;

	float scrollWheelDelta;

	void PollInputs();

	void CleanInputs();

    void AddInputEvent(sf::Event::KeyPressed);

    void AddInputEvent(sf::Event::MouseButtonPressed);

	EngineInputSystem();

private:

    //List of Input Events to be processed later, cleaned once per frame;
    std::vector<sf::Event> inputEvents;
};
