#pragma once

namespace MatrixExtension
{
	double* allocateMemory(int);
	double** allocateMemory(double**, int, int*);


	int inputRowsCount();
	int* inputColumnsCount(double*, int)
}