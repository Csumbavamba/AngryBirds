#include "RevoluteJoint.h"
#include "WheelJoint.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"
#include "Input.h"
#include "AudioSound.h"
#include "AudioEngine.h"



RevoluteJoint::RevoluteJoint(Camera* mainCamera)
{
	this->camera = mainCamera;
	point1 = new RopePoint(mainCamera, "Sprites/Fluff.png");
	point2 = new RopePoint(mainCamera, "Sprites/Plane.png");
}

RevoluteJoint::~RevoluteJoint()
{
}

void RevoluteJoint::Initialise()
{
	point1->transform.position.x -= 100;
	point1->transform.scale *= 5;
	point2   ->transform.scale *= 5;
	point1->transform.rotation.y = 90;
	point1->Initialise(b2_dynamicBody);
	point2->Initialise(b2_dynamicBody);

	revoluteJointDef.Initialize(point1->GetPhysicsBody(), point2->GetPhysicsBody(), point1->GetPhysicsBody()->GetPosition());

	point1->GetPhysicsBody()->GetWorld()->CreateJoint(&revoluteJointDef);
}

void RevoluteJoint::Render(GLuint program)
{
	point1->GetMesh()->Render(camera, program);
	point2->GetMesh()->Render(camera, program);
}

void RevoluteJoint::Update(float deltaTime)
{
	point1->Update(deltaTime);
	point2->Update(deltaTime);
}
