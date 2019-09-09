#include <iostream>
#include <fstream>

//Поменять 1,3,5... из Первого с 0,2,4... из Второго остаток в Трейтий

#pragma warning(disable : 4996);

using namespace std;

void BlockWriteFile(char*, int, int, int);
void DisplayFile(char*, int, int);
void DisplayMatrix(int*, int, int);
void InitMatrix(int*, int, int);
int** Convert(int*, int**, int, int);
int* ReverseConvert(int**, int, int);
int** AllocateMemory(int, int);
int Input(const char*);
void WorkFile(char*, char*, char*, int, int, int, int);


int main()
{
	char firstFile[] = "firstFile.bin";
	char secondFile[] = "secondFile.bin";
	char thirdFile[] = "thirdFile.bin";


	int firstCount, secondCount, n, m;
	firstCount = Input("Enter number of matrix in 1 file: ");
	secondCount = Input("Enter number of matrix in 2 file: ");
	n = Input("Enter number of rows in matrix: ");
	m = Input("Enter number of columns in matrix: ");

	BlockWriteFile(firstFile, firstCount, n, m);
	BlockWriteFile(secondFile, secondCount, n, m);
	DisplayFile(firstFile, n, m);
	DisplayFile(secondFile, n, m);

	cout << endl << "--------------------------------------------------" << endl;

	WorkFile(firstFile, secondFile, thirdFile, firstCount, secondCount, n, m);
	DisplayFile(firstFile, n, m);
	DisplayFile(secondFile, n, m);


	system("pause");
	return 0;
}

void BlockWriteFile(char* fileName, int k, int n, int m)
{
	ofstream streamOut(fileName, ios::out | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write.";
		system("pause");
		exit(1);
	}
	int bufSize = sizeof(int) * n * m;
	int* pointer = new int[n * m];
	for (int i = 0; i < k; i++)
	{
		InitMatrix(pointer, n, m);
		streamOut.write((char*)pointer, bufSize);
	}
	delete[] pointer;
	streamOut.close();
}

void InitMatrix(int* pointer, int n, int m)
{
	for (int i = 0; i < n * m; i++)
		pointer[i] = rand() % 10;
}

void DisplayFile(char* fileName, int n, int m)
{
	ifstream streamIn(fileName, ios::in | ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read.";
		system("pause");
		exit(1);
	}
	int bufSize = sizeof(int) * n * m, counter = 0;
	int* pointer = new int[n * m];
	while (streamIn.read((char*)pointer, bufSize))
	{
		cout << endl << counter + 1 << "'s  matrix " << endl;
		DisplayMatrix(pointer, n, m);
		counter++;
	}
	delete[] pointer;
	streamIn.close();
}


int** AllocateMemory(int n, int m)
{
	int** result = new int*[n];

	for (int i = 0; i < m; i++)
	{
		result[i] = new int[m];
	}


	return result;
}

int Input(const char * msg)
{
	int result;
	cout << msg;
	cin >> result;
	return result;
}

void WorkFile(char * fFile, char * sFile, char * tFile, int fSize, int sSize, int n, int m)
{
	fstream streamF(fFile, ios::in | ios::out | ios::binary);
	fstream streamS(sFile, ios::in | ios::out | ios::binary);

	int* pointerF = new int[n * m];
	int* pointerS = new int[n * m];
	int bufSize = sizeof(int) * n * m;

	for (int i = 0; i + 1 < fSize && i + 1 < sSize; i += 2)
	{
		streamF.seekp(bufSize, ios_base::cur);
		streamF.read((char*)pointerF, bufSize);
		streamS.read((char*)pointerS, bufSize);

		streamF.seekp(-bufSize, ios_base::cur);
		streamS.seekp(-bufSize, ios_base::cur);

		streamF.write((char*)pointerS, bufSize);
		streamS.write((char*)pointerF, bufSize);

		streamS.seekp(bufSize, ios_base::cur);
	}

	streamF.close();
	streamS.close();

	delete[] pointerF;
	delete[] pointerS;
}

int* ReverseConvert(int** sourse, int n, int m)
{
	int* array = new int[n * m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			array[i*m + j] = sourse[i][j];
		}
	}

	return array;
}

int** Convert(int* sourse, int** matrix, int n, int m)
{

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];

		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = sourse[(i*m) + j];
		}
	}

	return matrix;
}

void DisplayMatrix(int* pointer, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(4);
			cout << pointer[i * m + j];
		}
		cout << endl;
	}
}