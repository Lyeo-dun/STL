#pragma once
#include "Object.h"

class Player : public Object
{
public:
	virtual void Initialize()override { strKey = "Player"; }
public:
	Player() {}
	virtual ~Player() {}
};

