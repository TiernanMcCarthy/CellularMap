#pragma once
#include "Behaviour.h"
#include <SFML/Graphics.hpp>
class RenderObject : public Behaviour
{
public:
	//Used to calculate Draw Depth (Only useful for SFML, rework for OpenGL or something
	unsigned int depth = 0;

	sf::Vector2<float> dimensions;

	//Render Update for All Render Objects, override for custom behaviours
	virtual void Render(sf::RenderWindow *target);

	virtual void UpdateVisualComponents();

	void Start() override;

	void OnDestroy() override;

	void SetDimensions(float x, float y);
};