#include <iostream>
#include <string>

using std::string;

void strcount(const string str);
void stringco();

void stringco()
{
	using namespace std;

	string input;

	cout << "�������� �� ���� �Է��Ͻʽÿ�:\n";
	getline(cin, input);
	while (input != "")
	{
		strcount(input);
		cout << "���� ���� �Է��Ͻʽÿ�(�������� �� ���� �Է�):\n";
		getline(cin, input);
	}

	cout << "���α׷��� �����մϴ�.\n";
}

void strcount(const string str)
{
	using namespace std;
	static int total = 0;

	cout << "\"" << str << "\"���� ";
	cout << str.size() << "���� ���ڰ� �ֽ��ϴ�.\n";
	total += str.size();
	cout << "���ݱ��� �� " << total << "���� ���ڸ� �Է��ϼ̽��ϴ�.\n";
}
