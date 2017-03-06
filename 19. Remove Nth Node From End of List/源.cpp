#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode*pahead=head, *pbehind=head;
	ListNode*last = NULL;
	int temp=1;

	while (temp<n)
	{
		if (pahead != NULL)
			pahead = pahead->next;

		temp++;
	}

	while (pahead->next!=NULL)
	{
		pahead = pahead->next;

		last = pbehind;
		pbehind = pbehind->next;
	}
	
	if (pbehind == head)
	{
		head = head->next;
	}
	else
	{
		last->next = pbehind->next;
	}
	

		


	return head;
}

void main()
{

}