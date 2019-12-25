#include "Set.h"

Set Set::operator+(Set newSet)
{
	int* result = this->AllocateMemory(this->length);

	for (int i = 0; i < this->length; i++)
	{
		result[i] = this->GetItem(i) + newSet.GetItem(i);
	}

	Set obj(result, this->length);
	return obj;
}

Set Set::operator-(Set newSet)
{
	int* result = this->AllocateMemory(this->length);

	for (int i = 0; i < this->length; i++)
	{
		result[i] = this->GetItem(i) - newSet.GetItem(i);
	}

	Set obj(result, this->length);
	return obj;
}

Set Set::operator*(Set newSet)
{
	int* result = this->AllocateMemory(this->length);

	for (int i = 0; i < this->length; i++)
	{
		result[i] = this->GetItem(i) * newSet.GetItem(i);
	}

	Set obj(result, this->length);
	return obj;
}

Set Set::operator/(Set newSet)
{
	int* result = this->AllocateMemory(this->length);

	for (int i = 0; i < this->length; i++)
	{
		result[i] = (int)(this->GetItem(i) / newSet.GetItem(i));
	}

	Set obj(result, this->length);
	return obj;
}

Set Set::operator=(Set newSet)
{
	this->SetSet(newSet.set, newSet.length);
	return *this;
}

Set::Set(Set& newSet)
{
	this->SetSet(newSet.set, newSet.length);
}

Set::Set(int length)
{
	this->set = this->AllocateMemory(length);
}

Set::Set(int* newSet, int newLength)
{
	this->SetSet(newSet, newLength);
}

int Set::GetItem(int i)
{
	return this->set[i];
}

void Set::SetSet(int* newSet, int newLength)
{
	this->set = this->AllocateMemory(newLength);
	this->length = newLength;

	for (int i = 0; i < newLength; i++)
	{
		this->SetItem(newSet[i], i);
	}
}

int* Set::AllocateMemory(int length)
{
	int* result = new int[length];
	return result;
}

void Set::SetItem(int item, int index)
{
	this->set[index] = item;
}

void Set::Display()
{
	cout << endl;

	for (int i = 0; i < this->length; i++)
	{
		cout << '\t' << this->GetItem(i);
	}

	cout << endl;
}
