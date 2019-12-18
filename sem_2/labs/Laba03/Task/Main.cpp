#include "BinaryTree.h"

int main() {
	vector<double> arr = { 10, 6, 16, 4, 7, 14, 17 };
	BinaryTree obj(arr);

	cout << "\nInit 10 - 6 16 - 4 7 14 17 tree: " << endl;
	obj.DisplayTree(0); cout << endl;
	obj.DisplayTree(1); cout << endl;
	obj.DisplayTree(2); cout << endl;

	cout << "\nSorted array: ";
	for (int i = 0; i < obj.GetArray().size(); i++)
	{
		cout << obj.GetArray()[i] << " ";
	}
	cout << "\n";
	return 0;
}