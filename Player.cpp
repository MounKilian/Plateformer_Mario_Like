#include "Player.h"
#include "Transform.h"
#include "Renderer.h"
#include "Entity.h"
#include <iostream>

void Player::Init()
{
	parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 256 }, { 128, 128 }));
	parent->getComponent<Transform>()->setOrigin({ 64,64 });
	parent->getComponent<Transform>()->setScale({0.5f, 0.5f });
}

void Player::Move(float deltaTime)
{
	float speed = deltaTime * 300.f;
	Transform* transform = parent->getComponent<Transform>();

	sf::Vector2f dir;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && transform->getPosition().x >= -180.f)
	{
		dir += { -1.f,0.f };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && transform->getPosition().x <= 180.f)
	{
		dir += { 1.f,0.f };
	}

	if (dir.y == 0 && dir.x == 0) {
		return ;
	};
	dir = dir.normalized();

	transform->move(dir * speed);
}

void Player::Update(float dt)
{
	Move(dt);
}

void Player::BeginCollision(ACollider* me, ACollider* other)
{
	std::cout << "Collision detected between Cube and another collider." << std::endl;
}

void Player::EndCollision(ACollider* me, ACollider* other)
{

}