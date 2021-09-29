#pragma once
#ifndef STRNG_H_
#define STRNG_H_
#include <iostream>
class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	// �����ڿ� ��Ÿ �޼���
	String(const String& st); // ���� ������
	String(const char* s); // ������
	String(); // ����Ʈ ������
	~String();
	int length() const { return len; }
	int has(char a);
	void stringlow();
	void stringup();
	// �����ε� ������ �޼���
	String& operator=(const String& st);
	String& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;
	// �����ε� ������ ������
	friend String operator+(const String& st1, const String& st2);
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend std::ostream& operator<<(std::ostream& os, const String& st);
	friend std::istream& operator>>(std::istream& os, String& st);
	// static �Լ�
	static int HowMany();
};
#endif