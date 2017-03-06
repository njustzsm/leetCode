#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


bool hasCycle(ListNode *head) 
{
	if (head == NULL||head->next==NULL)return false;


	ListNode*p = head, *q = head->next;
	while (q!=NULL)
	{
		if (p == q)return true;

		p = p->next;

		q = q->next;
		if (q != NULL)
			q = q->next;
	}

	return false;
}

void main()
{

}