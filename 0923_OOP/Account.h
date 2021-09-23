#pragma once
#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>

class Account
{
private:
	std::string name;
	std::string acctNum;
	double balance;
public:
	Account(const std::string& client, const std::string& num, double bal = 0.0);
	~Account();
	void show() const;
	void deposit(double cash);
	void withdraw(double cash);
};

#endif

