#include "StaticBox.h"
#include "Mesh2D_Quad.h"
#include "Utility.h"


StaticBox::StaticBox(Camera * mainCamera)
{
	camera = mainCamera;
	mesh = new Mesh2D_Quad(this);

	
}

StaticBox::~StaticBox()
{
	delete mesh;
	mesh = NULL;

	// Doesn't need a delete
	groundBody = NULL;
}

void StaticBox::Initialise()
{
	// We need it for scaling
	GameObject::Initialise();

	mesh->Initialise();

	// Setup the Box2D parts here
	// Create a body definition - set it's position based on the pixel positions
	b2BodyDef bodyDef;
	bodyDef.position.Set(Physics::PixelsToBox2DMeters(transform.position.x), Physics::PixelsToBox2DMeters(transform.position.z));

	// Create the body based on the body definition
	groundBody = Physics::CreateBody(bodyDef);

	// Setup the width and height of the box
	b2PolygonShape groundBox;
	groundBox.SetAsBox(Physics::PixelsToBox2DMeters(transform.scale.x / 2.0f), Physics::PixelsToBox2DMeters(transform.scale.z / 2.0f));

	// Create a static fixture (0.0f density)
	groundBody->CreateFixture(&groundBox, 0.0f);
}

void StaticBox::Render(GLuint program)
{
	mesh->Render(camera, program);
}

void StaticBox::Update(float deltaTime)
{
	mesh->Update();
}
