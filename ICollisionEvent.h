#pragma once

#include "ACollider.h"

class ICollisionEvent
{
	public:
		virtual void BeginCollision(Entity* me, Entity* other) = 0;
		virtual void EndCollision(Entity* me, Entity* other) = 0;
};

