#include "WheelJoint.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"
#include "Input.h"
#include "AudioSound.h"
#include "AudioEngine.h"



WheelJoint::WheelJoint(Camera* mainCamera)
{
	this->camera = mainCamera;
	ropePoint1 = new RopePoint(mainCamera, "Sprites/Wheel.png");
	ropePoint2 = new RopePoint(mainCamera, "Sprites/Pig.png");
}

WheelJoint::~WheelJoint()
{
}

void WheelJoint::Initialise()
{
	ropePoint1->transform.position.x -= 100;
	ropePoint1->transform.scale *= 5;
	ropePoint1->transform.rotation.y = 90;
	ropePoint1->Initialise(b2_dynamicBody);
	ropePoint2->Initialise(b2_dynamicBody);

	wheelJointDef.Initialize(ropePoint1->GetPhysicsBody(), ropePoint2->GetPhysicsBody(), ropePoint1->GetPhysicsBody()->GetPosition());

	ropePoint1->GetPhysicsBody()->GetWorld()->CreateJoint(&wheelJointDef);
}

void WheelJoint::Render(GLuint program)
{
	ropePoint1->GetMesh()->Render(camera, program);
	ropePoint2->GetMesh()->Render(camera, program);
}

void WheelJoint::Update(float deltaTime)
{
	ropePoint1->Update(deltaTime);
	ropePoint2->Update(deltaTime);
}
