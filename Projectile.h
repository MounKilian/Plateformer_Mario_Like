#pragma once

#include "Entity.h"
#include "AComponent.h"

class Projectile : public AComponent
{
	bool isPlayer;

	public:
		/*Projectile(bool isPlayer);*/
		void Init(bool isPlayer);
		void Move(float deltaTime);
		void Update(float dt) override;
};

