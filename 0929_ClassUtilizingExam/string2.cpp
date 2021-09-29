#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cctype>
#include "string2.h"

using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::~String()
{
	--num_strings;
	delete[] str;
}

int String::has(char a)
{
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == a)
			cnt++;
	}

	return cnt;
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

String operator+(const String& st1, const String& st2)
{
	int tlen = st1.len + st2.len;
	char* tstr = new char[tlen + 1];
	std::strcpy(tstr, st1.str);
	std::strcat(tstr, st2.str);
	String temp(tstr);
	return temp;
}

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;

	return is;
}
