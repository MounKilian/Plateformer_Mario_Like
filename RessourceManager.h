#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class RessourceManager
{
	static RessourceManager* m_instance;
	std::map<std::string, sf::Texture*> m_cache;

	public:
		static RessourceManager* Instance();
		sf::Texture* loadtexture(const std::string& filename);
};

