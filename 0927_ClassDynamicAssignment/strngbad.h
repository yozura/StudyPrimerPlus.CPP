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
	// 생성자와 기타 메서드
	StringBad(const StringBad& st); // 복사 생성자
	StringBad(const char* s); // 생성자
	StringBad(); // 디폴트 생성자
	~StringBad();
	int length() const { return len; }
	// 오버로딩 연산자 메서드
	StringBad& operator=(const StringBad& st);
	StringBad& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;
	// 오버로딩 연산자 프렌드
	friend bool operator<(const StringBad& st1, const StringBad& st2);
	friend bool operator>(const StringBad& st1, const StringBad& st2);
	friend bool operator==(const StringBad& st1, const StringBad& st2);
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
	friend std::istream& operator>>(std::istream& os, StringBad& st);
	// static 함수
	static int HowMany();
};

#endif