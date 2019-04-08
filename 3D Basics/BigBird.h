#pragma once
#include "Physics2D.h"
#include "Bird.h"

class BigBird : public Bird
{
public:
	BigBird(Camera * mainCamera);
	~BigBird();

	virtual void Initialise() override;
	virtual void Update(float deltaTime);

	virtual void ApplyImpulse(glm::vec2& impulseVector);

};
