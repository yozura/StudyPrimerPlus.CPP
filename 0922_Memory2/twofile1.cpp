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
	cout << "new�� ��ġ ���� new�� ù ��° ȣ��: \n";
	pd1 = new double[N];
	pd2 = new (buffer) double[N];

	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "�޸� �ּ�:\n" << pd1 << " : ��" << (void*)buffer << " : ���� " << endl;
	cout << "�޸� ����:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd1[i] << "�� " << pd1[i] << ";";
		cout << &pd2[i] << "�� " << pd2[i] << endl;
	}

	cout << "\nnew�� ��ġ ���� new�� �� ��° ȣ��:\n";
	double* pd3, * pd4;
	pd3 = new double[N];
	pd4 = new (buffer) double[N];
	for (i = 0; i < N; i++)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "�޸� ����:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd3[i] << "�� " << pd3[i] << ";";
		cout << &pd4[i] << "�� " << pd4[i] << endl;
	}

	cout << "\nnew�� ��ġ ���� new�� �� ��° ȣ��:\n";
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "�޸� ����:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd1[i] << "�� " << pd1[i] << ";";
		cout << &pd2[i] << "�� " << pd2[i] << endl;
	}

	delete[] pd1;
	delete[] pd3;
}

void inputs()
{
	using namespace std;
	char input[ArSize];
	char next;

	cout << "�������� �� ���� �Է��Ͻʽÿ�:\n";
	cin.get(input, ArSize);
	while (cin)
	{
		cin.get(next);
		while (next != '\n')
			cin.get(next);
		strcount(input);
		cout << "���� ���� �Է��Ͻʽÿ� (�������� �� ���� �Է�):\n";
		cin.get(input, ArSize);
	}
	cout << "���α׷��� �����մϴ�.\n";
}

void strcount(const char* str)
{
	using namespace std;
	static int total = 0;
	int count = 0;

	cout << "\"" << str << "\"���� ";
	while (*str++)
		count++;
	total += count;
	cout << count << "���� ���ڰ� �ֽ��ϴ�.\n";
	cout << "���ݱ��� �� " << total << "���� ���ڸ� �Է��ϼ̽��ϴ�.\n";
}

void acc()
{
	using namespace std;
	cout << "main()�� �����ϴ� �� ������ �ּ�:\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
	remote_access();
}