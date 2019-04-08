#pragma once
#include "Physics2D.h"
#include "Bird.h"

class YellowBird: public Bird
{
public:
	YellowBird(Camera * mainCamera);
	~YellowBird();

	virtual void Initialise() override;
	virtual void Update(float deltaTime);

protected:
	glm::vec2 testVector = glm::vec2(-50.0f, 1.0f);

	bool hasFired = false;

};

