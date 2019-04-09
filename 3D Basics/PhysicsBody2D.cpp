#include "PhysicsBody2D.h"
#include "GameObject.h"


// After this scaling is no longer supported
PhysicsBody2D::PhysicsBody2D(GameObject * owner)
{
	this->owner = owner;
	isDestructable = false;
}

PhysicsBody2D::~PhysicsBody2D()
{
	rigidBody = NULL;
}

void PhysicsBody2D::AddRigidBody(b2BodyType type)
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

	rigidBody->SetUserData(this);

	owner->SetPhysicsEnabled(true);

}

void PhysicsBody2D::AddCircleCollider(float32 density, float32 friction)
{
	b2CircleShape circle = CreateCircleCollider();

	// Switch between what's the type
	switch (rigidBody->GetType())
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

b2Body * PhysicsBody2D::GetRigidBody() const
{
	return rigidBody;
}

void PhysicsBody2D::SetIsDestructable(bool isDestructable)
{
	this->isDestructable = isDestructable;
}

bool PhysicsBody2D::IsDestructable() const
{
	return isDestructable;
}

GameObject * PhysicsBody2D::GetOwner() const
{
	return owner;
}


void PhysicsBody2D::AddBoxCollider(float32 density, float32 friction)
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

b2PolygonShape PhysicsBody2D::CreateBoxCollider()
{
	// Setup the width and height of the box
	b2PolygonShape box;
	box.SetAsBox(
		Physics2D::PixelsToBox2DMeters(this->owner->transform.scale.x / 2.0f),
		Physics2D::PixelsToBox2DMeters(this->owner->transform.scale.z / 2.0f));

	return box;
}

b2CircleShape PhysicsBody2D::CreateCircleCollider()
{
	// Create Circle shape
	b2CircleShape circle;

	// Setup radius
	circle.m_radius = Physics2D::PixelsToBox2DMeters(this->owner->transform.scale.x / 2.0f);

	return circle;
}


void PhysicsBody2D::Update()
{
	// Update the transform in case it's active and it's a dynamic body
	if (rigidBody->GetType() == b2_dynamicBody && rigidBody->IsActive())
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
