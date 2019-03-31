#pragma once
#include "Scene.h"

#include <Box2D/Box2D.h>

class GameMenu;

class StartMenuScene :
	public Scene
{
public:
	StartMenuScene();
	virtual ~StartMenuScene();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

private:
	
	GameMenu * startMenu = NULL;

	// Box2D physics
	b2Vec2 gravity;
	b2World * physicsWorld = NULL;
};

