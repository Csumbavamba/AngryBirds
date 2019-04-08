#include "GameScene.h"
#include "DynamicBox.h"
#include "StaticBox.h"
#include "DynamicCircle.h"
#include "Utility.h"
#include "Physics2D.h"
#include "Bird.h"
#include "Catapult.h"
#include "YellowBird.h"
#include "BigBird.h"
#include "UI_Image.h"


GameScene::GameScene()
{
	sceneName = "GameScene";

	testBox = new DynamicBox(mainCamera);
	testBox2 = new DynamicBox(mainCamera);
	ground = new StaticBox(mainCamera);
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

	delete redBird2;
	redBird2 = NULL;

	delete redBird3;
	redBird3 = NULL;

	delete redBird4;
	redBird4 = NULL;

	delete catapult;
	catapult = NULL;

	delete background;
	background = NULL;
}

void GameScene::Initialise()
{
	testBox->Initialise();
	testBox2->Initialise();
	testCircle->Initialise();
	ground->Initialise();
	testBird->Initialise();
	redBird2->Initialise();
	redBird3->Initialise();
	redBird4->Initialise();
	catapult->Initialise();

	background->Initialise();

	catapult->AddBird(testBird);
	catapult->AddBird(redBird2);
	catapult->AddBird(redBird3);
	catapult->AddBird(redBird4);
}

void GameScene::Render(GLuint program)
{
	background->Render(program);

	testBox->Render(program);
	testBox2->Render(program);
	testCircle->Render(program);
	ground->Render(program);
	testBird->Render(program);
	redBird2->Render(program);
	redBird3->Render(program);
	redBird4->Render(program);

	

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
	redBird2->Update(deltaTime);
	redBird3->Update(deltaTime);
	redBird4->Update(deltaTime);
	catapult->Update(deltaTime);

	background->Update(deltaTime);
}
