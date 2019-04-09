#include "Plank.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"


Plank::Plank(Camera * mainCamera)
{
	this->camera = mainCamera;

	transform.scale.z *= 2.0f;
	transform.scale.x *= 0.5f;
}


Plank::~Plank()
{
}

void Plank::Initialise()
{
	mesh->Initialise();
	mesh->GetTexture()->SetTexturePath("Sprites/Plank.jpg");

	physicsBody->AddRigidBody(b2_dynamicBody);
	physicsBody->AddBoxCollider(10.0f, 0.8f);
	physicsBody->GetRigidBody()->SetLinearDamping(0.9f);
	physicsBody->GetRigidBody()->SetAngularDamping(0.9f);
}

void Plank::DestroyObject()
{
	Destructable::DestroyObject();

	// Play destroy sound here
}
