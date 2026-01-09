#include "AScene.h"

void AScene::AddEntity(Entity* entity)
{
	m_toAdd.push_back(entity);
}

void AScene::RemoveEntity(Entity* entity)
{
	m_toRemove.push_back(entity);
}

void AScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (Entity* entity : m_entities) {
		target.draw(*entity, states);
	}
}

std::vector<Entity*> AScene::GetEntities()
{
	return m_entities;
}


void AScene::Update(float deltaTime)
{
	//sf::Texture textureTiles("tiles.png");

	for (Entity* entity : m_entities) {
		entity->Update(deltaTime);
	}

	for (Entity* entity : m_toAdd) {
		m_entities.push_back(entity);
	}
	m_toAdd.clear();
	for (Entity* entityToRemove : m_toRemove) {
		auto it = std::find(m_entities.begin(), m_entities.end(), entityToRemove);
		if (it != m_entities.end()) {
			m_entities.erase(it);
			delete entityToRemove;
		}
	}
	m_toRemove.clear();
}