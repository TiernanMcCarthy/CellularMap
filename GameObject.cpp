#include "GameObject.h"
#include "Engine.h"



GameObject::GameObject(std::string objectname)
{
	transform = Transform();
	name = objectname;
	visualElements = RenderObject();
	Engine::GEngine->AddGameObject(this);
}

GameObject::~GameObject()
{
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
