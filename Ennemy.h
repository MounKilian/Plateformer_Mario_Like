#pragma once

#include "AComponent.h"
#include "ICollisionEvent.h"

class Ennemy : public AComponent, public ICollisionEvent
{
	sf::Vector2f dir;
	int type;
	bool anim;
	float animTimer;
	float animSpeed;

	public:
		void Init(int type);
		void Move(float deltaTime);
		void Update(float dt);
		void BeginCollision(Entity* me, Entity* other) override;
		void EndCollision(Entity* me, Entity* other) override;
};

