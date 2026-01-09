#include "Level1Scene.h"
#include "RessourceManager.h"
#include "Application.h"
#include "Background.h"
#include "Entity.h"
#include "Renderer.h"
#include "Transform.h"
#include "Cube.h"
#include "Rigidbody.h"
#include "BoxCollider.h"

Application* app = Application::Instance();

void Level1Scene::Init()
{
	RessourceManager* ressourceManager = RessourceManager::Instance();
	sf::Texture* textureBackground = ressourceManager->loadtexture("Assets\\background.png");
	sf::Texture* textureTile = ressourceManager->loadtexture("Assets\\spritesheet_tiles.png");

    //Init du background
	Entity* backgroundCloud = new Entity();
    backgroundCloud->addComponent<Transform>()->setPosition({ 0.0f, -150.f });
    backgroundCloud->addComponent(new Renderer(textureBackground));
    backgroundCloud->addComponent<Background>()->Init(1);

    Entity* backgroundWhite = new Entity();
    backgroundWhite->addComponent<Transform>()->setPosition({ 0.0f, 0.0f });
    backgroundWhite->addComponent(new Renderer(textureBackground));
    backgroundWhite->addComponent<Background>()->Init(2);

    Entity* backgroundGround = new Entity();
    backgroundGround->addComponent<Transform>()->setPosition({ 0.0f, 150.0f });
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
}

void Level1Scene::Update(float deltaTime)
{
    app->getPhysicsWorld()->Update(deltaTime);
    AScene::Update(deltaTime);
}