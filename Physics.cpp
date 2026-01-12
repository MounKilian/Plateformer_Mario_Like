#include "Physics.h"
#include "SceneManager.h"
#include "AScene.h"
#include "Entity.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Application.h"
#include "Cube.h"

const float Physics::worldScale = 32.f;

Physics::Physics(b2Vec2 gravity)
{
	b2WorldDef worldDef = b2DefaultWorldDef();
	worldDef.gravity = gravity;
	world = b2CreateWorld(&worldDef);
}

void Physics::Update(float deltaTime)
{
	SceneManager* sceneManager = SceneManager::Instance();
	AScene* scene = sceneManager->GetCurrentScene();

	for (Entity* entity : scene->GetEntities()) {
		if (Rigidbody* rb = entity->getComponent<Rigidbody>()) {
			Transform* transform = entity->getComponent<Transform>();
			b2Body_SetTransform(rb->getBody(), { transform->getPosition().x / worldScale, transform->getPosition().y / worldScale }, b2MakeRot(transform->getRotation().asRadians()));
		}
	}

	b2World_Step(world, deltaTime, 4);

	for (Entity* entity : scene->GetEntities()) {
		if (Rigidbody* rb = entity->getComponent<Rigidbody>()) {
			Transform* transform = entity->getComponent<Transform>();
			transform->setPosition({ b2Body_GetPosition(rb->getBody()).x * worldScale, b2Body_GetPosition(rb->getBody()).y * worldScale });
			transform->setRotation(sf::radians(b2Rot_GetAngle(b2Body_GetRotation(rb->getBody()))));
		}
	}

	b2ContactEvents contactEvents = b2World_GetContactEvents(world);

	for (int i = 0; i < contactEvents.beginCount; i++)
	{
		b2ContactBeginTouchEvent beginEvent = contactEvents.beginEvents[i];
		ACollider* colliderA = nullptr;
		ACollider* colliderB = nullptr;

		for (Entity* entity : scene->GetEntities()) {
			if (ACollider* collider = entity->getComponent<ACollider>()) {
				if (B2_ID_EQUALS(collider->shapeId, beginEvent.shapeIdA)) {
					colliderA = collider;
				}
				else if (B2_ID_EQUALS(collider->shapeId, beginEvent.shapeIdB)) {
					colliderB = collider;
				}
			}
		}

		if (colliderA && colliderB) {
			if (auto event = colliderA->parent->getComponent<ICollisionEvent>())
				event->BeginCollision(colliderA, colliderB);

			if (auto event = colliderB->parent->getComponent<ICollisionEvent>())
				event->BeginCollision(colliderB, colliderA);
		}
	}
}

b2WorldId Physics::getWorld()
{
	return world;
}