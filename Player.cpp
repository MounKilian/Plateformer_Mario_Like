#include "Player.h"
#include "Transform.h"
#include "Renderer.h"
#include "Entity.h"
#include "Rigidbody.h"
#include "Physics.h"
#include "AComponent.h"
#include "ACollider.h"
#include <iostream>

void Player::Init()
{
	parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 258 }, { 124, 152 }));
	parent->getComponent<Transform>()->setOrigin({ 62, 76 });
	parent->getComponent<Transform>()->setScale({0.5f, 0.5f});
}

void Player::Move(float deltaTime)
{
	float speed = 120.f;
	Rigidbody* rb = parent->getComponent<Rigidbody>();

	sf::Vector2f dir;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		dir.x -= 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		dir.x += 1.f;

	if (dir.x == 0)
		return ;

	b2Vec2 velocity = rb->getLinearVelocity();
	velocity.x = dir.x * speed / Physics::worldScale;
	rb->setLinearVelocity(velocity);
}

void Player::Jump()
{
	float jumpForce = 7.5f;

	Rigidbody* rb = parent->getComponent<Rigidbody>();

	b2Vec2 velocity = rb->getLinearVelocity();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && std::abs(velocity.y) < 0.01f)
	{
		velocity.y = -jumpForce;
		rb->setLinearVelocity(velocity);
	}
}

void Player::Update(float dt)
{
	Move(dt);
	Jump();
}

void Player::BeginCollision(Entity* me, Entity* other)
{
	
}

void Player::EndCollision(Entity* me, Entity* other)
{
	
}