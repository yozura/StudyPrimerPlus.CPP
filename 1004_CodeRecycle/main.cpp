#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include "student.h"
#include "worker0.h"
#include "stacktp.h"
#include "arraytp.h"
#include "pairs.h"
#include "tempmemb.h"
#include "tempparm.h"
#include "frnd2tmp.h"
#include "tmp2tmp.h"
#include "manyfrnd.h"

using std::cin;
using std::cout;
using std::endl;
using std::strchr;
using std::string;

const int pupils = 3;
const int quizzes = 5;
const int LIM = 4;
const int SIZE = 5;
const int Num = 10;

int main()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);
	cout << "hfi1, hfi2: ";
	show2(hfi1, hfi2);
	cout << "hfdb, hfi2: ";
	show2(hfdb, hfi2);
	return 0;
}

void useTemplateToTemplateBoundFriendMethod()
{
	counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);
	report(hfi1);
	report(hfi2);
	report(hfdb);
	cout << "counts<int>() 출력:\n";
	counts<int>();
	cout << "counts<double>() 출력:\n";
	counts<double>();
}

void useFriendTemplate()
{
	cout << "객체가 선언되지 않음 : ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "hfi1 선언 후 : ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "hfi2 선언 후 : ";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "hfdb 선언 후 : ";
	counts();
	report(hfi1);
	report(hfi2);
	report(hfdb);
}

void useParameterTemplate()
{
	Crab<Stack> nebula;
	int ni;
	double nb;
	cout << "4 3.5와 같이 int double 쌍을 입력하라(끝내려면 0 0):\n";
	while (cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}

	while (nebula.pop(ni, nb))
		cout << ni << ", " << nb << endl;
	cout << "프로그램을 종료합니다.\n";
}

void useTemplateMember()
{
	beta<double> guy(3.5, 3);
	cout << "T가 double로 설정되었습니다.\n";
	guy.Show();
	cout << "V가 double인 T로 설정되었고, 그 다음에 V가 int로 설정되었습니다.\n";
	cout << guy.blab(10, 2.3) << endl;
	cout << "U가 int로 설정되었습니다.\n";
	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U가 double로 설정되었습니다.\n";
	cout << "프로그램을 종료합니다.\n";
}

void useMultiTemplate()
{
	Pair<string, int> ratings[4] =
	{
		Pair<string, int>("이동갈비", 5),
		Pair<string, int>("태릉갈비", 4),
		Pair<string, int>("수원갈비", 5),
		Pair<string, int>("서서갈비", 3)
	};

	int joints = sizeof(ratings) / sizeof(Pair<string, int>);
	cout << "등급:\t갈비 종류\n";
	for (int i = 0; i < joints; i++)
		cout << ratings[i].second() << ":\t" << ratings[i].first() << endl;
	cout << "조정된 등급:\n";
	ratings[3].first() = "서서떡갈비";
	ratings[3].second() = 6;
	cout << ratings[3].second() << ":\t" << ratings[3].first() << endl;
}

void useRecursiveTemplate()
{
	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10> twodee;

	int i, j;
	for (i = 0; i < 10; i++)
	{
		sums[i] = 0;
		for (j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1) * (j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << twodee[i][j] << ' ';
		}
		cout << ": 합계 = ";
		cout.width(3);
		cout << sums[i] << ", 평균 = " << aves[i] << endl;
	}

	cout << "프로그램을 종료합니다.\n";
}

void useStackTemplateDMA()
{
	std::srand(std::time(0));
	cout << "스택의 크기를 입력하십시오: ";
	int stackSize;
	cin >> stackSize;

	Stack<const char*> st(stackSize);

	const char* in[Num] = {
		" 1: 노미호", " 2: 주리혜",
		" 3: 이몽룡", " 4: 성춘향",
		" 5: 이수일", " 6: 심순애",
		" 7: 박문수", " 8: 홍길동",
		" 9: 김두한", "10: 하야시"
	};

	const char* out[Num];
	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num) // 확률 50 : 50
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}

	cout << "\nin\n";
	for (int i = 0; i < Num; i++)
		cout << in[i] << endl;

	cout << "\nout\n";
	for (int i = 0; i < Num; i++)
		cout << out[i] << endl;

	cout << "프로그램을 종료합니다.\n";
}

void useStackTemplate()
{
	Stack<std::string> st;
	char ch;
	std::string po;
	cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n";
	cout << "종료하려면 Q를 입력하세요.\n";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "추가할 주문서의 번호를 입력하십시오: ";
			cin >> po;
			if (st.isfull())
				cout << "스택이 가득 차 있습니다.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "스택이 비어있습니다.\n";
			else
			{
				st.pop(po);
				cout << "#" << po << " 주문서를 처리했습니다.\n";
			}
			break;
		}
		cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n";
		cout << "종료하려면 Q를 입력하세요.\n";
	}

	cout << "프로그램을 종료합니다.\n";
}

void useABCWorkerMI()
{
	Worker* lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "직종을 입력하십시오:\n";
		cout << "w: 웨이터\ts: 가수\t\tt: 가수 겸 웨이터\tq: 종료\n";
		cin >> choice;
		// strchr(char*, int)
		// s1 문자열에 choice 문자값이 있는 주소를 return하는 함수
		// choice 문자가 없으면 NULL 포인터를 return
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q 중에서 하나를 선택하십시오: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': lolas[ct] = new Waiter; break;
		case 's': lolas[ct] = new Singer; break;
		case 't': lolas[ct] = new SingingWaiter; break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	cout << "\n사원 현황은 다음과 같습니다:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	cout << "프로그램을 종료합니다.";

}

void useWorker()
{
	Waiter bob("홍길동", 314L, 5);
	Singer bev("조수미", 522L, 3);

	Waiter w_temp;
	Singer s_temp;

	Worker* pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

	int i;
	for (i = 2; i < LIM; i++)
		pw[i]->Set();
	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		cout << '\n';
	}
}

void set(Student& sa, int n)
{
	cout << "학생의 이름을 입력하십시오: ";
	getline(cin, sa);
	cout << n << "회에 걸린 시험 점수를 모두 입력하십시오:\n";
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;
}

void useStudent()
{
	Student ada[pupils] = {
		Student(quizzes),
		Student(quizzes),
		Student(quizzes)
	};

	int i;
	for (i = 0; i < pupils; ++i)
		set(ada[i], quizzes);
	cout << "\n학생 리스트:\n";
	for (i = 0; i < pupils; ++i)
		cout << ada[i].Name() << endl;
	cout << "\n시험 결과:";
	for (i = 0; i < pupils; ++i)
	{
		cout << endl << ada[i];
		cout << "평균: " << ada[i].Average() << endl;
	}
	cout << "프로그램을 종료합니다.\n";
}