#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Plorg.h"

Plorg::Plorg(const char* str, int val)
{
	strcpy(name, str);
	ci = val;
}

void Plorg::setCI(int val)
{
	ci = val;
}

void Plorg::showPlorg() const
{
	std::cout << "Plorg�� �̸� : " << name << '\n';
	std::cout << name << "�� CI : " << ci << '\n';
}
