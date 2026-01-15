#pragma once

#include "AScene.h"

class Level1Scene : public AScene
{
	Entity* m_player;

	public:
		void Init();
		void Update(float deltaTime);
};
	
