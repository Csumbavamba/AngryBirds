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
	void GainControlOfBird();
	void FireBird();

private:
	Mesh2D_Quad * mesh = NULL;

	int birdIndex; //Current bird that is being interacted with
	int birdCount; 
	std::vector<Bird*> vectorOfBirds;

	float maximumPullDistance = -220;
	float maximumPullHeight = -100;

	glm::vec2 newPosition;

	glm::vec2 basePosition = glm::vec2(-240, -120);
		
	//glm::vec2 

};

