
#include <iostream>
#include <BinaryTree.h>
#include <vector>
using namespace std;

int main()
{
	BinaryTree tree;
	vector<double> treeValues;

	tree.insert(5.2);
	tree.insert(8.6);
	tree.insert(3.1);
	tree.insert(12.9);
	tree.insert(9.7);

	if (tree.search(8))
		cout << "8 was found in tree.\n";
	else
		cout << "8 was not found in tree.\n";

	tree.inorder(treeValues);

	for (int i = 0; i < treeValues.size(); i++)
	{
		cout << treeValues[i] << "  ";
	}
	cout << endl;

	return 0;
}
