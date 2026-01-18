#pragma once

#include "AComponent.h"
#include "ICollisionEvent.h"
#include <vector>

class Player : public AComponent, public ICollisionEvent
{
	bool isJumping; 
	bool anim;
	float animTimer;
	float animSpeed;
	sf::SoundBuffer* soundPlayerJump;
	sf::SoundBuffer* soundPlayerDeath;
	int coinNbrs;

	public :
		void Init();
		void Move(float deltaTime);
		void Jump();
		void DeadZone();
		void Death();
		void Animation(float deltaTime, b2Vec2 velocity, sf::Vector2f dir);
		void Update(float dt) override;
		void BeginCollision(Entity* me, Entity* other) override;
		void EndCollision(Entity* me, Entity* other) override;
		void setCoinNbrs(int coinNbrs);
		int getCoinNbrs();
};
