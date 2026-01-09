#include "ACollider.h"

void ACollider::Init(Rigidbody* rigidbody)
{
	shapeDef = b2DefaultShapeDef();
	shapeDef.enableContactEvents = true;
	setShapeOnBody(rigidbody->getBody());
	isInit = true;
}

void ACollider::setDensity(float density)
{
	if (isInit)
	{
		b2Shape_SetDensity(shapeId, density, true);
	}
	else {
		shapeDef.density = density;
	}
}

void ACollider::setFriction(float friction)
{
	if (isInit)
	{
		b2Shape_SetFriction(shapeId, friction);
	}
	else {
		shapeDef.material.friction = friction;
	}
}
