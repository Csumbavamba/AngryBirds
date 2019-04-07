#pragma once
#include "Physics2D.h"

class GameObject;

class Physics2D_Box
{
public:
	Physics2D_Box(GameObject * owner);
	virtual ~Physics2D_Box();

	// Sets up the body - scaling is no longer supported after this
	void Initialise(b2BodyType type = b2_staticBody);

	// Overrides the Transform based on physics
	void Update();

private:
	b2Body * body = NULL;
	GameObject * owner = NULL;
};

