#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Person.h"

Person::Person(const string& ln, const char* fn)
{
	lname = ln;
	strcpy(fname, fn);
}

void Person::Show() const
{
	std::cout << fname << " " << lname << '\n';
}

void Person::FormalShow() const
{
	std::cout << lname << ", " << fname << '\n';
}
