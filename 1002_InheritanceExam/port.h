#pragma once
#ifndef PORT_H_
#define PORT_H_
#include <iostream>
class Port
{
private:
	char* brand;
	int bottles;
public:
	Port(const char* br = "none", int b = 0);
	Port(const Port& p); // ����� ���� ������
	virtual ~Port() { delete[] brand; }
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int BottleCount() const { return bottles; }
	virtual void Show() const;
	friend std::ostream& operator<<(std::ostream& os, const Port& p);
};

class VintagePort : public Port
{
private:
	char* nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char* br, int b, const char* nn, int y);
	VintagePort(const VintagePort& vp);
	virtual ~VintagePort() { delete[] nickname; }
	VintagePort& operator=(const VintagePort& vp);
	void Show() const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};
#endif