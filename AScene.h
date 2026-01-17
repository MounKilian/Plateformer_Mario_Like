#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"

class AScene : public sf::Drawable
{
	protected:
		std::vector<Entity*> m_entities;
		std::vector<Entity*> m_toAdd;
		std::vector<Entity*> m_toRemove;

	public:
	public:
		virtual void Init() = 0;
		void AddEntity(Entity* entity);
		void RemoveEntity(Entity* entity);
		virtual void Update(float dt);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		std::vector<Entity*> GetEntities();

};
