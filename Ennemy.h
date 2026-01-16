#pragma once

#include "AComponent.h"
#include "ICollisionEvent.h"

class Ennemy : public AComponent, public ICollisionEvent
{
	sf::Vector2f dir;

	public:
		void Init();
		void Move(float deltaTime);
		void Update(float dt);
		void BeginCollision(ACollider* me, ACollider* other) override;
		void EndCollision(ACollider* me, ACollider* other) override;
};

