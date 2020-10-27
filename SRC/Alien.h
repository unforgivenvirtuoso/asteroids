#pragma once

#include "GameObject.h"
#include "PowerUp.h"
#include <stdlib.h>
#include "BoundingShape.h"
#include "BoundingSphere.h"
#include "Bullet.h"
#include "Shape.h"

class Alien : public GameObject {

public:
	Alien(void);
	~Alien(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);

	void Shoot(shared_ptr<GameObject> o);
	void Update(int i);

	void SetBulletShape(shared_ptr<Shape> bullet_shape) {
		mBulletShape = bullet_shape;
	}

	shared_ptr<Shape> mBulletShape;
	shared_ptr<GameObject> bullet;
	

	int mRandom;
};