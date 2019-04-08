#pragma once
#include "GameObject.h"
#include "Bird.h"
#include <vector>

class Catapult: public GameObject
{
public:
	Catapult(Camera * mainCamera);
	~Catapult();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime);
	
	void AddBird(Bird* bird);

	void UpdateBirdPosition();

private:
	Mesh2D_Quad * mesh = NULL;

	int birdIndex; //Current bird that is being interacted with
	int birdCount; 
	std::vector<Bird*> vectorOfBirds;


};

