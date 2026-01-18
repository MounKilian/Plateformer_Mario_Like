#pragma once

#include "AScene.h"

class MenuScene : public AScene
{
	sf::SoundBuffer* soundSelect;
	Entity* menu;

	public :
		void Init();
		void Update(float deltaTime);
};

