#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::Matrix(int n, int m)
{
	this->AllocateMemory(n, m);
	this->SetRows(n);
	this->SetColumns(m);
	this->FillWith(0);
}

Matrix::Matrix(int ** matrix, int n, int m)
{
	this->SetRows(n);
	this->SetColumns(m);
	this->SetMatrix(matrix);
}


Matrix::Matrix(Matrix& newObj)
{
	this->SetColumns(newObj.GetColumns());
	this->SetRows(newObj.GetRows());
	this->SetMatrix(newObj.GetMatrix());
}

int Matrix::GetRows()
{
	return this->rows;
}

int Matrix::GetColumns()
{
	return this->columns;
}

int** Matrix::GetMatrix()
{
	return this->matrix;
}

Matrix& Matrix::GetMinor(int n, int m)
{
	int** result = this->AllocateMemory(this->GetRows() - 1, this->GetColumns() - 1);

	for (int i = 0; i < this->GetRows(); i++)
	{
		for (int j = 0; j < this->GetColumns(); j++)
		{
			if (i != n && j != m)
			{
				result[i - (i > n)][j - (j > m)] = this->GetMatrix()[i][j];
			}
		}
	}

	Matrix obj(result, this->GetRows() - 1, this->GetColumns() - 1);
	return obj;
}

void Matrix::Display()
{
	cout << endl;

	for (int i = 0; i < this->GetRows(); i++)
	{
		for (int j = 0; j < this->GetColumns(); j++)
		{
			cout << " " << this->GetMatrix()[i][j] << " ";
		}
	}

	cout << endl;
}

void Matrix::DisplayMinor(int n, int m)
{
	cout << endl;

	for (int i = 0; i < this->GetRows(); i++)
	{
		for (int j = 0; j < this->GetColumns(); j++)
		{
			if (i != (n - 1) && j != (m - 1))
			{
				cout << " " << this->GetMatrix()[i][j] << " ";
			}
		}
	}

	cout << endl;
}

void Matrix::FillWith(int numb)
{
	for (int i = 0; i < this->GetRows(); i++)
	{
		for (int j = 0; j < this->GetColumns(); j++)
		{
			this->GetMatrix()[i][j] = numb;
		}
	}
}


Matrix::~Matrix()
{
}

int ** Matrix::AllocateMemory(int n, int m)
{
	int** result = new int*[n];

	for (int i = 0; i < n; i++)
	{
		result[i] = new int[m];
	}
	return result;
}

void Matrix::SetRows(int newRow)
{
	this->rows = newRow;
}

void Matrix::SetColumns(int newColumn)
{
	this->columns = newColumn;
}

void Matrix::SetMatrix(int ** newMatrix)
{
	this->matrix = AllocateMemory(this->GetRows(), this->GetColumns());
	for (int i = 0; i < this->GetRows(); i++)
	{
		for (int j = 0; j < this->GetColumns(); j++)
		{
			this->matrix[i][j] = newMatrix[i][j];
		}
	}
}

Matrix operator+(Matrix & firstMatrix, Matrix & secondMatrix)
{
	int** result = firstMatrix.AllocateMemory(firstMatrix.GetRows(), firstMatrix.GetColumns());

	for (int i = 0; i < firstMatrix.GetRows(); i++)
	{
		for (int j = 0; j < firstMatrix.GetColumns(); j++)
		{
			result[i][j] = firstMatrix.GetMatrix()[i][j] + secondMatrix.GetMatrix()[i][j];
		}
	}

	Matrix obj(result, firstMatrix.GetRows(), firstMatrix.GetColumns());
	return obj;
}

Matrix operator-(Matrix & firstMatrix, Matrix & secondMatrix)
{
	int** result = firstMatrix.AllocateMemory(firstMatrix.GetRows(), firstMatrix.GetColumns());

	for (int i = 0; i < firstMatrix.GetRows(); i++)
	{
		for (int j = 0; j < firstMatrix.GetColumns(); j++)
		{
			result[i][j] = firstMatrix.GetMatrix()[i][j] - secondMatrix.GetMatrix()[i][j];
		}
	}

	Matrix obj(result, firstMatrix.GetRows(), firstMatrix.GetColumns());
	return obj;
}

Matrix operator*(Matrix & firstMatrix, Matrix & secondMatrix)
{
	int** result = firstMatrix.AllocateMemory(firstMatrix.GetRows(), firstMatrix.GetColumns());

	for (int i = 0; i < firstMatrix.GetRows(); i++)
	{
		for (int j = 0; j < firstMatrix.GetColumns(); j++)
		{
			result[i][j] = firstMatrix.GetMatrix()[i][j] * secondMatrix.GetMatrix()[i][j];
		}
	}

	Matrix obj(result, firstMatrix.GetRows(), firstMatrix.GetColumns());
	return obj;
}

