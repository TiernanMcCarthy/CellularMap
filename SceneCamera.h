#pragma once
#include <SFML/Graphics.hpp>
#include "Behaviour.h"

class SceneCamera : public Behaviour
{

public:

	float cameraSpeed;

	sf::View cameraView;

	sf::RenderWindow *renderTarget;

	sf::Vector2f size;

	sf::Vector2f position;

	sf::Vector2f minBounds;

	sf::Vector2f maxBounds;

	void Update(float deltaTime) override;

	SceneCamera();
private:
	float zoomLevel;
	float zoomSpeed;
	float oldZoom;
	void ManageCamera(float deltaTime);
};