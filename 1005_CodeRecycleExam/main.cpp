#include <iostream>
#include <cstring>
#include "wine.h"
#include "worker0.h"
#include "queue.h"

using namespace std;

const int SIZE = 5;

int main()
{
	
	return 0;
}

void useTemplateQueue()
{
	Queue<Worker*> q(SIZE);

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "직종을 입력하십시오:\n";
		cout << "w: 웨이터\ts: 가수\t\t" << "t: 가수 겸 웨이터\tq: 종료\n";
		cin >> choice;
		// strchr 함수는 s1 문자열 안에 s2 문자가 발견되면 발견된 문자의 주소를 반환하는 함수.
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q 중에서 하나를 선택하십시오: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': q.enqueue(new Waiter()); break;
		case 's': q.enqueue(new Singer()); break;
		case 't': q.enqueue(new SingingWaiter()); break;
		}
		cin.get();
		// q.peek은.. front의 item만 바꾸기 때무네...
		// 맨 앞에꺼.. 기준으로만,,. ㅎㅎ
		// 그래서 peek을 rear->item으로 바꿔주었으니 정상작동한다.
		q.peek()->Set();
	}

	for (int i = 0; i < SIZE; i++)
	{
		Worker* temp;
		q.dequeue(temp);
		if (temp != NULL)
			temp->Show();
		std::cout << '\n';
		delete temp;
	}
}

void useValArrayContainment()
{
	cout << "와인 이름을 입력하십시오: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "수확 년도 개수를 입력하시오: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << more.Label() << " 전체 수량:" << more.sum() << endl;
	cout << "프로그램을 종료합니다.";
}