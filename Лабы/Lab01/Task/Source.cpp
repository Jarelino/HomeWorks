#include <iostream>;
#include "ArrayLibrary.h";
#include <fstream>;

using namespace std;
using namespace ArrayExtension;

double* createNewArray(double*, int*, int, int, int, int&, key, key);
int ContentsFile(char*);
double* InitArray(char*, int);
void AddFile(char* , double* , int );


int main()
{
	char input[] = "input.txt";
	char output[] = "output.txt";
	int mainSize = ContentsFile(input);
	double* array = InitArray(input, mainSize);

	
	cout << "You array: ";
	displayArray(array, mainSize);

	int* keys = allocateMemory(mainSize);
	keys = createKeysD(array, mainSize, roundDown);


	quickSort(array, keys, 0, mainSize, countOfUnits);
	AddFile(output, array, mainSize);
	
	int zerousCount, unitsCount;

	cout << "Enter count units: ";
	unitsCount = enterIntNumber();
	cout << "Enter count zeros: ";
	zerousCount = enterIntNumber();

	int newSize = 0;
	double *newArray = allocateMemoryDouble(mainSize);

	newArray = createNewArray(array, keys , mainSize, zerousCount, unitsCount, newSize, countOfUnits, countOfZeros);
	AddFile(output, newArray, newSize);

	system("pause");
	return 0;
}

double* createNewArray(double* array, int* sourse, int size, int zeros, int units, int& newSize, key unit, key zero)
{
	for (int i = 0, j = 0; i < size; i++)
	{
		if (unit(sourse[i]) != units || zero(sourse[i]) != zeros)
		{
			newSize++;
		}
	}

	double* result = allocateMemoryDouble(newSize);

	for (int i = 0, j = 0; i < size; i++)
	{
		if (unit(sourse[i]) != units || zero(sourse[i]) != zeros)
		{
			result[j] = sourse[i];
			j++;
		}
	}

	delete[] sourse;

	return result;
}

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0;
	double term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

double* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	double* arr = new double[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}


void AddFile(char* fileName, double* arr, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nSorted array!\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << arr[i];
	}
	streamOut.close();
}
