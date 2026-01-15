#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class RessourceManager
{
	static RessourceManager* m_instance;
	std::map<std::string, sf::Texture*> m_cache;
	std::map<std::string, std::vector<std::vector<int>>> m_csvCache;

	public:
		static RessourceManager* Instance();
		sf::Texture* loadtexture(const std::string& filename);
		std::vector<std::vector<int>> loadCSV(const std::string& filepath);
};

