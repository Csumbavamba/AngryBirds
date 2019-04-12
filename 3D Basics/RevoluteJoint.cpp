#include "RevoluteJoint.h"
#include "WheelJoint.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"



RevoluteJoint::RevoluteJoint(Camera* mainCamera)
{
	this->camera = mainCamera;
	point1 = new RopePoint(mainCamera, "Sprites/Fluff.png");
	point2 = new RopePoint(mainCamera, "Sprites/Plane.png");
}

RevoluteJoint::~RevoluteJoint()
{
	delete point1;
	delete point2;
}

void RevoluteJoint::Initialise()
{
	point1->transform.position.x -= 100;
	point1->transform.position.y -= 1.0f;
	point1->transform.scale *= 5;
	point2   ->transform.scale *= 5;
	point1->transform.rotation.y = 90;
	point1->Initialise(b2_staticBody);
	point2->Initialise(b2_dynamicBody);

	revoluteJointDef.Initialize(point1->GetPhysicsBody(), point2->GetPhysicsBody(), point1->GetPhysicsBody()->GetPosition());

	point1->GetPhysicsBody()->GetWorld()->CreateJoint(&revoluteJointDef);
}

void RevoluteJoint::Render(GLuint program)
{
	if (isActive)
	{
		point1->GetMesh()->Render(camera, program);
		point2->GetMesh()->Render(camera, program);
		
		
	}
	
}

void RevoluteJoint::Update(float deltaTime)
{
	if (isActive)
	{
		point1->Update(deltaTime);
		point2->Update(deltaTime);

		//transform.position.z = 300.0f;
	}
}

void RevoluteJoint::SetIsActive(bool isActive)
{
	this->isActive = isActive;

	// Set the Physics as well - if there is physics added
	if (physicsBody)
		SetPhysicsEnabled(isActive);

	if (point1->GetPhysicsBody())
		point1->SetPhysicsEnabled(isActive);

	if (point2->GetPhysicsBody())
		point2->SetPhysicsEnabled(isActive);
}

void RevoluteJoint::SetPhysicsEnabled(bool isPhysicsEnabled)
{
	this->isPhysicsEnabled = isPhysicsEnabled;

	// Enable/Disable the rigidBody
	physicsBody->GetRigidBody()->SetActive(isPhysicsEnabled);
	point1->GetPhysicsBody()->SetActive(isPhysicsEnabled);
	point2->GetPhysicsBody()->SetActive(isPhysicsEnabled);
}
