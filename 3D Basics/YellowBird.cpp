#include "YellowBird.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"
#include "Input.h"
#include "AudioSound.h"


YellowBird::YellowBird(Camera * mainCamera)
{
	this->camera = mainCamera;
	birdCry = new AudioSound("Audio/YellowBirdCry.mp3", DEFAULT);
}


YellowBird::~YellowBird()
{
}

void YellowBird::Initialise()
{
	mesh->GetTexture()->SetTexturePath("Sprites/YellowBird.png");

	mesh->Initialise();
	physicsBody->AddRigidBody(b2_dynamicBody);
	physicsBody->AddCircleCollider(60.0f);
}

void YellowBird::Update(float deltaTime)
{
	mesh->Update();

	physicsBody->Update();

	if (Input::GetMouseState(2) == DOWN)
	{
		if (hasFired == false)
		{
			ApplyImpulse(testVector);
			hasFired = true;
		}
		
	}

}
