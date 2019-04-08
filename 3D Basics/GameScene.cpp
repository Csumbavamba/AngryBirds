#include "GameScene.h"
#include "DynamicBox.h"
#include "Ground.h"
#include "DynamicCircle.h"
#include "Utility.h"
#include "Physics2D.h"


GameScene::GameScene()
{
	sceneName = "GameScene";

	testBox = new DynamicBox(mainCamera);
	testBox2 = new DynamicBox(mainCamera);
	ground = new Ground(mainCamera);
	testCircle = new DynamicCircle(mainCamera);

	gameObjects.push_back(testBox);
	gameObjects.push_back(testBox2);
	gameObjects.push_back(ground);
	gameObjects.push_back(testCircle);


	testBox->transform.rotation.y = 50.0f;
	testBox->transform.position.z += 50.0f;
	testBox->transform.scale.z *= 2.0f;

	testCircle->transform.position.z += 200.0f;

	ground->transform.scale.x *= 5.0f;
	ground->transform.position.z = -300.0f;

	
}


GameScene::~GameScene()
{
	for (GameObject * gameObject : gameObjects)
	{
		delete gameObject;
		gameObject = NULL;
	}
}

void GameScene::Initialise()
{
	Scene::Initialise();
}


void GameScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	Physics2D::Update();

}
