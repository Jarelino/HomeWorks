#include <iostream>;

using namespace std;


void fillMass(int*, int);
void insertionSort(int*, int);
void swap(int&, int&);
void output(int*, int);

int main()
{
	int mass[1000];
	int n = 0;

	while(n < 1 || n > 1000)
	{
		cout << "Enter length of mass from 1 to 1000 - ";
		cin >> n;
		system("cls");
	}
	

	fillMass(mass, n);
	insertionSort(mass, n);
	output(mass, n);


	system("pause");

	return 0;
}

void output(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}
}

void  fillMass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 100;
	}
}


void insertionSort(int * mass, int n)
{
	int j;

	for (int i = 1; i < n; i++)
	{
		j = i;
		while (mass[j] < mass[j - 1])
		{
			swap(mass[j], mass[j - 1]);
			j--;
		}
	}
}


void swap(int & x, int & y)
{
	int t = y;
	y = x;
	x = t;
}