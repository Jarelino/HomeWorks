#include <iostream>

using namespace std;

template<class T>
class Matrix
{
	public:
		Matrix<T> operator+(Matrix<T>);
		Matrix<T> operator-(Matrix<T>);
		Matrix<T> operator*(Matrix<T>);
		Matrix<T> operator=(Matrix<T>);

		Matrix(int, int);
		Matrix(Matrix<T>&);
		Matrix();
		Matrix(T**, int, int);

		T getItem(int,int);
		Matrix<T> GetMinor(int, int);
		
		void DisplayMinor(int, int);
		void Display();

		Matrix<T>& FillWith(T);
	private:
		T** AllocateMemory(int, int);
		T** matrix;
		int rows, columns;
};

template<class T>
Matrix<T>::Matrix(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->matrix = AllocateMemory(rows, columns);
}

template<class T>
inline Matrix<T>::Matrix(Matrix<T>& newObj)
{
	this->rows = newObj.rows;
	this->columns = newObj.columns;

	this->matrix = AllocateMemory(this->rows, this->columns);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			this->matrix[i][j] = newObj.getItem(i, j);
		}
	}
}

template<class T>
inline Matrix<T>::Matrix()
{
	this->matrix = AllocateMemory(0, 0);
}

template<class T>
inline Matrix<T>::Matrix(T** newMat, int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;

	this->matrix = AllocateMemory(this->rows, this->columns);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			this->matrix[i][j] = newMat[i][j];
		}
	}
}

template<class T>
inline T Matrix<T>::getItem(int i, int j)
{
	return this->matrix[i][j];
}

template<class T>
inline Matrix<T> Matrix<T>::operator+(Matrix<T> newObj)
{
	T** result = this->AllocateMemory(this->rows, this->columns);

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			result[i][j] = this->getItem(i, j) + newObj.getItem(i, j);
		}
	}

	Matrix<T> obj(result, this->rows, this->columns);
	delete[] result;
	return obj;
}

template<class T>
inline Matrix<T> Matrix<T>::operator-(Matrix<T> newObj)
{
	T** result = this->AllocateMemory(this->rows, this->columns);

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			result[i][j] = this->getItem(i, j) - newObj.getItem(i, j);
		}
	}

	Matrix<T> obj(result, this->rows, this->columns);
	delete[] result;
	return obj;
}

template<class T>
inline Matrix<T> Matrix<T>::operator*(Matrix<T> newObj)
{
	T** result = this->AllocateMemory(this->rows, this->columns);

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			result[i][j] = this->getItem(i, j) * newObj.getItem(i, j);
		}
	}

	Matrix<T> obj(result, this->rows, this->columns);
	delete[] result;
	return obj;
}

template<class T>
inline Matrix<T> Matrix<T>::operator=(Matrix<T> newObj)
{
	this->rows = newObj.rows;
	this->columns = newObj.columns;

	this->matrix = AllocateMemory(this->rows, this->columns);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			this->matrix[i][j] = newObj.getItem(i, j);
		}
	}

	return *this;
}

template<class T>
inline void Matrix<T>::Display()
{
	cout << "Your matrix: \n";

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			cout << this->matrix[i][j] << " ";
		}

		cout << endl;
	}
}

template<class T>
inline void Matrix<T>::DisplayMinor(int row, int column)
{
	cout << "Your " << row << " " << column << " matrix: \n";

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if (i != row && j != column)
			{
				cout << this->matrix[i][j] << " ";
			}
		}
		if (i != row)
		{
			cout << endl;
		}
	}
}

template<class T>
inline Matrix<T> Matrix<T>::GetMinor(int row, int column)
{
	T** result = AllocateMemory(this->rows - 1, this->columns - 1);
	
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if (i != row && j != column)
			{
				result[i - (i > row)][j - (j > column)] = this->matrix[i][j];
			}
		}
	}
	Matrix<T> obj(result, this->rows - 1, this->columns - 1);
	delete[] result;
	return obj;
}

template<class T>
inline Matrix<T>& Matrix<T>::FillWith(T numb)
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			this->matrix[i][j] = numb;
		}
	}

	return *this;
}

template<class T>
T** Matrix<T>::AllocateMemory(int rows, int columns)
{
	T** result = new T * [rows];

	for (int i = 0; i < rows; i++)
	{
		result[i] = new T[columns];
	}

	return result;
}