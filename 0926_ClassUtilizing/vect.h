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
		double x; // ���� ����
		double y; // ���� ����
		double mag; // ������ ���� (magnitude as distance) 
		double ang; // ����(��)�� ǥ���Ǵ� ������ ����(angle)
		Mode mode; // ���� ��ǥ��� �� ��ǥ�� ��� ����
		void set_mag(); // ����, ���� �������κ��� ������ ���� ����
		void set_ang(); // ����, ���� �������κ��� ������ ���� ����
		void set_x(); // ������ ����, �������κ��� ���� ���� ����
		void set_y(); // ������ ����, �������κ��� ���� ���� ����
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; } // x�� ����
		double yval() const { return y; } // y�� ����
		double magval() const { return mag; } // ������ ���� ����
		double angval() const { return ang; } // ������ ���� ����
		void polar_mode(); // ��带 �� ��ǥ���
		void rect_mode(); // ��带 ���� ��ǥ���
		// ������ �����ε�
		Vector operator+(const Vector& v) const;
		Vector operator-(const Vector& v) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		// ������ �Լ�
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
#endif