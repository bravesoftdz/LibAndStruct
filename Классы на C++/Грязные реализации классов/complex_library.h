#pragma once

#include <iostream>
#include <cmath>

class Complex {
private:
	double re, im;
public:
	Complex() : re(0), im(0) {}
	Complex (double r) : re(r), im(0) {}
	Complex (double r, double i) : re(r), im(i) {}
	Complex (const Complex &c) : re(c.re), im(c.im) {}
	double abs() { return sqrt (re * re + im * im); }

	Complex& operator = (Complex &c) { re = c.re; im = c.im; return *this; }
	Complex& operator += (Complex &c) { re += c.re; im += c.im; return *this; }
	Complex& operator -= (Complex &c) { re -= c.re; im -= c.im; return *this; }

	Complex operator + (const Complex &c) { return Complex(re + c.re, im + c.im); }
	Complex operator - (const Complex &c) { return Complex(re - c.re, im - c.im); }

	Complex operator * (const Complex &c) {
		return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
	}

	Complex operator / (const Complex &c) {
		Complex temp;

		double r = c.re * c.re + c.im * c.im;
		temp.re = (re * c.re + im * c.im) / r;
		temp.im = (im * c.re - re * c.im) / r;

		return temp;
	}

	Complex pow(int n) {
		Complex temp;

		double R = powl(sqrt(re * re + im * im), n);
		double Phi = n * atan2(im, re);
		temp.re = R * cos(Phi);
		temp.im = R * sin(Phi);

		return temp;
	}		

	friend std::ostream& operator << (std::ostream &, const Complex &);   
	friend std::istream& operator >> (std::istream &, Complex &);
};

std::ostream& operator << (std::ostream &out, const Complex &c) {
	out << "(" << c.re << ", " << c.im << ")";
	return out;
}

std::istream& operator >> (std::istream &in, Complex &c) {
	in >> c.re >> c.im;
	return in;
}