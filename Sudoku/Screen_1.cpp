#include "Screen_1.h"



Screen_1::Screen_1(ResourceHolder* _rh, sf::RenderWindow& window) : rh(_rh), board(_rh, window)
{
}


Screen_1::~Screen_1()
{
}

void Screen_1::handle_mouseclick(sf::RenderWindow& window , sf::Vector2i m_pos)
{
	if (board.handle_click(window, m_pos)) return;
}

int Screen_1::Run(sf::RenderWindow& window)
{
	while (true)
	{
		sf::Vector2i m_pos = sf::Mouse::getPosition(window);
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 0;
			}
			if(event.type == sf::Event::MouseButtonPressed)
				if (event.key.code == sf::Mouse::Left)
				{
					handle_mouseclick(window, m_pos);
				}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Numpad1:
					board.handle_input(1);
					break;
				case sf::Keyboard::Numpad2:
					board.handle_input(2);
					break;
				case sf::Keyboard::Numpad3:
					board.handle_input(3);
					break;
				case sf::Keyboard::Numpad4:
					board.handle_input(4);
					break;
				case sf::Keyboard::Numpad5:
					board.handle_input(5);
					break;
				case sf::Keyboard::Numpad6:
					board.handle_input(6);
					break;
				case sf::Keyboard::Numpad7:
					board.handle_input(7);
					break;
				case sf::Keyboard::Numpad8:
					board.handle_input(8);
					break;
				case sf::Keyboard::Numpad9:
					board.handle_input(9);
					break;
				case sf::Keyboard::Numpad0:
					board.handle_input(0);
					break;
				}
			}
		}
		board.update_squares();

		window.clear(rh->background_color);
		board.draw(window);
		for (auto b : rh->buttons) window.draw(b);
		for (auto t : rh->texts) window.draw(t);
		window.display();
	}

	return 1;
}