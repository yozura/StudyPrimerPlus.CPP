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
		cout << fn << " 파일을 열 수 없습니다. 끝.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "대물렌즈 초점거리를 mm 단위로 입력하시오: ";
	cin >> objective;
	double eps[LIMIT];
	cout << LIMIT << "가지 대안렌즈의 초점거리를 mm 단위로 입력하시오:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "대안렌즈 #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	cout << "종료\n";
}

void file_it(ostream& os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initital;
	initital = os.setf(ios_base::fixed);
	os.precision(0);
	os << "대물렌즈의 초점거리: " << fo << " mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(17);
	os << "대안렌즈 초점거리";
	os.width(15);
	os << "확대배율" << endl;
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

	cout << "문자열을 입력하시오: ";
	getline(cin, input);
	copy = input;
	cout << "입력한 문자열: " << input << endl;
	result = version1(input, "***");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;

	result = version2(input, "###");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;

	cout << "원래 문자열 재설정\n";
	input = copy;
	result = version3(input, "@@@");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;
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
	// 부분 초기화
	free_throws one = { "Ifelsa Branch", 13, 14 };
	free_throws two = { "Andor Knott", 10, 16 };
	free_throws three = { "Minnie Max", 7, 9 };
	free_throws four = { "Whily Looper", 5, 9 };
	free_throws five = { "Long Long", 6, 14 };
	free_throws team = { "Throwgoods", 0, 0 };

	// 초기화 안함
	free_throws dup;
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);

	// 리턴 값을 매개변수로
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);

	// 리턴 값을 대입 값으로
	dup = accumulate(team, five);
	cout << "team 출력:\n";
	display(team);
	cout << " 대입 이후 dup 출력:\n";
	display(dup);
	set_pc(four);

	// 문제의 소지가 있는 대입
	accumulate(dup, five) = four;
	cout << "문제 소지가 있는 대입 이후 dup 출력:\n";
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
	cout << " = " << x << "의 세제곱\n";
	cout << refcube(x);
	cout << " = " << x << "의 세제곱\n";
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

	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "참조를 이용하여 내용들을 교환:\n";
	swapr(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "포인터를 이용하여 내용들을 다시 교환:\n";
	swapp(&wallet1, &wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "값으로 전달하여 내용 교환 시도:\n";
	swapv(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";
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

	cout << "rats의 주소 = " << &rats;
	cout << ", rodents의 주소 = " << &rodents << endl;

	int bunnies = 50;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "bunnise의 주소 = " << &bunnies;
	cout << ", rats의 주소 = " << &rats;
	cout << ", rodents의 주소 = " << &rodents << endl;
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

	cout << "rats의 주소 = " << &rats;
	cout << ", rodents의 주소 = " << &rodents << endl;
}

void inlinefunc()
{
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5);
	cout << "a = " << a << ", b = " << b << endl;
	cout << "c = " << c;
	cout << ", c의 제곱 = " << square(c++) << endl;
	cout << "현재 c = " << c << endl;
}