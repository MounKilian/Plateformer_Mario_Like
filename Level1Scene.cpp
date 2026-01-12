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
	Entity* backgroundCloud = new Entity();
    backgroundCloud->addComponent<Transform>()->setPosition({ 0.f, -150.f });
    backgroundCloud->addComponent(new Renderer(textureBackground));
    backgroundCloud->addComponent<Background>()->Init(1);

    Entity* backgroundWhite = new Entity();
    backgroundWhite->addComponent<Transform>()->setPosition({ 0.f, 0.0f });
    backgroundWhite->addComponent(new Renderer(textureBackground));
    backgroundWhite->addComponent<Background>()->Init(2);

    Entity* backgroundGround = new Entity();
    backgroundGround->addComponent<Transform>()->setPosition({ 0.f, 150.0f });
    backgroundGround->addComponent(new Renderer(textureBackground));
    backgroundGround->addComponent<Background>()->Init(3);

	this->AddEntity(backgroundCloud);
	this->AddEntity(backgroundWhite);
	this->AddEntity(backgroundGround);

	for (float i = -210.f; i <= 400.f; i += 32.f) {
		Entity* cube = new Entity();
		cube->addComponent<Transform>()->setPosition({ i, 170.0f });
		cube->addComponent(new Renderer(textureTile));
		cube->addComponent<Cube>()->Init();

		Rigidbody* rigidbody = cube->addComponent<Rigidbody>();
		rigidbody->Init(app->getPhysicsWorld()->getWorld());

		BoxCollider* boxCollider = cube->addComponent<BoxCollider>();
		boxCollider->setSize({ 32.0f, 32.0f });
		boxCollider->setDensity(1.0f);
		boxCollider->setFriction(0.5f);
		boxCollider->Init(rigidbody);
		
		this->AddEntity(cube);
	}

	Entity* player = new Entity();
	player->addComponent<Transform>()->setPosition({ 0.f, -90.f });
	player->addComponent(new Renderer(texturePlayer));
	player->addComponent<Player>()->Init();

	Rigidbody* rigidbody = player->addComponent<Rigidbody>();
	rigidbody->Init(app->getPhysicsWorld()->getWorld());
	rigidbody->setBodyType(b2_dynamicBody);

	BoxCollider* boxCollider = player->addComponent<BoxCollider>();
	boxCollider->setSize({ 64.0f, 64.0f });
	boxCollider->setDensity(1.0f);
	boxCollider->setFriction(0.5f);
	boxCollider->Init(rigidbody);

	this->AddEntity(player);

	Entity* player2 = new Entity();
	player2->addComponent<Transform>()->setPosition({ 20.f, -100.f });
	player2->addComponent(new Renderer(textureTile));
	player2->addComponent<Cube>()->Init();

	Rigidbody* rigidbody2 = player2->addComponent<Rigidbody>();
	rigidbody2->Init(app->getPhysicsWorld()->getWorld());

	BoxCollider* boxCollider2 = player2->addComponent<BoxCollider>();
	boxCollider2->setSize({ 32.f, 32.f });
	boxCollider2->setDensity(1.0f);
	boxCollider2->setFriction(0.5f);
	boxCollider2->Init(rigidbody2);

	this->AddEntity(player2);
}

void Level1Scene::Update(float deltaTime)
{
    app->getPhysicsWorld()->Update(deltaTime);
    AScene::Update(deltaTime);
}