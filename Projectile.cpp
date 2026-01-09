#include "Projectile.h"
#include "SceneManager.h"
#include "Ennemy.h"
#include "Player.h"
#include "Transform.h"
#include "Renderer.h"
#include "AComponent.h"


void Projectile::Init(bool isPlayer)
{
	this->isPlayer = isPlayer;
	parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 0 }, { 16, 16 }));
	parent->getComponent<Transform>()->setOrigin({ 8,8 });
}

void Projectile::Move(float deltaTime) {
	float speed = deltaTime * 500.f;
	Transform* transform = parent->getComponent<Transform>();

	if (isPlayer) {
		transform->setPosition(transform->getPosition() + sf::Vector2f{0.f, -1.f} * speed);
	}
	else {
		transform->setPosition(transform->getPosition() + sf::Vector2f{ 0.f, 1.f } *speed);
	}
}

void Projectile::Update(float dt)
{
    Move(dt);

    for (Entity* entity : SceneManager::Instance()->GetCurrentScene()->GetEntities()) {
        Ennemy* ennemy = entity->getComponent<Ennemy>();

        if (ennemy && isPlayer) {
            Transform* pTransform = parent->getComponent<Transform>();
            Renderer* pRenderer = parent->getComponent<Renderer>();

            Transform* eTransform = entity->getComponent<Transform>();
            Renderer* eRenderer = entity->getComponent<Renderer>();

            if (pTransform && pRenderer && eTransform && eRenderer) {
                sf::FloatRect pBounds = pTransform->getTransform().transformRect(pRenderer->GetSprite()->getLocalBounds());
                sf::FloatRect eBounds = eTransform->getTransform().transformRect(eRenderer->GetSprite()->getLocalBounds());

                if (pBounds.findIntersection(eBounds)) {
                    SceneManager::Instance()->GetCurrentScene()->RemoveEntity(entity);
                    SceneManager::Instance()->GetCurrentScene()->RemoveEntity(parent);
                    break;
                }
            }
        }
    }
}
