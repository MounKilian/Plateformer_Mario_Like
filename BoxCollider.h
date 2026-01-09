#pragma once

#include <box2d/box2d.h>
#include <SFML/System.hpp>
#include "ACollider.h"

class BoxCollider : public ACollider
{
	protected:
		b2Polygon shape;
		sf::Vector2f size;

	public:
		void setShapeOnBody(b2BodyId bodyid) override;
		void setSize(sf::Vector2f size);
};

