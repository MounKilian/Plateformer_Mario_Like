#include <SFML/Graphics.hpp>
#include "AScene.h"
#include "SceneManager.h"
#include "Application.h"
#include "Level1Scene.h"

int main()
{
	Application* app = Application::Instance();
    app->Init();

	Level1Scene* level1Scene = new Level1Scene;

	SceneManager* sceneManager = SceneManager::Instance();

	sceneManager->AddScene("Level1", level1Scene);
	sceneManager->ChangeScene("Level1");

	app->Loop();
}
