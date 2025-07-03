#pragma once
#include "EngineInputSystem.h"
#include "GameObject.h"
#include "Object.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window.hpp"
#include "StartupSequence.h"
#include "vector"
class RenderObject;

class GameObject;

class StartupSequence;


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

	void AddStartupSequence(StartupSequence *param);

    sf::RenderWindow &GetRenderWindow();

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

	std::vector<StartupSequence*> startupList;

    EngineInputSystem* engineInput;

    sf::RenderWindow renderWindow;

protected:
};