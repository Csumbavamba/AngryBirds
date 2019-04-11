#include "BigBird.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"
#include "Input.h"
#include "AudioSound.h"
#include "AudioEngine.h"


BigBird::BigBird(Camera * mainCamera)
{
	this->camera = mainCamera;
	transform.scale *= 5;
	mesh->GetTexture()->SetTexturePath("Sprites/BigBird.png");
	birdCry = new AudioSound("Audio/BigBirdCry.mp3", DEFAULT);
}

BigBird::~BigBird()
{
}

void BigBird::Initialise()
{
	mesh->Initialise();
	physicsBody->AddRigidBody(b2_dynamicBody);
	physicsBody->AddCircleCollider(1200.0f);

}

void BigBird::Update(float deltaTime)
{
	mesh->Update();

	physicsBody->Update();
}

void BigBird::ApplyImpulse(glm::vec2 & impulseVector)
{
	physicsBody->GetRigidBody()->SetLinearVelocity(b2Vec2(0, 0));
	physicsBody->GetRigidBody()->SetAngularVelocity(0);
	b2Vec2 force = b2Vec2(impulseVector.x * 1000, impulseVector.y * 600);
	b2Vec2 point = b2Vec2(Physics2D::PixelsToBox2DMeters(this->transform.position.x),
		Physics2D::PixelsToBox2DMeters(this->transform.position.z));

	physicsBody->GetRigidBody()->ApplyLinearImpulse(force, point, true);

	physicsBody->GetRigidBody()->SetAngularVelocity(0);


	birdCry->PlaySound();
}
