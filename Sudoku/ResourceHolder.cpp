#include "ResourceHolder.h"



ResourceHolder::ResourceHolder(): 
	background_color(0x536878FF), chosen_square_color(0x708090AA), 
	red_color(0xFF0000FF), clear_color(0xFFFFFF00), black_color(0x000000FF), blue_color(0x0000FFFF),
	button_color(0xf99820FF), button_line_color(0x000000FF)
{
	number_font.loadFromFile("fonts/SummitLight-Display.ttf");
	bohemian_font.loadFromFile("fonts/Bohemian_Typewriter.ttf");

	//Init buttons and header
	//Header
	sf::Text headline("Sudoku", bohemian_font, 100);
	headline.setFillColor(sf::Color:: Black);
	headline.setStyle(sf::Text::Bold);
	sf::FloatRect textRect = headline.getLocalBounds();
	headline.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	headline.setPosition(sf::Vector2f((s_width - (s_width - board_size - board_offset_x) / 2), 150));
	texts.push_back(headline);
	//Generate new
	//NEW GAME-button////////////////////////////////////////////////////////
	sf::RectangleShape new_button(sf::Vector2f(button_width, button_height));
	new_button.setOrigin(button_width / 2, button_height / 2);
	new_button.setFillColor(button_color);
	new_button.setOutlineColor(button_line_color);
	new_button.setOutlineThickness(button_outline_thickness);
	new_button.setPosition(sf::Vector2f(s_width - (s_width - board_size - board_offset_x) / 2, 400));
	buttons.push_back(new_button);

	sf::Text new_game_text("Generate New", bohemian_font, button_text_size);
	new_game_text.setFillColor(black_color);

	sf::FloatRect new_rectBounds = new_button.getGlobalBounds();
	sf::FloatRect new_textBounds = new_game_text.getGlobalBounds();

	new_game_text.setPosition(
		new_rectBounds.left + (new_rectBounds.width / 2) - (new_textBounds.width / 2),
		new_rectBounds.top + (new_rectBounds.height / 2) - (new_textBounds.height / 2));

	texts.push_back(new_game_text);

	//Solve
	sf::RectangleShape solve_button(sf::Vector2f(button_width, button_height));
	solve_button.setOrigin(button_width / 2, button_height / 2);
	solve_button.setFillColor(button_color);
	solve_button.setOutlineColor(button_line_color);
	solve_button.setOutlineThickness(button_outline_thickness);
	solve_button.setPosition(sf::Vector2f(s_width - (s_width - board_size - board_offset_x) / 2, 650));
	buttons.push_back(solve_button);

	sf::Text solve_text("Solve", bohemian_font, button_text_size);
	solve_text.setFillColor(black_color);

	sf::FloatRect solve_rectBounds = solve_button.getGlobalBounds();
	sf::FloatRect solve_textBounds = solve_text.getGlobalBounds();

	solve_text.setPosition(
		solve_rectBounds.left + (solve_rectBounds.width / 2) - (solve_textBounds.width / 2),
		solve_rectBounds.top + (solve_rectBounds.height / 2) - (solve_textBounds.height / 2));

	texts.push_back(solve_text);

	//Solve
	sf::RectangleShape manual_entry_button(sf::Vector2f(button_width, button_height));
	manual_entry_button.setOrigin(button_width / 2, button_height / 2);
	manual_entry_button.setFillColor(button_color);
	manual_entry_button.setOutlineColor(button_line_color);
	manual_entry_button.setOutlineThickness(button_outline_thickness);
	manual_entry_button.setPosition(sf::Vector2f(s_width - (s_width - board_size - board_offset_x) / 2, 900));
	buttons.push_back(manual_entry_button);

	sf::Text manual_entry_text("Manual entry", bohemian_font, button_text_size);
	manual_entry_text.setFillColor(black_color);

	sf::FloatRect manual_entry_rectBounds = manual_entry_button.getGlobalBounds();
	sf::FloatRect manual_entry_textBounds = manual_entry_text.getGlobalBounds();

	manual_entry_text.setPosition(
		manual_entry_rectBounds.left + (manual_entry_rectBounds.width / 2) - (manual_entry_textBounds.width / 2),
		manual_entry_rectBounds.top + (manual_entry_rectBounds.height / 2) - (manual_entry_textBounds.height / 2));

	texts.push_back(manual_entry_text);

	
	load_texture.loadFromFile("img/load_sheet.png");
	load_sprite.setTexture(load_texture);
	load_sprite.setTextureRect(sf::IntRect(0,0,load_texture.getSize().x/num_of_anims,load_texture.getSize().y));
	load_sprite.setOrigin(load_sprite.getGlobalBounds().width / 2, load_sprite.getGlobalBounds().height / 2);
	load_sprite.setPosition(board_offset_x + board_size / 2, board_offset_y + board_size / 2);

	icon.loadFromFile("img/icon.png");
}


ResourceHolder::~ResourceHolder()
{
}
