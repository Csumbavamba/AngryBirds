#include "GameObject.h"
#include "Camera.h"
#include "Physics2D.h"
#include "Utility.h"


GameObject::GameObject()
{
	isActive = true;
	isPhysicsEnabled = true; // TODO set this to false by default

	// TODO See if this works
	if (Utility::GetGameMode() == GAMEMODE_2D)
	{
		transform.scale *= Physics2D::Box2DMetersToPixels(1.0f);
	}
	
}
GameObject::~GameObject()
{
}

void GameObject::Initialise()
{
}


void GameObject::SetCamera(Camera * camera)
{
	this->camera = camera;
}

void GameObject::SetIsActive(bool isActive)
{
	this->isActive = isActive;
}

bool GameObject::IsActive() const
{
	return isActive;
}

bool GameObject::IsPhysicsEnabled() const
{
	return isPhysicsEnabled;
}

void GameObject::SetPhysicsEnabled(bool isPhysicsEnabled)
{
	this->isPhysicsEnabled = isPhysicsEnabled;
}
