#include "Destructable.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"


Destructable::Destructable()
{
	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this);
	physicsBody->SetIsDestructable(true);
	isReadyToDie = false;
}


Destructable::~Destructable()
{
	delete physicsBody;
	physicsBody = NULL;

	delete mesh;
	mesh = NULL;
}


void Destructable::Render(GLuint program)
{
	if (isActive)
	{
		mesh->Render(camera, program);
	}
}

void Destructable::Update(float deltaTime)
{
	if (isActive)
	{
		mesh->Update();
		physicsBody->Update();
	}
}

void Destructable::ReadyDestruction(bool isReady)
{
	this->isReadyToDie = isReady;
}

void Destructable::DestroyObject()
{
	if (isReadyToDie)
	{
		SetIsActive(false);
	}
}
