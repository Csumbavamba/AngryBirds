#include "Scene.h"
#include "Utility.h"
#include "Camera.h"
#include "GameObject.h"

Scene::Scene()
{
	sceneName = "";

	// Create Scene cameras based on game mode
	if (Utility::GetGameMode() == GAMEMODE_2D)
	{
		this->mainCamera = new Camera(ORTOGRAPHIC);
	}
	else
	{
		this->mainCamera = new Camera(PERSPECTIVE);
	}
	

	mainCamera->Initialise();
}

Scene::~Scene()
{
	delete mainCamera;
	mainCamera = NULL;
}

void Scene::Update(float deltaTime)
{
	mainCamera->Update(deltaTime);
}

bool Scene::IsActiveScene() const
{
	return isActiveScene;
}

void Scene::SetIsActiveScene(bool isActiveScene)
{
	this->isActiveScene = isActiveScene;

	// Set all GameObjects active
	for(GameObject * gameObject : gameObjects)
	{
		gameObject->SetIsActive(isActiveScene);
	}
}

std::string Scene::GetSceneName() const
{
	return sceneName;
}
