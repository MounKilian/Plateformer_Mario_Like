#include "Tiles.h"
#include "Transform.h"
#include "Renderer.h"
#include "Entity.h"
#include "SceneManager.h"
#include "AScene.h"
#include "ACollider.h"
#include "ICollisionEvent.h"
#include "Rigidbody.h"
#include "Player.h"
#include "Sound.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Tiles::Init(int type)
{
	this->type = type;
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
		case 9: // First Grass Tile Platform
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 1040, 585 }, { 64, 64 }));
			break;
		case 10: // Mid Grass Tile Platform
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 1105, 585 }, { 64, 64 }));
			break;
		case 11: // End Grass Tile Platform
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 650 }, { 64, 64 }));
			break;
		case 12: // Block Brick
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 585, 65 }, { 64, 64 }));
			break;
		case 13: // Block Mystery
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 390, 0 }, { 64, 64 }));
			break;
		case 14: // Spike
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 455 }, { 64, 64 }));
			break;
		case 15: // Exit Begin
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 520, 130 }, { 64, 64 }));
			break;
		case 16: // Exit End
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 455, 130 }, { 64, 64 }));
			break;
		case 17: // Bush
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 845, 65 }, { 64, 64 }));
			break;
		case 18: // Plant
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 455, 195 }, { 64, 64 }));
			break;
		case 19: // Exit Panel
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 910, 390 }, { 64, 64 }));
			break;
		case 20: // Ocean Sand Tile
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 975, 325 }, { 64, 64 }));
			break;
		case 21: // Ocean Sand Tile Mid
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 910, 325 }, { 64, 64 }));
			break;
		case 22: // First Sand Tile Ground
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 910, 780 }, { 64, 64 }));
			break;
		case 23: // Sand Tile Ground
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 845, 780 }, { 64, 64 }));
			break;
		case 24: // Last Sand Tile Ground
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 975, 780 }, { 64, 64 }));
			break;
		case 25: // First Sand Tile Deco
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 715, 780 }, { 64, 64 }));
			break;
		case 26: // Sand Tile Deco
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 650, 780 }, { 64, 64 }));
			break;
		case 27: // Last Sand Tile Deco
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 780, 780 }, { 64, 64 }));
			break;
		case 28: // First Sand Tile Plateform
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 845 }, { 64, 64 }));
			break;
		case 29: // Sand Tile Plateform
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 65, 845 }, { 64, 64 }));
			break;
		case 30: // Last Sand Tile Plateform
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 130, 845 }, { 64, 64 }));
			break;
		case 31: // Cactus
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 910, 65 }, { 64, 64 }));
			break;
		case 32: // Coins
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 130 }, { 64, 64 }));
			break;
	}

	parent->getComponent<Transform>()->setOrigin({ 32, 32 });
	parent->getComponent<Transform>()->setScale({ 0.5f, 0.5f });
	anim = true;
	animSpeed = 0.10f;
	animTimer = 0.f;
}

void Tiles::Animation(float deltaTime) {
	animTimer += deltaTime;
	if (animTimer >= animSpeed) {
		if (anim) {
			if (type == 32) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 65, 130 }, { 64, 64 }));
			}
			anim = false;
		}
		else {
			if (type == 32) {
				parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 130 }, { 64, 64 }));
			}
			anim = true;
		}
		animTimer = 0.f;
	}
}

void Tiles::Update(float deltaTime) {
	Animation(deltaTime);
}

void Tiles::BeginCollision(Entity* me, Entity* other)
{
	if (other->getComponent<Player>())
	{
		if (type == 14) {
			other->getComponent<Player>()->Death();
		}
		if (type == 15 || type == 16) {
			SceneManager* sceneManager = SceneManager::Instance();
			sceneManager->setLevel(sceneManager->getLevel()+1);
			sceneManager->ClearScene();

			if (sceneManager->getLevel() == 2) {
				sceneManager->ChangeScene("Level2");
			}
			else {
				sceneManager->setLevel(1);
				sceneManager->ChangeScene("Menu");
			}
		}
		if (type == 13) {
			parent->getComponent<Sound>()->Play();
			other->getComponent<Player>()->setCoinNbrs(other->getComponent<Player>()->getCoinNbrs() + 1);
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 325, 0 }, { 64, 64 }));
			type = 0;
		}
		if (type == 32) {
			parent->getComponent<Sound>()->Play();
			other->getComponent<Player>()->setCoinNbrs(other->getComponent<Player>()->getCoinNbrs() + 1);
			SceneManager* sceneManager = SceneManager::Instance();
			AScene* scene = sceneManager->GetCurrentScene();
			scene->RemoveEntity(parent);
		}
	}
}

void Tiles::EndCollision(Entity* me, Entity* other)
{
	
}

