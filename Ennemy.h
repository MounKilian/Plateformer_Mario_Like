#pragma once

#include "Projectile.h"
#include <vector>

class Ennemy : public AComponent
{
	sf::Clock timerShoot;
	sf::Clock timerMovement;
	sf::Vector2f dir;

	public: 
		/*Ennemy(sf::Texture& texture, float dammage, float life);*/
		void Init();
		void Move(float deltaTime);
		void Shoot();
		void Update(float dt) override;
};
