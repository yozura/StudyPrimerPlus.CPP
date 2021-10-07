#include "emp.h"

using std::cout;
using std::cin;
using std::endl;

abstr_emp::abstr_emp()
	: fname("No"), lname("Name"), job("UnEmployee")
{
}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
	: fname(fn), lname(ln), job(j)
{
}

void abstr_emp::ShowAll() const
{
	cout << fname << ", " << lname;
}

void abstr_emp::SetAll()
{
	cout << "성을 입력하세요 : ";
	getline(cin, fname);
	cout << "이름을 입력하세요 : ";
	getline(cin, lname);

	while (cin.get() != '\n')
		continue;
}

abstr_emp::~abstr_emp()
{
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& emp)
{
	os << emp.fname << ", " << emp.lname;
	return os;
}

employee::employee()
	: abstr_emp("No", "Name", "UnEmployee")
{
}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j)
	: abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager()
	: abstr_emp("No", "Name", "UnEmployee"), inchargeof(0)
{
}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico)
{
}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e), inchargeof(ico)
{
}

manager::manager(const manager& m)
	: abstr_emp(m), inchargeof(m.inchargeof)
{
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << ", " << inchargeof;
}

void manager::SetAll()
{
	abstr_emp::ShowAll();
	cout << "담당 업무를 입력하세요: ";
	cin >> inchargeof;

	while (cin.get() != '\n')
		continue;
}

fink::fink()
	: abstr_emp("No", "Name", "UnEmployee")
{
}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp& e, const std::string& rpo) 
	: abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink& f)
	: abstr_emp(f), reportsto(f.reportsto)
{
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << ", " << reportsto;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "레포트를 입력하세요: ";
	getline(cin, reportsto);
	
	while (cin.get() != '\n')
		continue;
}

highfink::highfink()
	: abstr_emp("No", "Name", "UnEmployee"), manager("No", "Name", "UnEmployee", 0), fink("No", "Name", "UnEmployee", "None")
{
}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink& f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f)
{
}

highfink::highfink(const manager& m, const std::string& rpo)
	: abstr_emp(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink& hf)
	: abstr_emp(hf), manager(hf), fink(hf)
{
}

void highfink::ShowAll() const
{
	manager::ShowAll();
	fink::ShowAll();
}

void highfink::SetAll()
{
	manager::SetAll();
	fink::SetAll();
}
