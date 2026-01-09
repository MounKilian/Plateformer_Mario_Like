#include "GameScene.h"
#include "Player.h"
#include "Ennemy.h"
#include "Transform.h"
#include "Renderer.h"
#include "RessourceManager.h"

void GameScene::Init()
{
    for (Entity* entity : m_entities) {
        delete entity;
	}

    m_entities.clear();

    RessourceManager* ressourceManager = RessourceManager::Instance();
    sf::Texture* textureShip = ressourceManager->loadtexture("Assets\\ships.png");

	Entity* player = new Entity();
    player->addComponent<Transform>()->setPosition({ 0, 0 });
	player->addComponent(new Renderer(textureShip));
	player->addComponent<Player>()->Init();

    Entity* ennemy = new Entity();
    ennemy->addComponent<Transform>()->setPosition({ 20, -150 });
    ennemy->addComponent(new Renderer(textureShip));
    ennemy->addComponent<Ennemy>()->Init();

    Entity* ennemy2 = new Entity();
    ennemy2->addComponent<Transform>()->setPosition({ 0,-120 });
    ennemy2->addComponent(new Renderer(textureShip));
    ennemy2->addComponent<Ennemy>()->Init();

    Entity* ennemy3 = new Entity();
    ennemy3->addComponent<Transform>()->setPosition({ 40,-90 });
    ennemy3->addComponent(new Renderer(textureShip));
    ennemy3->addComponent<Ennemy>()->Init();

	AddEntity(player);
	AddEntity(ennemy);
	AddEntity(ennemy2);
	AddEntity(ennemy3);
}

void GameScene::Update(float deltaTime)
{
	AScene::Update(deltaTime);
}