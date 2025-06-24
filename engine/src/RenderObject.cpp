#include "RenderObject.h"
#include "Engine.h"
#include "GameObject.h"


void RenderObject::Render(sf::RenderWindow *target)
{
}
void RenderObject::UpdateVisualComponents()
{
}
void RenderObject::Start()
{
	Engine::GEngine->RegisterDrawObject(this);
	dimensions = gameObject->transform.localScale;
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
