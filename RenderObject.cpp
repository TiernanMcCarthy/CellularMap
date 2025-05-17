#include "RenderObject.h"
#include "GameObject.h"
#include <iostream>
void RenderObject::Draw(GameObject parent)
{
	std::string output = "Render Object on "+ parent.name + " is not a valid Render Object, this is a base class \n";
	std::cout << output << std::endl;
}
