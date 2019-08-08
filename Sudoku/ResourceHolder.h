#pragma once
#include <SFML/Graphics.hpp>

class ResourceHolder
{
public:
	ResourceHolder();
	~ResourceHolder();

	//Const variables
	const int grid_size = 9;
	const int square_pixel_size = 100;
	const int small_border_width = 3;
	const int big_border_width = 6;
	const int board_size = 900;
	const int s_width = 1600;
	const int s_height = 1000;
	const int board_offset_x = 100;
	const int board_offset_y = 100;
	const int button_width = 400;
	const int button_height = 150;
	const int button_outline_thickness = -5;
	const int button_text_size = 50;
	const int num_of_anims = 12;
	sf::Texture load_texture;
	sf::Sprite load_sprite;
	sf::Image icon;
	
	

	sf::Color button_color;
	sf::Color button_line_color;
	sf::Color background_color;
	sf::Color chosen_square_color;
	sf::Color red_color;
	sf::Color clear_color;
	sf::Color black_color;
	sf::Color blue_color;

	sf::Font bohemian_font;
	sf::Font number_font;

	
	std::vector<sf::Text> texts;
	std::vector<sf::RectangleShape> buttons;
};

