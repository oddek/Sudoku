#pragma once
#include "cScreen.h"
#include "Board.h"

class Screen_1 : public cScreen
{
public:
	Screen_1(ResourceHolder* _rh, sf::RenderWindow& window);
	~Screen_1();

	Board board;
	ResourceHolder* rh;

	int Run(sf::RenderWindow& window);

	void handle_mouseclick(sf::RenderWindow& window, sf::Vector2i m_pos);


private:

	


};

