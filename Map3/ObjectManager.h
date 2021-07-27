#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;

public:
	static ObjectManager* GetInstance() {
		if (Instance == NULL)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	map<string, list<Object*>> ObjectList;

public:
	void AddObject(Object* _pObj);
	void Update();
	void Render();
	void Release();
public:
	~ObjectManager();

private:
	ObjectManager();
};

