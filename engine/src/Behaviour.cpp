#include "Behaviour.h"
#include "GameObject.h"


void Behaviour::OnDestroy()
{
	if (gameObject)
	{
		gameObject->RemoveBehaviour(this);
	}
}

void Behaviour::Start()
{
}

void Behaviour::Update(float deltaTime)
{
}


