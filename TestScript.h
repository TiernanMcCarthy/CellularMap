#pragma once  
#include "Behaviour.h"
#include <iostream>

class TestScript : public Behaviour {
public:
    void Start() override;
    void Update(float deltatime) override;
};
