#pragma once

#include <box2d/box2d.h>

class Physics
{
	protected:
		b2Vec2 gravity;
		b2WorldId world;

	public:
		Physics(b2Vec2 gravity);
		void Update(float deltaTime);
		b2WorldId getWorld();
		static const float worldScale;
};

