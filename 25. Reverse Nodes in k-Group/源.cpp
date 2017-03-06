#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseAGroup(ListNode*preNode, ListNode*pHead, int k)
{
	ListNode*lastNode = NULL;
	ListNode*curNode = pHead;
	ListNode*NextNode = NULL;

	for (int i = 0; i < k; i++)
	{
		NextNode = curNode->next;
		curNode->next = lastNode;
		lastNode = curNode;
		curNode = NextNode;
	}
	
	pHead->next = curNode;
	if (preNode!=NULL)
		preNode->next = lastNode;

	return lastNode;
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
	if (head == NULL)return NULL;
	if (k <= 1||head->next==NULL)return head;

	ListNode*result = NULL;

	ListNode*curNode = head;
	ListNode*temp = curNode;
	ListNode*preNode = NULL;

	while (true)
	{
		temp = curNode;
		for (int i = 1; i < k; i++)
		{
			if (temp == NULL)break;
			temp = temp->next;
		}
		if (temp!= NULL)
		{
			temp = temp->next;
			ListNode*curResult = reverseAGroup(preNode, curNode, k);
			if (result == NULL)result = curResult;
			preNode = curNode;
			curNode = temp;
		}
		else
		{
			if (result!=NULL)
				return result;
			return head;
		}
			
	}
	

}

void main()
{
	ListNode*pNode1 = new ListNode(1);
	ListNode*pNode2 = new ListNode(2);
	ListNode*pNode3 = new ListNode(3);
	ListNode*pNode4 = new ListNode(4);
	pNode1->next = pNode2;
	pNode2->next = pNode3;
	pNode3->next = pNode4;
	ListNode*result=reverseKGroup(pNode1,2);

	while (result != NULL)
	{
		printf("%d ", result->val);
		result = result->next;
	}

}