#include "LinkedLists.h"

LinkedLists::LinkedLists()
{

}

LinkedLists::~LinkedLists()
{

}

ListNode* LinkedLists::MakeNode(ListNode** head, int d)
{
	ListNode* newNode = new ListNode;
	ListNode* last = *head;

	newNode->data = d;
	newNode->next = nullptr;

	if (*head == nullptr)
	{
		*head = newNode;
		return newNode;
	}

	while (last->next != nullptr)
	{
		last = last->next;
	}
	last->next = newNode;
	return newNode;
}

ListNode* LinkedLists::InsertFirst(ListNode** head, int d)
{
	return NULL;
}

void LinkedLists::InsertAfter(ListNode* lastNode, int d)
{

}

void LinkedLists::DeleteList(ListNode** node)
{

}

void LinkedLists::DeleteAfter(ListNode* node)
{

}

ListNode* LinkedLists::GetNode(ListNode* node, int pos)
{
	return NULL;
}

ListNode* LinkedLists::Find(ListNode* node, int val)
{
	return NULL;
}

void LinkedLists::PrintList(ListNode* node)
{
	while (node != nullptr)
	{
		std::cout << std::setw(5) << "| " << node->data << " |-->";
		node = node->next;
	}
	if (node == nullptr)
	{
		std::cout << "| NULL |" << std::endl;
	}
	std::cout << std::endl;
}