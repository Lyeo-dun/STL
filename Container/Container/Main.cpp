#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>

using namespace std;


struct Info
{
	char* Name;
	int iKor;
	int iEng;
	int iMath;
	int Number;
};

/*
class Object
{
public:
	Object() {}
	virtual ~Object() {}
};

class Student : public Object
{
public:
	Student() {}
	virtual ~Student() {}
};
*/




vector<Info*> StudentList;
int Count = 0;

Info* CreateInfo();
char* SetName();
void Initialize(Info* _tInfo);
void AddStudent();
void DeleteStudent();



int main(void)
{
	while (true)
	{
		system("cls");

		cout << "1. 학생 정보 추가" << endl;
		cout << "2. 학생 정보 변경" << endl;
		cout << "3. 학생 정보 삭제" << endl;
		cout << "4. 학생 정보 전체 출력" << endl;
		cout << "5. 종료" << endl;


		int Choice = 0;

		cout << "입력 : "; cin >> Choice;

		system("cls");

		switch (Choice)
		{
		case 1:
			AddStudent();
			break;

		case 2:
		{
			int n = 0;
			cout << "변경할 학생의 번호: ";
			cin >> n;
			//** 학생 정보를 찾아 전달해줘야 함.
			for (vector<Info*>::iterator iter = StudentList.begin();
				iter != StudentList.end(); ++iter)
			{
				if ((*iter)->Number == n)
				{
					Initialize(*iter);
				}
			}
		}
		break;

		case 3:
			DeleteStudent();
			break;

		case 4:
			for (vector<Info*>::iterator iter = StudentList.begin();
				iter != StudentList.end(); ++iter)
			{
				cout << (*iter)->Number << ". " << (*iter)->Name << endl;
				cout << "국어 점수 : " << (*iter)->iKor << endl;
				cout << "영어 점수 : " << (*iter)->iEng << endl;
				cout << "수학 점수 : " << (*iter)->iMath << endl << endl;
			}

			break;

		case 5:
			exit(NULL);
			break;
		}

		system("pause");
	}

	return 0;
}

Info* CreateInfo()
{
	Info* tInfo;

	tInfo = new Info;
	tInfo->Number = Count + 1;

	return tInfo;
}

char* SetName()
{
	cout << "학생 이름 입력 : ";

	char buffer[128] = "";
	cin >> buffer;

	char* pName = new char[strlen(buffer)];
	strcpy(pName, buffer);

	return pName;
}

void Initialize(Info* _tInfo)
{
	_tInfo->Name = SetName();

	cout << "국어 점수 입력 : ";
	cin >> _tInfo->iKor;

	cout << "영어 점수 입력 : ";
	cin >> _tInfo->iEng;

	cout << "수학 점수 입력 : ";
	cin >> _tInfo->iMath;
}


void AddStudent()
{
	cout << "** 학생 정보 추가 **" << endl << endl;

	Info* tInfo = CreateInfo();
	Initialize(tInfo);

	++Count;
	StudentList.push_back(tInfo);
}


void DeleteStudent()
{
	cout << "** 학생 정보 삭제 **" << endl << endl;

	if (Count == 1)
	{
		StudentList.clear();
		Count = 0;
	}
	else
	{
		int n = 0;
		cout << "학생 번호 입력 : ";
		cin >> n;

		for (vector<Info*>::iterator iter = StudentList.begin();
			iter != StudentList.end(); )
		{
			if ((*iter)->Number == n)
				iter = StudentList.erase(iter);
			else
				++iter;
		}

		/*
		for (vector<Info>::iterator iter = StudentList.begin() ;
				iter != StudentList.end() ; ++iter)
		{
			if ((*iter).Index == n)
			{
				for (vector<Info>::iterator iter2 = StudentList.begin();
					iter2 != StudentList.end(); ++iter2)
				{
					(*iter2).Name = (iter2 + 1)->Name;
					(*iter2).iKor = (iter2 + 1)->iKor;
					(*iter2).iEng = (iter2 + 1)->iEng;
					(*iter2).iMath = (iter2 + 1)->iMath;
					(*iter2).Index = (iter2 + 1)->Index;
				}
				--Count;
				break;
			}
		}
		*/
	}
}
