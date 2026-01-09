#pragma once

#include "ACollider.h"

class ICollisionEvent
{
	public:
		virtual void BeginCollision(ACollider* me, ACollider* other) = 0;
		virtual void EndCollision(ACollider* me, ACollider* other) = 0;
};

