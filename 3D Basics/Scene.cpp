#include "Scene.h"


#include "Camera.h"


Scene::Scene()
{
	this->mainCamera = new Camera(ORTOGRAPHIC);

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
}

std::string Scene::GetSceneName() const
{
	return sceneName;
}
