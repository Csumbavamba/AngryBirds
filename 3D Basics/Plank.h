#pragma once
#include "Destructable.h"

class Mesh2D_Quad;

class Plank :
	public Destructable
{
public:
	Plank(Camera * mainCamera);
	virtual ~Plank();

	virtual void Initialise() override;
	virtual void DestroyObject() override;
};

