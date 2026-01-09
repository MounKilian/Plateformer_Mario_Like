#include "RessourceManager.h"
#include <filesystem>
#include <windows.h>
#include <iostream>

RessourceManager* RessourceManager::m_instance = nullptr;

RessourceManager* RessourceManager::Instance()
{
	if (m_instance == nullptr) {
		m_instance = new RessourceManager();
	}
	return m_instance;
}

sf::Texture* RessourceManager::loadtexture(const std::string& filename)
{

	if (!m_cache.contains(filename)) {
		TCHAR buffer[MAX_PATH];
		GetModuleFileName(NULL, buffer, MAX_PATH);

		std::string filenameAboslute = std::filesystem::path(buffer).parent_path().string();
		std::cout << "Loading texture: " << filenameAboslute + "\\" + filename << std::endl;
		m_cache[filename] = new sf::Texture(filenameAboslute + "\\" + filename);
	}
	return m_cache[filename];
}
