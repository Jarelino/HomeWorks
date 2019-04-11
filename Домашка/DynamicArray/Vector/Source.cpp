#include "DynamicArray.h"
#include <iostream>

using namespace std;

void console(const DynamicArray&);
bool assertThatAddWork();
bool assertThatSortWork();
bool assrtThatBinSearchWork();
bool assertThatInsertToWork();
void tests();

int main()
{
	tests();

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