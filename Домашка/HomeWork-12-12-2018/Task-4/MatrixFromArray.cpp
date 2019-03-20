#include <iostream>;
#include "MatrixLibrary.h";

using namespace std;

void matrixFromArray(int (*)[MAXSIZE], int *, int);

int main()
{
	int n = -1;
	int matrix[MAXSIZE][MAXSIZE];
	int arr[MAXSIZE];

	while (n < 0 || n > 100)
	{
		cout << "Choose the array size (1-100) ";
		cin >> n;
	}
	
	system("cls");

	inputArray(arr, n);

	system("cls");

	matrixFromArray(matrix, arr, n);
	displayMatrix(matrix, n, n);

	system("pause");
	return  0;
}

void matrixFromArray(int(*matrix)[MAXSIZE], int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < n - j)
			{
				matrix[i][j] = arr[n - 1 - (abs(n - (abs(i + j) + 1)))];
			}
			else
			{
				matrix[i][j] = arr[abs(n - (abs(i + j) + 1)) - 1];
			}
		}
	}
}