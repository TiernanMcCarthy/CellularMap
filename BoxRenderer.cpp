#include "BoxRenderer.h"
#include "GameObject.h"
void BoxRenderer::Render(sf::RenderWindow *target)
{
	if (target)
	{
		
		box.setPosition(gameObject->transform.GetPosition());
		target->draw(box);
		
	}
}

void BoxRenderer::UpdateVisualComponents()
{
	box.setSize(dimensions);
	box.setFillColor(color);
}

void BoxRenderer::Start()
{
	RenderObject::Start();
	box = sf::RectangleShape(dimensions);
	box.setFillColor(color);
	
}

BoxRenderer::BoxRenderer(sf::Vector2<float> size)
{
	dimensions = size;
}
