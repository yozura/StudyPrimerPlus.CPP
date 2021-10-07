#include <iostream>
#include <cstring>
#include "wine.h"
#include "worker0.h"
#include "queue.h"
#include "person.h"
#include "emp.h"

using namespace std;

const int SIZE = 5;

int main()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();

	highfink hf(ma, "Curly Kew");
	hf.ShowAll();

	cout << "���� ����� ���� �ƹ� Ű�� �����ʽÿ�:\n";
	cin.get();
	
	highfink hf2;
	hf2.SetAll();

	cout << "abstr_emp* �������� ���:\n";
	abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();

	return 0;
}

void useVirtualInheritance()
{
	srand(time(0));

	Person ps("Com", "Puter");
	Gunslinger gl("Kay", "Gay", 5);
	PokerPlayer pp("La", "Vita");
	BadDude bd("Mc", "Nald", 100);

	cout << "����� ����: ";
	ps.Show();

	cout << "�������� ������: " << gl.Draw() << '\n';
	cout << "�������� ����: ";
	gl.Show();

	cout << "��Ŀ�÷��̾��� �� ��: " << pp.Draw() << '\n';
	cout << "��Ŀ�÷��̾��� ����: ";
	pp.Show();

	cout << "�b���� ������: " << bd.Gdraw() << '\n';
	cout << "�b���� �� ��: " << bd.Cdraw() << '\n';
	cout << "�b���� ����: ";
	bd.Show();

	cout << "\n����� �����̷� ���ߴ�? ";
	ps = gl;
	ps.Show();

	cout << "\n����� ��Ŀ�÷��̾�� ���ߴ�? ";
	ps = pp;
	ps.Show();

	cout << "\n����� �b������ ���ߴ�? ";
	ps = bd;
	ps.Show();
}

void useTemplateQueue()
{
	Queue<Worker*> q(SIZE);

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "������ �Է��Ͻʽÿ�:\n";
		cout << "w: ������\ts: ����\t\t" << "t: ���� �� ������\tq: ����\n";
		cin >> choice;
		// strchr �Լ��� s1 ���ڿ� �ȿ� s2 ���ڰ� �߰ߵǸ� �߰ߵ� ������ �ּҸ� ��ȯ�ϴ� �Լ�.
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q �߿��� �ϳ��� �����Ͻʽÿ�: ";
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
		// q.peek��.. front�� item�� �ٲٱ� ������...
		// �� �տ���.. �������θ�,,. ����
		// �׷��� peek�� rear->item���� �ٲ��־����� �����۵��Ѵ�.
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
	cout << "���� �̸��� �Է��Ͻʽÿ�: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "��Ȯ �⵵ ������ �Է��Ͻÿ�: ";
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
	cout << more.Label() << " ��ü ����:" << more.sum() << endl;
	cout << "���α׷��� �����մϴ�.";
}