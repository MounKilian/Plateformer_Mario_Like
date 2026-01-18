#include "Player.h"
#include "Transform.h"
#include "Renderer.h"
#include "Entity.h"
#include "Rigidbody.h"
#include "Physics.h"
#include "AComponent.h"
#include "ACollider.h"
#include "SceneManager.h"
#include "AScene.h"
#include "BoxCollider.h"
#include "Application.h"
#include "Sound.h"
#include <iostream>

void Player::Init()
{
	parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 258 }, { 124, 152 }));
	parent->getComponent<Transform>()->setOrigin({ 62, 76 });
	parent->getComponent<Transform>()->setScale({0.5f, 0.5f});
	anim = true;
	animSpeed = 0.10f;
	animTimer = 0.f;
}

void Player::Move(float deltaTime)
{
	float speed = 110.f;
	Rigidbody* rb = parent->getComponent<Rigidbody>();

	sf::Vector2f dir;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		dir.x -= 1.f;
		parent->getComponent<Transform>()->setScale({ -0.5f, 0.5f });
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		dir.x += 1.f;
		parent->getComponent<Transform>()->setScale({ 0.5f, 0.5f });
	}

	b2Vec2 velocity = rb->getLinearVelocity();

	Animation(deltaTime, velocity, dir);

	if (dir.x == 0)
		return;

	velocity.x = dir.x * speed / Physics::worldScale;
	rb->setLinearVelocity(velocity);
}

void Player::Jump()
{
	float jumpForce = 8.f;

	Rigidbody* rb = parent->getComponent<Rigidbody>();

	b2Vec2 velocity = rb->getLinearVelocity();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && std::abs(velocity.y) < 0.01f)
	{
		parent->getComponent<Sound>()->Play();
		velocity.y = -jumpForce;
		rb->setLinearVelocity(velocity);
	}
}

void Player::Death()
{
	SceneManager* sceneManager = SceneManager::Instance();
	sceneManager->ClearScene(); 
	sceneManager->ChangeScene("GameOver");
}

void Player::Animation(float deltaTime, b2Vec2 velocity, sf::Vector2f dir)
{
	if (dir.x != 0 && std::abs(velocity.y) < 0.01f) {
		animTimer += deltaTime;
		if (animTimer >= animSpeed) {
			if (anim) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 258, 258 }, { 124, 152 }));
				anim = false;
			}
			else {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 258 }, { 124, 152 }));
				anim = true;
			}
			animTimer = 0.f;
		}
	}
	else if (std::abs(velocity.y) > 0.01f) {
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 387, 258 }, { 124, 152 }));
	}
	else {
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 258 }, { 124, 152 }));
		anim = true;
	}
}

void Player::DeadZone()
{
	if (parent->getComponent<Transform>()->getPosition().y > 300.f)
	{
		Death();
	}
}

void Player::Update(float dt)
{
	Move(dt);
	Jump();
	DeadZone();
}
 
void Player::BeginCollision(Entity* me, Entity* other)
{
	
}

void Player::EndCollision(Entity* me, Entity* other)
{
	
}