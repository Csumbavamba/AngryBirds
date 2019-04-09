#pragma once
#include "Destructable.h"

class Mesh2D_Quad;

class Pig :
	public Destructable
{
public:
	Pig(Camera * camera);
	virtual ~Pig();

	virtual void Initialise() override;
	virtual void DestroyObject() override;

};

