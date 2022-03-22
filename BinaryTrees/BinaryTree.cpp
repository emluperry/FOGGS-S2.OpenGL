#include "BinaryTree.h"

BinaryTree::BinaryTree()
{

}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::MakeNode(int d, TreeNode** r)
{
	TreeNode* newNode = new TreeNode(d);
	newNode->leftNode = nullptr;
	newNode->rightNode = nullptr;

	TreeNode* next = *r;
	TreeNode* last = *r;
	bool leftOrRight = false;

	if (*r == nullptr)
	{
		*r = newNode;
		return;
	}

	while (next != nullptr)
	{
		if (next->data > d)
		{
			last = next;
			next = next->leftNode;
			leftOrRight = false;
		}
		else
		{
			last = next;
			next = next->rightNode;
			leftOrRight = true;
		}
	}
	if (leftOrRight)
	{
		last->rightNode = newNode;
	}
	else
	{
		last->leftNode = newNode;
	}
}

void BinaryTree::PrintPreOrder(TreeNode* r)
{
	if (r == nullptr)
	{
		std::cout << " NULL ";
		return;
	}

	std::cout << " " << r->data << " ";
	if (r->leftNode != nullptr)
	{
		PrintPreOrder(r->leftNode);
	}
	if (r->rightNode != nullptr)
	{
		PrintPreOrder(r->rightNode);
	}
}

void BinaryTree::PrintInOrder(TreeNode* r)
{
	if (r == nullptr)
	{
		std::cout << " NULL ";
		return;
	}

	if (r->leftNode != nullptr)
	{
		PrintInOrder(r->leftNode);
	}
	std::cout << " " << r->data << " ";
	if (r->rightNode != nullptr)
	{
		PrintInOrder(r->rightNode);
	}
}

void BinaryTree::PrintPostOrder(TreeNode* r)
{
	if (r == nullptr)
	{
		std::cout << " NULL ";
		return;
	}

	if (r->leftNode != nullptr)
	{
		PrintPostOrder(r->leftNode);
	}
	if (r->rightNode != nullptr)
	{
		PrintPostOrder(r->rightNode);
	}
	std::cout << " " << r->data << " ";
}

void BinaryTree::DeleteTree(TreeNode** r)
{
	if ((*r)->leftNode != nullptr)
	{
		DeleteTree(&(*r)->leftNode);
		(*r)->leftNode = nullptr;
	}
	if ((*r)->rightNode != nullptr)
	{
		DeleteTree(&(*r)->rightNode);
		(*r)->rightNode = nullptr;
	}
	delete *r;
	*r = nullptr;
}