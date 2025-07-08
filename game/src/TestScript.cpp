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
    gameObject->transform.localScale=sf::Vector2<float>(1280, 720);

    gameObject->transform.SetPosition(sf::Vector2f(DISPLAYWIDTH/2, DISPLAYHEIGHT/2));

    boxR = gameObject->AddBehaviour<BoxRenderer>();
     activeColour=sf::Color::Green;
     inactiveColour=sf::Color::Red;
    boxR->color = inactiveColour;

    boxR->UpdateVisualComponents();

     //boxR->

    attachedButton=gameObject->AddBehaviour<Button>();
     attachedButton->OnPress.Subscribe(std::bind(&TestScript::ToggleAttached,this));
    //attachedButton->OnPress.Subscribe([this](){this->ToggleAttached();});
    //std::bind(&SceneCamera::PrintTest, camera)

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
