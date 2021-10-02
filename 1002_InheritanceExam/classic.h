#pragma once
#ifndef CLASSIC_H_
#define CLASSIC_H_
class Cd
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d); // 명시적 복사 생성자
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d); // 명시적 대입 연산자
};

class Classic : public Cd
{
private:
	char* repSong;
public:
	Classic(const char* s1, const char* s2, const char* s3, int n, double x);
	Classic(const Classic& d);
	Classic();
	virtual ~Classic();
	virtual void Report() const;
	Classic& operator=(const Classic& d);
};
#endif