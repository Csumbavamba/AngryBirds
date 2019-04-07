#pragma once

#include <Box2D/Box2D.h>

class Physics2D
{
public:

	static Physics2D * GetInstance();
	static b2Body * CreateBody(b2BodyDef bodyDef);

	static float PixelsToBox2DMeters(float pixels);
	static float Box2DMetersToPixels(float meters);

	static void Update();
	static void ShutDown();

private:
	Physics2D();
	~Physics2D();
	Physics2D(const Physics2D& copy) {};
	Physics2D& operator= (const Physics2D& move) {};

	static Physics2D * instance;

	b2Vec2 gravity;
	b2World * world;

	float pixelsPerMeter;

	// Simulation Setup
	float32 timeStep;
	int32 velocityIterations; // suggested 8
	int32 positionIterations; // suggested 3


};

