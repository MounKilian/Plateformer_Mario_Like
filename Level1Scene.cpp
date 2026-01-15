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

	for (float i = -200.f; i <= 440.f; i += 32.f) {
		Entity* cube = new Entity();
		cube->addComponent<Transform>()->setPosition({ i, 170.0f });
		cube->addComponent(new Renderer(textureTile));
		cube->addComponent<Cube>()->Init();

		/*Rigidbody* rigidbody = cube->addComponent<Rigidbody>();
		rigidbody->Init(app->getPhysicsWorld()->getWorld());

		BoxCollider* boxCollider = cube->addComponent<BoxCollider>();
		boxCollider->setSize({ 32.0f, 32.0f });
		boxCollider->setDensity(1.0f);
		boxCollider->setFriction(0.5f);
		boxCollider->Init(rigidbody);*/
		
		this->AddEntity(cube);
	}

	Entity* ground = new Entity();
	ground->addComponent<Transform>()->setPosition({ 120.f, 170.0f });

	Rigidbody* groundRb = ground->addComponent<Rigidbody>();
	groundRb->Init(app->getPhysicsWorld()->getWorld());
	groundRb->setBodyType(b2_staticBody);

	BoxCollider* groundCollider = ground->addComponent<BoxCollider>();
	groundCollider->setSize({ 672.f, 32.f });
	groundCollider->setFriction(0.8f);
	groundCollider->Init(groundRb);

	this->AddEntity(ground);

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