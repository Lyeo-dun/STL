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
	list<Object*>* GetList(string _strKey) {
		map<string, list<Object*>>::iterator iter = ObjectList.find("_strKey");

		if (iter == ObjectList.end())
			return NULL;

		return &iter->second;
	}

	void Update();
	void Render();
	void Release();
public:
	~ObjectManager();

private:
	ObjectManager();
};

