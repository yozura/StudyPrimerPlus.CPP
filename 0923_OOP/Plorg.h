#pragma once
#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
	static const int Len = 20;
	char name[Len];
	int ci;
public:
	Plorg(const char* str = "Plorga", int val = 50);
	void setCI(int val);
	void showPlorg() const;
};
#endif