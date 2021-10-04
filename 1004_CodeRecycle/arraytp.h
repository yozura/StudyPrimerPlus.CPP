#pragma once
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cstdlib>

template <class T, int n>
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP() { }
	explicit ArrayTP(const T& v); // 변환 함수 불허용
	virtual T& operator[] (int i);
	virtual T operator[] (int i) const;
};

template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T& v)
{
	// v값으로 배열 초기화.
	for (int i = 0; i < n; i++)
		ar[i] = v;
}

template <class T, int n>
T& ArrayTP<T, n>::operator[](int i)
{
	// i가 0보다 작거나 i가 n 보다 크거나 같으면 에러
	if (i < 0 || i >= n)
	{
		std::cerr << "배열의 경계를 벗어나는 에러: " << i << "--> 잘못된 인덱스입니다.\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

template <class T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
	{
		std::cerr << "배열의 경계를 벗어나는 에러: " << i << "--> 잘못된 인덱스입니다.\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}
#endif