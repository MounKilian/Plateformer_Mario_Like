#pragma once

#include "AComponent.h"
#include <SFML/Graphics.hpp>

class TextRenderer : public AComponent
{
	sf::Text text;

	public :
		TextRenderer(sf::Font* font);
		void setString(std::string str);
		void setCharacterSize(int size);
		void setFillColor(sf::Color color);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

