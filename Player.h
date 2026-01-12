#pragma once

#include "Ship.h"
#include "Projectile.h"
#include "AComponent.h"
#include "ICollisionEvent.h"
#include <vector>

class Player : public AComponent, public ICollisionEvent
{
	public :
		void Init();
		void Move(float deltaTime);
		void Update(float dt) override;
		void BeginCollision(ACollider* me, ACollider* other) override;
		void EndCollision(ACollider* me, ACollider* other) override;
};
