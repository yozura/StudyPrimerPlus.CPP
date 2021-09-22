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
	cout << "���� ǳ���� �̸��� �Է��Ͻʽÿ�: ";
	cin.get(ps->name, 20);
	cout << "���Ǹ� ������ ��Ʈ ������ �Է��Ͻʽÿ�: ";
	cin >> (*ps).volume;
	cout << "������ �޷� ������ �Է��Ͻʽÿ�: ";
	cin >> ps->price;
	cout << "�̸�: " << (*ps).name << endl;
	cout << "����: " << ps->volume << " cubic feet\n";
	cout << "����: $" << ps->price << endl;

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

	cout << "������ ������ �Է��Ͻʽÿ�: ";
	cin >> animal;
	// cin >> ps; �ϸ� �ȵǴ� ��

	ps = animal;
	cout << ps << "s!\n";
	cout << "strcpy() ��� ��:\n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << "strcpy() ��� ��:\n";
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
	cout << "pw �����Ϳ� 1�� ����:\n";
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "ps �����Ϳ� 1�� ����:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

	cout << "�迭 ǥ��� �� ���ҿ� ����\n";
	cout << "stacks[0] = " << stacks[0];
	cout << ", stacks[1] = " << stacks[1] << endl;
	cout << "������ ǥ��� �� ���ҿ� ����\n";
	cout << "*stacks = " << *stacks;
	cout << ", *(stacks + 1) = " << *(stacks + 1) << endl;

	cout << sizeof wages << " = wages �迭�� ũ��\n";
	cout << sizeof pw << " = pw �������� ũ��\n";
}

void arraynew()
{
	double* p3 = new double[3];

	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1]�� " << p3[1] << "�Դϴ�.\n";
	p3 = p3 + 1;
	cout << "������ p3[0]�� " << p3[0] << "�̰�, ";
	cout << "p3[1]�� " << p3[1] << "�Դϴ�.\n";
	p3 = p3 - 1;

	delete[] p3;
}

void use_new()
{
	int nights = 1001;
	int* pt = new int;
	*pt = 1001;

	cout << "nights�� �� = ";
	cout << nights << ": �޸� ��ġ " << &nights << endl;
	cout << "int ��";
	cout << "�� = " << *pt << ": �޸� ��ġ = " << pt << endl;

	double* pd = new double;
	*pd = 10000001.0;

	cout << "double ��";
	cout << "�� = " << *pd << ": �޸� ��ġ = " << pd << endl;
	cout << "������ pd�� �޸� ��ġ: " << &pd << endl;
	cout << "pt�� ũ�� = " << sizeof(pt);
	cout << ": *pt�� ũ�� = " << sizeof(*pt) << endl;
	cout << "pd�� ũ�� = " << sizeof(pd);
	cout << ": *pd�� ũ�� = " << sizeof(*pd) << endl;
}

void init_ptr()
{
	int higgens = 5;
	int* pt = &higgens;

	cout << "higgens�� �� = " << higgens << ", higgens�� �ּ� = " << &higgens << endl;
	cout << "*pt�� �� = " << *pt << ", pt�� �� = " << pt << endl;
}

void pointer()
{
	int updates = 6;
	int* p_updates;

	p_updates = &updates;

	cout << "��: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;

	cout << "�ּ�: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;

	*p_updates = *p_updates + 1;
	cout << "����� updates = " << updates << endl;
}

void address()
{
	int donuts = 6;
	double cups = 4.5;

	cout << "donuts�� �� = " << donuts;
	cout << ", donuts�� �ּ� = " << &donuts << endl;
	cout << "cups�� �� = " << cups;
	cout << ", cups�� �ּ� = " << &cups << endl;
}