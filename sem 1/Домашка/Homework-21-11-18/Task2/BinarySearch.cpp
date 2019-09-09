#include <iostream>;

using namespace std;


void fillMass(int*, int);
void insertionSort(int*, int);
void binarySearch(int*, int, int, int &);


int main()
{
	int mass[100];
	int n = 100;


	fillMass(mass, n);
	insertionSort(mass, n);
	
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}

	int item;
	cout << endl << "Enter item you want to find in array: ";
	cin >> item;
	int index = -1;

	binarySearch(mass, n, item, index);

	if (index >= 0)
	{
		cout << "Possition of you item is: " << index << endl;
	}
	else
	{
		cout << "There is no such element in the array" << endl;
	}

	system("pause");

	return 0;
}

void binarySearch(int* mass, int n, int item, int & index)
{
	int left = 0;
	int right = n;
	int midd = 0;

	while (true)
	{
		midd = (left + right) / 2;

		if (mass[midd] > item)
		{
			right = midd - 1;
		}
		else if (mass[midd] < item)
		{
			left = midd + 1;
		}
		else
		{
			index = midd;
			break;
		}

		if (left > right)
		{
			break;
		}

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
