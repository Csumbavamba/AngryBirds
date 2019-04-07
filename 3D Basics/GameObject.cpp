#include "GameObject.h"
#include "Camera.h"
#include "Physics.h"


GameObject::GameObject()
{
	isActive = true;
}
GameObject::~GameObject()
{
}

void GameObject::Initialise()
{
	if (camera->GetViewMode() == ORTOGRAPHIC)
	{
		transform.scale *= Physics::Box2DMetersToPixels(1.0f);
	}
}


void GameObject::SetCamera(Camera * camera)
{
	this->camera = camera;
}

void GameObject::SetActive(bool isActive)
{
	this->isActive = isActive;
}

bool GameObject::IsActive() const
{
	return isActive;
}
