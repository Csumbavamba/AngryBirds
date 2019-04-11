#pragma once
#include "Scene.h"

class Plank;
class Ground;
class Pig;
class Bird;
class YellowBird;
class BigBird;
class Catapult;
class UI_Image;
class StonePlank;
class RevoluteJoint;
class WheelJoint;

class Level2 :
	public Scene
{
public:
	Level2();
	virtual ~Level2();

	void SetupLevel();

	virtual void Initialise() override;
	virtual void Update(float deltaTime) override;

private:
	StonePlank * plankLeft = NULL;
	Plank * plankRight = NULL;
	Plank * plankRoof = NULL;
	Plank * plankTop = NULL;
	Ground * ground = NULL;
	Pig * pig = NULL;
	Pig * topPig = NULL;
	Bird * redBird1 = NULL;
	Bird * redBird2 = NULL;
	BigBird * bigBird1 = NULL;
	YellowBird * yellowBird1 = NULL;
	UI_Image * background = NULL;
	Catapult * catapult = NULL;
	WheelJoint * wheelJoint = NULL;
	RevoluteJoint * revoluteJoint = NULL;
};

