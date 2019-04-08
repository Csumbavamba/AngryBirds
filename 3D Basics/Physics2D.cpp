#include "Physics2D.h"

Physics2D * Physics2D::instance = NULL;

Physics2D * Physics2D::GetInstance()
{
	if (instance == NULL)
	{
		instance = new Physics2D();
	}
	return instance;
}

float Physics2D::PixelsToBox2DMeters(float pixels)
{
	return pixels / GetInstance()->pixelsPerMeter;
}

float Physics2D::Box2DMetersToPixels(float meters)
{
	return meters * GetInstance()->pixelsPerMeter;
}

// Create the body for the physics world
b2Body * Physics2D::CreateBody(b2BodyDef bodyDef)
{
	return GetInstance()->world->CreateBody(&bodyDef);
}

void Physics2D::Update()
{
	GetInstance()->world->Step(
		GetInstance()->timeStep,
		GetInstance()->velocityIterations,
		GetInstance()->positionIterations);

}

void Physics2D::ShutDown()
{
	delete instance;
	instance = NULL;
}

Physics2D::Physics2D()
{
	gravity = b2Vec2(0.0, -10.0f);
	world = new b2World(gravity);

	timeStep = 1.0f / 100.0f;
	velocityIterations = 6;
	positionIterations = 2;

	pixelsPerMeter = 25.0f;
}


Physics2D::~Physics2D()
{
	delete world;
	world = NULL;
}
