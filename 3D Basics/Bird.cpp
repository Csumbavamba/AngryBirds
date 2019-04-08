#include "Bird.h"
#include "Mesh2D_Quad.h"
#include "Physics2D_Circle.h"
#include "Texture.h"
#include "Input.h"


Bird::Bird(Camera * mainCamera)
{
	this->camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
	physicsBody = new Physics2D_Circle(this);

}


Bird::~Bird()
{
	delete mesh;
	mesh = NULL;

	delete physicsBody;
	physicsBody = NULL;
}

void Bird::Initialise()
{
	mesh->GetTexture()->SetTexturePath("Sprites/RedBird.png");

	mesh->Initialise();
	physicsBody->Initialise(b2_dynamicBody);
}

void Bird::Render(GLuint program)
{
	mesh->Render(camera, program);
}

void Bird::Update(float deltaTime)
{
	mesh->Update();

	physicsBody->Update();
	
	if (Input::GetKeyState('p') == DOWN_FIRST)
	{
		ApplyImpulse(testVector);
	}
	
}

void Bird::ApplyImpulse(glm::vec2& impulseVector)
{
	b2Vec2 force = b2Vec2(impulseVector.x, impulseVector.y);
	b2Vec2 point = b2Vec2(Physics2D::PixelsToBox2DMeters(this->transform.position.x),
						  Physics2D::PixelsToBox2DMeters(this->transform.position.z));

	physicsBody->GetRigidBody()->ApplyLinearImpulse(force, point, true); 

}
