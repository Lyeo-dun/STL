#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = NULL;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::Update()
{
}

void ObjectManager::AddObject(Object* _pObj)
{
	//전달 받은 매개변수의 키값 확인
	//find로 찾은 값이 end가 될 경우 map안에는 해당 키 값이 없는 상태를 의미한다.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_pObj->GetKey());

	//만약 존재하지 않는다면
	if (iter == ObjectList.end())
	{
		list<Object*> tmpList; //map에 넣을 리스트
		tmpList.push_back(_pObj); // 생성되 리스트에 전달받은 오브젝트 추가
		ObjectList.insert(make_pair(_pObj->GetKey(), tmpList));
		//오브젝트를 추가한 리스트를 오브젝트의 키값으로 map에 추가
	}
	else
	{
		iter->second.push_back(_pObj);
		//이미 있다면 동일한 키값에 존재하는 리스트에 값을 바로 추가한다
	}
}

void ObjectManager::Render()
{
	//출력하기
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Output();
		}
		cout << endl;
	}
}

void ObjectManager::Release()
{
	//출력하기
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			delete (*iter2);
			(*iter2) = NULL;
		}
		(*iter).second.clear();
	}
	ObjectList.clear();
}

