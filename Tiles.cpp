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
		case 1: // First Grass Tile
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 780, 585 }, { 64, 64 }));
			break;
		case 2: // Mid Grass Tile
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 715, 585 }, { 64, 64 }));
			break;
		case 3: // End Grass Tile
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 845, 585 }, { 64, 64 }));
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