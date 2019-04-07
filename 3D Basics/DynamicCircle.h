#pragma once
#include "GameObject.h"

class Physics2D_Circle;
class Mesh2D_Quad;

class DynamicCircle :
	public GameObject
{
public:
	DynamicCircle(Camera * mainCamera);
	virtual ~DynamicCircle();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime);

private:
	Mesh2D_Quad * mesh = NULL;
	Physics2D_Circle * physicsBody = NULL;
};

