#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

struct Vector3
{
	float x, y, z;

	Vector3():x(0), y(0), z(0) {}

	Vector3(float _x, float _y)	:x(_x), y(_y), z(0) {}

	Vector3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {}
};

struct Transform
{
	Vector3 Position;
};

//�߻� Ŭ����
class Object 
{
protected:
	Transform Info;
	string strKey;
public:
	virtual void Initialize() = 0;
	virtual void Output() { cout << strKey << endl; }
	virtual string GetKey() { return strKey; }
public:
	Object() {}
	virtual ~Object() {}
};

//����� Ŭ������
class Player : public Object
{
public:
	virtual void Initialize() { strKey = "Player"; }
public:
	Player() {}
	virtual ~Player() {}
};

class Enemy : public Object
{
public:
	virtual void Initialize() { strKey = "Enemy"; }
public:
	Enemy() {}
	virtual ~Enemy() {}
};

class Bullet : public Object
{
public:
	virtual void Initialize() { strKey = "Bullet"; }
public:
	Bullet() {}
	virtual ~Bullet() {}
};

map<string, list<Object*>> ObjectList;

template<typename T>
Object* CreateObeject();

void AddObject(Object* _pObj);

int main(void)
{
	//ObjectList.insert(make_pair());
	AddObject(CreateObeject<Player>()); //������� ���ø��� �̷� ���·� ���� ����
	
	AddObject(CreateObeject<Bullet>());
	AddObject(CreateObeject<Bullet>());
	AddObject(CreateObeject<Bullet>());

	AddObject(CreateObeject<Enemy>());
	AddObject(CreateObeject<Enemy>());
	AddObject(CreateObeject<Enemy>());
	AddObject(CreateObeject<Enemy>());

	//����ϱ�
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Output();
		}
		cout << endl;
	}

	//

	return 0;
}

template<typename T>
Object* CreateObeject()
{
	//�ʱ�ȭ�� �����Ϸ��� �̷� ������� �ڵ带 �ۼ��ؾ��Ѵ�.
	Object* pObj = new T; 

	//... Initialize
	pObj->Initialize();

	return pObj;
}

void AddObject(Object* _pObj)
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