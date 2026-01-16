#include "TextRenderer.h"
#include "Transform.h"
#include "Entity.h"

TextRenderer::TextRenderer(sf::Font* font): text(*font, "", 30) {

}

void TextRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= parent->getComponent<Transform>()->getTransform();
	target.draw(text, states);
}

void TextRenderer::setString(std::string str)
{
	text.setString(str);

	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin({ bounds.size.x / 2.f, bounds.size.y / 2.f });
}

void TextRenderer::setCharacterSize(int size)
{
	text.setCharacterSize(size);
}

void TextRenderer::setFillColor(sf::Color color)
{
	text.setFillColor(color);
}
