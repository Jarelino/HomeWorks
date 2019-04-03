#include "Fraction.h"

using namespace std;

Fraction::Fraction(int num, int den)
{
	setFraction(num, den);
}

Fraction::~Fraction()
{

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

void Fraction::display() const
{
	cout << numerator << "/" << denominator << endl;
}

int Fraction::GCD(int firstNumb, int secondNumb)
{
	int sign = Fraction::sign();

	while (sign * firstNumb)
	{
		int temp = secondNumb;
		secondNumb = firstNumb % secondNumb;
		firstNumb = temp;
	}
	return sign * firstNumb;
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


int Fraction::LCD(int firstDen, int secondDen)
{
	return (firstDen * secondDen) / GCD(firstDen, secondDen);
}

int Fraction::getDenominator() const
{
	return denominator;
}

int Fraction::getNumerator() const
{
	return numerator;
}


void Fraction::toCommonDenominator(Fraction& firstFrac, Fraction& secondFrac)
{
	int lcd = LCD(firstFrac.getDenominator(), secondFrac.getDenominator());

	firstFrac.setDenominator(lcd);
	firstFrac.setNumerator(firstFrac.getDenominator * lcd);
	firstFrac.reduce();

	secondFrac.setDenominator(lcd);
	secondFrac.setNumerator(secondFrac.getDenominator * lcd);
	secondFrac.reduce();
}

Fraction Fraction::plus(Fraction& firstFrac, Fraction& secondFrac)
{
	toCommonDenominator(firstFrac, secondFrac);
	Fraction fraction;
	fraction.setFraction(firstFrac.getNumerator() + secondFrac.getNumerator(), firstFrac.getDenominator());
	fraction.reduce();
	return fraction;
}

Fraction Fraction::multiply(Fraction& firstFrac, Fraction& secondFrac)
{
	Fraction fraction;
	fraction.setFraction(firstFrac.getNumerator * secondFrac.getNumerator, firstFrac.getDenominator * secondFrac.getDenominator);
	fraction.reduce();
	return fraction;
}

