#include "main.h"

void choices()
{
	int m = 20;
	int n = -30;
	double x = 15.5;
	double y = 25.9;

	cout << lesser(m, n) << endl;
	cout << lesser(x, y) << endl;
	cout << lesser<>(m, n) << endl;
	cout << lesser<int>(x, y) << endl;
}

void tempover()
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
	cout << "Mr.E의 재산 목록:\n";
	ShowArray(things, 6);

	cout << "Mr.E의 채무 목록:\n";
	ShowArray(pd, 3);
}

template <typename T>
void ShowArray(T arr[], int n)
{
	cout << "템플릿 A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <typename T>
void ShowArray(T* arr[], int n)
{
	cout << "템플릿 B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}

void twoswap()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);
	cout << "이제 i, j = " << i << ", " << j << ".\n";

	job sue = { "Susan Yaffee", 73000.60, 7 };
	job sidney = { "Sidney Taffee", 78060.72, 9 };
	cout << "job 교환 전:\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);
	cout << "job 교환 후:\n";
	Show(sue);
	Show(sidney);
}

void Show(job& j)
{
	cout << j.name << ": (" << j.floor << "층에 거주) " << "$" << j.salary << endl;
}

template <> void Swap<job>(job& j1, job& j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void twotemps()
{
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);
	cout << "이제 i, j = " << i << ", " << j << ".\n";

	int d1[Lim] = { 0, 7, 0, 4, 1, 7, 7, 6 };
	int d2[Lim] = { 0, 6, 2, 0, 1, 9, 6, 9 };
	cout << "원본 배열:\n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim);
	cout << "교환된 배열:\n";
	Show(d1);
	Show(d2);
}

void Show(int a[])
{
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++)
		cout << a[i];
	cout << endl;
}

template <typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Swap(T* a, T* b, int n)
{
	T temp;
	for(int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void funtemp()
{
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);
	cout << "이제 i, j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << ".\n";
	cout << "컴파일러가 생성한 double형 교환기를 사용하면\n";
	Swap(x, y);
	cout << "이제 x, y = " << x << ", " << y << ".\n";
}

void leftover()
{
	const char* trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char* temp;
	for (i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;
	}
}

void leftfunc()
{
	char sample[ArSize];
	cout << "문자열을 입력하십시오:\n";
	cin.get(sample, ArSize);
	char* ps = left(sample, 4);
	cout << ps << endl;
	delete[] ps;
	ps = left(sample);
	cout << ps << endl;
	delete[] ps;
}

unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	if (ct == 0 || num == 0)
		return 0;

	while (n /= 10)
		digits++;
	
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;
	}
	else
		return num;
}

char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];
	int i;
	// n이 i 보다 크고 str[i]가 널 문자가 아닐 경우 조건을 만족
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i];
	
	// i 가 n과 같거나 n이 더크면 p[i + 1] 에 널 문자 추가.
	while (i <= n)
		p[i++] = '\0';

	return p;
}