#pragma once
#include "Object.h"

template<typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		//초기화를 진행하려면 이런 방식으로 코드를 작성해야한다.
		Object* pObj = new T;
	
		//... Initialize
		pObj->Initialize();
	
		return pObj;
	}
};