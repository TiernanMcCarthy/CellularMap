#include "GameObject.h"
#include "Engine.h"
#include "Behaviour.h"
#include <iostream>

GameObject::GameObject(std::string objectname)
{
	transform = Transform();
	name = objectname;
	visualElements = RenderObject();
	behaviours = std::vector<Behaviour*>();
	Engine::GEngine->AddGameObject(this);
}

GameObject::~GameObject()
{
	std::cout << "WHYYYYY \n" << std::endl;
	
	for (auto b : behaviours)
	{
		if (b != nullptr)
		{
			delete b;
		}
	}
	behaviours.clear();
}




void GameObject::Destroy()
{
}

void GameObject::Update(float deltaTime)
{
}

void GameObject::UpdateTransform()
{
}

void GameObject::Start()
{

}

void GameObject::SetBehaviourParent(Behaviour* b)
{
	b->SetGameObject(this);
}
