#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	
	ListNode*result = NULL;
	ListNode*last = NULL;
	

	if (l1 == NULL&&l2 == NULL)return NULL;
	if (l1 == NULL)return l2;
	if (l2 == NULL)return l1;


	while (l1!=NULL&&l2!=NULL)
	{
		ListNode*cur = NULL;
		if (l1->val < l2->val)
		{
			cur = l1;
			l1 = l1->next;
		}
		else
		{
			cur = l2;
			l2 = l2->next;
		}
			

		if (result == NULL)
		{
			result = cur;
			last = cur;
		}
		else
		{
			last->next = cur;
			last = cur;
		}
	}
	if (l1 != NULL)
		last->next = l1;
	else
		last->next = l2;

	return result;
	
}
void main()
{

}