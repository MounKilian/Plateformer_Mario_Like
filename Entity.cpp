#include "Entity.h"

Entity::Entity()
{
	
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (AComponent* comp : components) {
		target.draw(*comp, states);
	}
}

void Entity::Update(float dt) {
	for (AComponent* comp : components) {
		comp->Update(dt);
	}
}