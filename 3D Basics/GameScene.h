#pragma once
#include "Scene.h"

class DynamicBox;
class DynamicCircle;
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
	Ground * ground = NULL;
};

