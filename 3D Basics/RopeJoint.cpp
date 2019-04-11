#include "RopeJoint.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"
#include "Input.h"
#include "AudioSound.h"
#include "AudioEngine.h"


RopeJoint::RopeJoint(Camera * mainCamera)
{
	this->camera = mainCamera;
	//mesh = new Mesh2D_Quad(this);
	ropePoint1 = new RopePoint(mainCamera, "Sprites/Rope.png");
	ropePoint2 = new RopePoint(mainCamera, "Sprites/Pig.png");
}


RopeJoint::~RopeJoint()
{
}

void RopeJoint::Initialise()
{

	ropePoint1->transform.position.x -= 100;
	ropePoint1->transform.scale *= 5;
	ropePoint1->transform.rotation.y = 90;
	//mesh->Initialise();
	ropePoint1->Initialise(b2_staticBody);
	ropePoint2->Initialise(b2_dynamicBody);

	distanceJointDef.Initialize(ropePoint1->GetPhysicsBody(), ropePoint2->GetPhysicsBody(), ropePoint1->GetPhysicsBody()->GetPosition(), ropePoint2->GetPhysicsBody()->GetPosition());
	//physicsBody1->GetRigidBody().
	ropePoint1->GetPhysicsBody()->GetWorld()->CreateJoint(&distanceJointDef);
	
}

void RopeJoint::Render(GLuint program)
{
	//mesh->Render(this->camera, program);
	ropePoint1->GetMesh()->Render(camera, program);
	ropePoint2->GetMesh()->Render(camera, program);
}

void RopeJoint::Update(float deltaTime)
{
	//mesh->Update();
	ropePoint1->Update(deltaTime);
	ropePoint2->Update(deltaTime);
}
