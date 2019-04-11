#include "Pig.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"



Pig::Pig(Camera * camera)
{
	this->camera = camera;
	
}


Pig::~Pig()
{
}

void Pig::Initialise()
{
	
	mesh->Initialise();
	mesh->GetTexture()->SetTexturePath("Sprites/Pig.png");

	// Setup Physics
	physicsBody->AddRigidBody(b2_dynamicBody);
	physicsBody->AddCircleCollider(3.0f, 0.2f);
	physicsBody->GetRigidBody()->SetLinearDamping(0.9f);
	physicsBody->GetRigidBody()->SetAngularDamping(0.9f);
}

void Pig::DestroyObject()
{
	Destructable::DestroyObject();
}


