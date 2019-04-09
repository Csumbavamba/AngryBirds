#pragma once

#include <Box2D/Box2D.h>
#include <vector>

class PhysicsContactListener;
class Destructable;

class Physics2D
{
public:

	static Physics2D * GetInstance();
	static b2Body * CreateBody(b2BodyDef bodyDef);
	static void SetContactListener(PhysicsContactListener * listener);

	static float PixelsToBox2DMeters(float pixels);
	static float Box2DMetersToPixels(float meters);
	

	static void Update(float deltaTime);
	static void ShutDown();

private:
	Physics2D();
	~Physics2D();
	Physics2D(const Physics2D& copy) {};
	Physics2D& operator= (const Physics2D& move) {};

	static Physics2D * instance;

	b2Vec2 gravity;
	b2World * world = NULL;
	PhysicsContactListener * contactListener = NULL;

	float pixelsPerMeter;

	// Simulation Setup
	float32 timeStep;
	int32 velocityIterations; // suggested 8
	int32 positionIterations; // suggested 3


};

class PhysicsContactListener :
	public b2ContactListener
{
public:

	void BeginContact(b2Contact* contact) override;
	void EndContact(b2Contact* contact) override;
	std::vector<Destructable*> * GetObjectsToDisable();

private:
	std::vector<Destructable*> objectsToDisable;
	const float destroyThreshold = 100.0f;

};

