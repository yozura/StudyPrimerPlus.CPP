#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow()
{
	strcpy(name, "default");
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy(name, nm);
	int len = strlen(ho);
	hobby = new char[len + 1];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy(name, c.name);
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	// �ڱ� �ڽſ� ���������� ���⼭ ����
	if (this == &c)
		return *this;
	delete[] hobby;
	
	strcpy(name, c.name);
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

void Cow::ShowCow() const
{
	using std::cout;
	cout << "�̸�: " << name << ", ���: " << hobby << ", ������: " << weight << '\n';
}