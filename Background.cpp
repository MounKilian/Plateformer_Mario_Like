#include "Background.h"
#include "Transform.h"
#include "Renderer.h"
#include "Entity.h"
#include "Application.h"

void Background::Init(int layout)
{
	switch (layout)
	{
		case 1:
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 0 }, { 256, 256 }));
			break;

		case 2:
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 257, 514 }, { 256, 256 }));
			break;

		case 3 : // Level 1
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 515}, {256, 256}));
			break;

		case 4 : // Level 2
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 257, 257 }, { 256, 256 }));
			break;
	}

	parent->getComponent<Transform>()->setOrigin({ 128.f, 128.f });
	sf::Vector2f winSize = {1200.f, 900.f};

	float scaleX = winSize.x /256.f;
	float scaleY = winSize.y / 3.f /256.f;

	parent->getComponent<Transform>()->setScale({ scaleX / 1.5f, scaleY / 1.5f });
}