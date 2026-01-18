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
#include "BoxCollider.h"
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
		case 3: // Red Blob
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 324 }, { 64, 64 }));
			break;
		case 4: // Fly
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 130, 130 }, { 64, 64 }));
			break;
	}
	parent->getComponent<Transform>()->setOrigin({ 32, 32 });
	parent->getComponent<Transform>()->setScale({ 0.5f, 0.5f });
	dir.x = -1.f;
	anim = true;
	animSpeed = 0.10f;
	animTimer = 0.f;
}

void Ennemy::Move(float deltaTime)
{
	float speed = 50.f;
	Rigidbody* rb = parent->getComponent<Rigidbody>();
		
	b2Vec2 velocity = rb->getLinearVelocity();

	Animation(deltaTime);

	velocity.x = dir.x * speed / Physics::worldScale;
	rb->setLinearVelocity(velocity);
}

void Ennemy::Animation(float deltaTime)
{
	animTimer += deltaTime;
	if (animTimer >= animSpeed) {
		if (anim) {
			if (type == 1) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 389 }, { 64, 64 }));
			}
			if (type == 2) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 195, 0 }, { 64, 64 }));
			}
			if (type == 3) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 324 }, { 64, 64 }));
			}
			if (type == 4) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 130, 130 }, { 64, 64 }));
			}
			anim = false;
		}
		else {
			if (type == 1) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 65, 389 }, { 64, 64 }));
			}
			if (type == 2) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 260, 0 }, { 64, 64 }));
			}
			if (type == 3) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 65, 324 }, { 64, 64 }));
			}
			if (type == 4) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 195, 130 }, { 64, 64 }));
			}
			anim = true;
		}
		animTimer = 0.f;
	}
}

void Ennemy::Update(float dt)
{
	Move(dt);
}

void Ennemy::BeginCollision(Entity* me, Entity* other)
{	
	if (other->getComponent<Player>())
    {
		if (type == 1 || type == 3) {
			other->getComponent<Player>()->Death();
		}
		else {
			if (other->getComponent<Transform>()->getPosition().y + 35.f <= parent->getComponent<Transform>()->getPosition().y) {
				SceneManager* sceneManager = SceneManager::Instance();
				AScene* scene = sceneManager->GetCurrentScene();
				scene->RemoveEntity(parent);
			}
			else {
				other->getComponent<Player>()->Death();
			}
		}
	}
	else {
		dir.x = -dir.x;
		parent->getComponent<Transform>()->setScale({ -parent->getComponent<Transform>()->getScale().x, parent->getComponent<Transform>()->getScale().y});
	}
}

void Ennemy::EndCollision(Entity* me, Entity* other)
{

}
