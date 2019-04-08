#include "StartMenuScene.h"

#include "GameMenu.h"
#include "Camera.h"


StartMenuScene::StartMenuScene()
{
	startMenu = new GameMenu(mainCamera);

	gameObjects.push_back(startMenu);

	sceneName = "StartMenuScene"; // TODO Create method to get this from file

}


StartMenuScene::~StartMenuScene()
{
	delete startMenu;
	startMenu = NULL;

}

void StartMenuScene::Initialise()
{
	Scene::Initialise();
}


void StartMenuScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	startMenu->Update(deltaTime);
}

