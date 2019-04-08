#include "Physics2D_Box.h"
#include "GameObject.h"


// After this scaling is no longer supported
Physics2D_Box::Physics2D_Box(GameObject * owner)
{
	this->owner = owner;
}

Physics2D_Box::~Physics2D_Box()
{
	rigidBody = NULL;
}

void Physics2D_Box::Initialise(b2BodyType type)
{
	// Create a body definition - set it's position based on the pixel positions
	b2BodyDef bodyDef;
	bodyDef.type = type;
	bodyDef.position.Set(
		Physics2D::PixelsToBox2DMeters(this->owner->transform.position.x),
		Physics2D::PixelsToBox2DMeters(this->owner->transform.position.z));
	bodyDef.angle = Transform::ToRadians(this->owner->transform.rotation.y);

	// Create the body based on the body definition
	rigidBody = Physics2D::CreateBody(bodyDef);

	AddBoxCollider(5.0f, 0.3f);
}

b2Body * Physics2D_Box::GetRigidBody() const
{
	return rigidBody;
}

void Physics2D_Box::AddBoxCollider(float32 density, float32 friction)
{
	b2PolygonShape box = CreateBoxCollider();

	// Switch between what's the type
	switch (rigidBody->GetType())
	{
	case b2_staticBody:
	{
		// Create a static fixture (0.0f density)
		rigidBody->CreateFixture(&box, 0.0f);
		break;
	}
	case b2_dynamicBody:
	{
		// Create a dynamic fixture - base values on density and friction
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &box;
		fixtureDef.density = density;
		fixtureDef.friction = friction;

		// Add fixture
		rigidBody->CreateFixture(&fixtureDef);
		break;
	}
	default: // STATIC
	{

		break;
	}
	}
}

b2PolygonShape Physics2D_Box::CreateBoxCollider()
{
	// Setup the width and height of the box
	b2PolygonShape box;
	box.SetAsBox(
		Physics2D::PixelsToBox2DMeters(this->owner->transform.scale.x / 2.0f),
		Physics2D::PixelsToBox2DMeters(this->owner->transform.scale.z / 2.0f));

	return box;
}


void Physics2D_Box::Update()
{
	// Update the transform in case it's a dynamic body - otherwise the gameobject should update it??
	if (rigidBody->GetType() == b2_dynamicBody)
	{
		// Get transform and rotation values from box2D
		b2Vec2 position = rigidBody->GetPosition();
		float32 angle = rigidBody->GetAngle(); // This is in radians

		// Update position
		this->owner->transform.position.x = Physics2D::Box2DMetersToPixels(position.x);
		this->owner->transform.position.z = Physics2D::Box2DMetersToPixels(position.y);

		this->owner->transform.rotation.y = Transform::ToDegrees(angle);
	}
}
