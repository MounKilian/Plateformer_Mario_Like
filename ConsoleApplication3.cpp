#include <SFML/Graphics.hpp>
#include "AScene.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "Application.h"
#include "TestScene.h"
#include "Level1Scene.h"

int main()
{
	Application* app = Application::Instance();
    app->Init();

	Level1Scene* level1Scene = new Level1Scene;

	/*GameScene* gameScene = new GameScene;*/
	/*MenuScene* menuScene = new MenuScene;*/
	/*TestScene* testScene = new TestScene;*/

	SceneManager* sceneManager = SceneManager::Instance();

	/*sceneManager->AddScene("game", gameScene);
	sceneManager->AddScene("test", testScene);*/
	/*sceneManager->AddScene("menu", menuScene);*/

	sceneManager->AddScene("Level1", level1Scene);
	sceneManager->ChangeScene("Level1");

	app->Loop();
}
