#include "RenderObject.h"
#include "Engine.h"



void RenderObject::Render()
{
}
void RenderObject::Start()
{
	Engine::GEngine->RegisterDrawObject(this);
	dimensions = sf::Vector2<int>();
}

void RenderObject::OnDestroy()
{
	Behaviour::OnDestroy();
	Engine::GEngine->RemoveDrawObject(this);
}

void RenderObject::SetDimensions(int x, int y)
{
	dimensions.x = x;
	dimensions.y = y;
}
