#include "StonePlank.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"


StonePlank::StonePlank(Camera * mainCamera)
{
	camera = mainCamera;

	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this);

	mesh->GetTexture()->SetTexturePath("Sprites/Rock.png");
	transform.scale.z *= 2.0f;
	transform.scale.x *= 0.5f;
}


StonePlank::~StonePlank()
{
	delete mesh;
	mesh = NULL;
	
	delete physicsBody;
	physicsBody = NULL;
}

void StonePlank::Initialise()
{
	mesh->Initialise();

	physicsBody->AddRigidBody(b2_dynamicBody);
	physicsBody->AddBoxCollider(600.0f);
	physicsBody->GetRigidBody()->SetLinearDamping(0.9f);
	physicsBody->GetRigidBody()->SetAngularDamping(0.9f);
}

void StonePlank::Render(GLuint program)
{
	if (isActive)
	{
		mesh->Render(camera, program);
	}
}

void StonePlank::Update(float deltaTime)
{
	if (isActive)
	{
		mesh->Update();
		physicsBody->Update();
	}
}
