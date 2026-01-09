#include "Cube.h"
#include "Transform.h"
#include "Renderer.h"
#include "Entity.h"
#include "ICollisionEvent.h"
#include "ACollider.h"
#include <iostream>

void Cube::Init()
{
	parent->getComponent<Renderer>()->GetSprite()->setTextureRect(sf::IntRect({ 0, 0 }, { 32, 32 }));
	parent->getComponent<Transform>()->setOrigin({ 16,16 });
}

void Cube::BeginCollision(ACollider* me, ACollider* other)
{
	std::cout << "Collision detected between Cube and another collider." << std::endl;
}

void Cube::EndCollision(ACollider* me, ACollider* other)
{

}
