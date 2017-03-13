#include<iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val)
{
	if (head == NULL)return NULL;

	ListNode*pre = NULL,*curNode=head;


	while (curNode!=NULL)
	{
		if (curNode->val == val)
		{
			if (curNode == head)
			{
				curNode = head->next;
				delete head;
				head = curNode;
			}
			else
			{
				pre->next = curNode->next;
				delete curNode;
				curNode = pre->next;
			}
		}
		else
		{
			pre = curNode;
			curNode = curNode->next;
		}
	}

	return head;





}

void main()
{

}
