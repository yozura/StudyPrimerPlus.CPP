#include <iostream>
#include <string>
#include <cfloat>
#include <cmath>
#include <new>
#include <cstdlib>
#include <stdexcept>
#include "queuetp.h"
#include "tv.h"
#include "exc_mean.h"
#include "sales.h"

using namespace std;

struct Big
{
	double stuff[20000];
};

class demo
{
private:
	string word;
public:
	demo(const string& str)
	{
		word = str;
		cout << "demo " << word << " 생성\n";
	}
	~demo()
	{
		cout << "demo " << word << " 파괴\n";
	}
	void show() const
	{
		cout << "demo " << word << " 생존\n";
	}
};

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);
double means(double a, double b) throw(bad_hmean, bad_gmean);

int main()
{
	double vals1[12] =
	{
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544
	};
	
	double vals2[12] =
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};

	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);
	cout << "첫 번째 try 블록:\n";
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{
			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; ++i)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "try 블록 1의 끝.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "잘못된 인덱스: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "잘못된 인덱스: " << bad.bi_val() << endl;
	}

	cout << "\n 다음 try 블록\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "try 블록 2의 끝.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "잘못된 인덱스: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "잘못된 인덱스: " << bad.bi_val() << endl;
	}
	cout << "프로그램을 종료합니다.\n";
	
	return 0;
}

void useNewexcep()
{
	Big* pb;
	try {
		cout << "큰 메모리 블록 대입을 요청하고 있습니다.\n";
		pb = new Big[10000];
		cout << "메모리 블록 대입 요청이 거부되었습니다.\n";
	}
	catch (bad_alloc& ba)
	{
		cout << "예외가 감지되었습니다!\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "메모리 블록이 성공적으로 대입되었습니다.\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[] pb;
}

void useUnwindingTheStack()
{
	double x, y, z;
	{
		demo d1("found in block in main()");
		cout << "두 수를 입력하십시오: ";
		while (cin >> x >> y)
		{
			try {
				z = means(x, y);
				cout << x << "와 " << y << "의 평균의 평균은 " << z << endl;
				cout << "다음 두 수를 입력하십시오: ";
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
				cout << "다시 하십시오.\n";
				continue;
			}
			catch (bad_gmean& hg)
			{
				cout << hg.mesg();
				cout << "사용된 두 값: " << hg.v1 << ", " << hg.v2 << endl;
				cout << "죄송합니다. 더 이상 진행할 수 없습니다.\n";
				break;
			}
		}
		d1.show();
	}
	cout << "프로그램을 종료합니다.";
	cin.get();
	cin.get();
}

double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch (bad_hmean& bg)
	{
		bg.mesg();
		cout << "means()에서 잡힘\n";
		throw;
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}

void useTryCatchObjectThrow()
{
	double x, y, z;
	cout << "두 수를 입력하시오: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << x << ", " << y << " 의 조화 평균은 " << z << "입니다.\n";
			cout << x << ", " << y << " 의 기하 평균은 " << gmean(x, y) << "입니다.\n";
			cout << "다른 두 수를 입력하십시오(끝내려면 q): ";
		}
		catch (bad_hmean& bh)
		{
			bh.mesg();
			cout << "다시 하십시오.\n";
			continue;
		}
		catch (bad_gmean& bg)
		{
			cout << bg.mesg();
			cout << "Values used: " << bg.v1 << ", " << bg.v2 << endl;
			cout << "죄송합니다. 더 이상 진행할 수 없습니다.\n";
			break;
		}
	}
	cout << "프로그램을 종료합니다.\n";
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return sqrt(a * b);
}

void useTryCatchThrow()
{
	double x, y, z;
	cout << "두 수를 입력하시오: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
		}
		catch (const char* s)
		{
			cout << s << endl;
			cout << "두 수를 새로 입력하십시오: ";
			continue;
		}
		cout << x << ", " << y << " 의 조화 평균은 " << z << "입니다.\n";
		cout << "다른 두 수를 입력하십시오(끝내려면 q): ";
	}
	cout << "프로그램을 종료합니다.\n";
}

double hmean(double a, double b, double* ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}

void useErrorCodeReturn()
{
	double x, y, z;
	cout << "두 수를 입력하시오: ";
	while (cin >> x >> y)
	{
		if (hmean(x, y, &z))
			cout << x << ", " << y << " 의 조화 평균은 " << z << "입니다.\n";
		else
			cout << "서로 부정인 두 수의 조화평균은 구할 수 없다.\n";
		cout << "다른 두 수를 입력하십시오(끝내려면 q): ";
	}
	cout << "프로그램을 종료합니다.\n";
}

double hmean(double a, double b)
{
	// abort 함수 사용해서 실행 중단시켜 확인하기
	//if (a == -b)
	//{
	//	cout << "매개변수들을 hmean()에 전달할 수 없습니다.\n";
	//	abort();
	//}
	
	// try~catch 문과 throw 키워드 사용
	//if (a == -b)
	//	throw "잘못된 hmean() 매개변수: a = -b는 허용되지 않습니다.";
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

void useAbort()
{
	double x, y, z;
	cout << "두 수를 입력하시오: ";
	while (cin >> x >> y)
	{
		z = hmean(x, y);
		cout << x << ", " << y << " 의 조화 평균은 " << z << "입니다.\n";
		cout << "다른 두 수를 입력하십시오(끝내려면 q): ";
	}
	cout << "프로그램을 종료합니다.\n";
}

void useQueueTemplateNestedClass()
{
	QueueTP<string> cs(5);
	string temp;

	while (!cs.isfull())
	{
		cout << "이름을 입력하십시오. 도착하신 순서대로 사은품을 드립니다.\n이름 : ";
		getline(cin, temp);
		cs.enqueue(temp);
	}

	cout << "큐가 가득 찼으므로, 지금부터 사은품을 나누어 드리겠습니다.\n";
	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << temp << " 님! 감사합니다. 안녕히 가십시오.\n";
	}
}

void useFriendClass()
{
	using std::cout;
	Tv s42;
	cout << "42\" TV의 초기 설정값:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\n42\" TV의 변경된 설정값:\n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n리모콘 사용 후 42\" TV의 설정값:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" TV의 설정값:\n";
	s58.settings();
}