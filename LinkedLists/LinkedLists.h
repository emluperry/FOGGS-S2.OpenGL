#pragma once
#include <iostream>
#include <iomanip>
#include "structs.h"

class LinkedLists
{
private:
	ListNode* head = nullptr;
public:
	LinkedLists();
	~LinkedLists();

	ListNode* MakeNode(ListNode** head, int d);
	ListNode* InsertFirst(ListNode** head, int d);
	void InsertAfter(ListNode* lastNode, int d);
	void DeleteList(ListNode** node);
	void DeleteAfter(ListNode* node);
	ListNode* GetNode(ListNode* node, int pos);
	ListNode* Find(ListNode* node, int val);
	void PrintList(ListNode* node);

	void DeleteNodeAtPos(ListNode** node, int pos);
};