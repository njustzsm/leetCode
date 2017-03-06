#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode*root)
{
	ListNode*pre = NULL, *cur = NULL, *nextNode = NULL;

	cur = root;


	while (cur!=NULL)
	{
		nextNode = cur->next;
		cur->next = pre;

		pre = cur;
		cur = nextNode;
	}

	return pre;
}

void reorderList(ListNode* head) {

	int num = 0;
	ListNode*p = head;

	while (p!=NULL)
	{
		num++;
		p = p->next;
	}

	if (num <= 2) return;

	int tailNum = num / 2;
	int res = num - tailNum;

	ListNode*q = head;

	for (int i = 1; i < res; i++)
	{
		q = q->next;
	}

	ListNode*tempNode = NULL;
	tempNode = q->next;
	q->next = NULL;
	q = reverse(tempNode);

	


	p = head;

	for (int i = 0; i < tailNum; i++)
	{
		tempNode = q->next;

		if (p->next != NULL)
		{
			q->next = p->next;
			p->next = q;
		}
		else
		{
			p->next = q;
			q->next = NULL;
		}
		q = tempNode;
		p = p->next->next;
	}

	



}

void main()
{
	ListNode*node0 = new ListNode(1);
	ListNode*node1 = new ListNode(2);
	ListNode*node2 = new ListNode(3);

	node0->next = node1;
	node1->next = node2;
	reorderList(node0);
}