#pragma once
#pragma once

namespace ArrayExtension
{
	typedef bool(*Predicate)(int);
	typedef double(*Rule)(int);
	typedef int(*key)(int);
	typedef int(*keyD)(double);


	int* allocateMemory(int);

	double* allocateMemoryDouble(int);

	void inputArray(int *, int);

	void inputArray(double *, int);

	void randomArray(int *, int);

	void displayArray(int *, int);

	void displayArray(double *, int);

	int * createKeysD(double *, int, keyD);

	int * createKeys(double *, int, key);

	void bubbleSort(int *, int);

	void bubbleSort(int*, int*, int);

	void bubbleSort(int*, int*, int, int*, int);

	void bubbleSort(int *, int, key);

	void bubbleSort(double*, int*, int, key);
	//void bubbleSort(int *, int, int(*key)(int));

	void swap(int&, int&);

	void swap(double&, double&);

	int* createKeys(int*, int, key);

	int* createKeysD(double*, int, keyD);

	int countOfUnits(int);

	int countOfZeros(int);

	int sqr(int);

	double * transform(int*, int, Predicate, Rule);

	bool isOdd(int);

	double sin(int);

	int roundDown(double);

	int* roundDownArray(double*, int);

	int enterIntNumber();

	void deleteElements(int*, int, int&);

	void quickSort(double*, int*, int, int, key);

}
