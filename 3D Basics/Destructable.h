#pragma once
#include "GameObject.h"

class Mesh2D_Quad;

class Destructable :
	public GameObject
{
public:
	Destructable();
	virtual ~Destructable();

	virtual void Initialise() = 0;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

	virtual void ReadyDestruction(bool isReady);
	virtual void DestroyObject();

protected:
	Mesh2D_Quad * mesh = NULL;
	bool isReadyToDie;
};

