#include "BoxCollider.h"
#include "Physics.h"

void BoxCollider::setShapeOnBody(b2BodyId bodyid)
{
	shape = b2MakeBox(size.x / 2.f / Physics::worldScale, size.y / 2.f / Physics::worldScale);
	shapeId = b2CreatePolygonShape(bodyid, &shapeDef, &shape);
}

void BoxCollider::setSize(sf::Vector2f size)
{
	this->size = size;
	if (isInit)
	{
		shape = b2MakeBox(size.x / 2.f / Physics::worldScale, size.y / 2.f / Physics::worldScale);
		b2Shape_SetPolygon(shapeId, &shape);
	}
}
