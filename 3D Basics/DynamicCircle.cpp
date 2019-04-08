#include "DynamicCircle.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"



DynamicCircle::DynamicCircle(Camera * mainCamera)
{
	this->camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this);

	mesh->GetTexture()->SetTexturePath("Sprites/AwesomeFace.png");
	
}


DynamicCircle::~DynamicCircle()
{
	delete mesh;
	mesh = NULL;
	
	delete physicsBody;
	physicsBody = NULL;
}

void DynamicCircle::Initialise()
{
	mesh->Initialise();

	physicsBody->AddRigidBody(b2_dynamicBody);
	physicsBody->AddCircleCollider();
}

void DynamicCircle::Render(GLuint program)
{
	if (isActive)
	{
		mesh->Render(camera, program);
	}
	
}

void DynamicCircle::Update(float deltaTime)
{
	if (isActive)
	{
		mesh->Update();

		physicsBody->Update();
	}
	else
	{
		// TODO - Figure out how to do nicer
		physicsBody->GetRigidBody()->SetActive(false);
	}
	
}
