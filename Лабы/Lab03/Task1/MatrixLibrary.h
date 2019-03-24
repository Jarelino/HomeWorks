#pragma once

namespace MatrixExtension
{
	typedef int(*keyD)(double);
	typedef int(*key)(int);
	typedef void(*sortDouble)(double*, int, int, key);

	double* allocateDoubleMemory(int);
	int* allocateIntMemory(int);
	double** allocateDoubleMatrixMemory(int, int*);
	int** allocateIntMatrixMemory(int, int*);


	int inputRowsCount();
	int* inputColumnsCount(int);
	int inputInt();
	void inputNonRectangularMatrix(double**, int, int*);

	int** createKeysD(double**, int, int*, keyD);
	int roundDown(double number);

	void merge(double*, int, int, int, key);
	void mergeSort(double*, int, int, key);
	void sort(double**, int*, int, int*, sortDouble, key);

	int countOfZeros(int);
	int countOfUnits(int);


	double** deleteElementsInMatrix(double**, int, int*, int*, int, int, key,key);
	double* deleteElementsInArray(double* , int& , int , int , key,key);
	void displayNonRectangularMatrix(double**, int, int*);
}