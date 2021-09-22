#include "main.h"

int main()
{
	exam10();
	return 0;
}

void choices()
{
	double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
	vector<double> a2(4);
	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[2] = 1.0 / 7.0;
	a2[3] = 1.0 / 9.0;

	array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.41 };
	array<double, 4> a4;
	a4 = a3;

	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

	a1[-2] = 20.2;
	cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
}

void mixtypes()
{
	antarctica_years_end s01, s02, s03;
	s01.year = 1998;
	antarctica_years_end* pa = &s02;
	pa->year = 1999;
	antarctica_years_end trio[3];
	trio[0].year = 2003;
	cout << trio->year << endl;
	const antarctica_years_end* arp[3] = { &s01, &s02, &s03 };
	cout << arp[1]->year << endl;
	const antarctica_years_end** ppa = arp;
	auto ppb = arp;

	cout << (*ppa)->year << endl;
	cout << (*(ppb + 1))->year << endl;
}

void deleteptr()
{
	char* name;

	name = getname();
	cout << (int*)name << ": " << name << "\n";
	delete[] name;

	name = getname();
	cout << (int*)name << ": " << name << "\n";
	delete[] name;
}

void newstrct()
{
	inflatable* ps = new inflatable;
	cout << "모형 풍선의 이름을 입력하십시오: ";
	cin.get(ps->name, 20);
	cout << "부피를 세제곱 피트 단위로 입력하십시오: ";
	cin >> (*ps).volume;
	cout << "가격을 달러 단위로 입력하십시오: ";
	cin >> ps->price;
	cout << "이름: " << (*ps).name << endl;
	cout << "부피: " << ps->volume << " cubic feet\n";
	cout << "가격: $" << ps->price << endl;

	delete ps;
}

void ptrstr()
{
	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;

	cout << animal << " and ";
	cout << bird << "\n";
	// cout << ps << "\n";

	cout << "동물의 종류를 입력하십시오: ";
	cin >> animal;
	// cin >> ps; 하면 안되는 짓

	ps = animal;
	cout << ps << "s!\n";
	cout << "strcpy() 사용 전:\n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << "strcpy() 사용 후:\n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;

	delete[] ps;
}

void addpntrs()
{
	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3, 2, 1 };

	double* pw = wages;
	short* ps = &stacks[0];

	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "pw 포인터에 1을 더함:\n";
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "ps 포인터에 1을 더함:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

	cout << "배열 표기로 두 원소에 접근\n";
	cout << "stacks[0] = " << stacks[0];
	cout << ", stacks[1] = " << stacks[1] << endl;
	cout << "포인터 표기로 두 원소에 접근\n";
	cout << "*stacks = " << *stacks;
	cout << ", *(stacks + 1) = " << *(stacks + 1) << endl;

	cout << sizeof wages << " = wages 배열의 크기\n";
	cout << sizeof pw << " = pw 포인터의 크기\n";
}

void arraynew()
{
	double* p3 = new double[3];

	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1]은 " << p3[1] << "입니다.\n";
	p3 = p3 + 1;
	cout << "이제는 p3[0]이 " << p3[0] << "이고, ";
	cout << "p3[1]이 " << p3[1] << "입니다.\n";
	p3 = p3 - 1;

	delete[] p3;
}

void use_new()
{
	int nights = 1001;
	int* pt = new int;
	*pt = 1001;

	cout << "nights의 값 = ";
	cout << nights << ": 메모리 위치 " << &nights << endl;
	cout << "int 형";
	cout << "값 = " << *pt << ": 메모리 위치 = " << pt << endl;

	double* pd = new double;
	*pd = 10000001.0;

	cout << "double 형";
	cout << "값 = " << *pd << ": 메모리 위치 = " << pd << endl;
	cout << "포인터 pd의 메모리 위치: " << &pd << endl;
	cout << "pt의 크기 = " << sizeof(pt);
	cout << ": *pt의 크기 = " << sizeof(*pt) << endl;
	cout << "pd의 크기 = " << sizeof(pd);
	cout << ": *pd의 크기 = " << sizeof(*pd) << endl;
}

void init_ptr()
{
	int higgens = 5;
	int* pt = &higgens;

	cout << "higgens의 값 = " << higgens << ", higgens의 주소 = " << &higgens << endl;
	cout << "*pt의 값 = " << *pt << ", pt의 값 = " << pt << endl;
}

void pointer()
{
	int updates = 6;
	int* p_updates;

	p_updates = &updates;

	cout << "값: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;

	cout << "주소: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;

	*p_updates = *p_updates + 1;
	cout << "변경된 updates = " << updates << endl;
}

void address()
{
	int donuts = 6;
	double cups = 4.5;

	cout << "donuts의 값 = " << donuts;
	cout << ", donuts의 주소 = " << &donuts << endl;
	cout << "cups의 값 = " << cups;
	cout << ", cups의 주소 = " << &cups << endl;
}