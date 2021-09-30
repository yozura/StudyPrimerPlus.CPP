#include <iostream>
#include <string>
#include "brass.h"

const int CLIENTS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	AcctABC* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "고객의 이름을 입력하십시오: ";
		getline(cin, temp);
		cout << "고객의 계좌 번호를 입력하십시오: ";
		cin >> tempnum;
		cout << "계좌 개설 잔액을 입력하십시오: ";
		cin >> tempbal;
		cout << "Brass 계좌는 1, BrassPlus 계좌는 2를 입력하십시오: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "1아니면 2, 둘중 하나를 입력하십시오: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "당좌 대월 한도를 입력하십시오: $";
			cin >> tmax;
			cout << "당좌 대월 이자율을 소수점 형식으로 입력하십시오: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
		delete p_clients[i];

	return 0;
}

void usebrass2()
{
	using std::cin;
	using std::cout;
	using std::endl;

	AcctABC* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "고객의 이름을 입력하십시오: ";
		getline(cin, temp);
		cout << "고객의 계좌 번호를 입력하십시오: ";
		cin >> tempnum;
		cout << "계좌 개설 잔액을 입력하십시오: ";
		cin >> tempbal;
		cout << "Brass 계좌는 1, BrassPlus 계좌는 2를 입력하십시오: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "1아니면 2, 둘중 하나를 입력하십시오: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "당좌 대월 한도를 입력하십시오: $";
			cin >> tmax;
			cout << "당좌 대월 이자율을 소수점 형식으로 입력하십시오: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
		delete p_clients[i];
}

void usebrass1()
{
	using std::cout;
	using std::endl;

	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Hogg 씨의 계좌에 $1000 입금:\n";
	Hoggy.Deposit(1000.00);
	cout << "Hogg 씨의 현재 잔액: $" << Hoggy.Balance() << endl;
	cout << "Pigg 씨의 계좌에서 $4200 인출:\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg 씨의 현재 잔액: $" << Piggy.Balance() << endl;
	cout << "Hogg 씨의 계좌에서 $4200 인출:\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
}