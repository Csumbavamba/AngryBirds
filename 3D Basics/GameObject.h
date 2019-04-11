#pragma once

#include <string>

#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

#include "Transform.h"

class Camera;
class PhysicsBody2D;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialise();
	virtual void Render(GLuint program) = 0;
	virtual void Update(float deltaTime) {};

	void SetCamera(Camera * camera);
	
	virtual void SetIsActive(bool isActive);
	virtual bool IsActive() const;

	virtual bool IsPhysicsEnabled() const; // TODO see if its needed
	virtual void SetPhysicsEnabled(bool isPhysicsEnabled);

	PhysicsBody2D * GetPhysicsBody() const;

	Transform transform;

protected:
	Camera * camera = NULL;
	bool isActive;
	bool isPhysicsEnabled; // TODO - see if it is needed
	PhysicsBody2D * physicsBody = NULL;
};

