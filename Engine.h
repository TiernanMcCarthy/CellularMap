#pragma once
#include "SFML/Window.hpp"
#include "vector";
#include "GameObject.h"
#include "Object.h"

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

	template<typename T>
	T* CreateGameObject(std::string name);


	void RemoveObjectFromList(GameObject* g);

private:

	//holds all gameobjects in the Engine Scene
	std::vector<GameObject*> gameObjects;

	//holds all objects that are being destroyed this frame, we need to clear them from the appropriate areas
	std::vector<Object*> destructionStack;

	float deltaTime;

	void EngineLoop();

	void ClearDestructionStack();

	bool isRunning = false;

protected:
};