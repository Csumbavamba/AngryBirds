#include "GameScene.h"
#include "DynamicBox.h"
#include "StaticBox.h"
#include "DynamicCircle.h"
#include "Utility.h"
#include "Physics2D.h"
#include "Bird.h"
#include "Catapult.h"


GameScene::GameScene()
{
	sceneName = "GameScene";

	testBox = new DynamicBox(mainCamera);
	testBox2 = new DynamicBox(mainCamera);
	ground = new StaticBox(mainCamera);
	testCircle = new DynamicCircle(mainCamera);
	testBird = new Bird(mainCamera);
	catapult = new Catapult(mainCamera);

	gameObjects.push_back(testBox);
	gameObjects.push_back(testBox2);
	gameObjects.push_back(ground);
	gameObjects.push_back(testCircle);


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
	delete testBox;
	testBox = NULL;

	delete testBox2;
	testBox2 = NULL;

	delete testCircle;
	testCircle = NULL;

	delete ground;
	ground = NULL;

	delete testBird;
	testBird = NULL;

	delete catapult;
	catapult = NULL;
}

void GameScene::Initialise()
{
	testBox->Initialise();
	testBox2->Initialise();
	testCircle->Initialise();
	ground->Initialise();
	testBird->Initialise();
	catapult->Initialise();

	catapult->AddBird(testBird);
}

void GameScene::Render(GLuint program)
{
	testBox->Render(program);
	testBox2->Render(program);
	testCircle->Render(program);
	ground->Render(program);
	testBird->Render(program);
	catapult->Render(program);
}

void GameScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	Physics2D::Update();

	testBox->Update(deltaTime);
	testBox2->Update(deltaTime);
	testCircle->Update(deltaTime);
	ground->Update(deltaTime);

	testBird->Update(deltaTime);
	catapult->Update(deltaTime);
}
