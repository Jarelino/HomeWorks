#include "DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray() : innerArray(nullptr)
{
	this->innerArray = allocateMemory(defaulCapacity);
	this->capacity = defaulCapacity;
	this->length = 0;
}

DynamicArray::DynamicArray(int size) :innerArray(nullptr)
{
	this->innerArray = allocateMemory(size);
	this->capacity = size;
	this->length = 0;
}

DynamicArray::DynamicArray(const DynamicArray & array)
{
	this->innerArray = allocateMemory(array.capacity);
	this->capacity = array.capacity;
	this->length = array.length;

	for (int i = 0; i < this->length; i++)
	{
		this->innerArray[i] = array.innerArray[i];
	}
}


DynamicArray::~DynamicArray()
{
	delete[] innerArray;
}

const int& DynamicArray::operator[](int index) const
{
	if (index < 0 || index >= length)
	{
		throw invalid_argument("Invalid index of array.");
	}

	return this->innerArray[index];
}

int& DynamicArray::operator[](int index)
{
	if (index < 0 || index >= length)
	{
		throw invalid_argument("Invalid index of array.");
	}

	return this->innerArray[index];
}

/*
DynamicArray DynamicArray::operator=(const DynamicArray & source)
{
	return DynamicArray(source);
}
*/

void DynamicArray::setLength(int number)
{
	if (number < 0)
	{
		throw invalid_argument("Length need to be more or equal to zero .");
	}

	this->length = number;
}

int DynamicArray::getLength() const
{
	return this->length;
}

int DynamicArray::min() const
{
	int min = this->innerArray[0];

	for (int i = 1; i < this->length; i++)
	{
		if (min > this->innerArray[i])
		{
			min = this->innerArray[i];
		}
	}

	return min;
}

int DynamicArray::max() const
{
	int max = this->innerArray[0];

	for (int i = 1; i < this->length; i++)
	{
		if (max < this->innerArray[i])
		{
			max = this->innerArray[i];
		}
	}

	return max;
}

void DynamicArray::add(int item)
{
	int length = this->getLength();

	if (length >= this->capacity)
	{
		this->capacity *= growFactor;

		this->resizeArray(this->innerArray, length, this->capacity);
	}

	this->innerArray[length] = item;
	this->setLength(this->length + 1);
}

int DynamicArray::binarySearch(int item) const
{
	int midd = 0 , left = 0, right = this->getLength() - 1;
	while (1)
	{
		midd = (left + right) / 2;

		if (item < this->innerArray[midd])       
			right = midd - 1;      
		else if (item > this->innerArray[midd])
			left = midd + 1;    
		else                      
			return midd;          

		if (left > right)         
			return -1;
	}
}


void DynamicArray::trim()
{
	resizeArray(this->innerArray,this->capacity, this->length);

	this->capacity = length;
}

void DynamicArray::insertTo(int item, int index)
{
	this->add(item);

	int i = this->getLength() - 2;
	
	while (i >= index)
	{
		swap(this->innerArray[i], this->innerArray[i + 1]);
		i--;
	}
}

void DynamicArray::remove(int index)
{
	for (int i = index + 1; i < this->length; i++)
	{
		(*this)[i - 1] = this->innerArray[i];
	}

	this->setLength(this->length - 1);
}


void DynamicArray::resizeArray(int *& array, int oldLength, int newLength)
{
	int* tmp = allocateMemory(newLength);

	copyArray(array, oldLength, tmp);

	delete[] array;

	array = tmp;
}

void DynamicArray::copyArray(int * array, int size, int* copyArray)
{
	for (int i = 0; i < size; i++)
	{
		copyArray[i] = array[i];
	}
}

int* DynamicArray::allocateMemory(int size)
{
	if (size < 0)
	{
		throw invalid_argument("Length need to be more or equal to zero .");
	}

	int* intMemory = new int[size];

	for (int i = 0; i < size; i++)
	{
		intMemory[i] = 0;
	}

	return intMemory;
}

ostream & operator<<(ostream & stream, const DynamicArray & array)
{
	for (int i = 0; i < array.getLength(); i++)
	{
		stream << array[i] << " ";
	}

	return stream;
}

void DynamicArray::qSort()
{
	this->qSort(0, this->getLength() - 1);
}

void DynamicArray::qSort(int start, int end)
{

	int i = start, j = end;

	int pivot = this->innerArray[(start + end) / 2];

	while (i <= j)
	{
		while (this->innerArray[i] < pivot)
			i++;
		while (this->innerArray[j] > pivot)
			j--;

		if (i <= j)
		{
			swap(this->innerArray[i], this->innerArray[j]);
			i++;
			j--;
		}

	};

	if (start < j)
		qSort(start, j);
	if (i < end)
		qSort(i, end);

}