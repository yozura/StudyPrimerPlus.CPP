#pragma once
#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <string>

class abstr_emp 
{
private:
	std::string fname;
	std::string lname;
	std::string job;
public:
	abstr_emp();
	abstr_emp(const std::string& fn, const std::string& ln, const std::string& j);
	virtual void ShowAll() const; // 필드의 모든 데이터를 보여준다.
	virtual void SetAll(); // 사용자에게 필드 값들을 입력하게 한다.
	friend std::ostream& operator<<(std::ostream& os, const abstr_emp& emp);
	virtual ~abstr_emp() = 0; // 순수 가상 파괴자를 선언함으로써 이 클래스는 가상 기초 클래스가 된다.
};

class employee : public abstr_emp
{
public:
	employee();
	employee(const std::string& fn, const std::string& ln, const std::string& j);
	virtual void ShowAll() const;
	virtual void SetAll();
};

class manager : virtual public abstr_emp // 가상 기초 클래스를 가상으로 상속함으로써 기초 클래스를 하나만 상속하게 된다.
{
private:
	int inchargeof;
protected:
	int InChargeOf() const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }
public:
	manager();
	manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);
	virtual void ShowAll() const;
	virtual void SetAll();
};

class fink : virtual public abstr_emp
{
private:
	std::string reportsto;
protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string& ReportsTo() { return reportsto; }
public:
	fink();
	fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
	fink(const abstr_emp& e, const std::string& rpo);
	fink(const fink& f);
	virtual void ShowAll() const;
	virtual void SetAll();
};

// 위에서 이미 가상 기초 함수를 상속했기 때문에 기초 함수는 하나만 설정된다.
class highfink : public manager, public fink
{
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico);
	highfink(const abstr_emp& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& hf);
	virtual void ShowAll() const;
	virtual void SetAll();
};
#endif // !EMP_H_