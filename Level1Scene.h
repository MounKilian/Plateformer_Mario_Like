#pragma once

#include "AScene.h"

class Level1Scene : public AScene
{
	Entity* m_player;

	public:
		void Init();
		void Update(float deltaTime);
		void CreateTilePlatform(int type, float startX, int tilesNbrs, float y, sf::Texture* textureTile);
};
	
