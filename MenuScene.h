#pragma once

#include "AScene.h"

class MenuScene : public AScene
{
	Entity* menu;

	public :
		void Init();
		void Update(float deltaTime);
};

