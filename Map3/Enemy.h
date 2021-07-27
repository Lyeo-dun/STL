#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	virtual void Initialize()override { strKey = "Enemy"; }
public:
	Enemy() {}
	virtual ~Enemy() {}
};

