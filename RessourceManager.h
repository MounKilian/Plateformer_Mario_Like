#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

class RessourceManager
{
	static RessourceManager* m_instance;
	std::map<std::string, sf::Texture*> m_cache;
	std::map<std::string, sf::SoundBuffer*> m_cacheSound;
	std::map<std::string, std::vector<std::vector<int>>> m_csvCache;
	std::map<std::string, sf::Font*> m_fontCache;

	public:
		static RessourceManager* Instance();
		sf::Texture* loadtexture(const std::string& filename);
		sf::SoundBuffer* loadsound(const std::string& filename);
		std::vector<std::vector<int>> loadCSV(const std::string& filepath);
		sf::Font* loadFont(const std::string& filename);
		std::string getMusicPath(const std::string& filename);
};

