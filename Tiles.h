#pragma once

#include "AComponent.h"
#include "ICollisionEvent.h"

class Tiles : public AComponent, public ICollisionEvent
{
	int type; 

	public:
		void Init(int type);
		void BeginCollision(Entity* me, Entity* other) override;
		void EndCollision(Entity* me, Entity* other) override;
};

