#include "MenuScene.h"
#include "Application.h"
#include "AScene.h"
#include "RessourceManager.h"
#include "Entity.h"
#include "Transform.h"
#include "Renderer.h"
#include "TextRenderer.h"
#include "Background.h"
#include "SceneManager.h"
#include <SFML/Graphics.hpp>

void MenuScene::Init()
{
    Application* app = Application::Instance();
    app->getView().setCenter({ 0.f, 0.f });
    app->getWindow().setView(app->getView());
    auto& view = app->getView();
    RessourceManager* ressourceManager = RessourceManager::Instance();
    sf::Texture* textureBackground = ressourceManager->loadtexture("Assets\\background.png");
    sf::Font* font = ressourceManager->loadFont("Assets\\JungleAdventurer.ttf");

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


    Entity* Menu = new Entity();
    Menu->addComponent<Transform>()->setPosition({ -70.f , -70.f });
    Menu->addComponent(new TextRenderer(font));
    Menu->getComponent<TextRenderer>()->setString("PLATEFORMER MENU");
    Menu->getComponent<TextRenderer>()->setFillColor(sf::Color::Red);
    Menu->getComponent<TextRenderer>()->setCharacterSize(52);
    this->AddEntity(Menu);

    Entity* playText = new Entity();
    playText->addComponent<Transform>()->setPosition({ 0.f, 40.f });
    playText->addComponent(new TextRenderer(font));
    playText->getComponent<TextRenderer>()->setString("Press P to Play");
    playText->getComponent<TextRenderer>()->setFillColor(sf::Color::Black);
    playText->getComponent<TextRenderer>()->setCharacterSize(32);
    this->AddEntity(playText);

    Entity* quitText = new Entity();
    quitText->addComponent<Transform>()->setPosition({ 0.f, 80.f });
    quitText->addComponent(new TextRenderer(font));
    quitText->getComponent<TextRenderer>()->setString("Press Q to Quit");
    quitText->getComponent<TextRenderer>()->setFillColor(sf::Color::Black);
    quitText->getComponent<TextRenderer>()->setCharacterSize(32);
    this->AddEntity(quitText);
}

void MenuScene::Update(float deltaTime)
{
    AScene::Update(deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
    {
        SceneManager* sceneManager = SceneManager::Instance();
        sceneManager->ClearScene();
        sceneManager->ChangeScene("Level1");
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
    {
        Application::Instance()->getWindow().close();
    }
}