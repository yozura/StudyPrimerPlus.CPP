#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int LIMIT = 5;

struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

inline double square(double x) { return x * x; }
void swapr(int& a, int& b);
void swapp(int* p, int* q);
void swapv(int a, int b);
double cube(double a);
double refcube(double& ra);
void display(const free_throws& ft);
void set_pc(free_throws& ft);
free_throws& accumulate(free_throws& target, const free_throws& source);
string version1(const string& s1, const string& s2);
const string& version2(string& s1, const string& s2);
const string& version3(string& s1, const string& s2);
void file_it(ostream& os, double fo, const double fe[], int n);