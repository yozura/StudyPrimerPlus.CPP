#pragma once
#include <iostream>
#include <string>
#include <new>

using namespace std;

const int BUF = 512;

class JustTesting
{
private:
	string words;
	int number;
public:
	JustTesting(const string& s = "Just Testing", int n = 0)
	{ words = s; number = n; cout << words << " ����\n"; }
	~JustTesting() { cout << words << "�ı�\n"; }
	void Show() const { cout << words << ", " << number << endl; }
};
