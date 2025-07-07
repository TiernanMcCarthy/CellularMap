#pragma once

#include "Behaviour.h"
#include "AABBCollider.h"
#include "FunctionSubscriber.h"
class Button : public Behaviour
{
public:

    ///On press event system, subscribe to this for functionality
    FunctionSubscriber OnPress;

    Button();

    ~Button();

    void Start() override;

    void Update(float deltaTime) override;

private:
    AABBCollider collider;

    void ManageButton();

};