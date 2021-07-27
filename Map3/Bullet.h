#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	virtual void Initialize()override { strKey = "Bullet"; }
public:
	Bullet() {}
	virtual ~Bullet() {}
};

