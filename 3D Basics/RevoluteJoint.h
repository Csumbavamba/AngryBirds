#pragma once
#include "GameObject.h"
#include "Physics2D.h"
#include "RopePoint.h"

class Physics2D_Circle;
class Mesh2D_Quad;
class AudioSound;


class RevoluteJoint : public GameObject
{
public:
	RevoluteJoint(Camera * mainCamera);
	virtual ~RevoluteJoint();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

	virtual void SetIsActive(bool isActive) override;
	virtual void SetPhysicsEnabled(bool isPhysicsEnabled) override;

private:

	RopePoint * point1 = NULL;
	RopePoint * point2 = NULL;

	b2RevoluteJointDef revoluteJointDef;
};

