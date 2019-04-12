#include "WheelJoint.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"
#include "Input.h"
#include "Pig.h"



WheelJoint::WheelJoint(Camera* mainCamera)
{
	this->camera = mainCamera;
	ropePoint1 = new RopePoint(mainCamera, "Sprites/Wheel.png");
	ropePoint2 = new RopePoint(mainCamera, "Sprites/Wheel.png");
}

WheelJoint::~WheelJoint()
{
	delete ropePoint1;
	delete ropePoint2;
}

void WheelJoint::Initialise()
{
	ropePoint1->transform.position.x += 200;
	ropePoint1->transform.scale *= 5;
	ropePoint1->transform.rotation.y = 90;
	ropePoint1->Initialise(b2_staticBody);
	ropePoint2->transform.position.x += 300;
	ropePoint2->Initialise(b2_dynamicBody);
	

	wheelJointDef.Initialize(ropePoint1->GetPhysicsBody(), ropePoint2->GetPhysicsBody(), ropePoint1->GetPhysicsBody()->GetPosition() );

	ropePoint1->GetPhysicsBody()->GetWorld()->CreateJoint(&wheelJointDef);
}

void WheelJoint::Render(GLuint program)
{
	if (isActive)
	{
		ropePoint1->GetMesh()->Render(camera, program);
		ropePoint2->Render(program);
	}
	
}

void WheelJoint::Update(float deltaTime)
{
	if (isActive)
	{
		ropePoint1->Update(deltaTime);
		ropePoint2->Update(deltaTime);
	}
}

void WheelJoint::SetIsActive(bool isActive)
{
	this->isActive = isActive;

	// Set the Physics as well - if there is physics added
	if (physicsBody)
		SetPhysicsEnabled(isActive);

	if (ropePoint1->GetPhysicsBody())
		ropePoint1->SetPhysicsEnabled(isActive);

	if (ropePoint2->GetPhysicsBody())
		ropePoint2->SetPhysicsEnabled(isActive);
}

void WheelJoint::SetPhysicsEnabled(bool isPhysicsEnabled)
{
	this->isPhysicsEnabled = isPhysicsEnabled;

	// Enable/Disable the rigidBody
	physicsBody->GetRigidBody()->SetActive(isPhysicsEnabled);
	ropePoint1->GetPhysicsBody()->SetActive(isPhysicsEnabled);
	ropePoint2->GetPhysicsBody()->SetActive(isPhysicsEnabled);
}
