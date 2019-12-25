#include <iostream>

using namespace std;

#pragma once
class Set
{
public:
	Set operator+(Set);
	Set operator-(Set);
	Set operator*(Set);
	Set operator/(Set);
	Set operator=(Set);
	Set(Set&);
	Set(int);
	Set(int*, int);
	int GetItem(int);
	void SetItem(int, int);
	void Display();
private:
	void SetSet(int*, int);
	static int* AllocateMemory(int);
	int* set;
	int length;
};

