#pragma once  
#include "GameObject.h"  

class TestScript : public GameObject 
{  
public:

   virtual void Update(float deltaTime) override;

   virtual void Start() override;

   TestScript(std::string objectName = "GameObject");
};