#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "stock2.h"

using namespace std;

Stock::Stock() : company(nullptr), shares(0), share_val(0.0), total_val(0.0)
{	
}

Stock::Stock(const char* co, long n, double pr)
{
	int len = strlen(co);
	company = new char[len + 1];
	strcpy(company, co);

	if (n < 0)
	{
		cout << "�ֽ� ���� ������ �� �� �����Ƿ�, " << company << " shares�� 0���� �����մϴ�.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	delete[] company;
}

void Stock::buy(long num, double price)
{
	if (num < 0)
		cout << "���� �ֽ� ���� ������ �� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�.\n";
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
		cout << "�ŵ� �ֽ� ���� ������ �� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�.\n";
	else if (num > shares)
		cout << "���� �ֽĺ��� ���� �ֽ��� �ŵ��� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�.\n";
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

std::ostream& operator<<(std::ostream& os, const Stock& s1)
{
	using std::ios_base;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = cout.precision(3);
	os << "ȸ���: " << s1.company << ", �ֽ� ��: " << s1.shares << '\n';
	cout.precision(2);
	os << "�ְ�: $" << s1.share_val << ", �ֽ� �� ����: $" << s1.total_val << '\n';
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
	return os;
}
