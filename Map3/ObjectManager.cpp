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
	//���� ���� �Ű������� Ű�� Ȯ��
	//find�� ã�� ���� end�� �� ��� map�ȿ��� �ش� Ű ���� ���� ���¸� �ǹ��Ѵ�.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_pObj->GetKey());

	//���� �������� �ʴ´ٸ�
	if (iter == ObjectList.end())
	{
		list<Object*> tmpList; //map�� ���� ����Ʈ
		tmpList.push_back(_pObj); // ������ ����Ʈ�� ���޹��� ������Ʈ �߰�
		ObjectList.insert(make_pair(_pObj->GetKey(), tmpList));
		//������Ʈ�� �߰��� ����Ʈ�� ������Ʈ�� Ű������ map�� �߰�
	}
	else
	{
		iter->second.push_back(_pObj);
		//�̹� �ִٸ� ������ Ű���� �����ϴ� ����Ʈ�� ���� �ٷ� �߰��Ѵ�
	}
}

void ObjectManager::Render()
{
	//����ϱ�
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
	//����ϱ�
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

