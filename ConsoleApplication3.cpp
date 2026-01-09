#include <SFML/Graphics.hpp>
#include "AScene.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "Application.h"
#include "TestScene.h"

int main()
{
	Application* app = Application::Instance();
    app->Init();

	GameScene* gameScene = new GameScene;
	/*MenuScene* menuScene = new MenuScene;*/
	TestScene* testScene = new TestScene;
	SceneManager* sceneManager = SceneManager::Instance();
	sceneManager->AddScene("game", gameScene);
	sceneManager->AddScene("test", testScene);
	/*sceneManager->AddScene("menu", menuScene);*/
	sceneManager->ChangeScene("test");

	app->Loop();
}
