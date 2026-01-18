#include "Level1Scene.h"
#include "RessourceManager.h"
#include "Application.h"
#include "Background.h"
#include "Entity.h"
#include "Renderer.h"
#include "Transform.h"
#include "Tiles.h"
#include "Rigidbody.h"
#include "Player.h"
#include "Ennemy.h"
#include "BoxCollider.h"

void Level1Scene::Init()
{
	RessourceManager* ressourceManager = RessourceManager::Instance();
	sf::Texture* textureBackground = ressourceManager->loadtexture("Assets\\background.png");
	sf::Texture* textureTile = ressourceManager->loadtexture("Assets\\spritesheet_tiles.png");
	sf::Texture* texturePlayer = ressourceManager->loadtexture("Assets\\characters.png");
	sf::Texture* textureEnnemy = ressourceManager->loadtexture("Assets\\enemies.png");
	sf::SoundBuffer* soundPlayer = ressourceManager->loadsound("Assets\\sfx_jump.ogg");
	std::vector<std::vector<int>> map = ressourceManager->loadCSV("Assets\\level1.csv");

	CreateBackground(textureBackground, 3);

	CreateMap(textureTile, map);

	CreatePlayer(texturePlayer, soundPlayer, { 430.f, 112.f });

	// GreenBlob (1)
	// Bee (2)
	CreateEnnemy(textureEnnemy, { 854.f, 112.f }, 2);
	CreateEnnemy(textureEnnemy, { 1400.f, 123.f }, 1);
}

void Level1Scene::Update(float deltaTime)
{
	Application* app = Application::Instance();

	//std::cout << "Player Position: (" << m_player->getComponent<Transform>()->getPosition().x << ", " << m_player->getComponent<Transform>()->getPosition().y << ")" << std::endl;
	app->getView().setCenter({ m_player->getComponent<Transform>()->getPosition().x, 22.f});
	app->getWindow().setView(app->getView());

    app->getPhysicsWorld()->Update(deltaTime);
    AScene::Update(deltaTime);
}
