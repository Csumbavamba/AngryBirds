#include "Catapult.h"
#include "Input.h"
#include "Mesh2D_Quad.h"
#include "Physics2D_Circle.h"
#include "Texture.h"
#include "Input.h"


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

	

}

void Catapult::AddBird(Bird * bird)
{
	vectorOfBirds.push_back(bird);
}

void Catapult::UpdateBirdPosition()
{
	glm::vec2 newPosition = Input::GetMousePosition();
	for (bird)

}
