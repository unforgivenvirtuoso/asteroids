#include "GameObject.h"
#include "PowerUp.h"
#include <stdlib.h>
#include "BoundingShape.h"
#include "BoundingSphere.h"
#include "Bullet.h"
#include "Alien.h"
#include "GameUtil.h"
#include "Spaceship.h"


Alien::Alien(void) : GameObject("Alien") {

	mAngle = 180;
	mRotation = 0;
	mPosition.x = rand() /2;
	mPosition.y = rand() /2;
	mPosition.z = 0.0;
	mVelocity.x = 10.0 * cos(DEG2RAD*mAngle);
	mVelocity.y = 10.0 * cos(DEG2RAD*mAngle);
	mVelocity.z = 0.0;
}

Alien::~Alien(void){

}
bool Alien::CollisionTest(shared_ptr<GameObject> o) {
	
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());

}

void Alien::OnCollision(const GameObjectList& objects) {
	for (auto object : objects) {
		if (object->GetType() == GameObjectType("Bullet") || object->GetType() == GameObjectType("Spaceship")) {
			mWorld->FlagForRemoval(GetThisPtr());
		}
	}
}

void Alien::Shoot(shared_ptr<GameObject> o) {

	
		auto SpaceshipPos = o->GetPosition();

		GLVector3f difference = SpaceshipPos - mPosition;
		GLVector3f spaceship_shooting = difference;
		spaceship_shooting.normalize();
		GLVector3f bullet_position = mPosition + (spaceship_shooting * 10);

		float bullet_speed = 20;

		GLVector3f bullet_velocity = mVelocity + spaceship_shooting * bullet_speed;
		shared_ptr<GameObject> bullet
		(new Bullet(bullet_position, bullet_velocity, mAcceleration, rand() % 120, 0, 2000));
		bullet->SetBoundingShape(make_shared<BoundingSphere>(bullet->GetThisPtr(), 2.0f));
		bullet->SetShape(mBulletShape);

		mWorld->AddObject(bullet);
	

}

void Alien::Update(int t) {

	GameObject::Update(t);
}

