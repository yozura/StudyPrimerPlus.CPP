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
	cout << "counts<int>() ���:\n";
	counts<int>();
	cout << "counts<double>() ���:\n";
	counts<double>();
}

void useFriendTemplate()
{
	cout << "��ü�� ������� ���� : ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "hfi1 ���� �� : ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "hfi2 ���� �� : ";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "hfdb ���� �� : ";
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
	cout << "4 3.5�� ���� int double ���� �Է��϶�(�������� 0 0):\n";
	while (cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}

	while (nebula.pop(ni, nb))
		cout << ni << ", " << nb << endl;
	cout << "���α׷��� �����մϴ�.\n";
}

void useTemplateMember()
{
	beta<double> guy(3.5, 3);
	cout << "T�� double�� �����Ǿ����ϴ�.\n";
	guy.Show();
	cout << "V�� double�� T�� �����Ǿ���, �� ������ V�� int�� �����Ǿ����ϴ�.\n";
	cout << guy.blab(10, 2.3) << endl;
	cout << "U�� int�� �����Ǿ����ϴ�.\n";
	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U�� double�� �����Ǿ����ϴ�.\n";
	cout << "���α׷��� �����մϴ�.\n";
}

void useMultiTemplate()
{
	Pair<string, int> ratings[4] =
	{
		Pair<string, int>("�̵�����", 5),
		Pair<string, int>("�¸�����", 4),
		Pair<string, int>("��������", 5),
		Pair<string, int>("��������", 3)
	};

	int joints = sizeof(ratings) / sizeof(Pair<string, int>);
	cout << "���:\t���� ����\n";
	for (int i = 0; i < joints; i++)
		cout << ratings[i].second() << ":\t" << ratings[i].first() << endl;
	cout << "������ ���:\n";
	ratings[3].first() = "����������";
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
		cout << ": �հ� = ";
		cout.width(3);
		cout << sums[i] << ", ��� = " << aves[i] << endl;
	}

	cout << "���α׷��� �����մϴ�.\n";
}

void useStackTemplateDMA()
{
	std::srand(std::time(0));
	cout << "������ ũ�⸦ �Է��Ͻʽÿ�: ";
	int stackSize;
	cin >> stackSize;

	Stack<const char*> st(stackSize);

	const char* in[Num] = {
		" 1: ���ȣ", " 2: �ָ���",
		" 3: �̸���", " 4: ������",
		" 5: �̼���", " 6: �ɼ���",
		" 7: �ڹ���", " 8: ȫ�浿",
		" 9: �����", "10: �Ͼ߽�"
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
		else if (std::rand() % 2 && nextin < Num) // Ȯ�� 50 : 50
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

	cout << "���α׷��� �����մϴ�.\n";
}

void useStackTemplate()
{
	Stack<std::string> st;
	char ch;
	std::string po;
	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n";
	cout << "�����Ϸ��� Q�� �Է��ϼ���.\n";
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
			cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�: ";
			cin >> po;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "������ ����ֽ��ϴ�.\n";
			else
			{
				st.pop(po);
				cout << "#" << po << " �ֹ����� ó���߽��ϴ�.\n";
			}
			break;
		}
		cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n";
		cout << "�����Ϸ��� Q�� �Է��ϼ���.\n";
	}

	cout << "���α׷��� �����մϴ�.\n";
}

void useABCWorkerMI()
{
	Worker* lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "������ �Է��Ͻʽÿ�:\n";
		cout << "w: ������\ts: ����\t\tt: ���� �� ������\tq: ����\n";
		cin >> choice;
		// strchr(char*, int)
		// s1 ���ڿ��� choice ���ڰ��� �ִ� �ּҸ� return�ϴ� �Լ�
		// choice ���ڰ� ������ NULL �����͸� return
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q �߿��� �ϳ��� �����Ͻʽÿ�: ";
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

	cout << "\n��� ��Ȳ�� ������ �����ϴ�:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	cout << "���α׷��� �����մϴ�.";

}

void useWorker()
{
	Waiter bob("ȫ�浿", 314L, 5);
	Singer bev("������", 522L, 3);

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
	cout << "�л��� �̸��� �Է��Ͻʽÿ�: ";
	getline(cin, sa);
	cout << n << "ȸ�� �ɸ� ���� ������ ��� �Է��Ͻʽÿ�:\n";
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
	cout << "\n�л� ����Ʈ:\n";
	for (i = 0; i < pupils; ++i)
		cout << ada[i].Name() << endl;
	cout << "\n���� ���:";
	for (i = 0; i < pupils; ++i)
	{
		cout << endl << ada[i];
		cout << "���: " << ada[i].Average() << endl;
	}
	cout << "���α׷��� �����մϴ�.\n";
}