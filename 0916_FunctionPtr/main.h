#pragma once
#include <iostream>
#include <string>
#include <array>
#include <cctype>

using namespace std;

const int SIZE = 10;
const int len = 4;
const int SLEN = 20;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

struct cost
{
	double costs[len];
};

struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getHarmonic(int, int);
int inputScores(int*, int);
void outputScores(const int*, int);
double avgScores(int*, int);
void showBox(box);
void setVolume(box*);
long double probability(unsigned numbers, unsigned picks);
long long factorial(unsigned);
int Fill_array(double[], int);
void Show_array(const double[], int);
void Reverse_array(double[], int);
void fill(cost*, const char*[], int);
void show(cost, const char*[], int);
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);
double calculate(double, double, double (*pf)(double, double));
double add(double x, double y);
double subtract(double x, double y);
double divide(double x, double y);
double multiple(double x, double y);

void exam10_1()
{
	double (*pf[4])(double, double) = { add, subtract, divide, multiple };

	while (true)
	{
		double x, y, f;
		char opcode;
		cout << "������ �� ���� �Է��ϼ��� :";
		cin >> x >> y;

		f = calculate(x, y, (*pf[0]));
		cout << "+ ���� �����: " << f << "\n";
		f = calculate(x, y, (*pf[1]));
		cout << "- ���� �����: " << f << "\n";
		f = calculate(x, y, (*pf[2]));
		cout << "/ ���� �����: " << f << "\n";
		f = calculate(x, y, (*pf[3]));
		cout << "* ���� �����: " << f << "\n";
	}
}

void exam10()
{
	// double (*pf[4])(double, double) = { add, subtract, divide, multiple };

	while (true)
	{
		double x, y, f;
		char opcode;
		cout << "������ �� ���� �Է��ϼ��� :";
		cin >> x >> y;
		cout << "�� ���� ������ �����ڸ� �Է��ϼ���.(+, -, /, *) : ";
		cin >> opcode;

		switch (opcode)
		{
		case '+':
			f = calculate(x, y, add);
			break;
		case '-':
			f = calculate(x, y, subtract);
			break;
		case '/':
			f = calculate(x, y, divide);
			break;
		case '*':
			f = calculate(x, y, multiple);
			break;
		default:
			cout << "���α׷� ����";
			return;
		}
		
		cout << "���� �����: " << f << "\n";
	}
}

double calculate(double x, double y, double (*pf)(double, double))
{
	return (*pf)(x, y);
}

double add(double x, double y)
{
	return x + y;
}

double subtract(double x, double y)
{
	return x - y;
}

double divide(double x, double y)
{
	return x / y;
}

double multiple(double x, double y)
{
	return x * y;
}

void exam9()
{
	cout << "�б��� �л� ���� �Է��Ͻʽÿ�: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	cout << "���α׷��� �����մϴ�.\n";
}

int getinfo(student pa[], int n)
{
	int i;
	cout << "�л��� ���� ������ �Է��Ͻÿ�.\n";
	for (i = 0; i < n; i++)
	{
		cout << "#" << (i + 1) << "�� �л�:\n";
		cout << "�л��� �̸�: ";
		cin >> pa[i].fullname;
		if (strcmp(pa[i].fullname, "") == 0)
			break;

		cout << "�л��� ���: ";
		cin >> pa[i].hobby;

		cout << "�л��� ����: ";
		cin >> pa[i].ooplevel;
	}
	
	return i;
}

void display1(student st)
{
	cout << "\ndisplay1\n";
	cout << "�л��� �̸� : " << st.fullname << "\n";
	cout << "�л��� ��� : " << st.hobby << "\n";
	cout << "�л��� ���� : " << st.ooplevel << "\n\n";
}

void display2(const student* ps)
{
	cout << "\ndisplay2\n";
	cout << "�л��� �̸� : " << ps->fullname << "\n";
	cout << "�л��� �̸� : " << ps->hobby << "\n";
	cout << "�л��� �̸� : " << ps->ooplevel << "\n\n";
}

void display3(const student pa[], int n)
{
	cout << "\ndisplay3\n";
	for (int i = 0; i < n; i++)
	{
		cout << "�л��� �̸� : " << pa[i].fullname << "\n";
		cout << "�л��� ��� : " << pa[i].hobby << "\n";
		cout << "�л��� ���� : " << pa[i].ooplevel << "\n";
	}
}

void exam8()
{
	const char* Sname[len] = { "Spring", "Summer", "Fall", "Winter" };
	cost _cost;
	fill(&_cost, Sname, len);
	show(_cost, Sname, len);
}

void fill(cost* _cost, const char* season[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << season[i] << "�� �ҿ�Ǵ� ��� : ";
		cin >> _cost->costs[i];
	}
}

void show(cost _cost, const char* season[], int size)
{
	double total = 0.0;
	cout << "\n������ ���\n";
	for (int i = 0; i < size; i++)
	{
		cout << season[i] << " : $" << _cost.costs[i] << endl;
		total += _cost.costs[i];
	}
	cout << "�� ��� : $" << total << endl;
}

void exam6()
{
	double arr[SIZE];
	int len = Fill_array(arr, SIZE);
	cout << "��迭 �� : \n";
	Show_array(arr, len);
	Reverse_array(arr, len);
	cout << "��迭 �� : \n";
	Show_array(arr, len);
	Reverse_array(arr + 1, len - 2);
	cout << "��迭 ��迭 �� : \n";
	Show_array(arr, len);
}

int Fill_array(double arr[], int size)
{
	double temp;
	int i;
	cout << "�迭�� ������ ���ҵ��� ������� �Է�(���� �Է½� ����):\n";
	for (i = 0; i < size; i++)
	{
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			break;
		}

		arr[i] = temp;
	}

	return i;
}

void Show_array(const double arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Reverse_array(double arr[], int size)
{
	double temp;
	for (int i = 0, j = size - 1; i < j; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void exam5()
{
	while (true)
	{
		unsigned n;
		cout << "���丮�� ����� ���� �Է� (�������� ���� �Է�) : ";
		cin >> n;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;

			cout << "���α׷� ����\n";
			break;
		}
		cout << n << "! = " << factorial(n) << "\n";
	}
}

long long factorial(unsigned n)
{
	if (n == 0)
		return 1;

	long long num = 0;
	num = n * factorial(n - 1);

	return num;
}

void exam4()
{
	double total, choices;
	long double lotto, suball;
	
	while (true)
	{
		cout << "1. ��ü ���� ������ ���� ���� ������ �Է��Ͻʽÿ�:\n";
		cin >> total >> choices;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			break;
		}
		if (choices >= total)
			break;

		lotto = probability(total, choices);

		cout << "2. ��ü ���� ������ ���� ���� ������ �Է��Ͻʽÿ�:\n";
		cin >> total >> choices;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			break;
		}
		if (choices >= total)
			break;

		suball = probability(total, choices);

		cout << "����� �׶������� ���� Ȯ����: ";
		cout << lotto * suball << endl;
	}
	cout << "���α׷��� �����մϴ�.\n";
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;

	return result;
}

void exam3()
{
	box tempBox = { "Nike", 30,	20, 50, 0 };

	showBox(tempBox);
	setVolume(&tempBox);
	showBox(tempBox);
}

void showBox(box _box)
{
	cout << "�ڽ� ������: " << _box.maker << "\n";
	cout << "�ڽ� ����: " << _box.height << "\n";
	cout << "�ڽ� �ʺ�: " << _box.width << "\n";
	cout << "�ڽ� ����: " << _box.length << "\n";
	cout << "�ڽ� ����: " << _box.volume << "\n";
}

void setVolume(box* _box)
{
	_box->volume = _box->height * _box->width * _box->length;
}

void exam2()
{
	int arr[SIZE];
	int length = inputScores(arr, SIZE);
	outputScores(arr, length);

	cout << "��� ���ھ�: " << avgScores(arr, length);
}

int inputScores(int* arr, int size)
{
	int i, temp;
	cout << "���� ���ھ ������� �Է����ּ���(�������� ���� �Է�):\n";
	for (i = 0; i < size; i++)
	{
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;

			cout << "�ҷ� �Է��Դϴ�. �Է��� ���⼭ �ߴܵ˴ϴ�.\n";
			break;
		}
		else if (temp < 0)
		{
			cout << "�Է��� ����˴ϴ�.\n";
			break;
		}

		arr[i] = temp;
	}

	return i;
}

void outputScores(const int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

double avgScores(int* arr, int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
		total += arr[i];

	return total / size;
}

void exam1()
{
	int x;
	int y;

	cout << "�� ���� �Է��ϼ���: ";
	cin >> x >> y;
	while (x != 0 && y != 0)
	{
		cout << getHarmonic(x, y) << "\n";
		cout << "�� ���� �Է��ϼ���(�������� 0�Է�): ";
		cin >> x >> y;
	}

	cout << "�����մϴ�.\n";
}

int getHarmonic(int x, int y)
{
	return 2.0 * x * y / x + y;
}