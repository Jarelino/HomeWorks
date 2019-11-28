#include <iostream>
#include "Tree.cpp"
#include <vector>
using namespace std;

class BinaryTree
{
public:
	BinaryTree(double);
	BinaryTree();
	void AddItem(double);
	void AddNode(double, tree*);
	void DisplayTree(int);
	void DisplayTree(tree*, int);
	void PrintTree(tree*, int);
	vector<double> GetArray();
private:
	static void PushArray(tree*, vector<double>&);
	tree* root;
};

