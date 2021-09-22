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
	cout << "�̸��� �Է��Ͻʽÿ�: ";
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
	cout << "40�ߵ� �޸��� �׽�Ʈ 1 : ";
	cin >> timer[0];
	cout << "40�ߵ� �޸��� �׽�Ʈ 2 : ";
	cin >> timer[1];
	cout << "40�ߵ� �޸��� �׽�Ʈ 3 : ";
	cin >> timer[2];

	average = (timer[0] + timer[1] + timer[2]) / 3;

	cout << "40�ߵ� �޸��� �׽�Ʈ ���\n";
	cout << "Ƚ�� : " << timer.size() << "\n";
	cout << "��� : " << average;
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
		cout << "cBar[" << i << "]�� �̸� : " << cBar[i].name << endl;
		cout << "cBar[" << i << "]�� ���� : " << (cBar + i)->weight << endl;
		cout << "cBar[" << i << "]�� Į�θ� : " << cBar[i].cal << endl;
	}

	delete[] cBar;
}

void exam8()
{
	PizzaCompany* company = new PizzaCompany;
	
	cout << "������ ������ �Է��ϼ���: ";
	cin >> (*company).diameter;
	cin.get();

	cout << "���� ȸ���� �̸��� �Է��ϼ���: ";
	getline(cin, company->name);

	cout << "������ ���Ը� �Է��ϼ���: ";
	cin >> company->weight;

	cout << (*company).name << " ȸ���� ������ ������ " << company->diameter << "cm�̸�, �߷��� "
		<< company->weight << "kg�Դϴ�.";
	
	delete company;
}

void exam7()
{
	PizzaCompany company;

	cout << "���� ȸ���� �̸��� �Է��ϼ���: ";
	getline(cin, company.name);

	cout << "������ ������ �Է��ϼ���: ";
	cin >> company.diameter;

	cout << "������ ���Ը� �Է��ϼ���: ";
	cin >> company.weight;

	cout << company.name << "ȸ���� ������ ������ " << company.diameter << "cm�̸�, �߷��� "
		<< company.weight << "kg�Դϴ�.";
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
		cout << "cBar[" << i << "]�� �̸� : " << cBar[i].name << endl;
		cout << "cBar[" << i << "]�� ���� : " << cBar[i].weight << endl;
		cout << "cBar[" << i << "]�� Į�θ� : " << cBar[i].cal << endl;
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

	cout << "snack�� ��ǥ��: " << snack.name << endl; 
	cout << "snack�� ����: " << snack.weight << endl;
	cout << "snack�� Į�θ�: " << snack.cal << endl;
}

void exam1()
{
	char fname[30];
	char lname[30];
	char grade;
	int age;

	cout << "���� �۽�Ʈ ����(�̸�): ";
	cin.getline(fname, 30);
	
	cout << "���� ��Ʈ ����(��): ";
	cin.get(lname, 30).get();
	
	cout << "�л��� ���ϴ� ����: ";
	cin >> grade;
	if (grade != 'C')
	{
		grade += 1;
	}

	cout << "����: ";
	cin >> age;

	cout << "����: " << lname << ", " << fname << "\n";
	cout << "����: " << grade << "\n";
	cout << "����: " << age << "\n";
}

void exam2()
{
	string fname;
	string lname;
	char grade;
	int age;

	cout << "���� �۽�Ʈ ����(�̸�): ";
	getline(cin, fname);
	
	cout << "���� ��Ʈ ����(��): ";
	getline(cin, lname);
	
	cout << "�л��� ���ϴ� ����: ";
	cin >> grade;
	if (grade != 'C')
	{
		grade += 1;
	}

	cout << "����: ";
	cin >> age;

	cout << "����: " << lname << ", " << fname << "\n";
	cout << "����: " << grade << "\n";
	cout << "����: " << age << "\n";
}

void exam3()
{
	char fname[30];
	char lname[30];

	cout << "�۽�Ʈ ����(�̸�)�� �Է��Ͻÿ�: ";
	cin.getline(fname, 30);
	cout << "��Ʈ ����(��)�� �Է��Ͻÿ�: ";
	cin.get(lname, 30).get();

	strcat(lname, ", ");

	cout << "�ϳ��� ���ڿ��� �����: " << strcat(lname, fname);
}

void exam4()
{
	string fname;
	string lname;
	string flname;

	cout << "�۽�Ʈ ����(�̸�)�� �Է��Ͻÿ�: ";
	getline(cin, fname);
	cout << "��Ʈ ����(��)�� �Է��Ͻÿ�: ";
	getline(cin, lname);

	flname = lname + ", " + fname;

	cout << "�ϳ��� ���ڿ��� �����: " << flname;
}