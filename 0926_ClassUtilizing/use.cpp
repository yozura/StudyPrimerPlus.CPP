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
	cout << "double형으로 변환 => ";
	cout << "Poppins: " << p_wt << "파운드\n";
	cout << "int형으로 변환 => ";
	cout << "Poppins: " << int(poppins) << "파운드\n";

	return 0;
}

void display(const Stonewt& st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "와! ";
		st.show_lbs();
	}
}

void useston()
{
	Stonewt pavarotti = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	cout << "테너 가수의 몸무게: ";
	pavarotti.show_stn();
	cout << "탐정의 몸무게: ";
	wolfe.show_stn();
	cout << "대통령의 몸무게: ";
	taft.show_lbs();

	pavarotti = 276.8;
	taft = 325;
	cout << "저녁 식사를 마친 후 테너 가수의 몸무게: ";
	pavarotti.show_stn();

	cout << "저녁 식사를 마친 후 대통령의 몸무게: ";
	taft.show_lbs();

	display(taft, 2);
	cout << "레슬링 선수는 그보다 더 무겁다.\n";
	display(422, 2);
	cout << "비만은 건강의 최대의 적이다.\n";

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

	cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	while (cin >> target)
	{
		cout << "저장할 파일의 이름을 입력하십시오(확장자 포함): ";
		cin >> str;

		cout << "보폭을 입력하십시오: ";
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
			fout << result << " #" << steps << "번째 걸음\n";
		}
		cout << steps << " 걸음을 걸은 후 술고래의 현재 위치:\n";
		cout << result << endl;
		fout.close();
		result.polar_mode();
		cout << " 또는\n" << result << endl;
		cout << "걸음당 기둥에서 벗어난 평균 거리 = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	}

	cout << "프로그램을 종료합니다.\n";
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

	cout << "Aida 와 Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca; // operator+ 사용
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
	total = weeding + waxing; // operator+ 사용
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
