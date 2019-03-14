

namespace MatrixLibrary
{
	typedef double(*value)(int, int);
	typedef double(*exactValue)(int, int, int);

	//inputs
	int inputSquareMatrixSize();
	int inputAccuracy();

	//allocateMemory
	int** allocateMemoryInt(int, int);
	double** allocateMemoryDouble(int, int);

	void fillMatrix(double**, int, int, value);
	void fillMatrix(double**, int, int, int, exactValue);

	void displayDoubleMatrix(double**, int, int);

	double taylorSin(double, int);

	double maxMatrixDifference(double**, double**, int, int);
}