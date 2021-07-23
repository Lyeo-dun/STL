#include <iostream>
#include <list>
#include <vector>
#include <map> //std namespace�� ������ ����� �Ұ��� > ������ �ٿ��ٰ�!
#include <string>

using namespace std;//���� ���� ����

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
	���� Ʈ�� ����
	�ϳ��� �θ��尡 �� �� 2������ �ڽĳ�带 ����
	����⼺�� ����

	���ÿ����� �����ʹ� ���� �ӵ��� �����͸� ã�Ƴ� > ��� ��ġ�� �� �� �� ������ ��� ������ ����
	
	���� ������ ��Ģ�� �־ ���� �ӵ��� �����͸� ã�Ƴ� �� ����
	new�� ������ ������ �ƴ� �� ������ �����͸� ����
	List�� �׷� ��ġ�� �������ִ� ��, ������ ������ �ƴ�
	
	����Ʈ�� ���� ����: ��ǻ�� �ǵ���� �����Ͱ� �� �ڸ��� ���̱� ������ ã�� �ӵ��� ����
	ã�� �ӵ��� ���� ������ ������ ������ �� �ϳ��� ã�´ٰ� �� �� 
	���͸� �̿��� �� ��� �ε����� ����ϸ� ã�� �� ����
	����Ʈ�� �̿��Ͽ� ã�´ٰ� �����Ѵٸ� ������ ����Ʈ�� ũ�⸸ŭ ���ƾ���
	���� �̿��Ѵٸ� ã�� �� n�� <n< �� �������� �����ϰ� �ֱ� ������ ��Ģ�� �̿��Ͽ� ã���� ��ġ�� �̹�
	�������ֱ� ������ �ݹ� �����Ϳ� ���� ������

	���� ������ ���� �� ���������� �׿�����
	�ڷḦ ã�� �� ȿ�����̱� ������ ���� ���� ��. 
	������ ������ ��ġ�� ���� �����Ͱ� �־���ϱ� ������ ��Ģ�� ���� �񱳸� ���� ������ �����Ͱ� �����ؾ���. 
	���������� �����͸� ���� �� ����.

	���� ���� Ʈ�� ������ ���ʺ��� �����Ͱ� �ڸ��ؾ���. ������ ��ġ�� ������� ��Ģ�� �°� ��� ����

	Map���� ��� �ѹ� �����͸� �������� ���� ����. ���� �ʿ� ���÷� �����͸� �ִ� ��찡 ���� �ѹ��� �־�ΰ� ����ϰ� ��
	*/

	/*
	//iter ����
	int Array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* pi = Array;

	cout << *(pi + 5) << endl; 
	*/

	/*list<int> liNumberList;
	vector<int> vecNumberList;*/

	//map<int, string> NumberList;//key���� �̿��Ͽ� ���ϰ�, key���� �����Ͽ� ���� ������
	////<���ϴ� ��, ���� ����ϴ� ��>

	//NumberList.insert(make_pair(1, "aaa"));
	//NumberList.insert(make_pair(2, "bbb"));
	//NumberList.insert(make_pair(3, "ccc"));
	//NumberList.insert(make_pair(4, "ddd"));
	//NumberList.insert(make_pair(5, "eee"));
	//NumberList.insert(make_pair(6, "fff"));

	/*
	//������ �����̱� ������ ���� �ִ� �����͸� ����
	NumberList.insert(make_pair(1, "rrr"));
	NumberList.insert(make_pair(2, "eee"));
	NumberList.insert(make_pair(3, "sss"));
	NumberList.insert(make_pair(4, "www"));
	NumberList.insert(make_pair(5, "qqq"));
	NumberList.insert(make_pair(6, "hhh")); 
	*/

	/*
	//������� ����, ������ �����Ͱ� ��� ���ư�
	NumberList[1] = "rrr";
	NumberList[2] = "eee";
	NumberList[3] = "sss";
	NumberList[4] = "www";
	NumberList[5] = "qqq";
	NumberList[6] = "hhh"; 
	*/
	//���� �������� ����ϴ� ��� ���忡�� ����. ��Ȳ�� ���� �´� ������ ����!
	
	//���� � ������� ���α׷��� ��������Ŀ� ���� ���α׷��� �򰡰� �޶��� �� ����

	//for (map<int, string>::iterator iter = NumberList.begin(); iter != NumberList.end(); ++iter)
	//	//iter�� ������ ������ �ƴϱ� ������ ������ ���� �������� �������δ� ��� �� �� ����
	//	//iter�� ��ġ�� ����Ŵ. ���� ��ġ�� ���ؾ��ϹǷ� �� ��ġ���� �ƴ����� �񱳸� �ؾ���
	//	//�����Ϳ��� ++�� ���� �ּ��� ���� �ּ� ��ġ�� �̵��Ѵٴ� �ǹ�
	//{
	//	cout << (*iter).first << ". " << (*iter).second << endl;
	//}

	/*
	map<int, string>::iterator iter = NumberList.find(3);

	cout << iter->second << endl;
	*/



	//�ǽ�
	/*
	�� �����̳ʿ� �����͸� �߰��Ͽ� �Ʒ��ʿ��� ��Ȱ�� ��µ� �� �ֵ��� �Ѵ�.

	1. ȫ�浿
	�������� : 1
	�������� : 2
	�������� : 3

	2. �Ӳ���
	�������� : 10
	�������� : 20
	�������� : 30

	3. �̸���
	�������� : 100
	�������� : 200
	�������� : 300

	*/

	map<int, StudentInfo*> StudentList;
	StudentList.insert(make_pair(1, new StudentInfo("ȫ�浿", 1, 2, 3)));
	StudentList.insert(make_pair(2, new StudentInfo("�Ӳ���", 10, 20, 30)));
	StudentList.insert(make_pair(3, new StudentInfo("�̸���", 100, 200, 300)));

	for (map<int, StudentInfo*>::iterator iter = StudentList.begin(); iter != StudentList.end(); ++iter)
	{
		cout << (*iter).first << ". " << (*iter).second->GetName() << endl;
		cout << "���� ����: " << (*iter).second->GetKor() << endl;
		cout << "���� ����: " << (*iter).second->GetEng() << endl;
		cout << "���� ����: " << (*iter).second->GetMath() << endl << endl;
	}

	//���� ����: 
	//map ���� �� mutimap ���
	//git �����

	return 0;
}