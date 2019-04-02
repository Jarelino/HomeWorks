#pragma once
#include <iostream>

using namespace std;

class Fraction
{
public:
	Fraction() : Fraction(1,1) {};
	Fraction(int, int);
	void setFraction(int, int);
	void setDenominator(int);
	void setNumerator(int);
	void display();
	int GCD(int, int);
	int sign();
	void reduce();
	~Fraction();

private:
	int numerator, denominator;
};