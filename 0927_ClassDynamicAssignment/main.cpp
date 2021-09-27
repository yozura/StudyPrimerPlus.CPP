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
	cout << "�ȳ��Ͻʴϱ�? ������ ��� �ǽʴϱ�?\n";
	cin >> name;

	cout << name << " ��! ������ ���� �Ӵ� " << ArSize << "���� �Է����ֽʽÿ�(�������� Enter):\n";
	StringBad sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		// �Է��� �ùٸ��� ���๮�ڰ� �ƴ� ��� �Է� ��Ʈ���� ����ش�.
		while (cin && cin.get() != '\n')
			continue;
		// �Է��� �����߰ų� �� �� �Է��� ��� Ż��
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp; // �Ӵ� �迭�� temp�� �߰��Ѵ�.
	}
	int total = i;
	if (total > 0)
	{
		cout << "(������ ���� �Ӵ���� �Է��ϼ̽��ϴ�.)\n";
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
		cout << "���� ª�� �Ӵ�:\n" << sayings[shortest] << endl;
		cout << "���������� ���� �տ� ������ �Ӵ�:\n" << sayings[first] << endl;
		cout << "�� ���α׷��� " << StringBad::HowMany() << "���� StringBad ��ü�� ����Ͽ����ϴ�. �̻�!\n";
	}
	else
		cout << "�Է� ����! �̻�.\n";

	return 0;
}

void callme1(StringBad& rsb)
{
	using std::cout;
	cout << "������ ���޵� StringBad:\n";
	cout << "      \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	using std::cout;
	cout << "������ ���޵� StringBad:\n";
	cout << "      \"" << sb << "\"\n";
}

void testingstr()
{
	using std::cout;
	using std::endl;
	{
		cout << "���� ����� �����Ѵ�.\n";
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
		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ:\n";
		StringBad sailor = sports;
		cout << "Sailor: " << sailor << endl;
		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� ����:\n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "�� ����� �������´�.\n";
	}
	cout << "main()�� ��";
}
