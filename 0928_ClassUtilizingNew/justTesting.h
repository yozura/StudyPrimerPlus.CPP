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
	{ words = s; number = n; cout << words << " »ý¼º\n"; }
	~JustTesting() { cout << words << "ÆÄ±«\n"; }
	void Show() const { cout << words << ", " << number << endl; }
};
