#pragma once
#include "GameObject.h"
#include "Physics2D.h"
#include "RopePoint.h"

class Physics2D_Circle;
class Mesh2D_Quad;
class AudioSound;


class RopeJoint: public GameObject
{
public:
	RopeJoint(Camera * mainCamera);
	virtual ~RopeJoint();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

private:
	//Mesh2D_Quad * mesh = NULL;

	RopePoint * ropePoint1 = NULL;
	RopePoint * ropePoint2 = NULL;

	b2DistanceJointDef distanceJointDef;
};

 