#pragma once
#include <SFML/Graphics.hpp>
#include "Behaviour.h"

class SceneCamera : public Behaviour
{

public:

	SceneCamera(sf::View startingView);

	float zoomSpeed;

	sf::Vector2f size;

	void Update(float deltaTime) override;

	sf::Vector2f minBounds;

	sf::Vector2f maxBounds;


private:

	void ManageCamera(float deltaTime);
};