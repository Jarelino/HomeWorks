#include "ComplexNumbers.h"
#include <iostream>

using namespace std;


ComplexNumbers::ComplexNumbers(double im, double rl)
{
	setNumber(im, rl);
}

/*ComplexNumbers::~ComplexNumbers()
{
	cout << "STOP KILLING COMPLEX NUMBERS!" << endl;
}
*/
void ComplexNumbers::setNumber(double im, double rl)
{
	setImaginary(im);
	setReal(rl);
}

void ComplexNumbers::setImaginary(double number)
{
	imaginary = number;
}

void ComplexNumbers::setReal(double number)
{
	real = number;
}

int ComplexNumbers::getImaginary() const
{
	return imaginary;
}

int ComplexNumbers::getReal() const
{
	return real;
}

ComplexNumbers& ComplexNumbers::operator-() const
{
	ComplexNumbers result(-getImaginary(),-getReal());
	return result;
}

ComplexNumbers& ComplexNumbers::operator-(const ComplexNumbers & complex) const
{
	ComplexNumbers temp = -complex;
	return *this + temp;
}

ComplexNumbers& ComplexNumbers::operator+(const ComplexNumbers& complex) const
{
	int cfcnt = getImaginary() + complex.getImaginary();
	int frmmb = getReal() + complex.getReal();
	ComplexNumbers result(cfcnt, frmmb);
	return result;
}

ComplexNumbers& ComplexNumbers::operator=(const ComplexNumbers & complex)
{
	setNumber(complex.getImaginary(), complex.getReal());
	return *this;
}

ComplexNumbers& ComplexNumbers::operator*(const ComplexNumbers& complex) const
{
	int im = (getImaginary() * complex.getReal())  + (complex.getImaginary() * getReal());
	int rl = (getReal() * complex.getReal()) - (getImaginary() * complex.getImaginary());
	ComplexNumbers result(im, rl);
	return result;
}

ostream& operator<<(ostream & stream, const ComplexNumbers& complex)
{
	if (complex.getImaginary() > 0 && complex.getReal() != 0)
	{
		return stream << complex.getReal() << " + " << complex.getImaginary() << "i";
	}
	if (complex.getImaginary() < 0 && complex.getReal() != 0)
	{
		return stream << complex.getReal() << " - " << abs(complex.getImaginary()) << "i";
	}
	if (complex.getReal() == 0 && complex.getImaginary() == 0)
	{
		return stream << 0;
	}
}

istream& operator>>(istream & stream, ComplexNumbers& complex)
{
	cout << "Input real part of your number : ";
	stream >> complex.real;

	cout << "Input imaginary part of your number : ";
	stream >> complex.imaginary;
	
	return stream;
}