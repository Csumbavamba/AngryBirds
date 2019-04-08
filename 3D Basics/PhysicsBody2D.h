#pragma once
#include "Physics2D.h"

class GameObject;

class PhysicsBody2D
{
public:
	PhysicsBody2D(GameObject * owner);
	virtual ~PhysicsBody2D();

	// Sets up the rigidBody - scaling is no longer supported after this
	void AddRigidBody(b2BodyType type = b2_staticBody);

	// Make a Box Collider (Fixture) needs a rigidBody
	void AddBoxCollider(float32 density = 1.0f, float32 friction = 0.3f);

	// Make a Circle Collider (Fixture) needs a rigidBody
	void AddCircleCollider(float32 density = 1.0f, float32 friction = 0.3f);

	b2Body * GetRigidBody() const;

	// Overrides the Transform based on physics
	void Update();

private:
	b2PolygonShape CreateBoxCollider();
	b2CircleShape CreateCircleCollider();

	b2Body * rigidBody = NULL;
	GameObject * owner = NULL;
};

