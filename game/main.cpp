#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "FontManager.h"
#include "StartupSequence.h"
#include "ObjectSpawnList.h"

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
    ObjectSpawnList temp = ObjectSpawnList();
    gameEngine.AddStartupSequence(&temp);
    gameEngine.Start();



}

