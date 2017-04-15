#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct node
{
	int val;
	int count;
	node*left;
	node*right;



	node(int a)
	{
		val = a;
		count = 1;
		left = right = NULL;
	}
};
vector<int> countSmaller(vector<int>& nums) 
{
	int n = nums.size();
	vector<int>result;


	node*root = NULL;

	for (int i = nums.size() - 1; i >= 0; i--)
	{
		node*newNode = new node(nums[i]);

		if (root == NULL)
		{
			root = newNode;
			result.push_back(0);
		}
		else
		{
			node*p = root;
			node*pre = NULL;
			int curCount = 0;
			while (p!=NULL)
			{
				if (p->val >= newNode->val)
				{
					
					p->count++;
					pre = p;
					p = p->left;
				}
				else 
				{
					curCount += p->count;
					pre = p;
					p = p->right;
					
				}
			}
			if (pre->val >= newNode->val)
				pre->left = newNode;
			else
				pre->right = newNode;

			result.push_back(curCount);
		}
	}

	reverse(result.begin(),result.end());


	return result;
	

}

int main()
{
	vector<int>data{5,2,6,1};
	vector<int>result = countSmaller(data);
	return 0;
}