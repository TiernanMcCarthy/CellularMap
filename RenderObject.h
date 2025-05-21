#pragma once
#include "Behaviour.h"

class RenderObject : public Behaviour
{
public:
	//Used to calculate Draw Depth (Only useful for SFML, rework for OpenGL or something
	unsigned int depth = 0;

	sf::Vector2<int> dimensions;

	//Render Update for All Render Objects, override for custom behaviours
	virtual void Render();

	void Start() override;

	void OnDestroy() override;

	void SetDimensions(int x, int y);
};