#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "port.h"

Port::Port(const char* br, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    bottles = b;
}

Port::Port(const Port& p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
    if (this == &p)
        return *this;
    delete[] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    bottles = p.bottles;
    return *this;
}

Port& Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port& Port::operator-=(int b)
{
    if (bottles >= b)
        bottles -= b;
    
    return *this;
}

void Port::Show() const
{
    std::cout << "브랜드: " << brand << '\n';
    std::cout << "수량: " << bottles << '\n';
}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
    os << p.brand << ", " << p.bottles;
    return os;
}

VintagePort::VintagePort()
    : Port()
{
    nickname = new char[1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
    : Port(br, b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort& vp)
    : Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    std::cout << "제품명: " << nickname << '\n';
    std::cout << "년도: " << year << '\n';
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
    os << (const Port&)vp;
    os << vp.nickname << ", " << vp.year;
    return os;
}