#pragma once

#include <SFML/Graphics.hpp>
#include "Physics.h"

class Application
{
	static Application* m_instance;
	sf::RenderWindow m_window;
	sf::View m_view;
	sf::Clock m_timer;
	Physics* physicsWorld;

	public:
		static Application* Instance();
		void Init();
		void Loop();
		Physics* getPhysicsWorld();
		sf::RenderWindow& getWindow();
		sf::View& getView();
};

