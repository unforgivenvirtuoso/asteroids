#include <stdlib.h>
#include "GameUtil.h"
#include "PowerUp.h"
#include "BoundingShape.h"

PowerUp::PowerUp(void) : GameObject("PowerUp") {

	mAngle = 180;
	mRotation = 20;
	mPosition.x = 0;
	mPosition.y = 0;
	mPosition.z = 0.0;
	mVelocity.x = 2.0;
	mVelocity.y = 2.0;
	mVelocity.z = 0.0;

}


PowerUp::~PowerUp(void)
{
}

bool PowerUp::CollisionTest(shared_ptr<GameObject> o)
{
	if (GetType() == o->GetType())return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void PowerUp::OnCollision(const GameObjectList& objects)
{
	for (auto object : objects) {
		if (object->GetType() == GameObjectType("Spaceship")) {
			mWorld->FlagForRemoval(GetThisPtr());
		}
	}
}