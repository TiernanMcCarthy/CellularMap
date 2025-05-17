#pragma once

#include "SFML/Graphics/Font.hpp";


class FontManager
{
public:

	static sf::Font* defaultFont;

	static void SetDefaultFont(sf::Font* font)
	{
		defaultFont = font;
	}

	FontManager();
};