#include "RenderObject.h"
#include "Engine.h"
void RenderObject::Start()
{
	Engine::GEngine->RegisterDrawObject(this);
}

void RenderObject::OnDestroy()
{
	Behaviour::OnDestroy();
	Engine::GEngine->RemoveDrawObject(this);
}
