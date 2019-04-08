#include "StaticBox.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"

StaticBox::StaticBox(Camera * mainCamera)
{
	camera = mainCamera;

	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this); // TODO make this into a factory
	
}

StaticBox::~StaticBox()
{
	delete mesh;
	mesh = NULL;

	delete physicsBody;
	physicsBody = NULL;

}

void StaticBox::Initialise()
{
	mesh->Initialise();

	physicsBody->AddRigidBody();
	physicsBody->AddBoxCollider();
}

void StaticBox::Render(GLuint program)
{
	if (isActive)
	{
		mesh->Render(camera, program);
	}
}

void StaticBox::Update(float deltaTime)
{
	if (isActive)
	{
		mesh->Update();
	}
}
