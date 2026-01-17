#include <SFML/Graphics.hpp>
#include "AScene.h"
#include "SceneManager.h"
#include "Application.h"
#include "Level1Scene.h"
#include "GameOverScene.h"
#include "MenuScene.h"

int main()
{
	Application* app = Application::Instance();
    app->Init();

	Level1Scene* level1Scene = new Level1Scene;
	GameOverScene* gameOverScene = new GameOverScene;
	MenuScene* menuScene = new MenuScene;

	SceneManager* sceneManager = SceneManager::Instance();

	sceneManager->AddScene("Level1", level1Scene);
	sceneManager->AddScene("GameOver", gameOverScene);
	sceneManager->AddScene("Menu", menuScene);

	sceneManager->ChangeScene("Menu");

	app->Loop();
}
