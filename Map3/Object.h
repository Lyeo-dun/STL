#pragma once
#include "Headers.h"

//�߻� Ŭ����
class Object
{
protected:
	Transform Info;
	string strKey;

public:
	virtual void Initialize() = 0;

public:
	virtual string GetKey() { return strKey; }
	virtual void Output() { cout << strKey << endl; }

public:
	Object();
	virtual ~Object();
};

