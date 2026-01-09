#pragma once

#include <box2d/box2d.h>
#include "AComponent.h"
#include "Rigidbody.h"

class ACollider : public AComponent
{
	protected:
		b2ShapeDef shapeDef;
		b2ShapeId shapeId;
		bool isInit = false;

	public :
		void Init(Rigidbody* rigidbody);
		virtual void setShapeOnBody(b2BodyId bodyid) = 0;
		void setDensity(float density);
		void setFriction(float friction);
		friend class Physics;
		
};

