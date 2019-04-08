#pragma once
#include "GameObject.h"
#include "Physics2D.h"

class Physics2D_Circle;
class Mesh2D_Quad;

class Bird:
	 public GameObject
{
public:
	Bird(Camera * mainCamera);
	~Bird();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime);

	virtual void ApplyImpulse(glm::vec2& impulseVector);

	virtual void SetIsInCatapult(bool isInCatapult);
	virtual bool GetIsInCatapult();

	virtual void SetIsCurrentBird(bool currentBird);
	virtual bool GetIsCurrentBird();

	virtual b2Vec2 GetRigidBodyPosition();
	virtual void SetRigidBodyPosition(b2Vec2 position);



protected:
	Mesh2D_Quad * mesh = NULL;
	Physics2D_Circle * physicsBody = NULL;
	glm::vec2 testVector = glm::vec2(8.0f, 10.0f);

	bool inCatapult = false;
	bool currentBird = false;
};

