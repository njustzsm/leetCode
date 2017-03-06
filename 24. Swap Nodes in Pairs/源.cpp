#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* swapPairs(ListNode* head) 
{
	if (head == NULL)return NULL;

	ListNode*pReturnHead = NULL;
	ListNode*preNode = NULL;
	ListNode*NodeA = head, *NodeB = head->next;
	if (NodeB == NULL)return head;

	while (NodeA!=NULL&&NodeB!=NULL)
	{
		if (preNode == NULL)
		{
			NodeA->next = NodeB->next;
			NodeB->next = NodeA;
			preNode = NodeA;
			pReturnHead = NodeB;
		}
		else
		{
			preNode->next = NodeB;
			NodeA->next = NodeB->next;
			NodeB->next = NodeA;

			preNode = NodeA;
		}
		
		if (NodeA->next == NULL)return pReturnHead;
		NodeB = NodeA->next->next;
		NodeA = NodeA->next;

	}
	return pReturnHead;



}
void main()
{

}