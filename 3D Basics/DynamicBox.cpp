#include "DynamicBox.h"
#include "Mesh2D_Quad.h"
#include "Physics2D_Box.h"


DynamicBox::DynamicBox(Camera * mainCamera)
{
	camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
	physicsBody = new Physics2D_Box(this);
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

	physicsBody->Initialise(b2_dynamicBody);
}

void DynamicBox::Render(GLuint program)
{
	mesh->Render(camera, program);
}

void DynamicBox::Update(float deltaTime)
{

	mesh->Update();

	physicsBody->Update();
}
