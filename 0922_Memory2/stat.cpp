#include <iostream>
#include <string>

using std::string;

void strcount(const string str);
void stringco();

void stringco()
{
	using namespace std;

	string input;

	cout << "영문으로 한 행을 입력하십시오:\n";
	getline(cin, input);
	while (input != "")
	{
		strcount(input);
		cout << "다음 행을 입력하십시오(끝내려면 빈 행을 입력):\n";
		getline(cin, input);
	}

	cout << "프로그램을 종료합니다.\n";
}

void strcount(const string str)
{
	using namespace std;
	static int total = 0;

	cout << "\"" << str << "\"에는 ";
	cout << str.size() << "개의 문자가 있습니다.\n";
	total += str.size();
	cout << "지금까지 총 " << total << "개의 문자를 입력하셨습니다.\n";
}
