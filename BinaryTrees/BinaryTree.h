#pragma once
#include "structs.h"
#include <iostream>

class BinaryTree
{
private:
	TreeNode* root = nullptr;
public:
	BinaryTree();
	~BinaryTree();

	void MakeNode(int d, TreeNode** r);

	void PrintPreOrder(TreeNode* r);
	void PrintInOrder(TreeNode* r);
	void PrintPostOrder(TreeNode* r);

	void DeleteTree(TreeNode** r);
};

