#pragma once
#include "GameObject.h"

class Mesh2D_Quad;
class Physics2D_Box;


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
	Physics2D_Box * physicsBody = NULL;
};

