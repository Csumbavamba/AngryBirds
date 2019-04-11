#include "Level2.h"
#include "Plank.h"
#include "Ground.h"
#include "Physics2D.h"
#include "Pig.h"
#include "Bird.h"
#include "Catapult.h"
#include "YellowBird.h"
#include "BigBird.h"
#include "UI_Image.h"
#include "Utility.h"
#include "RevoluteJoint.h"
#include "WheelJoint.h"
#include "StonePlank.h"
#include "Input.h"
#include "Application.h"


Level2::Level2()
{
	sceneName = "Level2";

	// Create Game Objects
	plankLeft = new StonePlank(mainCamera);
	plankRight = new Plank(mainCamera);
	plankRoof = new Plank(mainCamera);
	plankTop = new Plank(mainCamera);
	ground = new Ground(mainCamera);
	pig = new Pig(mainCamera);
	topPig = new Pig(mainCamera);
	redBird1 = new Bird(mainCamera);
	redBird2 = new Bird(mainCamera);
	bigBird1 = new BigBird(mainCamera);
	yellowBird1 = new YellowBird(mainCamera);
	catapult = new Catapult(mainCamera);
	wheelJoint = new WheelJoint(mainCamera);
	revoluteJoint = new RevoluteJoint(mainCamera);
	background = new UI_Image(mainCamera, "Sprites/BackgroundImage.png", Utility::GetScreenSize());

	// Add GameObjects to this list
	gameObjects.push_back(background);
	gameObjects.push_back(plankLeft);
	gameObjects.push_back(plankRight);
	gameObjects.push_back(plankRoof);
	gameObjects.push_back(plankTop);
	gameObjects.push_back(ground);
	gameObjects.push_back(pig);
	gameObjects.push_back(topPig);
	gameObjects.push_back(redBird1);
	gameObjects.push_back(redBird2);
	gameObjects.push_back(bigBird1);
	gameObjects.push_back(yellowBird1);
	gameObjects.push_back(catapult);
	gameObjects.push_back(wheelJoint);
	gameObjects.push_back(revoluteJoint);

	// Setup Catapult
	catapult->AddBird(redBird1);
	catapult->AddBird(redBird2);
	catapult->AddBird(bigBird1);
	catapult->AddBird(yellowBird1);

	// Place the Objects
	SetupLevel();
}


Level2::~Level2()
{
	for (GameObject * gameObject : gameObjects)
	{
		delete gameObject;
		gameObject = NULL;
	}
}

void Level2::SetupLevel()
{
	// Setup background
	background->transform.position.x += 250.0f;
	background->transform.position.y = -10.0f;

	//Bird Setup
	redBird1->transform.position.x += 250.0f;
	redBird2->transform.position.x += 250.0f;
	bigBird1->transform.position.x += 250.0f;
	yellowBird1->transform.position.x += 250.0f;

	//Catapult Setup
	catapult->transform.position.x += 550.0f;

	// Setup ground floor
	ground->transform.position.z = -390.0f;
	ground->transform.position.x += 250.0f;

	// Setup Plank left
	plankLeft->transform.position.z = ground->GetTopOfGround();
	plankLeft->transform.position.x += plankLeft->transform.scale.x;

	// Setup Plank right
	plankRight->transform.position.z = ground->GetTopOfGround();
	plankRight->transform.position.x -= plankLeft->transform.scale.x;

	// Setup Plank roof
	plankRoof->transform.position.z = ground->GetTopOfGround() + 45.0f;
	plankRoof->transform.rotation.y = 90.0f;

	// Setup Plank Top
	plankTop->transform.position.z = ground->GetTopOfGround() + 70.0f;

	// Setup Pig Positions
	pig->transform.position.z = ground->GetTopOfGround();
	topPig->transform.position.z = ground->GetTopOfGround() + 115.0f;

	redBird1->transform.position.z += 300.0f;

	//catapult->transform.position.x = 250.0f;
	catapult->transform.position.z = -220.0f;
	catapult->transform.scale *= 6;

	// Move the objects to the right
	for (GameObject * gameObject : gameObjects)
	{
		gameObject->transform.position.x -= 250.0f;
	}
}

void Level2::Initialise()
{
	// Calls should happen after this
	Scene::Initialise();
}

void Level2::Update(float deltaTime)
{
	// Calls should happen after this
	Scene::Update(deltaTime);

	Physics2D::Update(deltaTime);

	if (Input::GetMouseState(0) == DOWN && catapult->GetBirdIndex() > 3)
	{
		Application::QuitGame();
	}
}
