#include "Catapult.h"
#include "Input.h"
#include "Mesh2D_Quad.h"
#include "Physics2D_Circle.h"
#include "Texture.h"
#include "Input.h"
#include "Physics2D.h"
#include <iostream>
#include "Utility.h"

Catapult::Catapult(Camera * mainCamera)
{
	this->camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
	birdIndex = 0;

}


Catapult::~Catapult()
{
	delete mesh;
	mesh = NULL;

}

void Catapult::Initialise()
{
	mesh->GetTexture()->SetTexturePath("Sprites/Slingshot.jpg");
	mesh->Initialise();
}

void Catapult::Render(GLuint program)
{
	mesh->Render(camera, program);
}

void Catapult::Update(float deltaTime)
{
	mesh->Update();

	GainControlOfBird();

	UpdateBirdPosition();	

	FireBird();

	//system("CLS");
	//Utility::Print(Input::GetMousePosition().x);
	//Utility::Print(Input::GetMousePosition().y);
}

void Catapult::AddBird(Bird * bird)
{
	vectorOfBirds.push_back(bird);
	birdCount++;
}

void Catapult::UpdateBirdPosition()
{
	if (vectorOfBirds.at(birdIndex)->GetIsInCatapult() == true)
	{
		newPosition = Input::GetMousePosition();
		if (newPosition.x >= maximumPullDistance)
		{
			newPosition.x = maximumPullDistance;
		}

		if (newPosition.y >= maximumPullHeight)
		{
			newPosition.y = maximumPullHeight;
		}

		if (birdCount != 0)
		{
			vectorOfBirds.at(birdIndex)->transform.position.x = -newPosition.x;
			vectorOfBirds.at(birdIndex)->transform.position.z = newPosition.y;
		}
	}
}

void Catapult::GainControlOfBird()
{
	if (Input::GetMouseState(0) == DOWN)
	{
		if (birdCount != 0)
		{
			vectorOfBirds.at(birdIndex)->SetIsInCatapult(true);
			vectorOfBirds.at(birdIndex)->SetIsCurrentBird(true);
		}
	}

	else
	{
		vectorOfBirds.at(birdIndex)->SetIsInCatapult(false);
	}
}

void Catapult::FireBird()
{
	if (birdCount != 0)
	{
		if ((vectorOfBirds.at(birdIndex)->GetIsInCatapult() == false) && (vectorOfBirds.at(birdIndex)->GetIsCurrentBird() == true))
		{
			//Set rigidbody position
			b2Vec2 newB2Position;
			newB2Position.x = Physics2D::PixelsToBox2DMeters(-newPosition.x);
			newB2Position.y = Physics2D::PixelsToBox2DMeters(newPosition.y);
			
			vectorOfBirds.at(birdIndex)->SetRigidBodyPosition(newB2Position);


			//Add impulse
			glm::vec2 impulseVector;
			float magnitude = Transform::GetDistance2D(basePosition, newPosition);
			Utility::Print(magnitude);

			impulseVector.x = (basePosition.x + newPosition.x) * 0.06f;
			impulseVector.y = (magnitude) * 0.06f;

			



			//impulseVector.x = 
			vectorOfBirds.at(birdIndex)->ApplyImpulse(impulseVector);

			vectorOfBirds.at(birdIndex)->SetIsCurrentBird(false);
			
			
		}
	}
}