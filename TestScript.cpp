#include "TestScript.h"
#include <iostream>
#include "GameObject.h"
void TestScript::Start()
{
    std::cout << "TestScript Start called on GameObject: ";
    if (gameObject) {
        std::cout << gameObject->name << std::endl;
    }
    else {
        std::cout << "(no gameObject assigned!)" << std::endl;
    }
}

void TestScript::Update(float deltaTime)
{
    std::cout << "This is an epic game update loop \n" << std::endl;
}

