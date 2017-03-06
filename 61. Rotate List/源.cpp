#include<iostream>
#include<vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};




ListNode* rotateRight(ListNode* head, int k) 
{
	if (head == NULL)return NULL;
	if (head->next == NULL||k==0)return head;

	ListNode*p = head,*tail=NULL;
	int n = 0;
	while (p!=NULL)
	{
		n++;
		tail = p;
		p = p->next;
	}


	tail->next = head;

	ListNode*pHead = head;

	int time = n - (k%n);
	for (int i = 0; i <time; i++)
	{
		pHead = pHead->next;
		tail = tail->next;
	}

	tail->next = NULL;
	return pHead;

}

void main()
{
	ListNode*node1 =new ListNode(1);
	ListNode*node2 = new ListNode(2);
	node1->next = node2;
	ListNode*result = rotateRight(node1,1);
}