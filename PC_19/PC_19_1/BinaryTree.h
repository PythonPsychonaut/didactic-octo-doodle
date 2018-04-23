#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <vector>
using namespace std;

class BinaryTree
{
private:
	class CatstreeNode
	{
		friend class BinaryTree;
		double value;
		CatstreeNode *left;
		CatstreeNode *right;
		CatstreeNode(double value1, CatstreeNode *left1 = NULL, CatstreeNode *right1 = NULL)
		{
			value = value1;
			left = left1;
			right = right1;
		}
	};
	CatstreeNode *root;		
	void insert(CatstreeNode *&, double);
	bool search(double, CatstreeNode *);
	void fillInorder(vector <double> & v, CatstreeNode *);
public:
	BinaryTree(){ root = NULL; }
	void insert(double x)
	{insert(root, x);}
	bool search(double x)
	{return search(x, root);}
	void inorder(vector <double> & v)
	{fillInorder(v, root);}
};
#endif
