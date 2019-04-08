#include "Pig.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"



Pig::Pig(Camera * camera)
{
	this->camera = camera;
	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this);

	mesh->GetTexture()->SetTexturePath("Sprites/Pig.png");
}


Pig::~Pig()
{
	delete mesh;
	mesh = NULL;

	delete physicsBody;
	physicsBody = NULL;
}

void Pig::Initialise()
{
	mesh->Initialise();

	// Setup Physics
	physicsBody->AddRigidBody(b2_dynamicBody);
	physicsBody->AddCircleCollider(10.0f, 0.2f);
	physicsBody->GetRigidBody()->SetLinearDamping(0.9f);
	physicsBody->GetRigidBody()->SetAngularDamping(0.9f);
}

void Pig::Render(GLuint program)
{
	if (isActive)
	{
		mesh->Render(camera, program);
	}
	
}

void Pig::Update(float deltaTime)
{
	if (isActive)
	{
		mesh->Update();
		physicsBody->Update();
	}
}
