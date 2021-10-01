#pragma once
#ifndef DMA_H_
#define DMA_H_
#include <iostream>
class baseDMA
{
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	baseDMA& operator=(const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

class lacksDMA : public baseDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& ls);
};

class hasDMA : public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs); // 멤버 포인터 변수가 있기 때문에 명시적 복사 생성자 선언
	~hasDMA(); // 멤버 포인터 변수가 있기 때문에 명시적 파괴자 선언
	hasDMA& operator=(const hasDMA& rs); // 멤버 포인터 변수가 있기 때문에 명시적 대입 연산자 선언
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& hs);
};
#endif