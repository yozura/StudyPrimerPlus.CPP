#include <iostream>
#include <cstdlib>
#include <ctime>
#include "strngbad.h"
#include "justTesting.h"
#include "queue0.h"

const int ArSize = 10;
const int MaxLen = 81;
const int MIN_PER_HR = 60;

bool newcustomer(double x) // 새 고객이 도착했는가?
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
	cout << "사례 연구: 히서 은행의 ATM\n";
	cout << "큐의 최대 길이를 입력하십시오: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "시뮬레이션 시간을 입력하십시오: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;
	
	cout << "시간당 평균 고객 수를 입력하십시오: ";
	double perhour;
	cin >> perhour;
	double min_per_cust; // 평균 고객 도착 간격 (분 단위)
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;				// 새 고객 데이터
	long turnaways = 0;		// 큐가 가득 차서 발길을 돌린 고객 수
	long customers = 0;		// 큐에 줄을 선 고객 수
	long served = 0;		// 시뮬레이션에서 거래를 처리한 고객 수
	long sum_line = 0;		// 큐의 누적 길이
	int wait_time = 0;		// ATM이 빌 때까지 대기하는 시간
	long line_wait = 0;		// 고객들이 줄을 서서 대기한 누적 시간

	// 시뮬레이션 시작
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust)) // 새 고객이 도착했다.
		{
			if (line.isfull())
				turnaways++; // 발길을 돌린 고객 수 증가
			else
			{
				customers++; // 고객 수 증가
				temp.set(cycle);
				line.enqueue(temp);
			}
		}

		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when(); // 줄 서서 대기한 누적 시간 증가
			served++; // 거래 처리 고객 수 증가
		}

		if (wait_time > 0)
			wait_time--;

		sum_line += line.queuecount(); // 큐의 누적 길이 증가
	}

	if (customers > 0)
	{
		cout << " 큐에 줄을 선 고객 수: " << customers << endl;
		cout << "거래를 처리한 고객 수: " << served << endl;
		cout << "  발길을 돌린 고객 수: " << turnaways << endl;
		cout << "       평균 큐의 길이: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "       평균 대기 시간: " << (double)line_wait / served << "분\n";
	}
	else
		cout << "고객이 한 명도 없습니다!\n";
	cout << "완료!\n";
	
	return 0;
}

void sayingtset2()
{
	char* buffer = new char[BUF];
	JustTesting* pc1, * pc2;
	pc1 = new (buffer) JustTesting;
	pc2 = new JustTesting("Heap1", 20);

	cout << "메모리 블록 주소:\n" << "buffer: " << (void*)buffer << " heap: " << pc2 << endl;
	cout << "메모리 내용:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	JustTesting* pc3, * pc4;
	pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "메모리 내용:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();

	delete pc2;
	delete pc4;
	pc3->~JustTesting();
	pc1->~JustTesting();
	delete[] buffer;
	cout << "종료\n";

}

void sayingtest()
{
	using namespace std;
	StringBad name;
	cout << "안녕하십니까? 성함이 어떻게 되십니까?\n";
	cin >> name;

	cout << name << " 씨! 간단한 우리 속담 " << ArSize << "개만 입력해 주십시오(끝내려면 Enter):\n";
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
		cout << "(다음과 같은 속담들을 입력하셨습니다.)\n";
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
		cout << "가장 짧은 속담:\n" << *shortest << endl;
		srand(time(0));
		int choice = rand() % total;

		StringBad* favorite = new StringBad(sayings[choice]);
		cout << "내가 가장 좋아하는 속담:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "알고 있는 속담이 하나도 없어요?\n";

	cout << "프로그램을 종료합니다.\n";
}