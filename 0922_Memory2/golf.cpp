#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include "golf.h"

void setgolf(golf& g, const char* name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	std::cout << "이름을 입력하세요: ";
	std::cin >> g.fullname;

	std::cout << "핸디캡을 입력하세요: ";
	std::cin >> g.handicap;
	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	std::cout << "이름: " << g.fullname << std::endl;
	std::cout << "핸디캡: " << g.handicap << std::endl;
}