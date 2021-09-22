#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>

using namespace std;

char* getname(void)
{
	char temp[80];
	cout << "이름을 입력하십시오: ";
	cin >> temp;
	char* pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);

	return pn;
}

struct antarctica_years_end
{
	int year;
};

struct inflatable
{
	char name[20];
	float volume;
	double price;
};

struct CandyBar
{
	char name[30];
	double weight;
	int cal;
};

struct PizzaCompany
{
	string name;
	double diameter;
	double weight;
};

void exam10()
{
	array<double, 3> timer;
	double average;
	cout << "40야드 달리기 테스트 1 : ";
	cin >> timer[0];
	cout << "40야드 달리기 테스트 2 : ";
	cin >> timer[1];
	cout << "40야드 달리기 테스트 3 : ";
	cin >> timer[2];

	average = (timer[0] + timer[1] + timer[2]) / 3;

	cout << "40야드 달리기 테스트 결과\n";
	cout << "횟수 : " << timer.size() << "\n";
	cout << "평균 : " << average;
}

void exam9()
{
	CandyBar* cBar = new CandyBar[3];
	cBar[0] =
	{
		"M&M",
		2.0,
		140
	};
	cBar[1] =
	{
		"ChocoBar",
		4.5,
		400,
	};
	cBar[2] =
	{
		"Ottho",
		1.4,
		900,
	};

	for (int i = 0; i < 3; i++)
	{
		cout << "cBar[" << i << "]의 이름 : " << cBar[i].name << endl;
		cout << "cBar[" << i << "]의 무게 : " << (cBar + i)->weight << endl;
		cout << "cBar[" << i << "]의 칼로리 : " << cBar[i].cal << endl;
	}

	delete[] cBar;
}

void exam8()
{
	PizzaCompany* company = new PizzaCompany;
	
	cout << "피자의 지름을 입력하세요: ";
	cin >> (*company).diameter;
	cin.get();

	cout << "피자 회사의 이름을 입력하세요: ";
	getline(cin, company->name);

	cout << "피자의 무게를 입력하세요: ";
	cin >> company->weight;

	cout << (*company).name << " 회사의 피자의 지름은 " << company->diameter << "cm이며, 중량은 "
		<< company->weight << "kg입니다.";
	
	delete company;
}

void exam7()
{
	PizzaCompany company;

	cout << "피자 회사의 이름을 입력하세요: ";
	getline(cin, company.name);

	cout << "피자의 지름을 입력하세요: ";
	cin >> company.diameter;

	cout << "피자의 무게를 입력하세요: ";
	cin >> company.weight;

	cout << company.name << "회사의 피자의 지름은 " << company.diameter << "cm이며, 중량은 "
		<< company.weight << "kg입니다.";
}

void exam6()
{
	CandyBar cBar[3];
	cBar[0] =
	{
		"M&M",
		0.7,
		108
	};
	cBar[1] =
	{
		"ChocoBar",
		1.2,
		295
	};
	cBar[2] =
	{
		"Choco Ball",
		2.8,
		1024,
	};

	for (int i = 0; i < 3; i++)
	{
		cout << "cBar[" << i << "]의 이름 : " << cBar[i].name << endl;
		cout << "cBar[" << i << "]의 무게 : " << cBar[i].weight << endl;
		cout << "cBar[" << i << "]의 칼로리 : " << cBar[i].cal << endl;
	}
}

void exam5()
{
	CandyBar snack =
	{
		"Mocha Munch",
		2.3,
		350
	};

	cout << "snack의 상표명: " << snack.name << endl; 
	cout << "snack의 무게: " << snack.weight << endl;
	cout << "snack의 칼로리: " << snack.cal << endl;
}

void exam1()
{
	char fname[30];
	char lname[30];
	char grade;
	int age;

	cout << "영문 퍼스트 네임(이름): ";
	cin.getline(fname, 30);
	
	cout << "영문 라스트 네임(성): ";
	cin.get(lname, 30).get();
	
	cout << "학생이 원하는 학점: ";
	cin >> grade;
	if (grade != 'C')
	{
		grade += 1;
	}

	cout << "나이: ";
	cin >> age;

	cout << "성명: " << lname << ", " << fname << "\n";
	cout << "학점: " << grade << "\n";
	cout << "나이: " << age << "\n";
}

void exam2()
{
	string fname;
	string lname;
	char grade;
	int age;

	cout << "영문 퍼스트 네임(이름): ";
	getline(cin, fname);
	
	cout << "영문 라스트 네임(성): ";
	getline(cin, lname);
	
	cout << "학생이 원하는 학점: ";
	cin >> grade;
	if (grade != 'C')
	{
		grade += 1;
	}

	cout << "나이: ";
	cin >> age;

	cout << "성명: " << lname << ", " << fname << "\n";
	cout << "학점: " << grade << "\n";
	cout << "나이: " << age << "\n";
}

void exam3()
{
	char fname[30];
	char lname[30];

	cout << "퍼스트 네임(이름)을 입력하시오: ";
	cin.getline(fname, 30);
	cout << "라스트 네임(성)을 입력하시오: ";
	cin.get(lname, 30).get();

	strcat(lname, ", ");

	cout << "하나의 문자열로 만들면: " << strcat(lname, fname);
}

void exam4()
{
	string fname;
	string lname;
	string flname;

	cout << "퍼스트 네임(이름)을 입력하시오: ";
	getline(cin, fname);
	cout << "라스트 네임(성)을 입력하시오: ";
	getline(cin, lname);

	flname = lname + ", " + fname;

	cout << "하나의 문자열로 만들면: " << flname;
}