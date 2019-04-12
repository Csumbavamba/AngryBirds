#pragma once
#include "GameObject.h"
#include "Physics2D.h"
#include "RopePoint.h"

class Physics2D_Circle;
class Mesh2D_Quad;
class Pig;


class RopeJoint: public GameObject
{
public:
	RopeJoint(Camera * mainCamera);
	virtual ~RopeJoint();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

	virtual void SetIsActive(bool isActive) override;
	virtual void SetPhysicsEnabled(bool isPhysicsEnabled) override;

private:
	//Mesh2D_Quad * mesh = NULL;

	RopePoint * ropePoint1 = NULL;
	Pig * ropePoint2 = NULL;

	b2DistanceJointDef distanceJointDef;
};

 