#include "GameScene.h"
#include "Application.h"
#include "Entity.h"
#include "Transform.h"
#include "Renderer.h"
#include "Player.h"
#include "Ennemy.h"
#include "BoxCollider.h"
#include "SceneManager.h"
#include "Tiles.h"
#include "Sound.h"
#include "Background.h"
#include "UICoins.h"

void GameScene::CreatePlayer(sf::Texture* texturePlayer, sf::SoundBuffer* soundPlayer, sf::Vector2f spawn)
{
	Application* app = Application::Instance();
	SceneManager* scene = SceneManager::Instance();

	Entity* player = new Entity();
	player->addComponent<Transform>()->setPosition(spawn);
	player->addComponent(new Renderer(texturePlayer));
	player->addComponent<Player>()->Init();
	player->addComponent(new Sound(soundPlayer));

	Rigidbody* rigidbody = player->addComponent<Rigidbody>();
	rigidbody->Init(app->getPhysicsWorld()->getWorld());
	rigidbody->setBodyType(b2_dynamicBody);

	BoxCollider* boxCollider = player->addComponent<BoxCollider>();
	boxCollider->setSize({ 32.f, 48.f });
	boxCollider->setDensity(1.f);
	boxCollider->setFriction(0.8f);
	boxCollider->Init(rigidbody);

	m_player = player;
	scene->GetCurrentScene()->AddEntity(m_player);
}

void GameScene::CreateEnnemy(sf::Texture* textureEnnemy, sf::SoundBuffer* soundEnnemy, sf::Vector2f spawn, int type)
{
	Application* app = Application::Instance();
	SceneManager* scene = SceneManager::Instance();

	Entity* ennemy = new Entity();
	ennemy->addComponent<Transform>()->setPosition(spawn);
	ennemy->addComponent(new Renderer(textureEnnemy));
	ennemy->addComponent<Ennemy>()->Init(type);
	ennemy->addComponent(new Sound(soundEnnemy));

	Rigidbody* ennemyRigidbody = ennemy->addComponent<Rigidbody>();
	ennemyRigidbody->Init(app->getPhysicsWorld()->getWorld());
	ennemyRigidbody->setBodyType(b2_dynamicBody);

	BoxCollider* ennemyBoxCollider = ennemy->addComponent<BoxCollider>();
	ennemyBoxCollider->setSize({ 32.f, 32.f });
	ennemyBoxCollider->setDensity(1.f);
	ennemyBoxCollider->setFriction(1.f);
	ennemyBoxCollider->Init(ennemyRigidbody);

	scene->GetCurrentScene()->AddEntity(ennemy);
}


void GameScene::CreateTilePlatform(sf::SoundBuffer* soundCoin, int type, float startX, int tilesNbrs, float y, sf::Texture* textureTile)
{
	Application* app = Application::Instance();
	SceneManager* scene = SceneManager::Instance();

	const float tileSize = 32.f;
	Entity* firstTile = nullptr;
	Entity* lastTile = nullptr;
	bool isPhysics = false;

	if (type == 1 || type == 4 || type == 9 || type == 12 || type == 13 || type == 14 || type == 15 || type == 22 || type == 25 || type == 28 || type == 32 ) {
		isPhysics = true;
	}

	if (tilesNbrs == 1) {
		Entity* cube = new Entity();
		cube->addComponent<Transform>()->setPosition({ startX, y });
		cube->addComponent(new Renderer(textureTile));
		cube->addComponent<Tiles>()->Init(type);
		if (type == 13 || type == 32) {
			cube->addComponent(new Sound(soundCoin));
		}
		if (isPhysics) {
			float x = cube->getComponent<Transform>()->getPosition().x;
			cube->addComponent<Transform>()->setPosition({ x, y });

			Rigidbody* groundRb = cube->addComponent<Rigidbody>();
			groundRb->Init(app->getPhysicsWorld()->getWorld());
			groundRb->setBodyType(b2_staticBody);

			BoxCollider* groundCollider = cube->addComponent<BoxCollider>();
			if (type == 14) {
				groundCollider->setSize({ tileSize, tileSize / 2.f - 8.f });
			}
			else {
				groundCollider->setSize({ tileSize, tileSize });
			}

			groundCollider->setFriction(0.8f);
			groundCollider->Init(groundRb);
		}
		scene->GetCurrentScene()->AddEntity(cube);
	}
	else
	{
		for (float i = 0; i < tilesNbrs; ++i) {
			float x = startX + i * tileSize;

			Entity* cube = new Entity();
			cube->addComponent<Transform>()->setPosition({ x, y });
			cube->addComponent(new Renderer(textureTile));
			if (type == 13) {
				cube->addComponent(new Sound(soundCoin));
			}

			if (isPhysics) {
				if (i == 0)
				{
					cube->addComponent<Tiles>()->Init(type);
					firstTile = cube;
				}
				else if (i == tilesNbrs - 1)
				{
					cube->addComponent<Tiles>()->Init(type + 2);
					lastTile = cube;
				}
				else
				{
					cube->addComponent<Tiles>()->Init(type + 1);
				}
			}
			else {
				cube->addComponent<Tiles>()->Init(type);
			}
			scene->GetCurrentScene()->AddEntity(cube);
		}
		if (isPhysics) {
			float firstX = firstTile->getComponent<Transform>()->getPosition().x;
			float lastX = lastTile->getComponent<Transform>()->getPosition().x;

			float leftEdge = firstX - tileSize / 2.f;
			float rightEdge = lastX + tileSize / 2.f;

			float groundWidth = rightEdge - leftEdge;
			float groundCenter = (leftEdge + rightEdge) / 2.f;

			Entity* ground = new Entity();
			ground->addComponent<Transform>()->setPosition({ groundCenter, y });

			Rigidbody* groundRb = ground->addComponent<Rigidbody>();
			groundRb->Init(app->getPhysicsWorld()->getWorld());
			groundRb->setBodyType(b2_staticBody);

			BoxCollider* groundCollider = ground->addComponent<BoxCollider>();
			groundCollider->setSize({ groundWidth, tileSize });
			groundCollider->setFriction(0.8f);
			groundCollider->Init(groundRb);

			scene->GetCurrentScene()->AddEntity(ground);
		}
	}
}

void GameScene::CreateBackground(sf::Texture* textureBackground, int type)
{
	SceneManager* scene = SceneManager::Instance();

	for (float i = -350.f; i <= 4000.f; i += 800.f) {
		Entity* backgroundCloud = new Entity();
		backgroundCloud->addComponent<Transform>()->setPosition({ i, -150.f });
		backgroundCloud->addComponent(new Renderer(textureBackground));
		backgroundCloud->addComponent<Background>()->Init(1);

		Entity* backgroundWhite = new Entity();
		backgroundWhite->addComponent<Transform>()->setPosition({ i, 0.f });
		backgroundWhite->addComponent(new Renderer(textureBackground));
		backgroundWhite->addComponent<Background>()->Init(2);

		Entity* backgroundGround = new Entity();
		backgroundGround->addComponent<Transform>()->setPosition({ i, 150.f });
		backgroundGround->addComponent(new Renderer(textureBackground));
		backgroundGround->addComponent<Background>()->Init(type);

		scene->GetCurrentScene()->AddEntity(backgroundCloud);
		scene->GetCurrentScene()->AddEntity(backgroundWhite);
		scene->GetCurrentScene()->AddEntity(backgroundGround);
	}
}

void GameScene::CreateMap(sf::Texture* textureTile, sf::SoundBuffer* soundCoin, std::vector<std::vector<int>> map)
{
	const float tileSize = 32.f;
	float actualPositionX = -280.f;
	float actualPositionY = -200.f;

	for (int y = 0; y < map.size(); ++y) {

		actualPositionX = -280.f;

		for (int x = 0; x < map[y].size(); ++x) {
			int value = map[y][x];

			if (value == 0) {
				actualPositionX += tileSize;
				continue;
			};

			if (x + 1 < map[y].size() && map[y][x + 1] == value && value != 12 && value != 13 && value != 14 && value != 32) {
				int length = 2;
				while (x + length < map[y].size() && map[y][x + length] == value) {
					length++;
				}
				CreateTilePlatform(soundCoin, value, actualPositionX, length, actualPositionY, textureTile);
				actualPositionX += tileSize * length;
				x += length - 1;
				continue;
			}
			else {
				CreateTilePlatform(soundCoin, value, actualPositionX, 1, actualPositionY, textureTile);
				actualPositionX += tileSize;
				continue;
			}
			actualPositionX += tileSize;
		}
		actualPositionY += tileSize;
	}
}

void GameScene::CreateUI(sf::Texture* textureTile)
{
	Entity* coinUI = new Entity();
	coinUI->addComponent<Transform>()->setPosition({ 170.f, -160.f });
	coinUI->addComponent(new Renderer(textureTile));
	coinUI->addComponent<UICoins>()->Init(1, m_player);
	this->AddEntity(coinUI);

	Entity* coinUI2 = new Entity();
	coinUI2->addComponent<Transform>()->setPosition({ 200.f, -160.f });
	coinUI2->addComponent(new Renderer(textureTile));
	coinUI2->addComponent<UICoins>()->Init(2, m_player);
	this->AddEntity(coinUI2);

	Entity* coinUI3 = new Entity();
	coinUI3->addComponent<Transform>()->setPosition({ 220.f, -160.f });
	coinUI3->addComponent(new Renderer(textureTile));
	coinUI3->addComponent<UICoins>()->Init(3, m_player);
	this->AddEntity(coinUI3);

	Entity* coinUI4 = new Entity();
	coinUI4->addComponent<Transform>()->setPosition({ 240.f, -160.f });
	coinUI4->addComponent(new Renderer(textureTile));
	coinUI4->addComponent<UICoins>()->Init(4, m_player);
	this->AddEntity(coinUI4);
}
