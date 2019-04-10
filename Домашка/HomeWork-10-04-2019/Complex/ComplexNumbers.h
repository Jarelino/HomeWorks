#pragma once
#include <iostream>

using namespace std;

class ComplexNumbers
{
	friend ostream& operator<<(ostream &, const ComplexNumbers&);
	friend istream& operator>>(istream &, ComplexNumbers&);
public :
	ComplexNumbers(double = 1, double = 1);
	//~ComplexNumbers();

	void setNumber(double, double);
	
	int getImaginary() const;
	int getReal() const;

	ComplexNumbers& operator-(const ComplexNumbers&) const;
	ComplexNumbers& operator-() const;
	ComplexNumbers& operator+(const ComplexNumbers&) const;
	ComplexNumbers& operator*(const ComplexNumbers&) const;
	ComplexNumbers& operator=(const ComplexNumbers&);

private:
	double imaginary, real;
	void setImaginary(double);
	void setReal(double);
};