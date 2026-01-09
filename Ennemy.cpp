#include "Ennemy.h"
#include "Transform.h"
#include "Renderer.h"

//Ennemy::Ennemy(sf::Texture& texture, float dammage, float life) : Ship(texture, dammage, life)
//{
//	GetSprite().setTextureRect(sf::IntRect({ 32, 0 }, {32, 32 }));
//	setOrigin({ 16,16 });
//
//	timerMovement.restart();
//	float randomNum = rand() % 300 - 150;
//	float randomNum2 = rand() % 300 - 150;
//
//	sf::Vector2f position = { randomNum, randomNum2 };
//
//	dir = position - getPosition();
//
//	if (dir.y == 0 && dir.x == 0) {
//		return;
//	};
//	dir = dir.normalized();
//}

void Ennemy::Init()
{
	parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 32, 0 }, { 32, 32 }));
	Transform* transform = parent->getComponent<Transform>();
	transform->setOrigin({ 16,16 });
	transform->setRotation(sf::degrees(180));

	timerMovement.restart();
	float randomNum = rand() % 300 - 150;
	float randomNum2 = rand() % 300 - 150;

	sf::Vector2f position = { randomNum, randomNum2 };

	dir = position - transform->getPosition();

	if (dir.y == 0 && dir.x == 0) {
		return;
	};
	dir = dir.normalized();
}

void Ennemy::Move(float deltaTime)
{
	float speed = deltaTime * 100.0f;
	Transform* transform = parent->getComponent<Transform>();

	if (timerMovement.getElapsedTime().asSeconds() >= 1) {
		timerMovement.restart();
		float randomNum = rand() % 300 - 150;
		float randomNum2 = rand() % 300 - 150;

		sf::Vector2f position = { randomNum, randomNum2 };

		dir = position - transform->getPosition();

		if (dir.y == 0 && dir.x == 0) {
			return;
		};
		dir = dir.normalized();
	}

	transform->move(dir * speed);
}

void Ennemy::Shoot()
{

}

void Ennemy::Update(float dt)
{
    Move(dt);
}
