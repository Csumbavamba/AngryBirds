#include "DynamicBox.h"
#include "Mesh2D_Quad.h"
#include "Utility.h"


DynamicBox::DynamicBox(Camera * mainCamera)
{
	camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
}

DynamicBox::~DynamicBox()
{
	delete mesh;
	mesh = NULL;

	dynamicBody = NULL;
}

void DynamicBox::Initialise()
{
	GameObject::Initialise();

	mesh->Initialise();

	// Setup the Box2D parts here
	// Create a body definition - set it's position based on the pixel positions, make it dynamic
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(Physics::PixelsToBox2DMeters(transform.position.x), Physics::PixelsToBox2DMeters(transform.position.z));

	// Create the body based on the body definition
	dynamicBody = Physics::CreateBody(bodyDef);

	// Setup the width and height of the box
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(Physics::PixelsToBox2DMeters(transform.scale.x / 2.0f), Physics::PixelsToBox2DMeters(transform.scale.z / 2.0f));

	// Create a dynamic fixture
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	// Add fixture
	dynamicBody->CreateFixture(&fixtureDef);
}

void DynamicBox::Render(GLuint program)
{
	mesh->Render(camera, program);
}

void DynamicBox::Update(float deltaTime)
{
	// Get transform and rotation values from box2D
	b2Vec2 position = dynamicBody->GetPosition();
	float32 angle = dynamicBody->GetAngle(); // This is in radians

	// Update position
	transform.position.x = Physics::Box2DMetersToPixels(position.x);
	transform.position.z = Physics::Box2DMetersToPixels(position.y);

	transform.rotation.y = Transform::ToDegrees(angle);

	mesh->Update();
}
