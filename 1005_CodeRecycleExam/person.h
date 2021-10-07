#pragma once
#ifndef PERSON_H_
#define PERSON_H_
#include <string>
class Person
{
private:
	std::string fname;
	std::string lname;
protected:
	virtual void Data() const;
public:
	Person()
		: fname("No"), lname("Name") { } 
	Person(const std::string& f, const std::string& l)
		: fname(f), lname(l) { }
	virtual ~Person() { }
	virtual void Show() const;
};

class Gunslinger : virtual public Person
{
private:
	int notch;
protected:
	virtual void Data() const;
public:
	Gunslinger()
		: Person("No", "Name"), notch(0) { }
	Gunslinger(const std::string& f, const std::string& l, int nt = 0)
		: Person(f, l), notch(nt) { }
	Gunslinger(const Person& p, int nt = 0)
		: Person(p), notch(nt) { }
	virtual void Show() const;
	virtual double Draw();
};

class PokerPlayer : virtual public Person
{
protected:
	virtual void Data() const;
public:
	PokerPlayer()
		: Person("No", "Name") { } 
	PokerPlayer(const std::string& f, const std::string& l)
		: Person(f, l) { } 
	PokerPlayer(const Person& p)
		: Person(p) { }
	virtual void Show() const;
	virtual int Draw();
};

class BadDude : public Gunslinger, public PokerPlayer
{
protected:
	void Data() const;
public:
	BadDude()
		: Person("No", "Name"), Gunslinger("No", "Name", 0), PokerPlayer("No", "Name") { }
	BadDude(const std::string& f, const std::string& l, int nt = 0)
		: Person(f, l), Gunslinger(f, l, nt), PokerPlayer(f, l) { }
	BadDude(const Person& p, int nt = 0)
		: Person(p), Gunslinger(p, nt), PokerPlayer(p) { }
	BadDude(const Gunslinger& g, int nt = 0)
		: Person(g), Gunslinger(g, nt), PokerPlayer(g) { }
	BadDude(const PokerPlayer& p, int nt = 0)
		: Person(p), Gunslinger(p, nt), PokerPlayer(p) { }
	double Gdraw();
	int Cdraw();
	void Show() const;
};
#endif