#include <io.h>
#include <fstream>
#include <iostream>
#include "Student.h"

using namespace std;

void DisplayFile(char*);
void AddToEndFile(char*, Student*, int);
Student* InitStudent(char*, int);
int StudentsCount(char*);

int main()
{
	char binary[] = "List.bin";
	char input[] = "input.txt";

	int count = StudentsCount(input);
	Student* mans = InitStudent(input, count);

	AddToEndFile(binary, mans, count);
	DisplayFile(binary);

	system("pause");
	return 0;
}

int StudentsCount(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	char* str = new char[N];
	int mark;
	int count = 0;

	while (!streamIn.eof())
	{
		streamIn >> str;
		streamIn >> str;
		streamIn >> str;

		for (int i = 0; i < M; i++)
		{
			streamIn >> mark;
		}
		count++;
	}

	streamIn.close();
	return count;
}

Student* InitStudent(char* fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	Student* mans = new Student[n];
	int i = 0;
	char* name = new char[N];
	char* lastName = new char[N];
	char* faculty = new char[N];
	int* marks = new int[M];

	while (!streamIn.eof())
	{
		streamIn >> name;
		streamIn >> lastName;
		streamIn >> faculty;
		for (int i = 0; i < M; i++)
		{
			streamIn >> marks[i];
		}

		mans[i] = Student(name,lastName, faculty, marks);
		i++;
	}


	return mans;
}

void AddToEndFile(char* fileName, Student* man, int n)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		int bufSize = sizeof(Student);

		streamOut.write((char*)&man[i], bufSize);
	}
	streamOut.close();
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		system("cls");
		cout << "Can't open file to read!";
		system("pause");
		return;
	}
	int bufSize = sizeof(Student);
	Student* man = new Student;
	while (streamIn.read((char*)man, bufSize))
	{
		man->DisplayStudent();
	}

	cout << endl;
	streamIn.close();
}
