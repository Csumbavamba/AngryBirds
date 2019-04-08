#include "Physics2D_Circle.h"
#include "GameObject.h"
#include "Transform.h"



Physics2D_Circle::Physics2D_Circle(GameObject * owner)
{
	this->owner = owner;
}


Physics2D_Circle::~Physics2D_Circle()
{
	rigidBody = NULL;
}

void Physics2D_Circle::Initialise(b2BodyType type)
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

	// Create Circle shape
	b2CircleShape circle;

	// Setup radius
	circle.m_radius = Physics2D::PixelsToBox2DMeters(this->owner->transform.scale.x / 2.0f);


	// Switch between what's the type
	switch (type)
	{
	case b2_staticBody:
	{
		// Create a static fixture (0.0f density)
		rigidBody->CreateFixture(&circle, 0.0f);
		break;
	}
	case b2_dynamicBody:
	{
		// Create a dynamic fixture - base values on density and friction
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &circle;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;

		// Add fixture
		rigidBody->CreateFixture(&fixtureDef); // TODO - this makes the values to zero

		break;
	}
	default: // STATIC
	{

		break;
	}
	}
}

void Physics2D_Circle::Update()
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

		// Update radius
		this->owner->transform.rotation.y = Transform::ToDegrees(angle);
	}
}

b2Body * Physics2D_Circle::GetRigidBody() const
{
	return rigidBody;
}

float Physics2D_Circle::GetBiggerScaleAxes()
{
	// Check which scale is higher, return the higher one
	return (this->owner->transform.scale.x > this->owner->transform.scale.z ?
		this->owner->transform.scale.x : 
		this->owner->transform.scale.z);
}
