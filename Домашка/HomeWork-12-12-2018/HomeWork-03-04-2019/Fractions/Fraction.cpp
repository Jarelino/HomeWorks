#include "Fraction.h"

using namespace std;

Fraction::Fraction(int num, int den)
{
	setFraction(num, den);
}

void Fraction::setFraction(int num, int den)
{
	setNumerator(num);
	setDenominator(den);
}

void Fraction::setDenominator(int den)
{
	if (den == 0)
	{
		throw::invalid_argument("Denominator can't be equal to zero.");
	}

	if (den < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
		return;
	}

	denominator = den;
}

void Fraction::setNumerator(int num)
{
	numerator = num;
}

void Fraction::display()
{
	cout << numerator << "/" << denominator << endl;
}

int Fraction::GCD(int num, int den)
{
	while (sign() * num)
	{
		int temp = den;
		den = num % den;
		num = temp;
	}
	return sign() * num;
}

int Fraction::sign()
{
	return numerator > 0 ? 1 : -1;
}


void Fraction::reduce()
{
	int gcd = GCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}