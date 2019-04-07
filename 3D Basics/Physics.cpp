#include "Physics.h"

Physics * Physics::instance = NULL;

Physics * Physics::GetInstance()
{
	if (instance == NULL)
	{
		instance = new Physics();
	}
	return instance;
}

float Physics::PixelsToBox2DMeters(float pixels)
{
	return pixels / GetInstance()->pixelsPerMeter;
}

float Physics::Box2DMetersToPixels(float meters)
{
	return meters * GetInstance()->pixelsPerMeter;
}

// Create the body for the physics world
b2Body * Physics::CreateBody(b2BodyDef bodyDef)
{
	return GetInstance()->world->CreateBody(&bodyDef);
}

void Physics::Update()
{
	GetInstance()->world->Step(
		GetInstance()->timeStep,
		GetInstance()->velocityIterations,
		GetInstance()->positionIterations);

}

void Physics::ShutDown()
{
	delete instance;
	instance = NULL;
}

Physics::Physics()
{
	gravity = b2Vec2(0.0, -10.0f);
	world = new b2World(gravity);

	timeStep = 1.0f / 600.0f;
	velocityIterations = 8;
	positionIterations = 3;

	pixelsPerMeter = 20.0f;
}


Physics::~Physics()
{
	delete world;
	world = NULL;
}
