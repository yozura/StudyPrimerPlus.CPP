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
		cout << "demo " << word << " ����\n";
	}
	~demo()
	{
		cout << "demo " << word << " �ı�\n";
	}
	void show() const
	{
		cout << "demo " << word << " ����\n";
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
	cout << "ù ��° try ���:\n";
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
		cout << "try ��� 1�� ��.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "�߸��� �ε���: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "�߸��� �ε���: " << bad.bi_val() << endl;
	}

	cout << "\n ���� try ���\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "try ��� 2�� ��.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "�߸��� �ε���: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "�߸��� �ε���: " << bad.bi_val() << endl;
	}
	cout << "���α׷��� �����մϴ�.\n";
	
	return 0;
}

void useNewexcep()
{
	Big* pb;
	try {
		cout << "ū �޸� ��� ������ ��û�ϰ� �ֽ��ϴ�.\n";
		pb = new Big[10000];
		cout << "�޸� ��� ���� ��û�� �źεǾ����ϴ�.\n";
	}
	catch (bad_alloc& ba)
	{
		cout << "���ܰ� �����Ǿ����ϴ�!\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "�޸� ����� ���������� ���ԵǾ����ϴ�.\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[] pb;
}

void useUnwindingTheStack()
{
	double x, y, z;
	{
		demo d1("found in block in main()");
		cout << "�� ���� �Է��Ͻʽÿ�: ";
		while (cin >> x >> y)
		{
			try {
				z = means(x, y);
				cout << x << "�� " << y << "�� ����� ����� " << z << endl;
				cout << "���� �� ���� �Է��Ͻʽÿ�: ";
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
				cout << "�ٽ� �Ͻʽÿ�.\n";
				continue;
			}
			catch (bad_gmean& hg)
			{
				cout << hg.mesg();
				cout << "���� �� ��: " << hg.v1 << ", " << hg.v2 << endl;
				cout << "�˼��մϴ�. �� �̻� ������ �� �����ϴ�.\n";
				break;
			}
		}
		d1.show();
	}
	cout << "���α׷��� �����մϴ�.";
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
		cout << "means()���� ����\n";
		throw;
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}

void useTryCatchObjectThrow()
{
	double x, y, z;
	cout << "�� ���� �Է��Ͻÿ�: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << x << ", " << y << " �� ��ȭ ����� " << z << "�Դϴ�.\n";
			cout << x << ", " << y << " �� ���� ����� " << gmean(x, y) << "�Դϴ�.\n";
			cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q): ";
		}
		catch (bad_hmean& bh)
		{
			bh.mesg();
			cout << "�ٽ� �Ͻʽÿ�.\n";
			continue;
		}
		catch (bad_gmean& bg)
		{
			cout << bg.mesg();
			cout << "Values used: " << bg.v1 << ", " << bg.v2 << endl;
			cout << "�˼��մϴ�. �� �̻� ������ �� �����ϴ�.\n";
			break;
		}
	}
	cout << "���α׷��� �����մϴ�.\n";
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
	cout << "�� ���� �Է��Ͻÿ�: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
		}
		catch (const char* s)
		{
			cout << s << endl;
			cout << "�� ���� ���� �Է��Ͻʽÿ�: ";
			continue;
		}
		cout << x << ", " << y << " �� ��ȭ ����� " << z << "�Դϴ�.\n";
		cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q): ";
	}
	cout << "���α׷��� �����մϴ�.\n";
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
	cout << "�� ���� �Է��Ͻÿ�: ";
	while (cin >> x >> y)
	{
		if (hmean(x, y, &z))
			cout << x << ", " << y << " �� ��ȭ ����� " << z << "�Դϴ�.\n";
		else
			cout << "���� ������ �� ���� ��ȭ����� ���� �� ����.\n";
		cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q): ";
	}
	cout << "���α׷��� �����մϴ�.\n";
}

double hmean(double a, double b)
{
	// abort �Լ� ����ؼ� ���� �ߴܽ��� Ȯ���ϱ�
	//if (a == -b)
	//{
	//	cout << "�Ű��������� hmean()�� ������ �� �����ϴ�.\n";
	//	abort();
	//}
	
	// try~catch ���� throw Ű���� ���
	//if (a == -b)
	//	throw "�߸��� hmean() �Ű�����: a = -b�� ������ �ʽ��ϴ�.";
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

void useAbort()
{
	double x, y, z;
	cout << "�� ���� �Է��Ͻÿ�: ";
	while (cin >> x >> y)
	{
		z = hmean(x, y);
		cout << x << ", " << y << " �� ��ȭ ����� " << z << "�Դϴ�.\n";
		cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q): ";
	}
	cout << "���α׷��� �����մϴ�.\n";
}

void useQueueTemplateNestedClass()
{
	QueueTP<string> cs(5);
	string temp;

	while (!cs.isfull())
	{
		cout << "�̸��� �Է��Ͻʽÿ�. �����Ͻ� ������� ����ǰ�� �帳�ϴ�.\n�̸� : ";
		getline(cin, temp);
		cs.enqueue(temp);
	}

	cout << "ť�� ���� á���Ƿ�, ���ݺ��� ����ǰ�� ������ �帮�ڽ��ϴ�.\n";
	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << temp << " ��! �����մϴ�. �ȳ��� ���ʽÿ�.\n";
	}
}

void useFriendClass()
{
	using std::cout;
	Tv s42;
	cout << "42\" TV�� �ʱ� ������:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\n42\" TV�� ����� ������:\n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n������ ��� �� 42\" TV�� ������:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" TV�� ������:\n";
	s58.settings();
}