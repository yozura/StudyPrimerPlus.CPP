#include <iostream>
#include <new>

int tom = 3;
int dick = 30;
static int harry = 300;

const int BUF = 512;
const int N = 5;
const int ArSize = 10;

char buffer[BUF];

void remote_access();
void strcount(const char* str);

void anyway()
{
	using namespace std;

	double* pd1, * pd2;
	int i;
	cout << "new와 위치 지정 new의 첫 번째 호출: \n";
	pd1 = new double[N];
	pd2 = new (buffer) double[N];

	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "메모리 주소:\n" << pd1 << " : 힙" << (void*)buffer << " : 정적 " << endl;
	cout << "메모리 내용:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd1[i] << "에 " << pd1[i] << ";";
		cout << &pd2[i] << "에 " << pd2[i] << endl;
	}

	cout << "\nnew와 위치 지정 new의 두 번째 호출:\n";
	double* pd3, * pd4;
	pd3 = new double[N];
	pd4 = new (buffer) double[N];
	for (i = 0; i < N; i++)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "메모리 내용:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd3[i] << "에 " << pd3[i] << ";";
		cout << &pd4[i] << "에 " << pd4[i] << endl;
	}

	cout << "\nnew와 위치 지정 new의 세 번째 호출:\n";
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "메모리 내용:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd1[i] << "에 " << pd1[i] << ";";
		cout << &pd2[i] << "에 " << pd2[i] << endl;
	}

	delete[] pd1;
	delete[] pd3;
}

void inputs()
{
	using namespace std;
	char input[ArSize];
	char next;

	cout << "영문으로 한 행을 입력하십시오:\n";
	cin.get(input, ArSize);
	while (cin)
	{
		cin.get(next);
		while (next != '\n')
			cin.get(next);
		strcount(input);
		cout << "다음 행을 입력하십시오 (끝내려면 빈 행을 입력):\n";
		cin.get(input, ArSize);
	}
	cout << "프로그램을 종료합니다.\n";
}

void strcount(const char* str)
{
	using namespace std;
	static int total = 0;
	int count = 0;

	cout << "\"" << str << "\"에는 ";
	while (*str++)
		count++;
	total += count;
	cout << count << "개의 문자가 있습니다.\n";
	cout << "지금까지 총 " << total << "개의 문자를 입력하셨습니다.\n";
}

void acc()
{
	using namespace std;
	cout << "main()이 보고하는 세 변수의 주소:\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
	remote_access();
}