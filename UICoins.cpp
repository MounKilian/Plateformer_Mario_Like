#include "UICoins.h"
#include "Entity.h"
#include "Renderer.h"
#include "Transform.h"
#include "Player.h"
#include "Application.h"

void UICoins::Init(int type, Entity* player) {
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
	this->m_player = player;
}

void UICoins::Update(float deltatime) {
	Application* app = Application::Instance();
	sf::Vector2f center = app->getView().getCenter();
	int coinNbrs = m_player->getComponent<Player>()->getCoinNbrs();

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
		ChangeCoinUI((coinNbrs - coinNbrs % 10) / 10);
		break;
	case 4:
		parent->getComponent<Transform>()->setPosition({ center.x - 190.f, center.y -180.f});
		ChangeCoinUI(coinNbrs % 10);
		break;
	}
}

void UICoins::ChangeCoinUI(int number)
{
	switch (number)
	{
	case 0:
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 845, 195 }, { 64, 64 }));
		break;
	case 1:
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 910, 195 }, { 64, 64 }));
		break;
	case 2:
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 975, 195 }, { 64, 64 }));
		break;
	case 3:
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 1040, 195 }, { 64, 64 }));
		break;
	case 4:
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 1105, 195 }, { 64, 64 }));
		break;
	case 5:
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 260 }, { 64, 64 }));
		break;
	case 6:
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 65, 260 }, { 64, 64 }));
		break;
	case 7:
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 130, 260 }, { 64, 64 }));
		break;
	case 8:
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 195, 260 }, { 64, 64 }));
		break;
	case 9:
		parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 260, 260 }, { 64, 64 }));
		break;
	}
}
