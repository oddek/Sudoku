#include "Square.h"

Square::Square(){}

Square::Square(sf::Vector2f pos, int _correct_number, ResourceHolder* _rh): 
	correct_number(_correct_number), entered_number(_correct_number), rh(_rh), locked(true)
{
	setPosition(pos);
	setFillColor(rh->clear_color);
	setSize(sf::Vector2f(rh->square_pixel_size, rh->square_pixel_size));
	text.setFont(rh->number_font);
	text.setCharacterSize(20);
	text.setFillColor(rh->black_color);

	auto rect = getGlobalBounds();
	auto textRect = text.getGlobalBounds();

	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	text.setPosition({ rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f });

	

	//update();
}


Square::~Square()
{
}


void Square::update(bool manual_mode)
{
	if(entered_number != 0) text.setString(std::to_string(entered_number));
	else text.setString("");
	
	if (manual_mode)
	{
		correct_number = entered_number;
		text.setFillColor(rh->black_color);
	}
	else
	{
		if (entered_number == correct_number && !locked) text.setFillColor(rh->blue_color);
		else if (entered_number != correct_number && !locked) text.setFillColor(rh->red_color);
	}
}

void Square::draw(sf::RenderWindow& window)
{
	window.draw(*this);
	window.draw(text);
}