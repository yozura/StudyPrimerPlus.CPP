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
	cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P,\n";
	cout << "종료하려면 Q를 입력하십시오.\n";
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
			cout << "추가할 주문서의 번호를 입력하십시오: ";
			cin >> po;
			if (st.isfull())
				cout << "스택이 가득 차 있습니다.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "스택이 비어있습니다.\n";
			else
			{
				st.pop(po);
				cout << "#" << po << " 주문서를 처리했습니다.\n";
			}
			break;
		}
		cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P,\n";
		cout << "종료하려면 Q를 입력하십시오.\n";
	}
	cout << "프로그램을 종료합니다.\n";
}

void toktest()
{
	Stock stocks[STKS] = {
	Stock("NanoSmart", 12, 20.0),
	Stock("Boffo Objects", 200, 2.0),
	Stock("Monolithic Obelisks", 130, 3.25),
	Stock("Fleep Enterprises", 60, 6.5)
	};

	cout << "보유 주식 리스트:\n";
	int st;
	for (st = 0; st < STKS; st++)
		cout << stocks[st];

	const Stock* top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);

	cout << "\n최고 가치의 주식:\n" << *top;
}

void strtest()
{
	String s1(" and I am a C++ student.");
	String s2 = "영문 이름을 입력하십시오: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	cout << "다음 문자열에는\n" << s2 << "\n문자 'A'가 " << s2.has('A') << "개 들어 있습니다.\n";
	s1 = "red";
	String rgb[3] = { String(s1), String("green"), String("blue") };
	cout << "빛의 삼원색의 이름을 하나만 입력하십시오: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i])
			{
				cout << "맞았습니다!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "다시 입력하십시오: ";
	}
	cout << "프로그램을 종료합니다.\n";
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