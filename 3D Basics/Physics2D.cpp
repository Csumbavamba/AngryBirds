#include "Physics2D.h"
#include "Destructable.h"

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

void Physics2D::SetContactListener(PhysicsContactListener * listener)
{
	GetInstance()->world->SetContactListener(listener);
}

void Physics2D::Update(float deltaTime)
{
	GetInstance()->world->Step(
		deltaTime, // Should not work but works
		GetInstance()->velocityIterations,
		GetInstance()->positionIterations);

	// Get the objects that need to be destroyed
	std::vector<Destructable*> * objectsToDisable = GetInstance()->contactListener->GetObjectsToDisable();

	if (objectsToDisable->size() > 0)
	{
		// Destroy objects that need deleting
		for (Destructable * toDisable : *objectsToDisable)
		{
			toDisable->DestroyObject();
		}

		// Clear the destructable objects
		objectsToDisable->clear();
	}
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
	contactListener = new PhysicsContactListener();

	// Set the contact listener
	world->SetContactListener(contactListener);
}


Physics2D::~Physics2D()
{
	delete world;
	world = NULL;

	delete contactListener;
	contactListener = NULL;
}
