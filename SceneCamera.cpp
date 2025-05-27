#include "SceneCamera.h"

SceneCamera::SceneCamera(sf::View startingView)
{
	zoomSpeed = 10;

	size = startingView.getSize();

}

//Manage Keyboard and mouse input for moving the camera around th screen
void SceneCamera::ManageCamera(float deltaTime)
{
	sf::Vector2f movementVector = sf::Vector2f();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		movementVector.x += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		movementVector.x -= 1;
	}


}


void SceneCamera::Update(float deltaTime)
{
	
}
