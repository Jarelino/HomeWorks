#include <iostream>

using namespace std;

const int MAXSIZE = 100;

void displayMatrix(int(*)[MAXSIZE], int, int);
void inputArray(int *, int);
void inputMatrix(int(*)[MAXSIZE], int);
void matrixSwap(int(*)[MAXSIZE], int, int, int, int);

void displayMatrix(int(*a)[MAXSIZE], int n, int m)
{
	cout << "Your matrix : " << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}

	cout << endl;
}

void inputArray(int * arr, int n)
{
	cout << "Input your array : ";

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void inputMatrix(int(*matrix)[MAXSIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Input " << i + 1 << " line of your matrix (" << n << " elements) : ";
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void matrixSwap(int(*matrix)[MAXSIZE], int i, int j, int m, int n)
{
	int t = matrix[i][j];
	matrix[i][j] = matrix[m][n];
	matrix[m][n] = t;
}