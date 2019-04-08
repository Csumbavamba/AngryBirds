#include "Level1.h"
#include "Plank.h"
#include "Ground.h"
#include "Physics2D.h"


Level1::Level1()
{
	sceneName = "Level1";

	plankLeft = new Plank(mainCamera);
	plankRight = new Plank(mainCamera);
	plankRoof = new Plank(mainCamera);
	plankTop = new Plank(mainCamera);
	ground = new Ground(mainCamera);

	// Add GameObjects to this list
	gameObjects.push_back(plankLeft);
	gameObjects.push_back(plankRight);
	gameObjects.push_back(plankRoof);
	gameObjects.push_back(plankTop);
	gameObjects.push_back(ground);

	// Place the Objects
	SetupLevel();
}

void Level1::SetupLevel()
{
	// Setup Plank left
	plankLeft->transform.position.z = -220.0f;
	plankLeft->transform.position.x -= 50.0f;

	// Setup Plank right
	plankRight->transform.position.z = -220.0f;
	plankRight->transform.position.x += 50.0f;

	// Setup Plank roof
	plankRoof->transform.position.z = -150.0f;
	plankRoof->transform.rotation.y = 90.0f;

	// Setup Plank Top
	plankTop->transform.position.z = -100.0f;

	// Setup ground floor
	ground->transform.position.z = -325.0f;
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
	Scene::Initialise();
}

void Level1::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	Physics2D::Update();

}
