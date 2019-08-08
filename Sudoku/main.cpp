#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Screen_1.h"
#include <ctime>
#include "ResourceHolder.h"


/*
TODO:

Legg til vanskelighetsgradering av oppgaver og la bruker velge grad selv.

Sjekk hvor mange løsninger sudokuen har ved manual entry.

Legg til "vinnerskjerm" ved komplett utfylt sudoku.

*/


int main()
{
	//ShowWindow(GetConsoleWindow(), SW_HIDE);

	ResourceHolder* rh = new ResourceHolder();
	sf::RenderWindow window(sf::VideoMode(1600, 1200), "Sudoku");
	window.setIcon(rh->icon.getSize().x, rh->icon.getSize().y, rh->icon.getPixelsPtr());

	std::vector<cScreen*> Screens;
	int screen = 0;

	cScreen* s0 = new Screen_1(rh, window);
	Screens.push_back(s0);
	while (screen <= 0)
	{
		screen = Screens[screen]->Run(window);

		if (screen == 2)
		{
			delete Screens[0];
			cScreen* s0 = new Screen_1(rh, window);
			Screens.push_back(s0);
			screen = 0;
		}
	}
	return 0;
}
