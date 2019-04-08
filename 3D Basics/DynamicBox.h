#pragma once
#include "GameObject.h"

class Mesh2D_Quad;

class DynamicBox :
	public GameObject
{
public:
	DynamicBox(Camera * mainCamera);
	virtual ~DynamicBox();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

private:
	Mesh2D_Quad * mesh = NULL;
};

