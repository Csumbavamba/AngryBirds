#include "DynamicBox.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"


DynamicBox::DynamicBox(Camera * mainCamera)
{
	camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this);
}

DynamicBox::~DynamicBox()
{
	delete mesh;
	mesh = NULL;

	delete physicsBody;
	physicsBody = NULL;
}

void DynamicBox::Initialise()
{
	mesh->Initialise();

	physicsBody->AddRigidBody(b2_dynamicBody);
	physicsBody->AddBoxCollider();
}

void DynamicBox::Render(GLuint program)
{
	if (isActive)
	{
		mesh->Render(camera, program);
	}
	
}

void DynamicBox::Update(float deltaTime)
{
	if (isActive)
	{
		mesh->Update();

		physicsBody->Update();
	}
}
