#pragma once

#include "AScene.h"

class GameOverScene : public AScene
{
	Entity* gameOverText;

	public : 
		void Init();
		void Update(float deltaTime);
};

