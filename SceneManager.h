#pragma once

#include "AScene.h"
#include <map>

class SceneManager
{
	static SceneManager* m_instance;
	std::map<std::string, AScene*> scenes;
	std::string currentScene;
	int level;

	public:
		static SceneManager* Instance();
		AScene* GetCurrentScene();
		int getLevel();
		void setLevel(int level);
		void AddScene(std::string id, AScene* scene);
		void RemoveScene(std::string id, AScene* scene);
		void ChangeScene(std::string id);
		void ClearScene();
};

