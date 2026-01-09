#pragma once

#include <SFML/Graphics.hpp>

class Entity;

class AComponent : public sf::Drawable
{
	protected:
		Entity* parent;
		friend Entity;

	public :
		virtual void Update(float dt);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

