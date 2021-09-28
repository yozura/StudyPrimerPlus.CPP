#pragma once
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
class StringBad
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	// �����ڿ� ��Ÿ �޼���
	StringBad(const StringBad& st); // ���� ������
	StringBad(const char* s); // ������
	StringBad(); // ����Ʈ ������
	~StringBad();
	int length() const { return len; }
	// �����ε� ������ �޼���
	StringBad& operator=(const StringBad& st);
	StringBad& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;
	// �����ε� ������ ������
	friend bool operator<(const StringBad& st1, const StringBad& st2);
	friend bool operator>(const StringBad& st1, const StringBad& st2);
	friend bool operator==(const StringBad& st1, const StringBad& st2);
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
	friend std::istream& operator>>(std::istream& os, StringBad& st);
	// static �Լ�
	static int HowMany();
};

#endif