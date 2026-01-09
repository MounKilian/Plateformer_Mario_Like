#pragma once

#include "Entity.h"

class Ship : public AComponent
{
	float dammage;
	float life;

	public :
		Ship(sf::Texture& texture, float dammage, float life);
		float GetDammage();
		void SetDammage(float dammage);
		float GetLife();
		void SetLife(float life);
		virtual void IsColliding();
		virtual void TakeDammage();
};

