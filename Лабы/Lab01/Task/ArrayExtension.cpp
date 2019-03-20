#include <iostream>
#include "ArrayLibrary.h"

//using namespace std;

int* ArrayExtension::allocateMemory(int size)
{
	if (size <= 0)
	{
		//return nullptr;
		//http://www.cplusplus.com/reference/exception/exception/
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	int* array = new int[size];

	return array;
}

double* ArrayExtension::allocateMemoryDouble(int size)
{
	if (size <= 0)
	{
		//return nullptr;
		//http://www.cplusplus.com/reference/exception/exception/
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	double* array = new double[size];

	return array;
}

void ArrayExtension::inputArray(int * array, int size)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be empty.");
	}

	if (size <= 0)
	{
		throw std::invalid_argument("Invalid size value.");
	}

	for (int* p = array, i = 1; p < array + size; p++, i++)
	{
		std::cout << "a[" << i << "] = ";
		std::cin >> *p;
	}
}

void ArrayExtension::inputArray(double * array, int size)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be empty.");
	}

	if (size <= 0)
	{
		throw std::invalid_argument("Invalid size value.");
	}

	for (double* p = array, i = 1; p < array + size; p++, i++)
	{
		std::cout << "a[" << i << "] = ";
		std::cin >> *p;
	}
}

void ArrayExtension::randomArray(int * array, int size)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be empty.");
	}

	if (size <= 0)
	{
		throw std::invalid_argument("Invalid size value.");
	}

	for (int* p = array, i = 1; p < array + size; p++, i++)
	{
		*p = rand() % 20 - 9;
	}
}

void ArrayExtension::displayArray(int * array, int n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be empty.");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Invalid size value.");
	}

	for (int* p = array; p < array + n; p++)
	{
		std::cout << *p << " ";
	}

	std::cout << std::endl;
}

void ArrayExtension::displayArray(double * array, int size)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be empty.");
	}

	if (size <= 0)
	{
		throw std::invalid_argument("Invalid size value.");
	}

	for (double* p = array; p < array + size; p++)
	{
		std::cout << *p << " ";
	}

	std::cout << std::endl;
}

int * ArrayExtension::createKeys(double * array, int size, key key)
{
	int* keys = ArrayExtension::allocateMemory(size);

	for (int i = 0; i < size; i++)
	{
		keys[i] = key(array[i]);
	}

	return keys;
}

int * ArrayExtension::createKeys(int * array, int size, key key)
{
	int* keys = ArrayExtension::allocateMemory(size);

	for (int i = 0; i < size; i++)
	{
		keys[i] = key(array[i]);
	}

	return keys;
}

int * ArrayExtension::createKeysD(double * array, int size, ArrayExtension::keyD key)
{
	int* keys = ArrayExtension::allocateMemory(size);

	for (int i = 0; i < size; i++)
	{
		keys[i] = key(array[i]);
	}

	return keys;
}

void ArrayExtension::swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void ArrayExtension::swap(double& a, double& b)
{
	double t = a;
	a = b;
	b = t;
}

int ArrayExtension::countOfUnits(int number)
{
	int k = 0;

	number = abs(number);

	while (number)
	{
		int rest = number % 2;

		if (rest)
		{
			k++;
		}

		number /= 2;
	}

	return k;
}

int ArrayExtension::countOfZeros(int number)
{
	int k = 0;

	number = abs(number);

	while (number)
	{
		int rest = number % 2;

		if (!rest)
		{
			k++;
		}

		number /= 2;
	}

	return k;
}

void ArrayExtension::bubbleSort(int* array, int size)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = size - 1; j >= i; j--)
		{
			if (array[j] < array[j - 1])
			{
				ArrayExtension::swap(array[j], array[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(int* array, int* keys, int size)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = size - 1; j >= i; j--)
		{
			if (keys[j] < keys[j - 1])
			{
				ArrayExtension::swap(array[j], array[j - 1]);
				ArrayExtension::swap(keys[j], keys[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(int* array, int* keys, int size, int* indexes, int keySize)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = keySize - 1; j >= i; j--)
		{
			if (keys[indexes[j]] < keys[indexes[j - 1]])
			{
				ArrayExtension::swap(array[indexes[j]], array[indexes[j - 1]]);
				ArrayExtension::swap(keys[indexes[j]], keys[indexes[j - 1]]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(double* array, int* keys, int size, key key)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{
		swapped = false;

		for (int j = size - 1; j >= i; j--)
		{
			if (key(keys[j]) > key(keys[j - 1]))
			{
				ArrayExtension::swap(array[j], array[j - 1]);
				ArrayExtension::swap(keys[j], keys[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(int* array, int size, key key)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{
		swapped = false;

		for (int j = size - 1; j >= i; j--)
		{
			if (key(array[j]) > key(array[j - 1]))
			{
				ArrayExtension::swap(array[j], array[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

int ArrayExtension::sqr(int number)
{
	return number * number;
}


double * ArrayExtension::transform(int* source, int size, ArrayExtension::Predicate predicate, ArrayExtension::Rule rule)
{
	double* result = ArrayExtension::allocateMemoryDouble(size);

	for (int i = 0; i < size; i++)
	{
		result[i] = predicate(i) ? rule(source[i]) : source[i];
	}

	return result;
}

bool ArrayExtension::isOdd(int n)
{
	return n % 2;
}

double ArrayExtension::sin(int x)
{
	return std::sin((double)x);
}

int ArrayExtension::roundDown(double number)
{
	int roundDown = (int)number;

	return roundDown;
}

int* ArrayExtension::roundDownArray(double* array, int size)
{
	int * newArray = new int(size);

	for (int i = 0; i < size; i++)
	{
		newArray[i] = (int)array[i];
	}

	delete[] array;

	return newArray;
}

int ArrayExtension::enterIntNumber()
{
	int number;

	std::cin >> number;

	return number;
}

void ArrayExtension::deleteElements(int* array, int start, int& end)
{
	for (int i = 1; i < start - 1 - end; i++)
	{
		if (array[i] == array[i - 1])
		{
			for (int j = i; j < start; j++)
			{
				array[j] = array[j + 1];
			}
			i--;
			end++;
		}
	}
}

void ArrayExtension::quickSort(double* array, int* keys, int left, int right, key key)
{

	int i = left, j = right;

	int pivot = key(keys[(left + right) / 2]);



	while (i <= j) 
	{
		while (key(keys[i]) < pivot)
			i++;
		while (key(keys[j]) > pivot)
			j--;

		if (i <= j)
		{
			ArrayExtension::swap(array[i], array[j]);
			ArrayExtension::swap(keys[i], keys[j]);
			i++;
			j--;

		}

	};

	if (left < j)
		quickSort(array, keys, left, j, key);
	if (i < right)
		quickSort(array, keys, i, right, key);

}
