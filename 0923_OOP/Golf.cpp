#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Golf.h"

Golf::Golf()
{
	using namespace std;
	
	cout << "�̸��� �Է��Ͻʽÿ�: ";
	cin >> fullname;
	cout << "�ڵ�ĸ�� �Է��Ͻʽÿ�: ";
	cin >> handicap;

	Golf(fullname, handicap);
}

Golf::Golf(const char* name, int hc)
{
	strcpy(fullname, name);
	handicap = hc;
}

void Golf::showgolf() const
{
	std::cout << "�̸�: " << fullname << '\n';
	std::cout << "�ڵ�ĸ: " << handicap << '\n';
}
