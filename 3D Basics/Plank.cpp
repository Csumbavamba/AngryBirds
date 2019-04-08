#include "Plank.h"
#include "Mesh2D_Quad.h"
#include "Physics2D_Box.h"
#include "Texture.h"


Plank::Plank(Camera * mainCamera)
{
	this->camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
	physicsBody = new Physics2D_Box(this);
	
	mesh->GetTexture()->SetTexturePath("Sprites/Plank.jpg");
	// transform.scale.z *= 2.0f;
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

	physicsBody->Initialise(b2_dynamicBody);
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
	//if (isActive)
	{
		mesh->Update();
		physicsBody->Update();
	}	
}
