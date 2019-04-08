#include "GameScene.h"
#include "DynamicBox.h"
#include "Ground.h"
#include "DynamicCircle.h"
#include "Utility.h"
#include "Physics2D.h"
#include "Bird.h"
#include "Catapult.h"
#include "YellowBird.h"
#include "BigBird.h"
#include "UI_Image.h"
#include "Input.h"
#include "SceneManager.h"

GameScene::GameScene()
{
	sceneName = "GameScene";

	testBox = new DynamicBox(mainCamera);
	testBox2 = new DynamicBox(mainCamera);
	ground = new Ground(mainCamera);
	testCircle = new DynamicCircle(mainCamera);
	testBird = new Bird(mainCamera);
	redBird2 = new Bird(mainCamera);
	redBird3 = new BigBird(mainCamera);
	redBird4 = new YellowBird(mainCamera);
	catapult = new Catapult(mainCamera);

	background = new UI_Image(mainCamera, "Sprites/BackgroundImage.png", glm::vec2(800, 600));

	background->transform.scale *= 1.3;

	gameObjects.push_back(testBox);
	gameObjects.push_back(testBox2);
	gameObjects.push_back(ground);
	gameObjects.push_back(testCircle);

	gameObjects.push_back(testBird);
	gameObjects.push_back(redBird2);
	gameObjects.push_back(redBird3);
	gameObjects.push_back(redBird4);

	gameObjects.push_back(catapult);


	testBox->transform.rotation.y = 50.0f;
	testBox->transform.position.z += 50.0f;
	testBox->transform.scale.z *= 2.0f;

	testCircle->transform.position.z += 200.0f;

	testBird->transform.position.z += 300.0f;

	ground->transform.scale.x *= 5.0f;
	ground->transform.position.z = -300.0f;
	

	catapult->transform.position.x = 250.0f;
	catapult->transform.position.z = -220.0f;
	catapult->transform.scale *= 6;
	//catapult->transform.rotation. = 180.0f;
	
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

	if (Input::GetKeyState('w') == DOWN_FIRST)
	{
		SceneManager::ChangeActiveScene("Level1");
	}

}
