#include <iostream>
#include "BinaryTree.h"
#include "structs.h"

int main()
{
	TreeNode* root = nullptr;
	BinaryTree* tree = new BinaryTree();
	tree->MakeNode(10, &root);
	tree->MakeNode(6, &root);
	tree->MakeNode(13, &root);
	tree->MakeNode(3, &root);
	tree->MakeNode(8, &root);
	tree->MakeNode(11, &root);
	tree->MakeNode(15, &root);

	tree->PrintPreOrder(root);
	std::cout << std::endl;
	tree->PrintInOrder(root);
	std::cout << std::endl;
	tree->PrintPostOrder(root);
	std::cout << std::endl;

	tree->DeleteTree(&root);
	tree->PrintInOrder(root);
}