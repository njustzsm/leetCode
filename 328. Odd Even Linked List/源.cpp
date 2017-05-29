#include<iostream>


using namespace std;


struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};





ListNode* oddEvenList(ListNode* head) 
{
	ListNode*pre = NULL,*cur=head;
	ListNode*p = head;
	//ListNode*evenHead = NULL, *tail = NULL;

	while (cur!=NULL&&cur->next!=NULL&&cur->next->next!=NULL)
	{
		pre = cur->next;
		cur = cur->next->next;

		pre->next = cur->next;
		

		cur->next = p->next;
		p->next = cur;
		p = cur;

		cur = pre;

	}

	return head;
	

}


int main()
{
	return 0;
}