#include "SceneManager.h"

SceneManager* SceneManager::m_instance = nullptr;

SceneManager* SceneManager::Instance()
{
    if (m_instance == nullptr) {
		m_instance = new SceneManager();
    }
    return m_instance;
}

AScene* SceneManager::GetCurrentScene()
{
    return scenes[currentScene];
}

void SceneManager::AddScene(std::string id, AScene* scene)
{
	scenes[id] = scene;
}

void SceneManager::RemoveScene(std::string id, AScene* scene)
{
 	scenes.erase(id);
}

void SceneManager::ChangeScene(std::string id)
{
	currentScene = id;
	scenes[currentScene]->Init();
}

void SceneManager::ClearScene()
{
	for (Entity* entity : GetCurrentScene()->GetEntities()) {
		GetCurrentScene()->RemoveEntity(entity);
	}
}
