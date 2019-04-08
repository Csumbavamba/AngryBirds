#pragma once
#include "Physics2D.h"
#include "Bird.h"

class BigBird : public Bird
{
public:
	BigBird(Camera * mainCamera);
	virtual ~BigBird();

	virtual void Initialise() override;
	virtual void Update(float deltaTime) override;

	virtual void ApplyImpulse(glm::vec2& impulseVector);

};
