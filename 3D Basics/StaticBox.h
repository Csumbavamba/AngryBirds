#pragma once
#include "GameObject.h"

class Mesh2D_Quad;


class StaticBox :
	public GameObject
{
public:
	StaticBox(Camera * mainCamera);
	virtual ~StaticBox();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime);

private:
	Mesh2D_Quad * mesh = NULL;
};

