#pragma once
#include "Scene.h"

class DynamicBox;
class DynamicCircle;
class Bird;
class YellowBird;
class BigBird;
class Catapult;
class UI_Image;
class Ground;

class GameScene :
	public Scene
{
public:
	GameScene();
	virtual ~GameScene();

	virtual void Initialise() override;
	virtual void Update(float deltaTime) override;

private:

	DynamicBox * testBox = NULL;
	DynamicBox * testBox2 = NULL;
	DynamicCircle * testCircle = NULL;

	Bird * testBird = NULL;
	Bird * redBird2 = NULL;
	BigBird * redBird3 = NULL;
	YellowBird * redBird4 = NULL;

	UI_Image * background = NULL;



	Catapult * catapult = NULL;
	Ground * ground = NULL;
};

