#pragma once
#include "Destructable.h"
#include "Physics2D.h"

class Physics2D_Circle;
class Mesh2D_Quad;
class AudioSound;

class Bird:
	 public Destructable
{
public:
	Bird();
	Bird(Camera * mainCamera);
	virtual ~Bird();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

	virtual void ApplyImpulse(glm::vec2& impulseVector);

	virtual void SetIsInCatapult(bool isInCatapult);
	virtual bool GetIsInCatapult() const;

	virtual void SetIsCurrentBird(bool currentBird);
	virtual bool GetIsCurrentBird() const;

	virtual b2Vec2 GetRigidBodyPosition();
	virtual void SetRigidBodyPosition(b2Vec2 position);

	// Mass * Velocity
	virtual float GetMomentum();



protected:
	Mesh2D_Quad * mesh = NULL;
	glm::vec2 testVector = glm::vec2(-100.0f, 1.0f);

	bool inCatapult = false;
	bool currentBird = false;

	AudioSound * birdCry = NULL;
};

