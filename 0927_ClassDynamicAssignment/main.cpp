#include <iostream>
#include "strngbad.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	StringBad name;
	cout << "안녕하십니까? 성함이 어떻게 되십니까?\n";
	cin >> name;

	cout << name << " 씨! 간단한 영어 속담 " << ArSize << "개만 입력해주십시오(끝내려면 Enter):\n";
	StringBad sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		// 입력이 올바르고 개행문자가 아닌 경우 입력 스트림을 비워준다.
		while (cin && cin.get() != '\n')
			continue;
		// 입력이 실패했거나 빈 줄 입력일 경우 탈주
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp; // 속담 배열에 temp를 추가한다.
	}
	int total = i;
	if (total > 0)
	{
		cout << "(다음과 같은 속담들을 입력하셨습니다.)\n";
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;

		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}
		cout << "가장 짧은 속담:\n" << sayings[shortest] << endl;
		cout << "사전순으로 가장 앞에 나오는 속담:\n" << sayings[first] << endl;
		cout << "이 프로그램은 " << StringBad::HowMany() << "개의 StringBad 객체를 사용하였습니다. 이상!\n";
	}
	else
		cout << "입력 금지! 이상.\n";

	return 0;
}

void callme1(StringBad& rsb)
{
	using std::cout;
	cout << "참조로 전달된 StringBad:\n";
	cout << "      \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	using std::cout;
	cout << "값으로 전달된 StringBad:\n";
	cout << "      \"" << sb << "\"\n";
}

void testingstr()
{
	using std::cout;
	using std::endl;
	{
		cout << "내부 블록을 시작한다.\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;
		cout << "하나의 객체를 다른 객체로 초기화:\n";
		StringBad sailor = sports;
		cout << "Sailor: " << sailor << endl;
		cout << "하나의 객체를 다른 객체에 대입:\n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "이 블록을 빠져나온다.\n";
	}
	cout << "main()의 끝";
}
