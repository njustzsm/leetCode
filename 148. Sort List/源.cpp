#include<iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sort0(ListNode* head,int num)
{
	if (num == 1)return head;

	int halfNum = num / 2;

	ListNode*node = head;

	for (int i = 0; i < halfNum-1; i++)
	{
		node = node->next;
	}

	ListNode*right = sort0(node->next, num - halfNum);
	node->next = NULL;
	ListNode*left = sort0(head,halfNum);

	ListNode*result = NULL,*tail=NULL;

	while (right!=NULL&&left!=NULL)
	{
		ListNode*cur = right;
		if (right->val < left->val)
		{
			right = right->next;
		}
		else
		{
			cur = left;
			left = left->next;
		}

		if (result == NULL)
		{
			result = tail = cur;
		}
		else
		{
			tail->next = cur;
			tail = cur;
		}
	}

	if (right != NULL)
		tail->next = right;
	if (left != NULL)
		tail->next = left;
	
	return result;



}


ListNode* sortList(ListNode* head) 
{
	if (head == NULL || head->next == NULL)return head;


	int num = 0;
	ListNode*node = head;
	while (node)
	{
		num++;
		node = node->next;
	}

	return sort0(head,num);
}

void main()
{

}