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
		cout << "연산할 두 수를 입력하세요 :";
		cin >> x >> y;

		f = calculate(x, y, (*pf[0]));
		cout << "+ 연산 결과값: " << f << "\n";
		f = calculate(x, y, (*pf[1]));
		cout << "- 연산 결과값: " << f << "\n";
		f = calculate(x, y, (*pf[2]));
		cout << "/ 연산 결과값: " << f << "\n";
		f = calculate(x, y, (*pf[3]));
		cout << "* 연산 결과값: " << f << "\n";
	}
}

void exam10()
{
	// double (*pf[4])(double, double) = { add, subtract, divide, multiple };

	while (true)
	{
		double x, y, f;
		char opcode;
		cout << "연산할 두 수를 입력하세요 :";
		cin >> x >> y;
		cout << "두 수를 연산할 연산자를 입력하세요.(+, -, /, *) : ";
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
			cout << "프로그램 종료";
			return;
		}
		
		cout << "연산 결과값: " << f << "\n";
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
	cout << "학급의 학생 수를 입력하십시오: ";
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
	cout << "프로그램을 종료합니다.\n";
}

int getinfo(student pa[], int n)
{
	int i;
	cout << "학생에 대한 정보를 입력하시오.\n";
	for (i = 0; i < n; i++)
	{
		cout << "#" << (i + 1) << "번 학생:\n";
		cout << "학생의 이름: ";
		cin >> pa[i].fullname;
		if (strcmp(pa[i].fullname, "") == 0)
			break;

		cout << "학생의 취미: ";
		cin >> pa[i].hobby;

		cout << "학생의 레벨: ";
		cin >> pa[i].ooplevel;
	}
	
	return i;
}

void display1(student st)
{
	cout << "\ndisplay1\n";
	cout << "학생의 이름 : " << st.fullname << "\n";
	cout << "학생의 취미 : " << st.hobby << "\n";
	cout << "학생의 레벨 : " << st.ooplevel << "\n\n";
}

void display2(const student* ps)
{
	cout << "\ndisplay2\n";
	cout << "학생의 이름 : " << ps->fullname << "\n";
	cout << "학생의 이름 : " << ps->hobby << "\n";
	cout << "학생의 이름 : " << ps->ooplevel << "\n\n";
}

void display3(const student pa[], int n)
{
	cout << "\ndisplay3\n";
	for (int i = 0; i < n; i++)
	{
		cout << "학생의 이름 : " << pa[i].fullname << "\n";
		cout << "학생의 취미 : " << pa[i].hobby << "\n";
		cout << "학생의 레벨 : " << pa[i].ooplevel << "\n";
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
		cout << season[i] << "에 소요되는 비용 : ";
		cin >> _cost->costs[i];
	}
}

void show(cost _cost, const char* season[], int size)
{
	double total = 0.0;
	cout << "\n계절별 비용\n";
	for (int i = 0; i < size; i++)
	{
		cout << season[i] << " : $" << _cost.costs[i] << endl;
		total += _cost.costs[i];
	}
	cout << "총 비용 : $" << total << endl;
}

void exam6()
{
	double arr[SIZE];
	int len = Fill_array(arr, SIZE);
	cout << "재배열 전 : \n";
	Show_array(arr, len);
	Reverse_array(arr, len);
	cout << "재배열 후 : \n";
	Show_array(arr, len);
	Reverse_array(arr + 1, len - 2);
	cout << "재배열 재배열 후 : \n";
	Show_array(arr, len);
}

int Fill_array(double arr[], int size)
{
	double temp;
	int i;
	cout << "배열에 저장할 원소들을 순서대로 입력(문자 입력시 종료):\n";
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
		cout << "팩토리얼 계산할 정수 입력 (끝내려면 문자 입력) : ";
		cin >> n;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;

			cout << "프로그램 종료\n";
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
		cout << "1. 전체 수의 개수와 뽑을 수의 개수를 입력하십시오:\n";
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

		cout << "2. 전체 수의 개수와 뽑을 수의 개수를 입력하십시오:\n";
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

		cout << "당신이 그랑프리를 뽑을 확률은: ";
		cout << lotto * suball << endl;
	}
	cout << "프로그램을 종료합니다.\n";
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
	cout << "박스 제조사: " << _box.maker << "\n";
	cout << "박스 높이: " << _box.height << "\n";
	cout << "박스 너비: " << _box.width << "\n";
	cout << "박스 길이: " << _box.length << "\n";
	cout << "박스 부피: " << _box.volume << "\n";
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

	cout << "평균 스코어: " << avgScores(arr, length);
}

int inputScores(int* arr, int size)
{
	int i, temp;
	cout << "골프 스코어를 순서대로 입력해주세요(끝내려면 음수 입력):\n";
	for (i = 0; i < size; i++)
	{
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;

			cout << "불량 입력입니다. 입력이 여기서 중단됩니다.\n";
			break;
		}
		else if (temp < 0)
		{
			cout << "입력이 종료됩니다.\n";
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

	cout << "두 수를 입력하세요: ";
	cin >> x >> y;
	while (x != 0 && y != 0)
	{
		cout << getHarmonic(x, y) << "\n";
		cout << "두 수를 입력하세요(끝내려면 0입력): ";
		cin >> x >> y;
	}

	cout << "종료합니다.\n";
}

int getHarmonic(int x, int y)
{
	return 2.0 * x * y / x + y;
}