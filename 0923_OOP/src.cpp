#include <iostream>
#include <cctype>
#include "stack.h"
#include "stock20.h"
#include "Account.h"
#include "Person.h"
#include "Golf.h"
#include "Sales.h"
#include "Move.h"
#include "Plorg.h"

const int STKS = 4;

int main()
{
	{
		Plorg p1;
		Plorg p2("Florida");
		Plorg p3("Gamza", 18);
		
		p2.setCI(20);

		p1.showPlorg();
		p2.showPlorg();
		p3.showPlorg();
	}

	return 0;
}

void movestes()
{
	Move m1;
	Move m2(3, 3);
	Move m3(1);

	m1.showMove();
	m2.showMove();
	m3.showMove();

	m1.reset(2, 7);
	m1.showMove();

	Move m4 = m2.add(m1);
	m4.showMove();
}

void stacktest()
{
	{
		using namespace std;
		Stack st;
		char ch;
		customer c1;
		double total = 0;
		cout << "���� �ֹ��� �߰��Ϸ��� A, ���� �ֹ��� ó���Ϸ��� P,\n";
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
				cout << "�߰��� ���� �̸��� �Է��ϼ���: ";
				cin >> c1.fullname;
				cout << "�߰��� �ֹ��� �ݾ��� �Է��ϼ���: ";
				cin >> c1.payment;
				if (st.isfull())
					cout << "������ ���� �� �ֽ��ϴ�.\n";
				else
					st.push(c1);
				break;
			case 'P':
			case 'p':
				if (st.isempty())
					cout << "������ ��� �ֽ��ϴ�.\n";
				else
				{
					st.pop(c1);
					cout << "# " << c1.fullname << "������ $" << c1.payment << "�� �����߽��ϴ�. #\n";
					total += c1.payment;
					cout << "���� �� ����: " << total << '\n';
				}
				break;
			}

			cout << "���� �ֹ��� �߰��Ϸ��� A, ���� �ֹ��� ó���Ϸ��� P,\n";
			cout << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
		}

		cout << "���α׷��� �����մϴ�.\n";

	}
}

void saleid()
{
	{
		using namespace SALES;

		double ar[] = { 0, 1, 2, 3 };

		Sales s1;
		Sales s2(ar, 4);
		Sales s3(ar, 2);

		s1.showSales();
		s2.showSales();
		s3.showSales();
	}

}

void golfer()
{
	{
		Golf g1;
		Golf g2("GolfManager", 10);

		g1.showgolf();
		g2.showgolf();

		g1.setHandicap(3);
		g2.setHandicap(5);

		g1.showgolf();
		g2.showgolf();
	}
}

void perstest()
{
	{
		Person one;
		Person two("Smythecraft");
		Person three("Dimwiddy", "Sam");

		one.Show();
		std::cout << std::endl;
		one.FormalShow();
		std::cout << std::endl;
		two.Show();
		std::cout << std::endl;
		two.FormalShow();
		std::cout << std::endl;
		three.Show();
		std::cout << std::endl;
		three.FormalShow();
		std::cout << std::endl;
	}
}

void accttest()
{
	{
		Account acct1 = Account("Choi", "0104013792", 1.7);
		Account acct2("Gun", "00132132", 10.2);
		Account* pactt = &acct2;

		acct1.show();
		acct1.deposit(1.3);
		acct1.show();

		acct2.show();
		acct2.withdraw(5.2);
		acct2.show();

		pactt->show();
		pactt->deposit(2.0);
		pactt->show();

		acct1.show();
		acct2.show();
		pactt->show();
	}
}

void stacktest2()
{
	using namespace std;
	Stack st;
	char ch;
	customer po;
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
			cin >> po.payment;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "������ ��� �ֽ��ϴ�.\n";
			else
			{
				st.pop(po);
				cout << "#" << po.payment << " �ֹ����� ó���߽��ϴ�.\n";
			}
			break;
		}

		cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n";
		cout << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	}

	cout << "���α׷��� �����մϴ�.\n";

}

void tkn()
{
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.00),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "���� �ֽ� ����Ʈ:\n";
	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();

	const Stock* top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);

	std::cout << "\n�ְ� ��ġ�� �ֽ�:\n";
	top->show();

}

void crede()
{
	{
		using std::cout;
		cout << "�����ڸ� ����Ͽ� ���ο� ��ü���� �����Ѵ�.\n";
		Stock stock1("NanoSmart", 12, 20.0);
		stock1.show();
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);
		stock2.show();

		cout << "stock1�� stock2�� �����Ѵ�.\n";
		stock2 = stock1;
		cout << "stock1�� stock2�� ����Ѵ�.\n";
		stock1.show();
		stock2.show();

		cout << "�����ڸ� ����Ͽ� ��ü�� �缳���Ѵ�.\n";
		stock1 = Stock("Nifty Foods", 10, 50.0);
		cout << "���ŵ� stock1:\n";
		stock1.show();
		cout << "���α׷��� �����մϴ�.\n";
	}
}