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




void GameObject::Update(float deltaTime)
{
	//iterate through all attached behaviours
	for (int i = 0; i < behaviours.size(); i++)
	{
		behaviours[i]->Update(deltaTime);
	}
}

void GameObject::UpdateTransform()
{
}

void GameObject::Start()
{

}

void GameObject::RemoveBehaviour(Behaviour* t)
{
	auto behaviour = *t;
	for (int i = 0; i < behaviours.size(); i++)
	{
		auto compare = *behaviours[i];
		if (&behaviour == &compare)
		{
			int bob = 5;
		}
	}
}

void GameObject::SetBehaviourParent(Behaviour* b)
{
	b->SetGameObject(this);
}
