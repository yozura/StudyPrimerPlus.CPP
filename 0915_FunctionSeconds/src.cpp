#include "main.h"

int main()
{
	typedef double real;
	typedef const double* (*p_fun)(const double*, int);

	p_fun p1 = f1;
	p_fun pa[3] = { f1, f2, f3 };
	p_fun(*pd)[3] = &pa;

	return 0;
}

void arfupt()
{
	double av[3] = { 1112.3, 1542.6, 2227.9 };
	const double* (*p1)(const double*, int) = f1;
	auto p2 = f2;
	cout << "함수 포인터:\n";
	cout << "주소 값\n";
	cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

	const double* (*pa[3])(const double*, int) = { f1, f2, f3 };
	auto pb = pa;
	cout << "\n함수 포인터를 원소로 가지는 배열:\n";
	cout << "주소 값\n";
	for (int i = 0; i < 3; i++)
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;

	cout << "\n함수 포인터를 가리키는 포인터:\n";
	cout << "주소 값\n";
	for (int i = 0; i < 3; i++)
		cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;

	cout << "\n포인터를 원소로 가지는 배열을 가리키는 포인터:\n";
	cout << "주소 값:\n";
	auto pc = &pa;
	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;

	const double* (*(*pd)[3])(const double*, int) = &pa;
	const double* pdb = (*pd)[1](av, 3);
	cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2]) (av, 3) << endl;
}

const double* f1(const double* ar, int n)
{
	return ar;
}

const double* f2(const double ar[], int n)
{
	return ar + 1;
}

const double* f3(const double ar[], int n)
{
	return ar + 2;
}

void fun_ptr()
{
	int code;
	cout << "필요한 코드의 행 수를 입력하십시오: ";
	cin >> code;
	cout << "홍길동의 시간 예상:\n";
	estimate(code, gildong);
	cout << "박문수의 시간 예상:\n";
	estimate(code, moonsoo);
}

double gildong(int lns)
{
	return 0.05 * lns;
}

double moonsoo(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pt)(int))
{
	cout << lines << "행을 작성하는데 ";
	cout << (*pt)(lines) << "시간이 걸립니다.\n";
}

void ruler()
{
	char ruler[Len];
	int i;
	for (i = 1; i < Len - 2; i++)
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;
	for (i = 1; i <= Divs; i++)
	{
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		for (int j = 1; j < Len - 2; j++)
			ruler[j] = ' ';
	}
}

void subdivide(char ar[], int low, int high, int level)
{
	// divide and conquer (분할 정복 전략)

	// 계속 나누다가 level이 0이 되는 순간 종료
	if (level == 0)
		return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
	// low - mid 사이를 반으로 계속 나눔
	subdivide(ar, low, mid, level - 1);
	// mid - high 사이를 반으로 계속 나눔
	subdivide(ar, mid, high, level - 1);
}

void recur()
{
	countdown(5);
}

void countdown(int n)
{
	cout << "카운트 다운 ..." << n << " (n at " << &n << ")" << endl;
	if (n > 0)
		countdown(n - 1);
	cout << n << ": Kaboom!" << " (n at " << &n << ")\n";
}

void arrobj()
{
	std::array<double, Seasons> expenses;
	fill(&expenses);
	show(expenses);
}

void fill(std::array<double, Seasons>* pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << "에 소요되는 비용:";
		cin >> (*pa)[i];
	}
}

void show(std::array<double, Seasons> da)
{
	double total = 0.0;
	cout << "\n계절별 비용\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << " : $" << da[i] << endl;
		total += da[i];
	}
	cout << "총 비용 : $" << total << endl;
}

void topfive()
{
	string list[SIZE];
	cout << "좋아하는 밤하늘의 광경을 " << SIZE << "개 입력하시오:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << ": ";
		getline(cin, list[i]);
	}
	cout << "입력하신 내용은 다음과 같습니다:\n";
	display(list, SIZE);
}

void display(const string sa[], int n)
{
	for (int i = 0; i < n; i++)
		cout << i + 1 << ": " << sa[i] << endl;
}

void strctfun2()
{
	rect rplace;
	polar pplace;

	cout << "x값과 y값을 입력하십시오: ";
	while (cin >> rplace.x >> rplace.y)
	{
		rect_to_polar(&rplace, &pplace);
		show_polar(&pplace);
		cout << "x값과 y값을 입력하십시오(끝내려면 q를 입력): ";
	}
	cout << "프로그램을 종료합니다.\n";
}

void show_polar(const polar* pda)
{
	const double Rad_to_deg = 57.29577951;
	cout << "거리 = " << pda->distance;
	cout << ", 각도 = " << pda->angle * Rad_to_deg;
	cout << "도\n";
}

void rect_to_polar(const rect* pxy, polar* pda)
{
	pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}

void strctfun()
{
	rect rplace;
	polar pplace;

	cout << "x값과 y값을 입력하십시오: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "x값과 y값을 입력하십시오(끝내려면 q를 입력): ";
	}
	cout << "프로그램을 종료합니다.\n";
}

void show_polar(polar dapos)
{
	const double Rad_to_deg = 57.29577951;
	cout << "거리 = " << dapos.distance;
	cout << ", 각도 = " << dapos.angle * Rad_to_deg;
	cout << "도\n";
}

polar rect_to_polar(rect xypos)
{
	polar answer;
	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer;
}

void travel()
{
	travel_time day1 = { 5, 45 };
	travel_time day2 = { 4, 55 };

	travel_time trip = sum(day1, day2);
	cout << "이틀간 소요시간: ";
	show_time(trip);

	travel_time day3 = { 4, 32 };
	cout << "사흘간 소요시간: ";
	show_time(sum(trip, day3));
}

void show_time(travel_time t)
{
	cout << t.hours << "시간 " << t.mins << "분\n";
}

travel_time sum(travel_time t1, travel_time t2)
{
	travel_time total;
	total.mins = (t1.mins + t2.mins) % Mins_per_hr;
	total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Mins_per_hr;
	return total;
}

void strgback()
{
	int times;
	char ch;

	cout << "문자 하나를 입력하십시오: ";
	cin >> ch;
	cout << "정수 하나를 입력하십시오: ";
	cin >> times;
	char* ps = buildstr(ch, times);
	cout << ps << endl;
	delete[] ps;
	ps = buildstr('+', 20);
	cout << ps << "-DONE-" << ps << endl;
	delete[] ps;
}

char* buildstr(char c, int n)
{
	char* pstr = new char[n + 1]; // \0문자를 저장하기 위해 + 1 해주기
	pstr[n] = '\0'; // 문자열의 끝에 널 문자 삽입
	// n을 감소시키면서 모든 원소에 c를 삽입
	while (n-- > 0)
		pstr[n] = c;
	return pstr;
}

void strgfun()
{
	char mmm[15] = "minimum";
	const char* wail = "ululate";

	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << mmm << "에는 m이 " << ms << "개 들어 있습니다.\n";
	cout << wail << "에는 u가 " << us << "개 들어 있습니다.\n";
}

unsigned int c_in_str(const char* str, char ch)
{
	int count = 0;
	// str이 null 문자가 아니면 참인 것 같음.
	while (*str)
	{
		if (*str == ch)
			count++;
		str++;
	}

	return count;
}