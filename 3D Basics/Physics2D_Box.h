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
	b2Body * GetRigidBody() const;

	// Overrides the Transform based on physics
	void Update();

private:
	void AddBoxCollider(float32 density = 1.0f, float32 friction = 0.3f);
	b2PolygonShape CreateBoxCollider();

	b2Body * rigidBody = NULL;
	GameObject * owner = NULL;
};

