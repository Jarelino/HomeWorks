#include <iostream>

using namespace std;
#include "BinaryTree.h"

int main() {
	BinaryTree obj(10);
	obj.AddItem(6);
	obj.AddItem(16);
	obj.AddItem(17);
	obj.AddItem(14);
	obj.AddItem(4);
	obj.AddItem(7);
	cout << "Init 10 - 6 16 - 4 7 14 17 tree: " << endl;
	obj.DisplayTree(0); cout << endl;
	obj.DisplayTree(1); cout << endl;
	obj.DisplayTree(2); cout << endl;
	for (int i = 0; i < obj.GetArray().size(); i++)
	{
		cout << obj.GetArray()[i] << " ";
	}
	return 0;
}