#pragma once
#include "Object.h"

template<typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		//�ʱ�ȭ�� �����Ϸ��� �̷� ������� �ڵ带 �ۼ��ؾ��Ѵ�.
		Object* pObj = new T;
	
		//... Initialize
		pObj->Initialize();
	
		return pObj;
	}
};