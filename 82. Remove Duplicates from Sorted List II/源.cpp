#include<iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


ListNode* deleteDuplicates(ListNode* head) 
{
	if (head == NULL || head->next == NULL)return head;

	ListNode*p = head,*q=NULL,*prePoint=NULL;

	while (p!=NULL&&p->next!=NULL)
	{
		if (p->val == p->next->val)
		{
			q = p->next;
			while (q!=NULL&&q->val==p->val)
			{
				q = q->next;
			}

			if (q == NULL)
			{
				
				if (p == head)
				{
					while (p!=NULL)
					{
						ListNode*tt = p->next;
						delete p;
						p = tt;
					}
					return NULL;
				}
				else
				{
					prePoint->next =NULL;
					while (p != NULL)
					{
						ListNode*tt = p->next;
						delete p;
						p = tt;
					}

				}
			}
			else
			{
				if (p == head)
				{
					head = q;
					prePoint = NULL;
				}
				else
				{
					prePoint->next = q;
				}

				while (p!=q)
				{
					ListNode*tt = p->next;
					delete p;
					p = tt;
				}
				
			}
		}
		else
		{
			if (prePoint == NULL)
				prePoint = p;
			else
				prePoint = prePoint->next;
			p = p->next;
		}
	}

	return head;
}

void main()
{

}