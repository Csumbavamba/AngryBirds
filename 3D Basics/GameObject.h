#pragma once

#include <string>

#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

#include "Transform.h"

class Camera;
class Collider_Sphere;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialise();
	virtual void Render(GLuint program) = 0;

	void SetCamera(Camera * camera);
	
	void SetIsActive(bool isActive);
	bool IsActive() const;

	bool IsPhysicsEnabled() const; // TODO see if its needed
	void SetPhysicsEnabled(bool isPhysicsEnabled);

	Transform transform;

protected:
	Camera * camera = NULL;
	bool isActive;
	bool isPhysicsEnabled;
	
};

