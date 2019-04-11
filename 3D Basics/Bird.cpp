#include "Bird.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"
#include "Input.h"
#include "AudioSound.h"
#include "AudioEngine.h"


Bird::Bird()
{
	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this);
}

Bird::Bird(Camera * mainCamera)
{
	this->camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this);
	birdCry = new AudioSound("Audio/RedBirdCry.mp3", DEFAULT);

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
	physicsBody->AddRigidBody(b2_dynamicBody);
	physicsBody->AddCircleCollider(60.0f);
}

void Bird::Render(GLuint program)
{
	mesh->Render(camera, program);
}

void Bird::Update(float deltaTime)
{
	mesh->Update();

	physicsBody->Update();
	
	//if (Input::GetKeyState('p') == DOWN_FIRST)
	//{
	//	ApplyImpulse(testVector);
	//}
	
}

void Bird::ApplyImpulse(glm::vec2& impulseVector)
{
	physicsBody->GetRigidBody()->SetLinearVelocity(b2Vec2(0, 0));
	physicsBody->GetRigidBody()->SetAngularVelocity(0);
	b2Vec2 force = b2Vec2(impulseVector.x, impulseVector.y);
	b2Vec2 point = b2Vec2(Physics2D::PixelsToBox2DMeters(this->transform.position.x),
						  Physics2D::PixelsToBox2DMeters(this->transform.position.z));

	physicsBody->GetRigidBody()->ApplyLinearImpulse(force, point, true); 

	physicsBody->GetRigidBody()->SetAngularVelocity(0);


	birdCry->PlaySound();

}

void Bird::SetIsInCatapult(bool isInCatapult)
{
	inCatapult = isInCatapult;
}

bool Bird::GetIsInCatapult() const
{
	return inCatapult;
}

void Bird::SetIsCurrentBird(bool currentBird)
{
	this->currentBird = currentBird;
}

bool Bird::GetIsCurrentBird() const
{
	return currentBird;
}

b2Vec2 Bird::GetRigidBodyPosition()
{
	return physicsBody->GetRigidBody()->GetTransform().p;
}

void Bird::SetRigidBodyPosition(b2Vec2 position)
{
	physicsBody->GetRigidBody()->SetTransform(position, physicsBody->GetRigidBody()->GetAngle());
}

float Bird::GetMomentum()
{
	return physicsBody->GetRigidBody()->GetLinearVelocity().Length() * physicsBody->GetRigidBody()->GetMass();
}
