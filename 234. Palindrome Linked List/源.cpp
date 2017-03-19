#include<iostream>
#include<string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) 
{
	if (head == NULL||head->next==NULL)return true;
	int n = 0;
	ListNode*node = head;

	while (node!=NULL)
	{
		n++;
		node = node->next;
	}


	ListNode*p1 = head, *p2 = head;

	int half = n / 2;
	if (n % 2 != 0)
		half++;

	for (int i = 0; i < half; i++)
	{
		p2 = p2->next;

	}
	
	ListNode*pre = NULL, *nextNode = NULL;

	while (p2!=NULL)
	{
		nextNode = p2->next;
		p2->next = pre;
		pre = p2;
		p2 = nextNode;
	}


	p2 = pre;

	while (p2!=NULL)
	{
		if (p1->val != p2->val)
			return false;

		p1 = p1->next;
		p2 = p2->next;
	}

	return true;



}
void main()
{

}