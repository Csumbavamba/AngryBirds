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
class RopeJoint;
class RevoluteJoint;
class WheelJoint;

class Level1 :
	public Scene
{
public:
	Level1();
	void SetupLevel();
	virtual ~Level1();

	virtual void Initialise() override;
	virtual void Update(float deltaTime) override;

private:
	Plank * plankLeft = NULL;
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
	RopeJoint * ropeJoint = NULL;
	WheelJoint * wheelJoint = NULL;
	RevoluteJoint * revoluteJoint = NULL;
};

