#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class CommonFunctions
{
private:
	CommonFunctions();
	~CommonFunctions();

public:
	static void clearScreen();
	static void drawRectangle(sf::RenderTarget &target, sf::FloatRect rect);
};
