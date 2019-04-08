#pragma once
#include "Scene.h"

class DynamicBox;
class DynamicCircle;
class Bird;
class StaticBox;
class Catapult;

class GameScene :
	public Scene
{
public:
	GameScene();
	virtual ~GameScene();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

private:

	DynamicBox * testBox = NULL;
	DynamicBox * testBox2 = NULL;
	DynamicCircle * testCircle = NULL;

	Bird * testBird = NULL;
	StaticBox * ground = NULL;

	Catapult * catapult = NULL;
};

