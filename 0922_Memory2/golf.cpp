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
	std::cout << "�̸��� �Է��ϼ���: ";
	std::cin >> g.fullname;

	std::cout << "�ڵ�ĸ�� �Է��ϼ���: ";
	std::cin >> g.handicap;
	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	std::cout << "�̸�: " << g.fullname << std::endl;
	std::cout << "�ڵ�ĸ: " << g.handicap << std::endl;
}