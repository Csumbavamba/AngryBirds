#include "Level1.h"
#include "Plank.h"
#include "Ground.h"
#include "Physics2D.h"
#include "Pig.h"


Level1::Level1()
{
	sceneName = "Level1";

	// Create Game Objects
	plankLeft = new Plank(mainCamera);
	plankRight = new Plank(mainCamera);
	plankRoof = new Plank(mainCamera);
	plankTop = new Plank(mainCamera);
	ground = new Ground(mainCamera);
	pig = new Pig(mainCamera);
	topPig = new Pig(mainCamera);

	// Add GameObjects to this list
	gameObjects.push_back(plankLeft);
	gameObjects.push_back(plankRight);
	gameObjects.push_back(plankRoof);
	gameObjects.push_back(plankTop);
	gameObjects.push_back(ground);
	gameObjects.push_back(pig);
	gameObjects.push_back(topPig);

	// Place the Objects
	SetupLevel();
}

void Level1::SetupLevel()
{
	// Setup ground floor
	ground->transform.position.z = -325.0f;
	ground->transform.position.x += 250.0f;

	// Setup Plank left
	plankLeft->transform.position.z = ground->GetTopOfGround();
	plankLeft->transform.position.x += plankLeft->transform.scale.x;

	// Setup Plank right
	plankRight->transform.position.z = ground->GetTopOfGround();
	plankRight->transform.position.x -= plankLeft->transform.scale.x;

	// Setup Plank roof
	plankRoof->transform.position.z = ground->GetTopOfGround() + 50.0f;
	plankRoof->transform.rotation.y = 90.0f;

	// Setup Plank Top
	plankTop->transform.position.z = ground->GetTopOfGround() + 75.0f;

	// Setup Pig Positions
	pig->transform.position.z = ground->GetTopOfGround();
	topPig->transform.position.z = ground->GetTopOfGround() + 120.0f;

	// Move the objects to the right
	for (GameObject * gameObject : gameObjects)
	{
		gameObject->transform.position.x -= 250.0f;
	}
}


Level1::~Level1()
{
	for (GameObject * gameObject : gameObjects)
	{
		delete gameObject;
		gameObject = NULL;
	}
}

void Level1::Initialise()
{
	// Calls should happen after this
	Scene::Initialise();
}

void Level1::Update(float deltaTime)
{
	// Calls should happen after this
	Scene::Update(deltaTime);

	Physics2D::Update();
}
