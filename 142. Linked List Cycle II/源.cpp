#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode * hasCycle(ListNode *head)
{
	if (head == NULL || head->next == NULL)return NULL;


	ListNode*p = head, *q = head->next;
	while (q != NULL)
	{
		if (p == q)break;

		p = p->next;

		q = q->next;
		if (q != NULL)
			q = q->next;
	}

	if (q == NULL)return NULL;

	int cycleNum = 1;
	q = q->next;
	while (p!=q)
	{
		cycleNum++;
		q = q->next;
	}

	p = head;
	q = head;
	for (int i = 0; i < cycleNum; i++)
		q = q->next;

	while (p!=q)
	{
		p = p->next;
		q = q->next;
	}

	return p;

	
}

void main()
{

}