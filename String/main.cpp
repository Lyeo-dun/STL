#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str1 = "Hello";
	//���ڿ��� ���尡��
	//�����̳� ������ �ƴ�
	
	string str2 = "World!!";

	string str3 = str1 + " " + str2;

	cout << str3 << endl;
	str3.clear();

	str3 = to_string(100);
	cout << str3 << endl;
	cout << endl;

	char* Buffer = (char*)"\nwow!!";

	str3 += Buffer;
	cout << str3 << endl;

	return 0;
}