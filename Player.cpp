#include "Player.h"
#include "Ennemy.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Renderer.h"
#include "RessourceManager.h"

//Player::Player(sf::Texture& texture, float dammage, float life) : Ship(texture, dammage, life), texture("tiles.png")
//{
//	GetSprite().setTextureRect(sf::IntRect({ 0, 0 }, { 32, 32 }));
//	setOrigin({16,16});
//}

void Player::Init()
{
	parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 0 }, { 32, 32 }));
	parent->getComponent<Transform>()->setOrigin({ 16,16 });
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && transform->getPosition().y >= -180.f)
	{
		dir += { 0.f,-1.f };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && transform->getPosition().y <= 180.f)
	{
		dir += { 0.f,1.f };
	}

	if (dir.y == 0 && dir.x == 0) {
		return ;
	};
	dir = dir.normalized();

	transform->move(dir * speed);
}

void Player::Shoot()
{
	if (timerShoot.getElapsedTime() >= sf::seconds(0.5f)) {
		SceneManager* sceneManager = SceneManager::Instance();
		AScene* scene = sceneManager->GetCurrentScene();

		RessourceManager* ressourceManager = RessourceManager::Instance();
		sf::Texture* textureprojectile = ressourceManager->loadtexture("Assets\\tiles.png");

		Entity* projectile = new Entity();
		Transform* playerTransform = parent->getComponent<Transform>();
		projectile->addComponent<Transform>()->setPosition((playerTransform->getPosition()));
		projectile->addComponent(new Renderer(textureprojectile));
		projectile->addComponent<Projectile>()->Init(true);

		scene->AddEntity(projectile);

		timerShoot.restart();
	}
}

void Player::Update(float dt)
{
	Move(dt);
	Shoot();
}
