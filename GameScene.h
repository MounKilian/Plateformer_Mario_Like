#pragma once

#include "AScene.h"

class GameScene : public AScene
{
	protected :
		Entity* m_player;

		void CreatePlayer(sf::Texture* texturePlayer, sf::SoundBuffer* soundPlayer, sf::Vector2f spawn);
		void CreateEnnemy(sf::Texture* textureEnnemy, sf::SoundBuffer* soundEnnemy, sf::Vector2f spawn, int type);
		void CreateTilePlatform(int type, float startX, int tilesNbrs, float y, sf::Texture* textureTile);
		void CreateBackground(sf::Texture* textureBackground, int type);
		void CreateMap(sf::Texture* textureTile, std::vector<std::vector<int>> map);
};

