#include <iostream>
#include "cow.h"
#include "string2.h"
#include "stock2.h"
#include "stack2.h"

using namespace std;

const int STKS = 4;

int main()
{
	
	return 0;
}

void stacktest()
{
	Stack st;
	char ch;
	unsigned long po;
	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n";
	cout << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;

		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}

		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�: ";
			cin >> po;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "������ ����ֽ��ϴ�.\n";
			else
			{
				st.pop(po);
				cout << "#" << po << " �ֹ����� ó���߽��ϴ�.\n";
			}
			break;
		}
		cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n";
		cout << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	}
	cout << "���α׷��� �����մϴ�.\n";
}

void toktest()
{
	Stock stocks[STKS] = {
	Stock("NanoSmart", 12, 20.0),
	Stock("Boffo Objects", 200, 2.0),
	Stock("Monolithic Obelisks", 130, 3.25),
	Stock("Fleep Enterprises", 60, 6.5)
	};

	cout << "���� �ֽ� ����Ʈ:\n";
	int st;
	for (st = 0; st < STKS; st++)
		cout << stocks[st];

	const Stock* top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);

	cout << "\n�ְ� ��ġ�� �ֽ�:\n" << *top;
}

void strtest()
{
	String s1(" and I am a C++ student.");
	String s2 = "���� �̸��� �Է��Ͻʽÿ�: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	cout << "���� ���ڿ�����\n" << s2 << "\n���� 'A'�� " << s2.has('A') << "�� ��� �ֽ��ϴ�.\n";
	s1 = "red";
	String rgb[3] = { String(s1), String("green"), String("blue") };
	cout << "���� ������� �̸��� �ϳ��� �Է��Ͻʽÿ�: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i])
			{
				cout << "�¾ҽ��ϴ�!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "�ٽ� �Է��Ͻʽÿ�: ";
	}
	cout << "���α׷��� �����մϴ�.\n";
}

void cowtest()
{
	Cow c1;
	Cow c2("Choi", "Computer", 99);
	Cow c3("Gun", "Kautus", 50);
	Cow c4("Amiya", "Rodes", 39);

	c1 = c3;

	c1.ShowCow();
	c2.ShowCow();
	c3.ShowCow();
	c4.ShowCow();
}