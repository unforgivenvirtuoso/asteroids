#pragma once

#include "GameObject.h"

class PowerUp : public GameObject
{
public:
	PowerUp(void);
	~PowerUp(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);

};