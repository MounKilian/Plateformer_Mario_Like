#include "Tiles.h"
#include "Transform.h"
#include "Renderer.h"
#include "Entity.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Tiles::Init(int type)
{
	switch (type)
	{
		case 1: // First Grass Tile Ground
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 780, 585 }, { 64, 64 }));
			break;
		case 2: // Mid Grass Tile Ground
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 715, 585 }, { 64, 64 }));
			break;
		case 3: // End Grass Tile Ground
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 845, 585 }, { 64, 64 }));
			break;
		case 4: // First Grass Tile Deco
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 585, 585 }, { 64, 64 }));
			break;
		case 5: // Mid Grass Tile Deco
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 520, 585 }, { 64, 64 }));
			break;
		case 6: // End Grass Tile Deco
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 650, 585 }, { 64, 64 }));
			break;
		case 7: // Ocean Tile
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 260, 1105 }, { 64, 64 }));
			break;
		case 8: // Ocean Tile Mid
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 195, 1105 }, { 64, 64 }));
			break;
	}

	parent->getComponent<Transform>()->setOrigin({ 32, 32 });
	parent->getComponent<Transform>()->setScale({ 0.5f, 0.5f });
}

void Tiles::BeginCollision(ACollider* me, ACollider* other)
{
	std::cout << "Collision detected between Cube and another collider." << std::endl;
}

void Tiles::EndCollision(ACollider* me, ACollider* other)
{

}