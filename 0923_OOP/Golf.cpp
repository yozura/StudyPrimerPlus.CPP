#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Golf.h"

Golf::Golf()
{
	using namespace std;
	
	cout << "이름을 입력하십시오: ";
	cin >> fullname;
	cout << "핸디캡을 입력하십시오: ";
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
	std::cout << "이름: " << fullname << '\n';
	std::cout << "핸디캡: " << handicap << '\n';
}
