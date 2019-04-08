#pragma once
#include "GameObject.h"

class Mesh2D_Quad;


class Ground :
	public GameObject
{
public:
	Ground(Camera * mainCamera);
	virtual ~Ground();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

	float GetTopOfGround();

private:
	Mesh2D_Quad * mesh = NULL;
};

