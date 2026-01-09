#pragma once

#include "AComponent.h"

class Renderer : public AComponent 
{
	sf::Sprite sprite;

	public:
		Renderer(sf::Texture* texture);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		sf::Sprite* GetSprite();
};

