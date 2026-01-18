#include <SFML/Graphics.hpp>
#include "AScene.h"
#include "SceneManager.h"
#include "Application.h"

int main()
{
	Application* app = Application::Instance();
    app->Init();
	app->Loop();
}
