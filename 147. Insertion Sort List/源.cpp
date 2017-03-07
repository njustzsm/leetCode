#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* insertionSortList(ListNode* head) 
{
	if (head == NULL || head->next == NULL)return head;


	ListNode*result = NULL;

	ListNode*p = head,*nextNode=NULL;

	while (p!=NULL)
	{
		nextNode = p->next;
		if (result == NULL)
		{
			result =p;
			result->next = NULL;
		}
		else
		{
			ListNode*pre = NULL;
			ListNode*cur = result;

			while (cur!=NULL&&cur->val<p->val)
			{
				pre = cur;
				cur = cur->next;
			}

			if (pre == NULL)
			{
				p->next = result;
				result = p;
			}
			else if (cur == NULL)
			{
				pre->next = p;
				p->next = NULL;
			}
			else
			{
				pre->next = p;
				p->next = cur;
			}
		}
		p = nextNode;
	}

	return result;

}

void main()
{

}