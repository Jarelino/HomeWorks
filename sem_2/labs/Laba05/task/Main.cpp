#include "Set.h";

int main() {
	int* arr = new int[5];
	Set obj(arr, 5);

	obj.SetItem(1, 0);
	obj.SetItem(2, 1);
	obj.SetItem(3, 2);
	obj.SetItem(4, 3);
	obj.SetItem(5, 4);

	Set obj1(arr, 5);

	obj1 = obj;
	cout << "\t\tMain class Tests\n";
	cout << "Set 1:";
	obj1.Display();
	cout << "Set 2:";
	obj.Display();

	cout << "Operation(+):";
	(obj1 + obj).Display();

	cout << "Operation(-):";
	(obj1 - obj).Display();
	
	cout << "Operation(*):";
	(obj1 * obj).Display();
	
	cout << "Operation(/):";
	(obj1 / obj).Display();
	
	return 0;
}