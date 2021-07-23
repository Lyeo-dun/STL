#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>

using namespace std;

class StudentInfo
{
	string Name;
	int Kor;
	int Eng;
	int Math;

public:
	StudentInfo(string _name, int _kor, int _eng, int _math)
		:Name(_name), Kor(_kor), Eng(_eng), Math(_math)
	{}
	~StudentInfo() {}

public:
	void SetName(const string& _name) { Name = _name; }
	string GetName() const { return Name; }
	void SetKor(const int& _score) { Kor = _score; }
	int GetKor() const { return Kor; }
	void SetEng(const int& _score) { Eng = _score; }
	int GetEng() const { return Eng; }
	void SetMath(const int& _score) { Math = _score; }
	int GetMath() const { return Math; }

};

int main(void)
{
	//���Ӹ��� ���縸 �ϴ� �͵��� �ʿ� ������
	/*
	������Ʈ ���� ������ ������ �ϰ� ����
	�̷� ���� ������ ���� ���յ� �ϳ��� �����ͺ��̽��� ���� ��ü������ ������ ����
	=> ������Ʈ �Ŵ����� ���� �׷� ����
	������� ����� ���´� ������Ʈ�� ���� ����� ����
	map<�б���, �л�>
	�̷� ������ ������ ���� ������ ������
	*/

	/*map<string, list<StudentInfo>> StudentList;

	StudentList["A"].push_back(StudentInfo("aaa", 100, 200, 300));
	StudentList["A"].push_back(StudentInfo("bbb", 200, 400, 600));
	
	StudentList["B"].push_back(StudentInfo("ccc", 2, 4, 6));
	StudentList["B"].push_back(StudentInfo("ddd", 1, 2, 3));*/

	/*
	//��ü ���
	for (map<string, list<StudentInfo>>::iterator iter = StudentList.begin();iter != StudentList.end(); ++iter)
	{
		cout << iter->first << "�б� " << endl;
		for (list<StudentInfo>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			cout << iter2->GetName() << endl;
			cout << "���� ���� : " << iter2->GetKor() << endl;
			cout << "���� ���� : " << iter2->GetEng() << endl;
			cout << "���� ���� : " << iter2->GetMath() << endl << endl;
		}
		cout << endl << endl;
	}
	*/


	/*
	//search
	map<string, list<StudentInfo>>::iterator iter = StudentList.find("A");

	for (list<StudentInfo>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
	{
		cout << iter2->GetName() << endl;
		cout << "���� ���� : " << iter2->GetKor() << endl;
		cout << "���� ���� : " << iter2->GetEng() << endl;
		cout << "���� ���� : " << iter2->GetMath() << endl << endl;
	}
	*/

	//���� ������ ����
	//map<string, list<StudentInfo*>*>* StudentList;
	//map<string, list<StudentInfo*>*>::iterator iter = (*StudentList).begin();


	//multimap
	//������ Ű������ ���� ���� �ڷ����� ������ �� �ִ� �ڷ���
	/*
	multimap<string, int> StudentList;
	StudentList.insert(make_pair("AAA", 10));
	StudentList.insert(make_pair("AAA", 20));
	StudentList.insert(make_pair("AAA", 30));
	StudentList.insert(make_pair("AAA", 40));
	StudentList.insert(make_pair("AAA", 50)); 

	for (map<string, int>::iterator iter = StudentList.begin(); iter != StudentList.end(); ++iter)
	{
		cout << iter->first << ". " << iter->second << endl;
	}
	*/

	//����
	/*
	//����ź�̳� ��쿡 ���� �� ���� multimap�� ��
	player�� Enemy ������ �Ÿ��� Ű������ ���, enemy�� value�� ��
	multimap<float, Object*> EnemyList;
	
	enemyList.begin(); �Ÿ��� ���� ����� �ͺ��� �θ�	
	*/

	return 0;
}