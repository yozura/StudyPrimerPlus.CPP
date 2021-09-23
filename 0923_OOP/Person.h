#pragma once
#ifndef PERSON_H_
#define PERSON_H_

#include <string>

using std::string;

class Person
{
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = '\0'; } // #1
	Person(const string& ln, const char* fn = "Heyyou"); // #2
	void Show() const; // 이름 성씨 형식
	void FormalShow() const; // 성씨, 이름 형식
};

#endif