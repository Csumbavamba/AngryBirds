#pragma once
#include "Scene.h"

class Plank;
class Ground;
class Pig;

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
};

