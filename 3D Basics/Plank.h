#pragma once
#include "GameObject.h"

class Mesh2D_Quad;

class Plank :
	public GameObject
{
public:
	Plank(Camera * mainCamera);
	virtual ~Plank();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

private:
	Mesh2D_Quad * mesh = NULL;
};

