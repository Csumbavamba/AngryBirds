#pragma once
#pragma once
#include "GameObject.h"
#include "Physics2D.h"
#include <string.h>
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"

class Physics2D_Circle;
class AudioSound;

class RopePoint : public GameObject
{
public:
	RopePoint(Camera * mainCamera, std::string filePath);
	virtual ~RopePoint();
	
	virtual void Initialise(b2BodyType type);
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

	virtual Mesh2D_Quad * GetMesh();

	virtual b2Body* GetPhysicsBody();

protected:
	Mesh2D_Quad * mesh = NULL;
	std::string filePath;
};

