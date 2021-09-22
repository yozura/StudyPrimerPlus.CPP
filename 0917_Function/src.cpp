#include "main.h"

int main()
{
	

	return 0;
}

void filefunc()
{
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << fn << " ������ �� �� �����ϴ�. ��.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "�빰���� �����Ÿ��� mm ������ �Է��Ͻÿ�: ";
	cin >> objective;
	double eps[LIMIT];
	cout << LIMIT << "���� ��ȷ����� �����Ÿ��� mm ������ �Է��Ͻÿ�:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "��ȷ��� #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	cout << "����\n";
}

void file_it(ostream& os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initital;
	initital = os.setf(ios_base::fixed);
	os.precision(0);
	os << "�빰������ �����Ÿ�: " << fo << " mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(17);
	os << "��ȷ��� �����Ÿ�";
	os.width(15);
	os << "Ȯ�����" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(17);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initital);
}

void strquote()
{
	string input;
	string copy;
	string result;

	cout << "���ڿ��� �Է��Ͻÿ�: ";
	getline(cin, input);
	copy = input;
	cout << "�Է��� ���ڿ�: " << input << endl;
	result = version1(input, "***");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;

	result = version2(input, "###");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;

	cout << "���� ���ڿ� �缳��\n";
	input = copy;
	result = version3(input, "@@@");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;
}

string version1(const string& s1, const string& s2)
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}

const string& version2(string& s1, const string& s2)
{
	s1 = s2 + s1 + s2;
	return s1;
}

const string& version3(string& s1, const string& s2)
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}

void strc_ref()
{
	// �κ� �ʱ�ȭ
	free_throws one = { "Ifelsa Branch", 13, 14 };
	free_throws two = { "Andor Knott", 10, 16 };
	free_throws three = { "Minnie Max", 7, 9 };
	free_throws four = { "Whily Looper", 5, 9 };
	free_throws five = { "Long Long", 6, 14 };
	free_throws team = { "Throwgoods", 0, 0 };

	// �ʱ�ȭ ����
	free_throws dup;
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);

	// ���� ���� �Ű�������
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);

	// ���� ���� ���� ������
	dup = accumulate(team, five);
	cout << "team ���:\n";
	display(team);
	cout << " ���� ���� dup ���:\n";
	display(dup);
	set_pc(four);

	// ������ ������ �ִ� ����
	accumulate(dup, five) = four;
	cout << "���� ������ �ִ� ���� ���� dup ���:\n";
	display(dup);
}

void display(const free_throws& ft)
{
	cout << "Name: " << ft.name << '\n';
	cout << "Made: " << ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws& ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
	else
		ft.percent = 0;
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}

void cubes()
{
	double x = 3.0;

	cout << cube(x);
	cout << " = " << x << "�� ������\n";
	cout << refcube(x);
	cout << " = " << x << "�� ������\n";
}

double cube(double a)
{
	a *= a * a;
	return a;
}

double refcube(double& ra)
{ 
	ra *= ra * ra;
	return ra;
}

void swaps()
{
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "���� 1 = " << wallet1 << "��";
	cout << ", ���� 2 = " << wallet2 << "��\n";

	cout << "������ �̿��Ͽ� ������� ��ȯ:\n";
	swapr(wallet1, wallet2);
	cout << "���� 1 = " << wallet1 << "��";
	cout << ", ���� 2 = " << wallet2 << "��\n";

	cout << "�����͸� �̿��Ͽ� ������� �ٽ� ��ȯ:\n";
	swapp(&wallet1, &wallet2);
	cout << "���� 1 = " << wallet1 << "��";
	cout << ", ���� 2 = " << wallet2 << "��\n";

	cout << "������ �����Ͽ� ���� ��ȯ �õ�:\n";
	swapv(wallet1, wallet2);
	cout << "���� 1 = " << wallet1 << "��";
	cout << ", ���� 2 = " << wallet2 << "��\n";
}

void swapr(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swapp(int* p, int* q)
{
	int temp;
	temp = *q;
	*q = *p;
	*p = temp;
}

void swapv(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void secref()
{
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats�� �ּ� = " << &rats;
	cout << ", rodents�� �ּ� = " << &rodents << endl;

	int bunnies = 50;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "bunnise�� �ּ� = " << &bunnies;
	cout << ", rats�� �ּ� = " << &rats;
	cout << ", rodents�� �ּ� = " << &rodents << endl;
}

void firstref()
{
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats�� �ּ� = " << &rats;
	cout << ", rodents�� �ּ� = " << &rodents << endl;
}

void inlinefunc()
{
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5);
	cout << "a = " << a << ", b = " << b << endl;
	cout << "c = " << c;
	cout << ", c�� ���� = " << square(c++) << endl;
	cout << "���� c = " << c << endl;
}