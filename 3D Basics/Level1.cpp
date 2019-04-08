#include "Level1.h"
#include "Plank.h"
#include "StaticBox.h"
#include "Physics2D.h"


Level1::Level1()
{
	sceneName = "Level1";

	plank = new Plank(mainCamera);
	ground = new StaticBox(mainCamera);

	plank->transform.position.z = +100.0f;
	// plank->transform.rotation.y = 10.0f;

	ground->transform.scale.x *= 10.0f;
	ground->transform.position.z = -300.0f;
}


Level1::~Level1()
{
	delete plank;
	plank = NULL;

	delete ground;
	ground = NULL;
}

void Level1::Initialise()
{
	plank->Initialise();
	ground->Initialise();
}

void Level1::Render(GLuint program)
{
	plank->Render(program);
	ground->Render(program);
}

void Level1::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	Physics2D::Update();

	plank->Update(deltaTime);
	ground->Update(deltaTime);
}
