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

//추상 클래스
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

//사용할 클래스들
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
	AddObject(CreateObeject<Player>()); //어딜가도 템플릿은 이런 형태로 많이 사용됨
	
	AddObject(CreateObeject<Bullet>());
	AddObject(CreateObeject<Bullet>());
	AddObject(CreateObeject<Bullet>());

	AddObject(CreateObeject<Enemy>());
	AddObject(CreateObeject<Enemy>());
	AddObject(CreateObeject<Enemy>());
	AddObject(CreateObeject<Enemy>());

	//출력하기
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
	//초기화를 진행하려면 이런 방식으로 코드를 작성해야한다.
	Object* pObj = new T; 

	//... Initialize
	pObj->Initialize();

	return pObj;
}

void AddObject(Object* _pObj)
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