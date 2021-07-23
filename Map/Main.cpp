#include <iostream>
#include <list>
#include <vector>
#include <map> //std namespace가 없으면 사용이 불가능 > 무조건 붙여줄것!
#include <string>

using namespace std;//절대 잊지 말것

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
	/*
	이진 트리 구조
	하나의 부모노드가 두 개 2이하의 자식노드를 가짐
	양방향성을 가짐

	스택영역의 데이터는 빠른 속도로 데이터를 찾아냄 > 어디에 위치할 지 알 수 없지만 어떻게 생길지 보임
	
	힙은 정해진 규칙이 있어서 빠른 속도로 데이터를 찾아낼 수 있음
	new는 스택의 영역이 아닌 힙 영역에 데이터를 놓음
	List는 그런 위치를 가르쳐주는 것, 데이터 저장이 아님
	
	이진트리 구조 장점: 컴퓨터 의도대로 데이터가 그 자리에 놓이기 때문에 찾는 속도가 빠름
	찾는 속도가 빠른 이유는 수많은 데이터 중 하나를 찾는다고 할 때 
	벡터를 이용할 시 계속 인덱스를 기억하며 찾을 수 없다
	리스트를 이용하여 찾는다고 가정한다면 무조건 리스트의 크기만큼 돌아야함
	힙을 이용한다면 찾는 값 n이 <n< 의 기준으로 존재하고 있기 때문에 규칙을 이용하여 찾으면 위치가 이미
	정해져있기 때문에 금방 데이터에 접근 가능함

	힙은 옆으로 봤을 때 순차적으로 쌓여있음
	자료를 찾을 때 효율적이기 때문에 많이 쓰게 됨. 
	하지만 정해진 위치에 의해 데이터가 있어야하기 때문에 규칙에 의한 비교를 위해 무조건 데이터가 존재해야함. 
	막무가내로 데이터를 넣을 수 없음.

	완전 이진 트리 구조는 왼쪽부터 데이터가 자리해야함. 정해진 위치에 들어가기까지 규칙에 맞게 계속 비교함

	Map같은 경우 한번 데이터를 넣으려면 쉽지 않음. 따라서 맵에 수시로 데이터를 넣는 경우가 없고 한번에 넣어두고 사용하게 됨
	*/

	/*
	//iter 개념
	int Array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* pi = Array;

	cout << *(pi + 5) << endl; 
	*/

	/*list<int> liNumberList;
	vector<int> vecNumberList;*/

	//map<int, string> NumberList;//key값을 이용하여 비교하고, key값을 지정하여 값을 저장함
	////<비교하는 값, 실제 사용하는 값>

	//NumberList.insert(make_pair(1, "aaa"));
	//NumberList.insert(make_pair(2, "bbb"));
	//NumberList.insert(make_pair(3, "ccc"));
	//NumberList.insert(make_pair(4, "ddd"));
	//NumberList.insert(make_pair(5, "eee"));
	//NumberList.insert(make_pair(6, "fff"));

	/*
	//삽입의 개념이기 때문에 원래 있던 데이터를 존중
	NumberList.insert(make_pair(1, "rrr"));
	NumberList.insert(make_pair(2, "eee"));
	NumberList.insert(make_pair(3, "sss"));
	NumberList.insert(make_pair(4, "www"));
	NumberList.insert(make_pair(5, "qqq"));
	NumberList.insert(make_pair(6, "hhh")); 
	*/

	/*
	//덮어쓰기의 개념, 기존의 데이터가 모두 날아감
	NumberList[1] = "rrr";
	NumberList[2] = "eee";
	NumberList[3] = "sss";
	NumberList[4] = "www";
	NumberList[5] = "qqq";
	NumberList[6] = "hhh"; 
	*/
	//무얼 쓰는지는 사용하는 사람 입장에서 갈림. 상황에 따라 맞는 것으로 쓰기!
	
	//누가 어떤 방식으로 프로그램을 만들었느냐에 따라 프로그램의 평가가 달라질 수 있음

	//for (map<int, string>::iterator iter = NumberList.begin(); iter != NumberList.end(); ++iter)
	//	//iter는 정수의 개념이 아니기 때문에 작은가 작지 않은가의 개념으로는 제어를 할 수 없음
	//	//iter는 위치를 가르킴. 따라서 위치로 비교해야하므로 그 위치인지 아닌지로 비교를 해야함
	//	//포인터에서 ++는 현재 주소의 다음 주소 위치로 이동한다는 의미
	//{
	//	cout << (*iter).first << ". " << (*iter).second << endl;
	//}

	/*
	map<int, string>::iterator iter = NumberList.find(3);

	cout << iter->second << endl;
	*/



	//실습
	/*
	위 컨테이너에 데이터를 추가하여 아래쪽에서 원활히 출력될 수 있도록 한다.

	1. 홍길동
	국어점수 : 1
	영어점수 : 2
	수학점수 : 3

	2. 임꺽정
	국어점수 : 10
	영어점수 : 20
	수학점수 : 30

	3. 이몽룡
	국어점수 : 100
	영어점수 : 200
	수학점수 : 300

	*/

	map<int, StudentInfo*> StudentList;
	StudentList.insert(make_pair(1, new StudentInfo("홍길동", 1, 2, 3)));
	StudentList.insert(make_pair(2, new StudentInfo("임꺽정", 10, 20, 30)));
	StudentList.insert(make_pair(3, new StudentInfo("이몽룡", 100, 200, 300)));

	for (map<int, StudentInfo*>::iterator iter = StudentList.begin(); iter != StudentList.end(); ++iter)
	{
		cout << (*iter).first << ". " << (*iter).second->GetName() << endl;
		cout << "국어 점수: " << (*iter).second->GetKor() << endl;
		cout << "영어 점수: " << (*iter).second->GetEng() << endl;
		cout << "수학 점수: " << (*iter).second->GetMath() << endl << endl;
	}

	//내일 수업: 
	//map 응용 및 mutimap 사용
	//git 사용방법

	return 0;
}