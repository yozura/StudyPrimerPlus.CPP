#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

#include "strngbad.h"
using std::cout;

int StringBad::num_strings = 0;

int StringBad::HowMany()
{
	return num_strings;
}

StringBad::StringBad(const StringBad& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

StringBad::StringBad()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

StringBad::~StringBad()
{
	--num_strings;
	delete[] str;
}

StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

StringBad& StringBad::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char& StringBad::operator[](int i)
{
	return str[i];
}

const char& StringBad::operator[](int i) const
{
	return str[i];
}

bool operator<(const StringBad& st1, const StringBad& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const StringBad& st1, const StringBad& st2)
{
	return st2 < st1;
}

bool operator==(const StringBad& st1, const StringBad& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}

std::istream& operator>>(std::istream& is, StringBad& st)
{
	char temp[StringBad::CINLIM];
	is.get(temp, StringBad::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;

	return is;
}
