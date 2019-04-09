#include "Physics2D.h"
#include "Destructable.h"
#include "PhysicsBody2D.h"
#include "Utility.h"

void PhysicsContactListener::BeginContact(b2Contact * contact)
{
	float birdMomentum;

	// Check if the first object is a Bird
	auto contactData = contact->GetFixtureA()->GetBody()->GetUserData();
	if (contactData) 
	{ 
		birdMomentum = static_cast<PhysicsBody2D*>(contactData)->GetRigidBody()->GetMass() * 
			static_cast<PhysicsBody2D*>(contactData)->GetRigidBody()->GetLinearVelocity().Length();

		
	}

	// If the second object is destructable
	contactData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (contactData)
	{
		// Check if the momentum of the bird object is bigger than a threshold (set inside the object)
		auto destructableBody = static_cast<PhysicsBody2D*>(contactData);

		if (destructableBody->IsDestructable())
		{
			Utility::Print(birdMomentum);
			// If it is destroy it - Otherwise do nothing
			if (destroyThreshold < birdMomentum)
			{
				
				// int i = 0;
				auto* destructableObject = static_cast<Destructable*>(destructableBody->GetOwner());
				objectsToDisable.push_back(destructableObject);
				destructableObject->ReadyDestruction(true);
			}
		}

		
	}
}

void PhysicsContactListener::EndContact(b2Contact* contact)
{
	////check if fixture A was a Destructable obj
	//auto contactData = contact->GetFixtureA()->GetBody()->GetUserData();
	//if (contactData) //{/*Do nothing*/}
	//{
	//	auto destructableBody = static_cast<PhysicsBody2D*>(contactData);

	//	if (destructableBody->IsDestructable())
	//	{
	//		if (destructableBody->GetRigidBody()->IsActive())
	//		{
	//			static_cast<Destructable*>(destructableBody->GetOwner())->DestroyObject();
	//		}
	//		
	//	}
	//}

	////check if fixture B was a Destructable obj
	///*auto contactData = contact->GetFixtureB()->GetBody()->GetUserData();
	//if (contactData)
	//{
	//	auto destructableBody = static_cast<PhysicsBody2D*>(contactData);

	//	if (destructableBody->IsDestructable())
	//	{
	//		if (destructableBody->GetRigidBody()->IsActive())
	//		{
	//			static_cast<Destructable*>(destructableBody->GetOwner())->DestroyObject();
	//		}
	//		
	//	}
	//}*/
}

std::vector<Destructable*> * PhysicsContactListener::GetObjectsToDisable()
{
	return &objectsToDisable;
}

