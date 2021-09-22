#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct CandyBar
{
	char name[100];
	double volume;
	int kcal;
};

struct stringy
{
	char* str;
	int ct;
};

struct debts
{
	char name[50];
	double amount;
};

void strPrint(const char* str, int n = 0);
void setCandyBar(CandyBar& cbar, const char* name = "Millennium Munch", double volume = 2.85, int kcal = 350);
void showCandyBar(const CandyBar& cbar);
void strtoUp(string& str);
void set(stringy&, char*);

void show(const stringy, int = 0);
void show(const char*, int = 0);

template <typename T>
T max5(T arr[]);

template <typename T>
T maxn(T arr[], int n);

template <> const char* maxn<const char*>(const char* [], int);

template <typename T>
T sumArray(T t1[], int n);

template <typename T>
T sumArray(T* t1[], int n);

void exam7()
{
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_E[3] =
	{
		{ "Ima Wolfe", 2400.0 },
		{ "Ura Foxe", 1300.0 },
		{ "Iby Stout", 1800.0 }
	};

	double* pd[3];
	
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;
	
	cout << "Mr. E의 재산 합계: " << sumArray(things, 6) << endl;
	cout << "Mr. E의 채무 합계: " << sumArray(pd, 3);
}

template <typename T>
T sumArray(T t1[], int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += t1[i];

	return sum;
}

template <typename T>
T sumArray(T* t1[], int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += *t1[i];

	return sum;
}

void exam6()
{
	int c[10] = { 1, 3, 5, 2, 31, 9, 10, 21, 7, 8 };
	double a1[5] = { 1.0, 10.0, 8.5, 9.7, 0.2 };

	cout << maxn(c, 10) << endl;
	cout << maxn(a1, 5) << endl;

	const char* ar[5] =
	{
		"Hello Watch",
		"Korean March pencil",
		"Computer's computer",
		"Kali's Axe",
		"ATOMIC SAMURAI"
	};

	cout << maxn(ar, 5) << endl;
}

template <typename T>
T maxn(T arr[], int n)
{
	T temp;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[max] < arr[i])
			max = i;
	}

	return arr[max];
}

template <> const char* maxn<const char*>(const char* arr[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (strlen(arr[max]) < strlen(arr[i]))
			max = i;
	}

	return arr[max];
}

void exam5()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 5, 4, 3, 2, 1 };
	int c[5] = { 1, 3, 5, 2, 4 };
	double a1[5] = { 1.0, 2.0, 5.5, 9.7, 0.2 };
	double b2[5] = { 2.0, 9.0, 4.5, 1.7, 0.6 };
	double c3[5] = { 4.1, 2.5, 3.3, 7.8, 0.3 };

	cout << max5(a) << "\n";
	cout << max5(b) << "\n";
	cout << max5(c) << "\n";
	cout << max5(a1) << "\n";
	cout << max5(b2) << "\n";
	cout << max5(c3) << "\n";
}

template <typename T>
T max5(T arr[])
{
	T temp;
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (arr[max] < arr[i])
		{
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}

	return arr[max];
}

void exam4()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done");
}

void set(stringy& strgy, char* str)
{
	int n = 0;
	for (int i = 0; str[i]; i++)
		n++;

	strgy.str = new char[n + 1];
	strcpy(strgy.str, str);
	strgy.ct = n;
}

void show(const stringy strgy, int n)
{
	if (n > 0)
	{ 
		for (int i = 0; i < n; i++)
			cout << strgy.str << endl;
	}
	else
		cout << strgy.str << endl;
}

void show(const char* str, int n)
{
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
			cout << str << endl;
	}
	else
		cout << str << endl;
}

void exam3()
{
	string str;
	cout << "문자열을 입력하시오 (끝내려면 q) : ";
	while (cin >> str && str != "q")
	{
		strtoUp(str);
		cout << str << endl;
		cout << "다음 문자열을 입력하시오 (끝내려면 q) : ";
	}

	cout << "\n종료";
}

void strtoUp(string& str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
}

void exam2()
{
	CandyBar candy;
	CandyBar candy2;

	setCandyBar(candy);
	setCandyBar(candy2, "Korean Killer", 9.7, 100);
	showCandyBar(candy);
	showCandyBar(candy2);
}

void setCandyBar(CandyBar& cbar, const char* name, double volume, int kcal)
{
	strcpy(cbar.name, name);
	cbar.volume = volume;
	cbar.kcal = kcal;
}

void showCandyBar(const CandyBar& cbar)
{
	cout << cbar.name << ", ";
	cout << cbar.volume << ", ";
	cout << cbar.kcal << endl;
}

void exam1()
{
	int n = 0;
	strPrint("김치피자탕수육");
	strPrint("치즈김치닭갈비", ++n);
}

void strPrint(const char* str, int n)
{
	if (n != 0)
	{
		for (int i = 0; i < n; i++)
			cout << str << endl;
	}
	else
		cout << str << endl;
}