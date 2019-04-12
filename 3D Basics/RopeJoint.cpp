#include "RopeJoint.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"
#include "Input.h"
#include "Pig.h"


RopeJoint::RopeJoint(Camera * mainCamera)
{
	this->camera = mainCamera;
	//mesh = new Mesh2D_Quad(this);
	ropePoint1 = new RopePoint(mainCamera, "Sprites/Rope.png");
	ropePoint2 = new Pig(mainCamera);
}


RopeJoint::~RopeJoint()
{
	delete ropePoint1;
	delete ropePoint2;
}

void RopeJoint::Initialise()
{

	ropePoint1->transform.position.x -= 100;
	ropePoint1->transform.scale *= 5;
	ropePoint1->transform.rotation.y = 90;
	//mesh->Initialise();
	ropePoint1->Initialise(b2_staticBody);
	ropePoint2->Initialise();

	distanceJointDef.Initialize(ropePoint1->GetPhysicsBody(), ropePoint2->GetPhysicsBody()->GetRigidBody(), ropePoint1->GetPhysicsBody()->GetPosition(), ropePoint2->GetPhysicsBody()->GetRigidBody()->GetPosition());
	//physicsBody1->GetRigidBody().
	ropePoint1->GetPhysicsBody()->GetWorld()->CreateJoint(&distanceJointDef);
	
}

void RopeJoint::Render(GLuint program)
{
	if (isActive)
	{
		//mesh->Render(this->camera, program);
		ropePoint1->GetMesh()->Render(camera, program);
		ropePoint2->Render(program);
	}
	
}

void RopeJoint::Update(float deltaTime)
{
	if (isActive)
	{
		//mesh->Update();
		ropePoint1->Update(deltaTime);
		ropePoint2->Update(deltaTime);
	}

	
}

void RopeJoint::SetIsActive(bool isActive)
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

void RopeJoint::SetPhysicsEnabled(bool isPhysicsEnabled)
{
	this->isPhysicsEnabled = isPhysicsEnabled;

	// Enable/Disable the rigidBody
	physicsBody->GetRigidBody()->SetActive(isPhysicsEnabled);
	ropePoint1->GetPhysicsBody()->SetActive(isPhysicsEnabled);
	ropePoint2->SetIsActive(isPhysicsEnabled);
}
