#pragma once
#ifndef GOLF_H_
#define GOLF_H_

class Golf
{
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	// 대화식
	Golf();
	// 비대화식
	Golf(const char* name, int hc);
	void setHandicap(int hc) { handicap = hc; };
	void showgolf() const;
};

#endif