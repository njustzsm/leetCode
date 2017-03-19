#include<iostream>


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


void deleteNode(ListNode* node) 
{
	if (node == NULL)return;

	ListNode*pre = NULL, *cur = node, *nextNode = NULL;

	while (cur->next!=NULL)
	{
		nextNode = cur->next;

		cur->val = nextNode->val;

		pre = cur;
		cur = nextNode;
	}

	pre->next = NULL;
	delete cur;
	cur = NULL;
}

void main()
{

}