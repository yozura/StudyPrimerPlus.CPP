#pragma once
#ifndef VECTOR_H_
#define VECTOR_H_
#include <ostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POLAR };
	private:
		double x; // 수평 성분
		double y; // 수직 성분
		double mag; // 벡터의 길이 (magnitude as distance) 
		double ang; // 방위(도)로 표현되는 벡터의 방향(angle)
		Mode mode; // 직교 좌표계와 극 좌표계 모드 설정
		void set_mag(); // 수평, 수직 성분으로부터 벡터의 길이 추출
		void set_ang(); // 수평, 수직 성분으로부터 벡터의 방향 추출
		void set_x(); // 벡터의 길이, 방향으로부터 수평 성분 추출
		void set_y(); // 벡터의 길이, 방향으로부터 수직 성분 추출
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; } // x값 보고
		double yval() const { return y; } // y값 보고
		double magval() const { return mag; } // 벡터의 길이 보고
		double angval() const { return ang; } // 벡터의 방향 보고
		void polar_mode(); // 모드를 극 좌표계로
		void rect_mode(); // 모드를 직교 좌표계로
		// 연산자 오버로딩
		Vector operator+(const Vector& v) const;
		Vector operator-(const Vector& v) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		// 프렌드 함수
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
#endif