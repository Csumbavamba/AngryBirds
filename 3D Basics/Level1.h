#pragma once
#include "Scene.h"

class Plank;
class StaticBox;

class Level1 :
	public Scene
{
public:
	Level1();
	virtual ~Level1();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

private:
	Plank * plank = NULL;
	StaticBox * ground = NULL;
};

