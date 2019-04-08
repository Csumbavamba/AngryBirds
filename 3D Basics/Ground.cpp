#include "Ground.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"

Ground::Ground(Camera * mainCamera)
{
	camera = mainCamera;

	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this); // TODO make this into a factory

	mesh->GetTexture()->SetTexturePath("Sprites/Grass.png");
	transform.scale.x *= 50.0f;
	transform.scale.z *= 3.0f;
	
}

Ground::~Ground()
{
	delete mesh;
	mesh = NULL;

	delete physicsBody;
	physicsBody = NULL;

}

void Ground::Initialise()
{
	mesh->Initialise();

	physicsBody->AddRigidBody();
	physicsBody->AddBoxCollider();
}

void Ground::Render(GLuint program)
{
	if (isActive)
	{
		mesh->Render(camera, program);
	}
}

void Ground::Update(float deltaTime)
{
	if (isActive)
	{
		mesh->Update();
	}
}
