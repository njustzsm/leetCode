#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	if (l1 == NULL)return l2;
	if (l2 == NULL)return l1;


	ListNode*s1 = l1, *s2 = l2,*result=NULL,*tail=NULL;
	int res = 0,sum=0,cur=0;

	while (s1!=NULL&&s2!=NULL)
	{
		sum = s1->val + s2->val + res;
		res = sum / 10;
		cur = sum % 10;
		ListNode*node = new ListNode(cur);
		if (result == NULL)
		{
			result = tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
		s1 = s1->next;
		s2 = s2->next;
	}

	while (s1 != NULL)
	{
		sum = s1->val + res;
		res = sum / 10;
		cur = sum % 10;

		ListNode*node = new ListNode(cur);
		tail->next = node;
		tail = node;

		s1 = s1->next;
	}

	while (s2 != NULL)
	{
		sum = s2->val + res;
		res = sum / 10;
		cur = sum % 10;

		ListNode*node = new ListNode(cur);
		tail->next = node;
		tail = node;

		s2 = s2->next;
	}

	if (res != 0)
	{
		ListNode*node = new ListNode(res);
		tail->next = node;
		tail = node;
	}

	return result;
	//vector<int>s1, s2;

	/*ListNode*cur = l1;
	while (cur!=NULL)
	{
		s1.push_back(cur->val);
		cur = cur->next;
	}

	cur = l2;
	while (cur != NULL)
	{
		s2.push_back(cur->val);
		cur = cur->next;
	}

	int add = 0;

	ListNode*node = NULL;*/
	





}

void main()
{

}