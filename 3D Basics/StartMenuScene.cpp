#include "StartMenuScene.h"

#include "GameMenu.h"
#include "Camera.h"


StartMenuScene::StartMenuScene()
{
	startMenu = new GameMenu(mainCamera);

	sceneName = "StartMenuScene"; // TODO Create method to get this from file

	// Create Physics World
	gravity = b2Vec2(0.0f, -10.0f);
	physicsWorld = new b2World(gravity);
}


StartMenuScene::~StartMenuScene()
{
	delete startMenu;
	startMenu = NULL;

	delete physicsWorld;
	physicsWorld = NULL;
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

