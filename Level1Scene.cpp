#include "Level1Scene.h"
#include "RessourceManager.h"
#include "Application.h"
#include "Background.h"
#include "Entity.h"
#include "Renderer.h"
#include "Transform.h"
#include "Player.h"

Application* app = Application::Instance();

void Level1Scene::Init()
{
	RessourceManager* ressourceManager = RessourceManager::Instance();
	sf::Texture* textureBackground = ressourceManager->loadtexture("Assets\\background.png");
	sf::Texture* textureShip = ressourceManager->loadtexture("Assets\\ships.png");

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

    Entity* player = new Entity();
    player->addComponent<Transform>()->setPosition({ 0, 0 });
    player->addComponent(new Renderer(textureShip));
    player->addComponent<Player>()->Init();

	this->AddEntity(backgroundCloud);
	this->AddEntity(backgroundWhite);
	this->AddEntity(backgroundGround);
	this->AddEntity(player);
}

void Level1Scene::Update(float deltaTime)
{
    app->getPhysicsWorld()->Update(deltaTime);
    AScene::Update(deltaTime);
}