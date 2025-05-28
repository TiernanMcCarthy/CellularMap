#include "SceneCamera.h"

SceneCamera::SceneCamera()
{
	zoomSpeed = 10;
	cameraSpeed = 100;
}

//Manage Keyboard and mouse input for moving the camera around the screen
void SceneCamera::ManageCamera(float deltaTime)
{
	sf::Vector2f movementVector = sf::Vector2f();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		movementVector.y += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		movementVector.y -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		movementVector.x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		movementVector.x += 1;
	}

	position = movementVector * cameraSpeed * deltaTime;
	cameraView.move(position);

	renderTarget->setView(cameraView);
	
}


void SceneCamera::Update(float deltaTime)
{
	ManageCamera(deltaTime);
}
