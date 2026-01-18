#pragma once

#include "AComponent.h"
#include "ICollisionEvent.h"

class Tiles : public AComponent, public ICollisionEvent
{
	int type; 
	bool anim;
	float animTimer;
	float animSpeed;

	public:
		void Init(int type);
		void Animation(float deltaTime);
		void Update(float deltaTime);
		void BeginCollision(Entity* me, Entity* other) override;
		void EndCollision(Entity* me, Entity* other) override;
};

