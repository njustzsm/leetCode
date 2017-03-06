#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode*merge2Lists(ListNode*listA,ListNode*listB)
{
	if (listA == NULL)return listB;
	if (listB == NULL)return listA;

	ListNode*result = NULL, *tail = NULL;
	ListNode*p = listA, *q = listB;
	while (p!=NULL&&q!=NULL)
	{
		ListNode*cur = new ListNode(p->val);
		if (p->val > q->val)
		{
			cur->val = q->val;
			q = q->next;
		}
		else
		{
			p = p->next;
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

	while (p!=NULL)
	{
		ListNode*cur = new ListNode(p->val);
		tail->next = cur;
		tail = cur;
		p = p->next;
	}
	while (q != NULL)
	{
		ListNode*cur = new ListNode(q->val);
		tail->next = cur;
		tail = cur;
		q = q->next;
	}
	return result;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0)return NULL;
	vector<ListNode*>ListA(lists), ListB;
	int number = 0;


	while (true)
	{
		if (number == 0)
		{
			if (ListA.size() == 1)
				return ListA[0];
			int p = 0, q = ListA.size() - 1;
			ListB.clear();
			while (p<q)
			{
				ListNode*cur = merge2Lists(ListA[p],ListA[q]);
				ListB.push_back(cur);
				p++;
				q--;
			}
			if (p == q)
				ListB.push_back(ListA[p]);
			
		}
		else
		{
			if (ListB.size() == 1)
				return ListB[0];

			int p = 0, q = ListB.size() - 1;
			ListA.clear();
			while (p<q)
			{
				ListNode*cur = merge2Lists(ListB[p], ListB[q]);
				ListA.push_back(cur);
				p++;
				q--;
			}
			if (p == q)
				ListA.push_back(ListB[p]);
		}
		number = 1 - number;
	}
	
	
}

void main()
{

}