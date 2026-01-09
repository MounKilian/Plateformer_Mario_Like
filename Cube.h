#pragma once

#include "AComponent.h"
#include "ICollisionEvent.h"

class Cube : public AComponent, public ICollisionEvent
{
	public:
		void Init();
		void BeginCollision(ACollider* me, ACollider* other) override;
		void EndCollision(ACollider* me, ACollider* other) override;
};

