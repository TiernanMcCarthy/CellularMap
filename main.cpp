#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "FontManager.h"
#include <iostream>
int main()
{
    //Initialising Game Engine
    std::cout << "Initialising Game Engine \n" << std::endl;
    Engine gameEngine = Engine();

    //Start FontManager
    sf::Font font;
    std::cout << "Loading Fonts \n" << std::endl;
    if (font.openFromFile("arial.ttf"))
    {
        FontManager::SetDefaultFont(&font);
    }
    else
    {
        std::cout << "FontLoading failed, please ensure there is a font in project folder \n" << std::endl;
        return 1;
    }

    std::cout << "Starting Engine \n" << std::endl;
    gameEngine.Start();

}

/*sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "SFML works!");
    sf::CircleShape shape(20);
    shape.setOrigin(sf::Vector2f(10, 10));
    sf::CircleShape shape2(10);
    shape.setOrigin(sf::Vector2f(5, 5));
    GameObject temp = GameObject("JEPIC");

    temp.transform.localPosition += sf::Vector2f(5, -1);

    GameObject temp2 = GameObject("JEPIC2");

    temp2.transform.localPosition += sf::Vector2f(5, -1);

    temp2.transform.SetParent(&temp.transform);
    
    shape.setFillColor(sf::Color::Green);

    shape2.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
		temp.transform.localPosition += sf::Vector2f(0.01f, 0);
        shape.setPosition(temp.transform.GetPosition());
        shape2.setPosition(temp.transform.GetPosition());
        window.clear();
        window.draw(shape);
		window.draw(shape2);
        window.display();
    }*/