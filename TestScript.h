#pragma once  
#include "Behaviour.h"
#include <iostream>

class TestScript : public Behaviour {
public:
    void Start() override;
};

class EpicTest : public TestScript
{
public:
    void Start() override
    {
        //TestScript::Start();
        std::cout << "IM SO CLEVER" << std::endl;
    }

    std::string epicString()
    {
        return "We Have a Component System for now";
    }
};