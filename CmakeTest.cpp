// CmakeTest.cpp : Defines the entry point for the application.
//

#include "CmakeTest.h"
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
