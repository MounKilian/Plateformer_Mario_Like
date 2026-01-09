#include "TestScene.h"
#include "AScene.h"
#include "Physics.h"
#include "Entity.h"
#include "Transform.h"
#include "Renderer.h"
#include "RessourceManager.h"
#include "Rigidbody.h"
#include "BoxCollider.h"
#include "Application.h"
#include "Cube.h"

//Application* app = Application::Instance();

void TestScene::Init()
{	
	RessourceManager* ressourceManager = RessourceManager::Instance();
	sf::Texture* textureShip = ressourceManager->loadtexture("Assets\\ships.png");

	Entity* cube = new Entity();

	Transform* transform = cube->addComponent<Transform>();
	transform->setPosition({ 0.0f, -115.0f });
	transform->setScale({ 1.0f, 1.0f });

	cube->addComponent(new Renderer(textureShip));

	cube->addComponent<Cube>()->Init();

	Rigidbody* rigidbody = cube->addComponent<Rigidbody>();
	//rigidbody->Init(app->getPhysicsWorld()->getWorld());
	rigidbody->setBodyType(b2_dynamicBody);

	BoxCollider* boxCollider = cube->addComponent<BoxCollider>();
	boxCollider->setSize({ 32.0f, 32.0f });
	boxCollider->setDensity(1.0f);
	boxCollider->setFriction(0.5f);
	boxCollider->Init(rigidbody);

	Entity* cube2 = new Entity();

	Transform* transform2 = cube2->addComponent<Transform>();
	transform2->setPosition({ 0.0f, 0.0f });
	transform2->setScale({ 1.0f, 1.0f });

	cube2->addComponent(new Renderer(textureShip));

	cube2->addComponent<Cube>()->Init();

	Rigidbody* rigidbody2 = cube2->addComponent<Rigidbody>();
	//rigidbody2->Init(app->getPhysicsWorld()->getWorld());

	BoxCollider* boxCollider2 = cube2->addComponent<BoxCollider>();
	boxCollider2->setSize({ 32.0f, 32.0f });
	boxCollider2->setFriction(0.5f);
	boxCollider2->Init(rigidbody2);

	this->AddEntity(cube);
	this->AddEntity(cube2);
}

void TestScene::Update(float deltaTime)
{
	//app->getPhysicsWorld()->Update(deltaTime);
	AScene::Update(deltaTime);
}