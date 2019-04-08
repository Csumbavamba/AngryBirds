#pragma once
#include "Physics2D.h"

class GameObject;

class Physics2D_Circle
{
public:
	Physics2D_Circle(GameObject * owner);
	virtual ~Physics2D_Circle();

	// Sets up the body - scaling is no longer supported after this
	void Initialise(b2BodyType type = b2_staticBody);

	// Overrides the Transform based on physics
	void Update();

	b2Body* GetRigidBody() const;

private:
	float GetBiggerScaleAxes();

	b2Body * rigidBody = NULL;
	GameObject * owner = NULL;
};

