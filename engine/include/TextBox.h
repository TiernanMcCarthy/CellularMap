#pragma once
#include "Behaviour.h"
#include "GameObject.h"
#include "RenderObject.h"
#include "SFML/Graphics/Text.hpp"

#include <string>
#include <vector>

class TextBox : public  RenderObject
{
public:
    std::string text;

    void Update(float deltaTime) override;
    void Start() override;
    void Render(sf::RenderWindow *target) override;
	 
    TextBox();
    ~TextBox() = default;

    sf::Vector2<float> offsetPos;

    unsigned int fontSize;
private:

    sf::Text* textBox;

};

