#include "BinaryTree.h"

BinaryTree::BinaryTree(double numb)
{
	this->root = new tree();
	this->root->info = numb;
}

BinaryTree::BinaryTree()
{
	this->root = new tree();
}

BinaryTree::BinaryTree(double* arr, int size)
{
	this->root = new tree();

	for (int i = 0; i < size; i++)
	{
		this->AddItem(arr[i]);
	}
}

BinaryTree::BinaryTree(vector<double>& arr)
{
	this->root = new tree();

	for (int i = 0; i < arr.size(); i++)
	{
		this->AddItem(arr[i]);
	}
}

void BinaryTree::AddItem(double numb)
{
	AddNode(numb, this->root);
}

void BinaryTree::AddNode(double numb, tree* node)
{
	if (node->info == numb || !node->info)
	{
		node->info = numb;
		return;
	}
	if (numb > node->info && !node->right)
	{
		node->right = new tree();
		node->right->info = numb;
		return;
	}
	else if (numb < node->info && !node->left)
	{
		node->left = new tree();
		node->left->info = numb;
		return;
	}

	if (numb < node->info)
	{
		this->AddNode(numb, node->left);
	}
	else
	{
		this->AddNode(numb, node->right);
	}

}

void BinaryTree::PrintTree(tree* node, int layer)
{
	if (layer < 0)
	{
		cout << "Cannot display " << layer << " layer!";
		return;
	}

	if (layer == 0)
	{
		cout << ' ' << node->info << ' ';
	}
	else {
		if (node->left)
		{
			this->PrintTree(node->left, layer - 1);
		}
		else 
		{
			cout << " noneL ";
		}

		if (node->right)
		{
			this->PrintTree(node->right, layer - 1);
		}
		else 
		{
			cout << " noneR ";
		}
	}
}

vector<double> BinaryTree::GetArray()
{
	vector<double> result;
	PushArray(this->root, result);
	return result;
}

void BinaryTree::PushArray(tree* node, vector<double>& array)
{
	if(node->left) PushArray(node->left, array);
	array.push_back(node->info);
	if(node->right) PushArray(node->right, array);
}

void BinaryTree::DisplayTree(int r)
{
	PrintTree(this->root, r);
}

void BinaryTree::DisplayTree(tree* node, int r)
{
	PrintTree(node, r);
}

