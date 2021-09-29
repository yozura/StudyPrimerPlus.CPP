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
	srand(time(0));			// rand()�� ������ �ʱ�ȭ

	cout << "��� ����: ���� ������ �ڵ� ���ޱ�\n";
	cout << "ť�� �ִ� ���̸� �Է��Ͻʽÿ�: ";
	int qs;
	cin >> qs;

	int hours;			// �ùķ��̼� �ð� ��
	while (1)
	{
		cout << "�ùķ��̼� �ð� ���� �Է��Ͻʽÿ�(>= 100): ";
		cin >> hours;
		if (hours >= 100)
			break;
	}
	// �ùķ��̼��� 1�п� 1�ֱ⸦ �����Ѵ�
	long cyclelimit = MIN_PER_HR * hours;	// �ùķ��̼� �ֱ� ��

	double perhour;			// �ð��� ��� �� ��
	double min_per_cust; 	// ��� �� ���� ����(�� ����)
	double avg_wait_time = 0;	// ��� ��� �ð�(�� ����)

	Item temp;					// �� �� ������
	long turnaways;					// ť�� ���� ���� �߱��� ���� �� ��
	long customers;					// ť�� ���� �� �� ��
	long served1, served2;			// ��1 ť, ��2 ť���� �ŷ��� ó���� �� ��
	long sum_line1, sum_line2;		// ��1 ť, ��2 ť�� ���� ����
	int wait_time1, wait_time2;		// ��1 �ڵ� ���ޱ�, ��2 �ڵ� ���ޱⰡ �� ������ ����ϴ� �ð�
	long line_wait1, line_wait2;	// ��1 ť, ��2 ť���� ������ ���� ���� ����ϴ� ���� �ð�

	for (perhour = 1; avg_wait_time < 1; perhour++)		// ��� ��� �ð��� 1�� �̻��� �Ǹ� ������ Ż���Ѵ�
	{
		Queue line1(qs);	// line1, line2 ť���� �ִ� qs����� ����� �� �ִ�
		Queue line2(qs);

		min_per_cust = MIN_PER_HR / perhour;
		turnaways = 0;
		customers = 0;
		served1 = served2 = 0;
		sum_line1 = sum_line2 = 0;
		wait_time1 = wait_time2 = 0;
		line_wait1 = line_wait2 = 0;

		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))		// �� ���� �����ߴ�
			{
				if (line1.isfull() && line2.isfull())
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle);			// cycle�� ���� �ð��� �ȴ�
					if (line1.queuecount() < line2.queuecount())
						line1.enqueue(temp); 	// ��1 ť�� �� ���� �߰��Ѵ�
					else
						line2.enqueue(temp);	// ��2 ť�� �� ���� �߰��Ѵ�
				}
			}
			if (wait_time1 <= 0 && !line1.isempty())
			{
				line1.dequeue(temp); 			// ��1 ť���� ���� ���� �޴´�
				wait_time1 = temp.ptime();		// wait_time1�� �����Ѵ�
				line_wait1 += cycle - temp.when();
				served1++;
			}
			if (wait_time2 <= 0 && !line2.isempty())
			{
				line2.dequeue(temp); 			// ��2 ť���� ���� ���� �޴´�
				wait_time2 = temp.ptime();		// wait_time2�� �����Ѵ�
				line_wait2 += cycle - temp.when();
				served2++;
			}

			if (wait_time1 > 0)
				wait_time1--;
			if (wait_time2 > 0)
				wait_time2--;

			sum_line1 += line1.queuecount();
			sum_line2 += line1.queuecount();
		}

		if (customers > 0)
		{
			cout << "-------------------------------\n";
			cout << "  �ð��� ��� �� ��: " << (int)perhour << '\n';
			cout << " ť�� ���� �� �� ��: " << customers << '\n';
			cout << "�ŷ��� ó���� �� ��: " << served1 + served2 << '\n';
			cout << "  �߱��� ���� �� ��: " << turnaways << '\n';
			cout << "       ��� ť�� ����: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout.setf(ios_base::showpoint);
			cout << (double)((sum_line1 + sum_line2) / 2) / cyclelimit << '\n';
			cout << "       ��� ��� �ð�: "
				<< (double)((line_wait1 + line_wait2) / 2) / (served1 + served2) << "��\n";
		}
		else
			cout << "���� �� �� �����ϴ�!\n";

		avg_wait_time = (double)((line_wait1 + line_wait2) / 2) / (served1 + served2);
	}

	cout << "\n" << "�ڵ� ���ޱ⸦ 2�� ��ġ���� ��쿡,\n"
		<< "�ð��� ��� �� ���� " << (int)perhour - 1 << "�� �̻��� �Ǹ�,\n"
		<< "��� ��� �ð��� 1���� �ʰ��ϰ� �˴ϴ�.\n";

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