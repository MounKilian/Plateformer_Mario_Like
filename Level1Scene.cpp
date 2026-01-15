#include "Level1Scene.h"
#include "RessourceManager.h"
#include "Application.h"
#include "Background.h"
#include "Entity.h"
#include "Renderer.h"
#include "Transform.h"
#include "Cube.h"
#include "Rigidbody.h"
#include "Player.h"
#include "BoxCollider.h"

Application* app = Application::Instance();

void Level1Scene::Init()
{
	RessourceManager* ressourceManager = RessourceManager::Instance();
	sf::Texture* textureBackground = ressourceManager->loadtexture("Assets\\background.png");
	sf::Texture* textureTile = ressourceManager->loadtexture("Assets\\spritesheet_tiles.png");
	sf::Texture* texturePlayer = ressourceManager->loadtexture("Assets\\characters.png");

    //Init du background
	for (float i = -100.f; i <= 4000.f; i += 800.f) {
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
		backgroundGround->addComponent<Background>()->Init(3);

		this->AddEntity(backgroundCloud);
		this->AddEntity(backgroundWhite);
		this->AddEntity(backgroundGround);
	}

	//Init des plateformes
	float actualPositionX = -200.f;

	CreateTilePlatform(actualPositionX, 20, 170.f, textureTile);
	actualPositionX += 32.f * 20;

	CreateTilePlatform(actualPositionX + 32.f * 3, 4, 94.f, textureTile);

	Entity* player = new Entity();
	player->addComponent<Transform>()->setPosition({ 0.f, -90.f });
	player->addComponent(new Renderer(texturePlayer));
	player->addComponent<Player>()->Init();

	Rigidbody* rigidbody = player->addComponent<Rigidbody>();
	rigidbody->Init(app->getPhysicsWorld()->getWorld());
	rigidbody->setBodyType(b2_dynamicBody);

	BoxCollider* boxCollider = player->addComponent<BoxCollider>();
	boxCollider->setSize({ 64.f, 64.f });
	boxCollider->setDensity(1.f);
	boxCollider->setFriction(0.0f);
	boxCollider->Init(rigidbody);

	m_player = player;
	
	this->AddEntity(player);
}

void Level1Scene::Update(float deltaTime)
{
	app->getView().setCenter({ m_player->getComponent<Transform>()->getPosition().x, 22.f});
	app->getWindow().setView(app->getView());

    app->getPhysicsWorld()->Update(deltaTime);
    AScene::Update(deltaTime);
}

void Level1Scene::CreateTilePlatform(float startX, int tilesNbrs, float y, sf::Texture* textureTile)
{
	const float tileSize = 32.f;
	Entity* firstTile = nullptr;
	Entity* lastTile = nullptr;

	for (float i = startX; i <= startX + tileSize * tilesNbrs; i += tileSize) {
		Entity* cube = new Entity();
		cube->addComponent<Transform>()->setPosition({ i, y });
		cube->addComponent(new Renderer(textureTile));
		cube->addComponent<Cube>()->Init();

		if (!firstTile) firstTile = cube;
		lastTile = cube;

		this->AddEntity(cube);
	}

	float firstX = firstTile->getComponent<Transform>()->getPosition().x;
	float lastX = lastTile->getComponent<Transform>()->getPosition().x;

	float leftEdge = firstX - tileSize / 2.f;
	float rightEdge = lastX + tileSize / 2.f;

	float groundWidth = rightEdge - leftEdge - tileSize; 
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

	this->AddEntity(ground);
}
