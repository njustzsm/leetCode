#include<iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* partition(ListNode* head, int x) 
{
	if (head == NULL || head->next == NULL)return head;

	ListNode*curNode = head;
	ListNode*tailNode = NULL;

	
	bool isSolved = true;

	while (curNode!=NULL)
	{
		if (curNode->next == NULL)
			tailNode = curNode;

		if (curNode->val >=x&&curNode->next != NULL)
			isSolved = false;

		curNode = curNode->next;
	}

	if (isSolved)return head;


	ListNode*startNode = head;
	
	while (startNode!=NULL&&startNode->val<x)
	{
		startNode = startNode->next;
	}

	if (startNode == NULL)return head;


	ListNode*preNode = startNode;
	startNode = startNode->next;
	
	while (startNode!=NULL)
	{
		while (startNode!=NULL&&startNode->val>=x)
		{
			preNode = startNode;
			startNode = startNode->next;
		}
		if (startNode == NULL)
			return head;

		ListNode*insertNode = startNode;
		preNode->next = startNode->next;
		startNode = startNode->next;

		if (head->val >= x)
		{
			insertNode->next = head;
			head = insertNode;
		}
		else
		{
			ListNode*temp = head;
			while (temp->next->val<x)
			{
				temp = temp->next;
			}
			
			insertNode->next = temp->next;
			temp->next = insertNode;
		}
	}

	return head;
}

void main()
{

}