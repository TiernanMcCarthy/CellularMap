#pragma once
#include <SFML/Graphics.hpp>
#include "RenderObject.h"

class SpriteElement :public RenderObject
{
public:

	//sf::Sprite sprite;

	SpriteElement();

	void Start() override;
};