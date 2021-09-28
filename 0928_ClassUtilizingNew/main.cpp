#include <iostream>
#include <cstdlib>
#include <ctime>
#include "strngbad.h"
#include "justTesting.h"
#include "queue0.h"

const int ArSize = 10;
const int MaxLen = 81;
const int MIN_PER_HR = 60;

bool newcustomer(double x) // �� ���� �����ߴ°�?
{
	return (std::rand() * x / RAND_MAX < 1);
}

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));
	cout << "��� ����: ���� ������ ATM\n";
	cout << "ť�� �ִ� ���̸� �Է��Ͻʽÿ�: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "�ùķ��̼� �ð��� �Է��Ͻʽÿ�: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;
	
	cout << "�ð��� ��� �� ���� �Է��Ͻʽÿ�: ";
	double perhour;
	cin >> perhour;
	double min_per_cust; // ��� �� ���� ���� (�� ����)
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;				// �� �� ������
	long turnaways = 0;		// ť�� ���� ���� �߱��� ���� �� ��
	long customers = 0;		// ť�� ���� �� �� ��
	long served = 0;		// �ùķ��̼ǿ��� �ŷ��� ó���� �� ��
	long sum_line = 0;		// ť�� ���� ����
	int wait_time = 0;		// ATM�� �� ������ ����ϴ� �ð�
	long line_wait = 0;		// ������ ���� ���� ����� ���� �ð�

	// �ùķ��̼� ����
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust)) // �� ���� �����ߴ�.
		{
			if (line.isfull())
				turnaways++; // �߱��� ���� �� �� ����
			else
			{
				customers++; // �� �� ����
				temp.set(cycle);
				line.enqueue(temp);
			}
		}

		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when(); // �� ���� ����� ���� �ð� ����
			served++; // �ŷ� ó�� �� �� ����
		}

		if (wait_time > 0)
			wait_time--;

		sum_line += line.queuecount(); // ť�� ���� ���� ����
	}

	if (customers > 0)
	{
		cout << " ť�� ���� �� �� ��: " << customers << endl;
		cout << "�ŷ��� ó���� �� ��: " << served << endl;
		cout << "  �߱��� ���� �� ��: " << turnaways << endl;
		cout << "       ��� ť�� ����: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "       ��� ��� �ð�: " << (double)line_wait / served << "��\n";
	}
	else
		cout << "���� �� �� �����ϴ�!\n";
	cout << "�Ϸ�!\n";
	
	return 0;
}

void sayingtset2()
{
	char* buffer = new char[BUF];
	JustTesting* pc1, * pc2;
	pc1 = new (buffer) JustTesting;
	pc2 = new JustTesting("Heap1", 20);

	cout << "�޸� ��� �ּ�:\n" << "buffer: " << (void*)buffer << " heap: " << pc2 << endl;
	cout << "�޸� ����:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	JustTesting* pc3, * pc4;
	pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "�޸� ����:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();

	delete pc2;
	delete pc4;
	pc3->~JustTesting();
	pc1->~JustTesting();
	delete[] buffer;
	cout << "����\n";

}

void sayingtest()
{
	using namespace std;
	StringBad name;
	cout << "�ȳ��Ͻʴϱ�? ������ ��� �ǽʴϱ�?\n";
	cin >> name;

	cout << name << " ��! ������ �츮 �Ӵ� " << ArSize << "���� �Է��� �ֽʽÿ�(�������� Enter):\n";
	StringBad sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;

	if (total > 0)
	{
		cout << "(������ ���� �Ӵ���� �Է��ϼ̽��ϴ�.)\n";
		for (i = 0; i < total; i++)
			cout << sayings[i] << "\n";

		StringBad* shortest = &sayings[0];
		StringBad* first = &sayings[0];
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "���� ª�� �Ӵ�:\n" << *shortest << endl;
		srand(time(0));
		int choice = rand() % total;

		StringBad* favorite = new StringBad(sayings[choice]);
		cout << "���� ���� �����ϴ� �Ӵ�:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "�˰� �ִ� �Ӵ��� �ϳ��� �����?\n";

	cout << "���α׷��� �����մϴ�.\n";
}