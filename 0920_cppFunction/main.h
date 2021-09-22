#pragma once
#define _CRT_SECURE_WARNING
#include <iostream>

using namespace std;

const int ArSize = 80;
const int Lim = 8;

struct job
{
	char name[40];
	double salary;
	int floor;
};

struct debts
{
	char name[50];
	double amount;
};

unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 1);

template <typename T>
void Swap(T& a, T& b);

template <> void Swap<job>(job& j1, job& j2);

void Show(job& j);

template <typename T>
void Swap(T* a, T* b, int n);

void Show(int a[]);

template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T* arr[], int n);

template <class T>
T lesser(T a, T b)
{
	return a < b ? a : b;
}

int lesser(int a, int b)
{
	a = a < 0 ? -a : a;
	b = a < 0 ? -b : b;
	return a < b ? a : b;
}