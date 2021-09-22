#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <array>

using namespace std;

struct travel_time
{
	int hours;
	int mins;
};

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

const int Len = 66;
const int Divs = 6;
const int Mins_per_hr = 60;
const int SIZE = 5;
const int Seasons = 4;
const std::array<std::string, Seasons> Sname = { "Spring", "Summer", "Fall", "Winter" };

const double* f1(const double ar[], int n);
const double* f2(const double [], int n);
const double* f3(const double*, int n);
double gildong(int);
double moonsoo(int);
void estimate(int lines, double (*pt)(int));
void subdivide(char ar[], int low, int high, int level);
void countdown(int n);
void show_time(travel_time t);
travel_time sum(travel_time t1, travel_time t2);
unsigned int c_in_str(const char* str, char ch);
char* buildstr(char c, int n);
polar rect_to_polar(rect xypos);
void rect_to_polar(const rect* pxy, polar* pda);
void show_polar(const polar* pda);
void show_polar(polar dapos);
void display(const string sa[], int n);
void fill(std::array<double, Seasons>* pa);
void show(std::array<double, Seasons> da);


