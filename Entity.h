#pragma once

#include <SFML/Graphics.hpp>
#include "AComponent.h"

class Entity : public sf::Drawable
{
	int id;
	std::vector<AComponent*> components;

	public :
		Entity();

        template<typename T>
        T* addComponent() {
			T* t = new T();
			t->parent = this;
			components.push_back(t);
			return t;
		}

		void addComponent(AComponent* t) {
			t->parent = this;
			components.push_back(t);
		}

        template<typename T>
        T* getComponent() {
			for (AComponent* comp : components) {
				if (T* castedComp = dynamic_cast<T*>(comp)) {
					return castedComp;
				}
			}
			return nullptr;
        }

		// Hérité via Drawable
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		virtual void Update(float dt);
};

