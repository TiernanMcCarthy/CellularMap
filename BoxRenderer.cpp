#include "BoxRenderer.h"
#include "GameObject.h"
#include <iostream>
void BoxRenderer::ApplyImage(std::string path)
{
	if (renderTexture)
	{
		delete renderTexture;
	}

	renderTexture = new sf::Texture();

	if (renderTexture->loadFromFile(path))
	{
		box.setTexture(renderTexture);
		//Texture Loaded
	}
	else
	{
		std::cout << "Invalid path or file type at " + path << std::endl;
	}
}
void BoxRenderer::Render(sf::RenderWindow *target)
{
	if (target)
	{
		UpdateVisualComponents();
		box.setOrigin(sf::Vector2f(gameObject->transform.localScale.x / 2, gameObject->transform.localScale.y / 2));
		box.setPosition(gameObject->transform.GetPosition());
		target->draw(box);
		
	}
}

void BoxRenderer::UpdateVisualComponents()
{
	box.setSize(gameObject->transform.localScale);
	box.setFillColor(color);
}


void BoxRenderer::Start()
{
	RenderObject::Start();
	box = sf::RectangleShape(gameObject->transform.localScale);
	box.setOrigin(sf::Vector2f(gameObject->transform.localScale.x / 2, gameObject->transform.localScale.y / 2));
	box.setFillColor(color);
}

BoxRenderer::BoxRenderer(sf::Vector2<float> size)
{
	dimensions = size;
	color = sf::Color::White;
}
