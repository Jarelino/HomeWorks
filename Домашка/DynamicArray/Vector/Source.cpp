#include "DynamicArray.h"
#include <iostream>
#include <fstream>

using namespace std;

void console(const DynamicArray&);
bool assertThatAddWork();
bool assertThatSortWork();
bool assrtThatBinSearchWork();
bool assertThatInsertToWork();
void tests();

void CreateFile(char* fileName, int n);
int ContentsFile(char*);
int* InitArray(char*, int);
void BubbleSort(int*, int);
void AddFile(char*, int*, int);
void quickSort(int*,int,int);

int main()
{
	const int N = 30;
	char fileName[] = "file.txt";
	int count = ContentsFile(fileName);
	int* someArray = InitArray(fileName, count);

	quickSort(someArray, 0, count);
	AddFile(fileName, someArray, count);
	system("pause");
	return 0;
}

void tests()
{
	cout << "Method add works? " << (assertThatAddWork() ? "True." : "False.") << endl;
	cout << "Method insertTo works? " << (assertThatInsertToWork() ? "True." : "False.") << endl;
	cout << "Sort works? " << (assertThatSortWork() ? "True." : "False.") << endl;
	cout << "BinarySearch works? " << (assrtThatBinSearchWork() ? "True." : "False.") << endl;
}

bool assertThatAddWork()
{
	DynamicArray firstArray;

	int length = 10;

	bool sameElements = true;

	for (int i = 0; i < length; i++)
	{
		firstArray.add(i);

		if (firstArray[i] != i)
		{
			sameElements = false;
			break;
		}
	}

	bool rigthLength = firstArray.getLength() == length;

	return sameElements && rigthLength;
}

bool assertThatSortWork()
{
	DynamicArray array;

	int length = 10;

	for (int i = length - 1; i >= 0; i--)
	{
		array.add(i);
	}

	array.qSort();

	for (int i = 1; i < length; i++)
	{
		if (array[i] < array[i - 1])
		{
			return false;
		}
	}

	return true;
}

bool assrtThatBinSearchWork()
{
	DynamicArray array;

	int length = 10;

	bool needElement = true;

	for (int i = 0; i < length; i++)
	{
		array.add(i);
		if (array.binarySearch(i) != i)
		{
			needElement = false;
		}
	}

	return needElement;
}

bool assertThatInsertToWork()
{
	DynamicArray array;

	array.add(1);
	array.add(1);
	array.add(1);
	array.add(1);
	array.add(1);
	array.add(1);
	array.add(1);
	array.insertTo(5, 0);

	return array[0] == 5 ? true : false;
}

void CreateFile(char* fileName, int n)
{
	ofstream streamOut(fileName);
	//    ofstream streamOut;
	//    streamOut.open(fileName, ios::out);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	for (int i = 1; i <= n; i++)
	{
		//int temp;
		//cout << "enter value # " << i << " : ";
		//cin >> temp;
		int temp = n - i;
		streamOut.width(5);
		streamOut << temp;
		//cout << temp << endl;
	}

	streamOut.close();
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

	int count = 0, term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}

void BubbleSort(int* arr, int n)//error dimention!
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int x = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = x;
			}
		}
	}
}

void AddFile(char* fileName, int* arr, int n)
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

void quickSort(int* array, int left, int right)
{

	int i = left, j = right;

	int pivot = array[(left + right) / 2];



	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i <= j)
		{
			swap(array[i], array[j]);
			i++;
			j--;

		}

	};

	if (left < j)
		quickSort(array,left, j);
	if (i < right)
		quickSort(array, i, right);

}