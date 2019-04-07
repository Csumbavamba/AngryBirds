#pragma once
#include "Scene.h"
#include "Box2D/Box2D.h"

class DynamicBox;
class StaticBox;

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
	b2Vec2 gravity;
	b2World * world;

	DynamicBox * testBox = NULL;
	StaticBox * ground = NULL;
};

