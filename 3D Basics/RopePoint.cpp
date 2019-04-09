#include "RopePoint.h"
#include "Mesh2D_Quad.h"
#include "PhysicsBody2D.h"
#include "Texture.h"
#include "Input.h"
#include "AudioSound.h"
#include "AudioEngine.h"


RopePoint::RopePoint(Camera * mainCamera, std::string filePath)
{
	this->camera = mainCamera;
	mesh = new Mesh2D_Quad(this);
	physicsBody = new PhysicsBody2D(this);
	this->filePath = filePath;
	
}


RopePoint::~RopePoint()
{
	delete mesh;
	mesh = NULL;

	delete physicsBody;
	physicsBody = NULL;
}

void RopePoint::Initialise(b2BodyType type)
{
	mesh->GetTexture()->SetTexturePath(filePath);
	mesh->Initialise();
	physicsBody->AddRigidBody(type);
	physicsBody->AddCircleCollider();
}

void RopePoint::Render(GLuint program)
{
	mesh->Render(camera, program);
}

void RopePoint::Update(float deltaTime)
{
	mesh->Update();

	physicsBody->Update();
}

Mesh2D_Quad * RopePoint::GetMesh()
{
	return mesh;
}

b2Body* RopePoint::GetPhysicsBody()
{
	return physicsBody->GetRigidBody();
}
