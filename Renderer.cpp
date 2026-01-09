#include "Renderer.h"
#include "Transform.h"
#include "Entity.h"

Renderer::Renderer(sf::Texture* texture) : sprite(*texture)
{
}

void Renderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= parent->getComponent<Transform>()->getTransform();
	target.draw(sprite, states);
}

sf::Sprite* Renderer::GetSprite()
{
	return &sprite;
}