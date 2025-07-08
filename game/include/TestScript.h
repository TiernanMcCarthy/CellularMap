#pragma once  
#include "Behaviour.h"
#include "BoxRenderer.h"
#include "Button.h"

#include <iostream>

class TestScript : public Behaviour {
public:
    void Start() override;
    void Update(float deltatime) override;

    TestScript();



    bool state=false;

    void ToggleAttached();

    sf::Color activeColour;
    sf::Color inactiveColour;
private:
    Button* attachedButton;

    BoxRenderer* boxR;
};
