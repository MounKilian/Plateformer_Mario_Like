#include "Rigidbody.h"
#include "Transform.h"
#include "Entity.h"
#include "Physics.h"

void Rigidbody::Init(b2WorldId world)
{
	bodyDef = b2DefaultBodyDef();
	sf::Vector2f position = parent->getComponent<Transform>()->getPosition();
	bodyDef.position = { position.x / Physics::worldScale, position.y / Physics::worldScale};
	bodyId = b2CreateBody(world, &bodyDef);
	b2Body_SetFixedRotation(bodyId, true);
}

void Rigidbody::setBodyType(b2BodyType type)
{
	b2Body_SetType(bodyId, type);
}

void Rigidbody::setBodyPosition(b2Vec2 position)
{
	b2Body_SetTransform(bodyId, { position.x / Physics::worldScale, position.y / Physics::worldScale }, getRotation());
}

void Rigidbody::setLinearVelocity(b2Vec2 velocity)
{
	b2Body_SetLinearVelocity(bodyId, velocity);
}

void Rigidbody::setAngularVelocity(float velocity)
{
	b2Body_SetAngularVelocity(bodyId, velocity);
}

b2Vec2 Rigidbody::getBodyPosition()
{
	return b2Body_GetPosition(bodyId);
}

b2Rot Rigidbody::getRotation()
{
	return b2Body_GetRotation(bodyId);
}

b2Vec2 Rigidbody::getLinearVelocity()
{
	return b2Body_GetLinearVelocity(bodyId);
}

float Rigidbody::getAngularVelocity()
{
	return b2Body_GetAngularVelocity(bodyId);
}

b2BodyId Rigidbody::getBody()
{
	return bodyId;
}

void Rigidbody::DestroyBody(b2BodyId bodyId)
{
	b2DestroyBody(bodyId);
	this->bodyId = b2_nullBodyId;
}
