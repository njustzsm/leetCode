#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
	if (headA == NULL || headB == NULL)return NULL;

	int sumA = 0, sumB = 0;

	ListNode*node = headA;
	while (node!=NULL)
	{
		sumA++;
		node = node->next;
	}
	node = headB;
	while (node!=NULL)
	{
		sumB++;
		node = node->next;
	}

	ListNode*p = headA, *q = headB;

	if (sumA > sumB)
	{
		int num = sumA - sumB;
		for (int i = 0; i < num; i++)
			p = p->next;
	}
	if (sumA < sumB)
	{
		int num = sumB - sumA;
		for (int i = 0; i < num; i++)
			q = q->next;
	}

	while (p!=NULL&&p->val!=q->val)
	{
		p = p->next;
		q = q->next;
	}

	return p;







}
void main()
{

}