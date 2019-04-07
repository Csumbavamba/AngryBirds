#include "StaticBox.h"
#include "Mesh2D_Quad.h"
#include "Physics2D_Box.h"

StaticBox::StaticBox(Camera * mainCamera)
{
	camera = mainCamera;

	mesh = new Mesh2D_Quad(this);
	physicsBody = new Physics2D_Box(this); // TODO make this into a factory
	
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

	physicsBody->Initialise();
}

void StaticBox::Render(GLuint program)
{
	mesh->Render(camera, program);
}

void StaticBox::Update(float deltaTime)
{
	mesh->Update();
}
