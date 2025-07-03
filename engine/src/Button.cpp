//
// Created by tiernan on 7/3/25.
//
#include "Button.h"


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
}


