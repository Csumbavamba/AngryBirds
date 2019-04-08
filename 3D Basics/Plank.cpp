#include "Plank.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"


Plank::Plank(Camera * mainCamera)
{
	this->camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this);
	
	mesh->GetTexture()->SetTexturePath("Sprites/Plank.jpg");
	transform.scale.z *= 2.0f;
	transform.scale.x *= 0.5f;
}


Plank::~Plank()
{
	delete physicsBody;
	physicsBody = NULL;

	delete mesh;
	mesh = NULL;
}

void Plank::Initialise()
{
	mesh->Initialise();

	physicsBody->AddRigidBody(b2_dynamicBody);
	physicsBody->AddBoxCollider(20.0f, 0.8f);
	physicsBody->GetRigidBody()->SetLinearDamping(0.9f);
	physicsBody->GetRigidBody()->SetAngularDamping(0.9f);
}

void Plank::Render(GLuint program)
{
	if (isActive)
	{
		mesh->Render(camera, program);
	}
	
}

void Plank::Update(float deltaTime)
{
	if (isActive)
	{
		mesh->Update();
		physicsBody->Update();
	}	
}
