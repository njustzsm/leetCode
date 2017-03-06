#include<iostream>


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (head == NULL)return NULL;
	if (head->next == NULL)return head;
	if (n - m < 1)return head;

	ListNode*tailNode = NULL, *firstNode = NULL,*endNode=NULL,*preNode=NULL,*nextNode=NULL,*curNode=head;
	

	int countn = 1;



	while (countn<m&&curNode!=NULL)
	{
		tailNode = curNode;
		curNode = curNode->next;
		countn++;
	}
	if (curNode == NULL)return head;

	if (tailNode != NULL)
		firstNode = tailNode->next;


	
	preNode = curNode;
	curNode = curNode->next;
	
	if (curNode == NULL)return head;

	while (countn<n&&curNode!=NULL)
	{
		nextNode = curNode->next;
		curNode->next = preNode;
		preNode = curNode;
		curNode = nextNode;

		countn++;

	}

	if (curNode == NULL)
	{
		if (tailNode == NULL)
		{
			head->next = NULL;
			return preNode;
		}
			
		else
		{
			firstNode->next = NULL;
			tailNode->next = preNode;
			return head;
		}
	}
	else
	{
		if (tailNode == NULL)
		{
			head->next = curNode;
			return preNode;
		}
		else
		{
			tailNode->next = preNode;
			firstNode->next = nextNode;
			return head;
		}
	}

}

void main()
{
	ListNode* node1 = new ListNode(3);
	ListNode* node2 = new ListNode(5);
	node1->next = node2;

	reverseBetween(node1,1,2);
}