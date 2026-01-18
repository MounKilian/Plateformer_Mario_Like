#include "RessourceManager.h"
#include <filesystem>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>

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

sf::SoundBuffer* RessourceManager::loadsound(const std::string& filename)
{
    if (!m_cacheSound.contains(filename)) {
        TCHAR buffer[MAX_PATH];
        GetModuleFileName(NULL, buffer, MAX_PATH);

        std::string filenameAboslute = std::filesystem::path(buffer).parent_path().string();
        std::cout << "Loading sound: " << filenameAboslute + "\\" + filename << std::endl;
        m_cacheSound[filename] = new sf::SoundBuffer(filenameAboslute + "\\" + filename);
    }
    return m_cacheSound[filename];
}

std::vector<std::vector<int>> RessourceManager::loadCSV(const std::string& filename)
{
    if (m_csvCache.contains(filename)) {
        return m_csvCache[filename];
    }

    std::vector<std::vector<int>> result;

    TCHAR buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::string basePath = std::filesystem::path(buffer).parent_path().string();

    std::string fullPath = basePath + "\\" + filename;

    std::ifstream file(fullPath);
    if (!file.is_open()) {
        return result;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stoi(cell));
        }

        result.push_back(row);
    }

    m_csvCache[filename] = result;

    return result;
}

sf::Font* RessourceManager::loadFont(const std::string& filename)
{
    if (!m_fontCache.contains(filename)) {
        TCHAR buffer[MAX_PATH];
        GetModuleFileName(NULL, buffer, MAX_PATH);

        std::string filenameAboslute = std::filesystem::path(buffer).parent_path().string();
        std::cout << "Loading font: " << filenameAboslute + "\\" + filename << std::endl;
        m_fontCache[filename] = new sf::Font(filenameAboslute + "\\" + filename);
    }
    return m_fontCache[filename];
}
