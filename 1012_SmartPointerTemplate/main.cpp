#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
	std::string str;
public:
	Report(const std::string s) : str(s) { std::cout << "��ü�� �����Ǿ����ϴ�!\n"; }
	~Report() { std::cout << "��ü�� �����Ǿ����ϴ�!\n"; }
	void comment() const { std::cout << str << "\n"; }
};

using namespace std;

unique_ptr<string> demo(const char* s)
{
	unique_ptr<string> temp(new string(s));
	return temp;
}

int main()
{
	unique_ptr<string> ps;
	ps = demo("Uniquely special");


	shared_ptr<string> films[5] =
	{
		shared_ptr<string> (new string("Fowl Balls")),
		shared_ptr<string> (new string("Duck Walks")),
		shared_ptr<string> (new string("Chicken Runs")),
		shared_ptr<string> (new string("Turkey Errors")),
		shared_ptr<string> (new string("Goose Eggs"))
	};
	shared_ptr<string> pwin;
	pwin = films[2];
	
	cout << "������ �ְ��� ���� ��ȭ�� �ĺ��Դϴ�\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "�����ڴ� " << *pwin << "!\n";
	cin.get();

	return 0;
}

void useSmartPtr()
{
	{
		std::auto_ptr<Report> ps(new Report("auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("unique_ptr"));
		ps->comment();
	}
}