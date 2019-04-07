#include "DynamicCircle.h"
#include "Mesh2D_Quad.h"
#include "Physics2D_Circle.h"
#include "Texture.h"



DynamicCircle::DynamicCircle(Camera * mainCamera)
{
	this->camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
	physicsBody = new Physics2D_Circle(this);

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

	physicsBody->Initialise(b2_dynamicBody);
}

void DynamicCircle::Render(GLuint program)
{
	mesh->Render(camera, program);
}

void DynamicCircle::Update(float deltaTime)
{
	mesh->Update();

	physicsBody->Update();
}
