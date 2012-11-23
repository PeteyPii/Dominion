#include "CommonFunctions.h"

#include <SFML/Window.hpp>

#ifdef WIN32

#include <windows.h>

#else

#include <unistd.h>
#include <term.h>

#endif

CommonFunctions::CommonFunctions()
{

}
CommonFunctions::~CommonFunctions()
{

}
void CommonFunctions::clearScreen()
{
#ifdef WIN32
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = {0, 0};

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if(hStdOut == INVALID_HANDLE_VALUE) 
		return;

	/* Get the number of cells in the current buffer */
	if(!GetConsoleScreenBufferInfo(hStdOut, &csbi)) 
		return;

	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if(!FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount, homeCoords, &count)) 
		return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) 
		return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
#else
	if(!cur_term)
	{
		int result;
		setupterm(NULL, STDOUT_FILENO, &result);
		if(result <= 0) 
			return;
	}

	putp(tigetstr("clear"));
#endif
}
void CommonFunctions::drawRectangle(sf::RenderTarget &target, sf::FloatRect rect)
{
	sf::Vertex vertex[5];

	vertex[0] = sf::Vertex(sf::Vector2f(rect.left, rect.top), sf::Color::Magenta);
	vertex[1] = sf::Vertex(sf::Vector2f(rect.left + rect.width, rect.top), sf::Color::Magenta);
	vertex[2] = sf::Vertex(sf::Vector2f(rect.left + rect.width, rect.top + rect.height), sf::Color::Magenta);
	vertex[3] = sf::Vertex(sf::Vector2f(rect.left, rect.top + rect.height), sf::Color::Magenta);
	vertex[4] = sf::Vertex(sf::Vector2f(rect.left, rect.top), sf::Color::Magenta);

	target.draw(vertex, 5, sf::LinesStrip);
}
