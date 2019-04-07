#include "GameScene.h"
#include "DynamicBox.h"
#include "StaticBox.h"
#include "Utility.h"


GameScene::GameScene()
{
	sceneName = "GameScene";

	gravity = b2Vec2(0.0f, -10.0f);
	world = new b2World(gravity);


	testBox = new DynamicBox(mainCamera);
	ground = new StaticBox(mainCamera);

	ground->transform.scale.x *= 5.0f;
	ground->transform.position.z = -300.0f;

	
}


GameScene::~GameScene()
{
	delete testBox;
	testBox = NULL;

	delete ground;
	ground = NULL;

	delete world;
	world = NULL;
}

void GameScene::Initialise()
{
	testBox->Initialise();
	ground->Initialise();
}

void GameScene::Render(GLuint program)
{
	testBox->Render(program);
	ground->Render(program);
}

void GameScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	Physics::Update();

	testBox->Update(deltaTime);
	ground->Update(deltaTime);
}
