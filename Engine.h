#pragma once
#include "SFML/Window.hpp"
#include "vector";
#include "Object.h"
#include "GameObject.h"
class RenderObject;

class GameObject;

class Engine
{
public:

	static Engine *GEngine;

	Engine(bool startEngine = false);

	/// <summary>
	/// Destroys a GameObject and removes it from the gameobject List
	/// </summary>
	void Destroy(Object* target);

	void Start();

	void AddGameObject(GameObject* newObject);


	float DeltaTime();

	void RemoveObjectFromList(GameObject* g);

	void RegisterDrawObject(RenderObject* object);

	void RemoveDrawObject(RenderObject* object);

private:

	//holds all gameobjects in the Engine Scene
	std::vector<GameObject*> gameObjects;

	//holds all objects that are being destroyed this frame, we need to clear them from the appropriate areas
	std::vector<Object*> destructionStack;

	//Draw stack that contains all Behaviours that are involved in rendering
	std::vector<RenderObject*> drawStack;

	float deltaTime;

	void EngineLoop();

	void ClearDestructionStack();

	void SortDrawStack();

	bool isRunning = false;

protected:
};