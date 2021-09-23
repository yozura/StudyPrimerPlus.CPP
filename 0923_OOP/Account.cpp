#include <iostream>
#include "Account.h"

Account::Account(const std::string& client, const std::string& num, double bal)
{
	name = client;
	acctNum = num;
	balance = bal;
}

Account::~Account()
{
}

void Account::show() const
{
	using std::cout;
	using std::ios_base;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "예금주: " << name << '\n';
	cout << "계좌번호: " << acctNum << '\n';
	cout.precision(2);
	cout << "잔액: $" << balance << '\n';

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

void Account::deposit(double cash)
{
	if (cash > 0)
		balance += cash;
	else
		std::cout << "입금하려는 금액이 음수입니다.\n";
}

void Account::withdraw(double cash)
{
	if (balance >= cash)
		balance -= cash;
	else
		std::cout << "잔액이 부족합니다.\n";
}
