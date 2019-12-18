#include "Matrix.h"

int main()
{
	Matrix<float> mat(5, 5);
	mat.FillWith(1);
	mat.Display();
	mat.FillWith(2).Display();
	mat.GetMinor(1, 1).FillWith(5).Display();
	mat.DisplayMinor(1, 1);

	(mat.FillWith(1) + mat.FillWith(2)).Display();
	(mat.FillWith(2) * mat.FillWith(2.5)).Display();
	(mat.FillWith(1) - mat.FillWith(2)).Display();

	(mat = mat.FillWith(1)).Display();

	return 0;
}