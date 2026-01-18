#include "GameOverScene.h"
#include "Application.h"
#include "AScene.h"
#include "RessourceManager.h"
#include "Entity.h"
#include "Transform.h"
#include "Renderer.h"
#include "TextRenderer.h"
#include "Sound.h"
#include "Background.h"
#include "SceneManager.h"
#include <SFML/Graphics.hpp>

void GameOverScene::Init()
{
    Application* app = Application::Instance();
	app->getView().setCenter({ 0.f, 0.f });
	app->getWindow().setView(app->getView());
    auto& view = app->getView();
	RessourceManager* ressourceManager = RessourceManager::Instance();
	sf::Texture* textureBackground = ressourceManager->loadtexture("Assets\\background.png");
    sf::Font* font = ressourceManager->loadFont("Assets\\JungleAdventurer.ttf");
    sf::SoundBuffer* soundSelect = ressourceManager->loadsound("Assets\\sfx_select.ogg");

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


	gameOverText = new Entity();
    gameOverText->addComponent<Transform>()->setPosition({ -70.f , -70.f});
	gameOverText->addComponent(new TextRenderer(font));
    gameOverText->addComponent(new Sound(soundSelect));
    gameOverText->getComponent<TextRenderer>()->setString("GAME OVER");
    gameOverText->getComponent<TextRenderer>()->setFillColor(sf::Color::Red);
    gameOverText->getComponent<TextRenderer>()->setCharacterSize(64);
	this->AddEntity(gameOverText);

    Entity* replayText = new Entity();
    replayText->addComponent<Transform>()->setPosition({ 0.f, 40.f });
    replayText->addComponent(new TextRenderer(font));
    replayText->getComponent<TextRenderer>()->setString("Press R to Replay");
    replayText->getComponent<TextRenderer>()->setFillColor(sf::Color::Black);
    replayText->getComponent<TextRenderer>()->setCharacterSize(32);
    this->AddEntity(replayText);

    Entity* quitText = new Entity();
    quitText->addComponent<Transform>()->setPosition({ 0.f, 80.f });
    quitText->addComponent(new TextRenderer(font));
    quitText->getComponent<TextRenderer>()->setString("Press Q to Quit");
    quitText->getComponent<TextRenderer>()->setFillColor(sf::Color::Black);
    quitText->getComponent<TextRenderer>()->setCharacterSize(32);
    this->AddEntity(quitText);
}

void GameOverScene::Update(float deltaTime)
{
	AScene::Update(deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
    {
        SceneManager* sceneManager = SceneManager::Instance();
        gameOverText->getComponent<Sound>()->Play();

        sceneManager->ClearScene();

        if (sceneManager->getLevel() == 1) {

            sceneManager->ChangeScene("Level1");
        }
        else {
            sceneManager->ChangeScene("Level2");
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
    {
        Application::Instance()->getWindow().close();
    }
}