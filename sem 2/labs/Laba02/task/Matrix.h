#include <iostream>

using namespace std;


class Matrix
{

	friend Matrix operator+(Matrix&, Matrix&);
	friend Matrix operator-(Matrix&);
	friend Matrix operator*(Matrix&);
public:
	Matrix();
	Matrix(int, int);
	Matrix(int**, int, int);
	Matrix(Matrix&);


	int GetRows();
	int GetColumns();
	int** GetMatrix();
	Matrix& GetMinor(int, int);

	void Display();
	void DisplayMinor(int, int);
	void FillWith(int);
	int** AllocateMemory(int, int);

	~Matrix();
private:
	int** matrix;
	int rows, columns;

	void SetRows(int);
	void SetColumns(int);
	void SetMatrix(int**);
};

