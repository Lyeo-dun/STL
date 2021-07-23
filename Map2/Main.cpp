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
	//게임마다 존재만 하는 것들을 맵에 저장함
	/*
	오브젝트 모음 단위로 관리를 하고 싶음
	이런 모음 단위를 묶어 통합된 하나의 데이터베이스를 만들어서 전체적으로 관리를 원함
	=> 오브젝트 매니저는 원래 그런 역할
	현재까지 사용한 형태는 오브젝트를 따로 만드는 형태
	map<학교명, 학생>
	이런 형태의 맵으로 쉽게 관리가 가능함
	*/

	/*map<string, list<StudentInfo>> StudentList;

	StudentList["A"].push_back(StudentInfo("aaa", 100, 200, 300));
	StudentList["A"].push_back(StudentInfo("bbb", 200, 400, 600));
	
	StudentList["B"].push_back(StudentInfo("ccc", 2, 4, 6));
	StudentList["B"].push_back(StudentInfo("ddd", 1, 2, 3));*/

	/*
	//전체 출력
	for (map<string, list<StudentInfo>>::iterator iter = StudentList.begin();iter != StudentList.end(); ++iter)
	{
		cout << iter->first << "학교 " << endl;
		for (list<StudentInfo>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			cout << iter2->GetName() << endl;
			cout << "국어 점수 : " << iter2->GetKor() << endl;
			cout << "영어 점수 : " << iter2->GetEng() << endl;
			cout << "수학 점수 : " << iter2->GetMath() << endl << endl;
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
		cout << "국어 점수 : " << iter2->GetKor() << endl;
		cout << "영어 점수 : " << iter2->GetEng() << endl;
		cout << "수학 점수 : " << iter2->GetMath() << endl << endl;
	}
	*/

	//실제 쓰임의 모양새
	//map<string, list<StudentInfo*>*>* StudentList;
	//map<string, list<StudentInfo*>*>::iterator iter = (*StudentList).begin();


	//multimap
	//동일한 키값으로 여러 개의 자료형을 저장할 수 있는 자료형
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

	//예시
	/*
	//유도탄이나 경우에 따라 적 역시 multimap을 씀
	player와 Enemy 사이의 거리를 키값으로 사용, enemy는 value로 들어감
	multimap<float, Object*> EnemyList;
	
	enemyList.begin(); 거리가 가장 가까운 것부터 부름	
	*/

	return 0;
}