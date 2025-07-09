#include "TestScript.h"
#include <iostream>
#include "GameObject.h"
#include "BoxRenderer.h"
#include "Constants.h"
#include <math.h>
#include <SFML/System/Clock.hpp>

static sf::Clock globalClock;

 TestScript::TestScript()
{

}


void TestScript::Start()
{
    gameObject->transform.localScale=sf::Vector2<float>(DISPLAYWIDTH/10, DISPLAYWIDTH/10);

    gameObject->transform.SetPosition(sf::Vector2f(DISPLAYWIDTH/18, DISPLAYHEIGHT/10));

    boxR = gameObject->AddBehaviour<BoxRenderer>();
     //boxR->SetDimensions(gameObject->transform.localScale.x, gameObject->transform.localScale.y);
     activeColour=sf::Color::Green;
     inactiveColour=sf::Color::Red;
    boxR->color = inactiveColour;

    boxR->UpdateVisualComponents();
     boxR->drawLayer=DrawMode::UI;


     //boxR->

    attachedButton=gameObject->AddBehaviour<Button>();
     attachedButton->OnPress.Subscribe(std::bind(&TestScript::ToggleAttached,this));
    attachedButton->worldSpace=false;

}
void TestScript::ToggleAttached()
{
    state=!state;

    if (state)
    {
        boxR->color=activeColour;
        boxR->UpdateVisualComponents();
    }
    else
    {
        boxR->color=inactiveColour;
        boxR->UpdateVisualComponents();
    }
}

void TestScript::Update(float deltaTime)  
{  

}
