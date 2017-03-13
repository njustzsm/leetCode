#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};



ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;

	ListNode*cur = head, *pre = NULL, *nextNode = NULL;

	while (cur!=NULL)
	{
		nextNode = cur->next;

		cur->next = pre;

		pre = cur;
		cur = nextNode;
	}

	return pre;


}
void main()
{

}