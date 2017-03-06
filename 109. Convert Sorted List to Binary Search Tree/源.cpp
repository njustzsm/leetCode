#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};



struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


TreeNode* sortedListToBST(ListNode* head) 
{
	if (head == NULL)return NULL;

	
	if (head->next == NULL)
	{
		TreeNode*node = new TreeNode(head->val);
		return node;
	}

	int countn = 0;
	ListNode*cur = head;
	while (cur!=NULL)
	{
		countn++;
		cur = cur->next;
	}

	ListNode*preNode = NULL;
	cur = head;

	int num = countn / 2;

	for (int i = 0; i < num; i++)
	{
		preNode = cur;
		cur = cur->next;
	}

	TreeNode*node = new TreeNode(cur->val);

	if (preNode == NULL)
	{
		node->left = NULL;
		node->right = sortedListToBST(cur->next);
		return node;
	}
	else
	{
		preNode->next = NULL;
		node->left = sortedListToBST(head);
		node->right = sortedListToBST(cur->next);
		return node;
	}



}


void main()
{

}