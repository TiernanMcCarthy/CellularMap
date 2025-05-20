#pragma once
#include "Behaviour.h"

class RenderObject : public Behaviour
{
public:
	//Used to calculate Draw Depth (Only useful for SFML, rework for OpenGL or something
	unsigned int depth = 0;

	void Start() override;

	void OnDestroy() override;
};