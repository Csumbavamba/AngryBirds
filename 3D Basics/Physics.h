#pragma once

#include <Box2D/Box2D.h>

class Physics
{
public:

	static Physics * GetInstance();
	static b2Body * CreateBody(b2BodyDef bodyDef);

	static float PixelsToBox2DMeters(float pixels);
	static float Box2DMetersToPixels(float meters);

	static void Update();
	static void ShutDown();

private:
	Physics();
	~Physics();
	Physics(const Physics& copy) {};
	Physics& operator= (const Physics& move) {};

	static Physics * instance;

	b2Vec2 gravity;
	b2World * world;

	float pixelsPerMeter;

	// Simulation Setup
	float32 timeStep;
	int32 velocityIterations; // suggested 8
	int32 positionIterations; // suggested 3


};

