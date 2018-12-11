#include <iostream>

using namespace std;

const int MAXSIZE = 100;

void displayMatrix(int(*)[MAXSIZE], int, int);
void inputArray(int *, int);

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