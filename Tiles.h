#pragma once

#include "AComponent.h"
#include "ICollisionEvent.h"

class Tiles : public AComponent, public ICollisionEvent
{
	public:
		void Init(int type);
		void BeginCollision(ACollider* me, ACollider* other);
		void EndCollision(ACollider* me, ACollider* other);
};

