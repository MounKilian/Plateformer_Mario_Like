#pragma once

#include <box2d/box2d.h>
#include "AComponent.h"

class Rigidbody : public AComponent
{
	protected:
		b2BodyDef bodyDef;
		b2BodyId bodyId;

	public:
		void Init(b2WorldId world);
		void setBodyType(b2BodyType type);
		void setBodyPosition(b2Vec2 position);
		void setLinearVelocity(b2Vec2 velocity);
		void setAngularVelocity(float velocity);
		b2Vec2 getBodyPosition();
		b2Rot getRotation();
		b2Vec2 getLinearVelocity();
		float getAngularVelocity();
		b2BodyId getBody();
};
