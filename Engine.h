#pragma once
#include "SFML/Window.hpp"
#include "vector";
#include "GameObject.h"


class Engine
{
public:

	static Engine *GEngine;

	Engine(bool startEngine = false);

	void Start();

	void AddGameObject(GameObject* newObject);


	float DeltaTime();

	template<typename T>
	T* CreateGameObject(std::string name);

private:

	std::vector<GameObject*> gameObjects;

	float deltaTime;

	void EngineLoop();

	bool isRunning = false;

protected:
};