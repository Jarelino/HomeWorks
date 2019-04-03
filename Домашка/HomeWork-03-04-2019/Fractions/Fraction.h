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
	void display() const;
	int getDenominator() const;
	int getNumerator() const;
	
	int LCD(int, int);
	int GCD(int, int);
	int sign();
	
	Fraction plus(Fraction&, Fraction&);
	Fraction multiply(Fraction& , Fraction&);
	void reduce();


	void toCommonDenominator(Fraction& , Fraction&);
	~Fraction();

private:
	int numerator, denominator;

};