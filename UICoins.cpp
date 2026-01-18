#include "UICoins.h"
#include "Entity.h"
#include "Renderer.h"
#include "Transform.h"
#include "Application.h"

void UICoins::Init(int type) {
	this->type = type;

	switch (type)
	{
		case 1:
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 455, 260 }, { 64, 64 }));
			break;
		case 2:
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 325, 260 }, { 64, 64 }));
			break;
		case 3:
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 845, 195 }, { 64, 64 }));
			break;
		case 4:
			parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 845, 195 }, { 64, 64 }));
			break;
	}

	parent->getComponent<Transform>()->setOrigin({ 32.f, 32.f });
	parent->getComponent<Transform>()->setScale({ 0.5f, 0.5f });
}

void UICoins::Update(float deltatime) {
	Application* app = Application::Instance();
	sf::Vector2f center = app->getView().getCenter();

	switch (type)
	{
	case 1:
		parent->getComponent<Transform>()->setPosition({ center.x - 260.f, center.y -180.f});
		break;
	case 2:
		parent->getComponent<Transform>()->setPosition({ center.x - 230.f, center.y -180.f});
		break;
	case 3:
		parent->getComponent<Transform>()->setPosition({ center.x - 210.f, center.y -180.f});
		break;
	case 4:
		parent->getComponent<Transform>()->setPosition({ center.x - 190.f, center.y -180.f});
		break;
	}
}