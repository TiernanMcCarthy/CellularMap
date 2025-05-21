#include "RenderObject.h"
#include "Engine.h"



void RenderObject::Render(sf::RenderWindow *target)
{
}
void RenderObject::UpdateVisualComponents()
{
}
void RenderObject::Start()
{
	Engine::GEngine->RegisterDrawObject(this);
	dimensions = sf::Vector2<float>();
}

void RenderObject::OnDestroy()
{
	Behaviour::OnDestroy();
	Engine::GEngine->RemoveDrawObject(this);
}

void RenderObject::SetDimensions(float x, float y)
{
	dimensions.x = x;
	dimensions.y = y;
	UpdateVisualComponents();
}
