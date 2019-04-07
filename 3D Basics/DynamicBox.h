#pragma once
#include "GameObject.h"

#include "Physics.h"

class Mesh2D_Quad;

class DynamicBox :
	public GameObject
{
public:
	DynamicBox(Camera * mainCamera);
	virtual ~DynamicBox();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime);

private:
	Mesh2D_Quad * mesh = NULL;
	b2Body * dynamicBody = NULL;
};

