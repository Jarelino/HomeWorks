#include <iostream>

using namespace std;


class Matrix
{

	friend Matrix operator+(Matrix, Matrix);
	friend Matrix operator-(Matrix&, Matrix&);
	friend Matrix operator*(Matrix&, Matrix&);
public:
	Matrix& operator= (Matrix obj);
	
	Matrix();
	Matrix(int, int);
	Matrix(int**, int, int);
	Matrix(const Matrix&);

	
	int GetRows() const;
	int GetColumns() const;
	void MultiplyBy(int);
	int** GetMatrix() const;
	Matrix GetMinor(int, int);

	void Enter(int**, int, int);
	int** AllocateMemory(int, int);
	void Display();
	void DisplayMinor(int, int);
	Matrix& FillWith(int);

	~Matrix();
private:
	int** matrix;
	int rows, columns;

	void SetRows(int);
	void SetColumns(int);
	void SetMatrix(int**);
};

