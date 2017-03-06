#include<iostream>


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
	if (head == NULL || head->next == NULL)return head;

	ListNode*p = head;

	while (p->next!=NULL)
	{
		if (p->val == p->next->val)
		{
			ListNode*tt = p->next;
			p->next = p->next->next;
			delete tt;
			tt = NULL;
		}
		else
		{
			p = p->next;
		}
	}
	return head;

}

void main()
{

}