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
		cout << "���� �̸��� �Է��Ͻʽÿ�: ";
		getline(cin, temp);
		cout << "���� ���� ��ȣ�� �Է��Ͻʽÿ�: ";
		cin >> tempnum;
		cout << "���� ���� �ܾ��� �Է��Ͻʽÿ�: ";
		cin >> tempbal;
		cout << "Brass ���´� 1, BrassPlus ���´� 2�� �Է��Ͻʽÿ�: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "1�ƴϸ� 2, ���� �ϳ��� �Է��Ͻʽÿ�: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "���� ��� �ѵ��� �Է��Ͻʽÿ�: $";
			cin >> tmax;
			cout << "���� ��� �������� �Ҽ��� �������� �Է��Ͻʽÿ�: ";
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
		cout << "���� �̸��� �Է��Ͻʽÿ�: ";
		getline(cin, temp);
		cout << "���� ���� ��ȣ�� �Է��Ͻʽÿ�: ";
		cin >> tempnum;
		cout << "���� ���� �ܾ��� �Է��Ͻʽÿ�: ";
		cin >> tempbal;
		cout << "Brass ���´� 1, BrassPlus ���´� 2�� �Է��Ͻʽÿ�: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "1�ƴϸ� 2, ���� �ϳ��� �Է��Ͻʽÿ�: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "���� ��� �ѵ��� �Է��Ͻʽÿ�: $";
			cin >> tmax;
			cout << "���� ��� �������� �Ҽ��� �������� �Է��Ͻʽÿ�: ";
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
	cout << "Hogg ���� ���¿� $1000 �Ա�:\n";
	Hoggy.Deposit(1000.00);
	cout << "Hogg ���� ���� �ܾ�: $" << Hoggy.Balance() << endl;
	cout << "Pigg ���� ���¿��� $4200 ����:\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg ���� ���� �ܾ�: $" << Piggy.Balance() << endl;
	cout << "Hogg ���� ���¿��� $4200 ����:\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
}