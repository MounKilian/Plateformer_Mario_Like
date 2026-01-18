#include <SFML/Graphics.hpp>
#include "Application.h"
#include "SceneManager.h"
#include "Level1Scene.h"
#include "Level2Scene.h"
#include "GameOverScene.h"
#include "RessourceManager.h"
#include "MenuScene.h"

Application* Application::m_instance = nullptr;

Application* Application::Instance()
{
	if (m_instance == nullptr) {
		m_instance = new Application();
	}
	return m_instance;
}

void Application::Init()
{
	physicsWorld = new Physics({ 0.0f, 15.0f });
	m_window.create(sf::VideoMode({ 1200, 900 }), "Plateformer");
	m_window.setFramerateLimit(60);

	srand(time(0));

	m_view.setSize({ 1200.f, 900.f });
	m_view.zoom(0.5);
	m_view.setCenter({ 0.f,0.f });
	m_window.setView(m_view);

	RessourceManager* ressources = RessourceManager::Instance();
	std::string musicPath = ressources->getMusicPath("Assets\\music.wav");
	sf::Music* music = new sf::Music(musicPath);
	music->setLooping(true);
	music->play();

	Level1Scene* level1Scene = new Level1Scene;
	Level2Scene* level2Scene = new Level2Scene;
	GameOverScene* gameOverScene = new GameOverScene;
	MenuScene* menuScene = new MenuScene;

	SceneManager* sceneManager = SceneManager::Instance();
	sceneManager->setLevel(1);

	sceneManager->AddScene("Level1", level1Scene);
	sceneManager->AddScene("Level2", level2Scene);
	sceneManager->AddScene("GameOver", gameOverScene);
	sceneManager->AddScene("Menu", menuScene);

	sceneManager->ChangeScene("Menu");
}

void Application::Loop()
{
	while (m_window.isOpen()) {
		float deltaTime = m_timer.restart().asSeconds();
		AScene* currentScene = SceneManager::Instance()->GetCurrentScene();

		while (const std::optional event = m_window.pollEvent())
		{
			// "close requested" event: we close the window
			if (event->is<sf::Event::Closed>())
				m_window.close();


		}

		currentScene->Update(deltaTime);

		m_window.clear(sf::Color::Black);

		m_window.draw(*currentScene);

		m_window.display();
	}
}

Physics* Application::getPhysicsWorld()
{
	return physicsWorld;
}

sf::RenderWindow& Application::getWindow()
{
	return m_window;
}

sf::View& Application::getView()
{
	return m_view;
}
