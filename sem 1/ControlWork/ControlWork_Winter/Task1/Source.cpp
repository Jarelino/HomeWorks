#include <iostream>

using namespace std;

int nextSmallerThan(int);
void nextSmallerThanTests();
void getDigits(int, int *);
bool equalArray(int *, int *, int);
void createZerosArray(int *, int);

const int MAXSIZE = 10;

int main()
{
	nextSmallerThanTests();

	system("pause");
	return 0;
}

int nextSmallerThan(int number)
{
	int arrayNumbers[MAXSIZE];
	int newArrayNumbers[MAXSIZE];

	createZerosArray(arrayNumbers, MAXSIZE);
	getDigits(number, arrayNumbers);

	for (int i = number - 1; i > 0; i--)
	{
		getDigits(i, newArrayNumbers);

		if (equalArray(arrayNumbers, newArrayNumbers, MAXSIZE))
		{
			return i;
		}
	}

	return -1;
}

bool equalArray(int * firstArray, int * secondArray, int size)
{
	for (int j = 0; j < size; j++)
	{
		if (firstArray[j] != secondArray[j])
		{
			return false;
		}
	}

	return true;
}

void createZerosArray(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

void getDigits(int number, int * arr)
{
	createZerosArray(arr, MAXSIZE);

	while (number > 0)
	{
		int digit = number % 10;
		arr[digit] += 1;
		number /= 10;
	}

}

void nextSmallerThanTests()
{
	cout << (nextSmallerThan(21) == 12) << endl;
	cout << (nextSmallerThan(531) == 513) << endl;
	cout << (nextSmallerThan(2071) == 2017) << endl;
	cout << (nextSmallerThan(9) == -1) << endl;
	cout << (nextSmallerThan(111) == -1) << endl;
	cout << (nextSmallerThan(135) == -1) << endl;
	cout << (nextSmallerThan(1027) == -1) << endl;
	cout << (nextSmallerThan(-100) == -1) << endl;
	//...
	cout << (nextSmallerThan(12746) == 12674) << endl;
	cout << (nextSmallerThan(651) == 615) << endl;
	cout << (nextSmallerThan(1848) == 1488) << endl;
	cout << (nextSmallerThan(2018) == 1820) << endl;
	cout << (nextSmallerThan(-10) == -1) << endl;
	cout << (nextSmallerThan(12345) == -1) << endl;
	cout << (nextSmallerThan(17799) == -1) << endl;
	cout << (nextSmallerThan(987654321) == 987654312) << endl;
}