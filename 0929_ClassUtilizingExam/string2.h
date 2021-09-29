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
	// 생성자와 기타 메서드
	String(const String& st); // 복사 생성자
	String(const char* s); // 생성자
	String(); // 디폴트 생성자
	~String();
	int length() const { return len; }
	int has(char a);
	void stringlow();
	void stringup();
	// 오버로딩 연산자 메서드
	String& operator=(const String& st);
	String& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;
	// 오버로딩 연산자 프렌드
	friend String operator+(const String& st1, const String& st2);
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend std::ostream& operator<<(std::ostream& os, const String& st);
	friend std::istream& operator>>(std::istream& os, String& st);
	// static 함수
	static int HowMany();
};
#endif