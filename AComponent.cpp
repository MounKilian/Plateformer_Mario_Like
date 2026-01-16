#include "AComponent.h"

void AComponent::Update(float dt) {}

void AComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const {}

Entity* AComponent::getParent()
{
    return parent;
}
