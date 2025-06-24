#pragma once

#include "RenderObject.h"

class Image :public RenderObject
{
public:

	sf::Image element;

	void Start() override;

	void Render(sf::RenderWindow *target) override;

};