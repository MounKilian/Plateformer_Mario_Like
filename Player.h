#pragma once

#include "AComponent.h"
#include "ICollisionEvent.h"
#include <vector>

class Player : public AComponent, public ICollisionEvent
{
	bool isJumping; 

	public :
		void Init();
		void Move(float deltaTime);
		void Jump();
		void DeadZone();
		void Death();
		void Update(float dt) override;
		void BeginCollision(Entity* me, Entity* other) override;
		void EndCollision(Entity* me, Entity* other) override;
};
