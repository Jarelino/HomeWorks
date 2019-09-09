#include "ComplexNumbers.h"
#include <iostream>

using namespace std;

int main()
{
	ComplexNumbers firstNumber(5, 3), secondNumber(3, 5);
	ComplexNumbers temp = -secondNumber;

	cout << temp << endl;

	ComplexNumbers sum = firstNumber + secondNumber;

	cout << sum << endl;

	system("pause");
	return 0;
}