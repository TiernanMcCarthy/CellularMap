//
// Created by tiernan on 7/3/25.
//
#include "Button.h"

#include "EngineInputSystem.h"

Button::Button()
{
    OnPress = FunctionSubscriber();
}

Button::~Button()
{

}


void Button::Start()
{
    collider = AABBCollider();
    collider.SetGameObject(gameObject);
}

void Button::ManageButton()
{
    //Check for collision

    if (EngineInputSystem::InputSystem->MouseOne->wasReleasedThisFrame)
    {
        sf::Vector2<float> pos=EngineInputSystem::WorldSpaceMousePos();

        if (collider.IsPosInside(pos))
        {
            OnPress.Activate();
        }
    }
}

void Button::Update(float deltaTime)
{
    ManageButton();


}




