#include "StartMenuScene.h"

#include "GameMenu.h"
#include "Camera.h"


StartMenuScene::StartMenuScene()
{
	startMenu = new GameMenu(mainCamera);

	sceneName = "StartMenuScene"; // TODO Create method to get this from file
}


StartMenuScene::~StartMenuScene()
{
	delete startMenu;
	startMenu = NULL;
}

void StartMenuScene::Initialise()
{
}

void StartMenuScene::Render(GLuint program)
{
	startMenu->Render(program);
}

void StartMenuScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	startMenu->Update(deltaTime);
}

