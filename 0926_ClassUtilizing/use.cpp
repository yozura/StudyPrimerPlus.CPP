#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "mytime0.h"
#include "mytime1.h"
#include "mytime2.h"
#include "vect.h"
#include "stonewt.h"
using std::cout;

int main()
{
	Stonewt poppins(9, 2.8);
	double p_wt = double(poppins);
	cout << "double������ ��ȯ => ";
	cout << "Poppins: " << p_wt << "�Ŀ��\n";
	cout << "int������ ��ȯ => ";
	cout << "Poppins: " << int(poppins) << "�Ŀ��\n";

	return 0;
}

void display(const Stonewt& st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "��! ";
		st.show_lbs();
	}
}

void useston()
{
	Stonewt pavarotti = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	cout << "�׳� ������ ������: ";
	pavarotti.show_stn();
	cout << "Ž���� ������: ";
	wolfe.show_stn();
	cout << "������� ������: ";
	taft.show_lbs();

	pavarotti = 276.8;
	taft = 325;
	cout << "���� �Ļ縦 ��ģ �� �׳� ������ ������: ";
	pavarotti.show_stn();

	cout << "���� �Ļ縦 ��ģ �� ������� ������: ";
	taft.show_lbs();

	display(taft, 2);
	cout << "������ ������ �׺��� �� ���̴�.\n";
	display(422, 2);
	cout << "���� �ǰ��� �ִ��� ���̴�.\n";

}

void randwalk()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	ofstream fout;
	string str;

	cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	while (cin >> target)
	{
		cout << "������ ������ �̸��� �Է��Ͻʽÿ�(Ȯ���� ����): ";
		cin >> str;

		cout << "������ �Է��Ͻʽÿ�: ";
		if (!(cin >> dstep))
			break;

		fout.open(str);
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POLAR);
			result = result + step;
			steps++;
			result.polar_mode();
			fout << result << " : ";
			result.rect_mode();
			fout << result << " #" << steps << "��° ����\n";
		}
		cout << steps << " ������ ���� �� ������ ���� ��ġ:\n";
		cout << result << endl;
		fout.close();
		result.polar_mode();
		cout << " �Ǵ�\n" << result << endl;
		cout << "������ ��տ��� ��� ��� �Ÿ� = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	}

	cout << "���α׷��� �����մϴ�.\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
}

void usetimeFriend()
{
	using std::cout;
	using std::endl;

	Tm aida(3, 35);
	Tm tosca(2, 48);
	Tm temp;

	cout << "Aida �� Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca; // operator+ ���
	cout << "Aida + Tosca :" << temp << endl;
	temp = aida * 1.17;	// operator*
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10 * Tosca: " << 10 * tosca << endl;
}

void usetime2()
{
	using std::cout;
	using std::endl;

	Tm weeding(4, 35);
	Tm waxing(2, 47);
	Tm total;
	Tm diff;
	Tm adjusted;

	cout << "weeding time = ";
	weeding.show();
	cout << endl;

	cout << "waxing time = ";
	waxing.show();
	cout << endl;

	cout << "total work time = ";
	total = weeding + waxing; // operator+ ���
	total.show();
	cout << endl;

	diff = weeding - waxing;
	cout << "weeding time - waxing time = ";
	diff.show();
	cout << endl;

	adjusted = total * 1.5;
	cout << "adjusted work time = ";
	adjusted.show();
	cout << endl;
}

void usetime1()
{
	using std::cout;
	using std::endl;

	Tim planning;
	Tim coding(2, 40);
	Tim fixing(5, 55);
	Tim extra(6, 60);
	Tim virgin(6, 80);
	Tim total;

	cout << "planning time = ";
	planning.show();
	cout << endl;

	cout << "coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;

	cout << "extra time = ";
	extra.show();
	cout << endl;

	cout << "virgin time = ";
	virgin.show();
	cout << endl;

	total = coding.operator+(fixing);
	cout << "coding.operator+(fixing) = ";
	total.show();
	cout << endl;

	total = coding + fixing;
	cout << "coding + fixing = ";
	total.show();
	cout << endl;

	total = coding + fixing + extra + virgin;
	cout << "coding + fixing + extra + virgin = ";
	total.show();
	cout << endl;

	total = coding.operator+(fixing.operator+(extra).operator+(virgin));
	cout << "coding.operator+(fixing.operator+(extra).operator+(virgin)) = ";
	total.show();
	cout << endl;

}

void usetime0()
{
	using std::cout;
	using std::endl;

	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time extra(6, 60);
	Time virgin(6, 80);
	Time total;

	cout << "planning time = ";
	planning.show();
	cout << endl;

	cout << "coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;

	cout << "extra time = ";
	extra.show();
	cout << endl;

	cout << "virgin time = ";
	virgin.show();
	cout << endl;

	total = coding.sum(fixing);
	cout << "coding.sum(fixing) = ";
	total.show();
	cout << endl;
}
