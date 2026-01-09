#pragma once

#include "Ship.h"
#include "Projectile.h"
#include <vector>

class Player : public AComponent
{
	sf::Clock timerShoot;

	public :
		/*Player(sf::Texture& texture, float dammage, float life);*/
		void Init();
		void Move(float deltaTime);
		void Shoot();
		void Update(float dt) override;
};
