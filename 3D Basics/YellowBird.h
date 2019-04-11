#pragma once
#include "Physics2D.h"
#include "Bird.h"

class YellowBird: public Bird
{
public:
	YellowBird(Camera * mainCamera);
	virtual ~YellowBird();

	virtual void Initialise() override;
	virtual void Update(float deltaTime) override;

protected:
	glm::vec2 testVector = glm::vec2(-3000.0f, 60.0f);

	bool hasFired = false;

};

