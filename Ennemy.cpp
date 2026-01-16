#include "Ennemy.h"
#include "Transform.h"
#include "Renderer.h"
#include "Entity.h"
#include "Rigidbody.h"
#include "Physics.h"
#include "Tiles.h"
#include "ACollider.h"
#include "SceneManager.h"
#include "AScene.h"
#include "ICollisionEvent.h"
#include "Player.h"
#include <iostream>

void Ennemy::Init(int type)
{
	this->type = type;
	switch (type)
	{
		case 1: // Green Blob
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 389 }, { 64, 64 }));
			break;
		case 2: // Bee
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 195, 0 }, { 64, 64 }));
			break;
	}
	parent->getComponent<Transform>()->setOrigin({ 32, 32 });
	parent->getComponent<Transform>()->setScale({ 0.5f, 0.5f });
	dir.x = -1.f;
}

void Ennemy::Move(float deltaTime)
{
	float speed = 50.f;
	Rigidbody* rb = parent->getComponent<Rigidbody>();
		
	b2Vec2 velocity = rb->getLinearVelocity();
	velocity.x = dir.x * speed / Physics::worldScale;
	rb->setLinearVelocity(velocity);
}

void Ennemy::Update(float dt)
{
	Move(dt);
}

void Ennemy::BeginCollision(ACollider* me, ACollider* other)
{	
	if (other->getParent()->getComponent<Player>())
    {
        SceneManager* sceneManager = SceneManager::Instance();
        AScene* scene = sceneManager->GetCurrentScene();
        scene->RemoveEntity(other->getParent());
	}
	else {
		dir.x = -dir.x;
		parent->getComponent<Transform>()->setScale({ -parent->getComponent<Transform>()->getScale().x, parent->getComponent<Transform>()->getScale().y});
	}
}

void Ennemy::EndCollision(ACollider* me, ACollider* other)
{

}
