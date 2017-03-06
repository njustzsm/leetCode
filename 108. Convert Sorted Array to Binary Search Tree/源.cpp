#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	if (nums.size() == 0)return NULL;
	if (nums.size() == 1)
	{
		TreeNode*node=new TreeNode(nums[0]);
		return node;
	}

	int n = nums.size();

	TreeNode*root=new TreeNode(nums[n / 2]);

	vector<int>left0(nums.begin(),nums.begin()+n/2);
	vector<int>right0(nums.begin()+n/2+1,nums.end());
	
	root->left = sortedArrayToBST(left0);
	root->right = sortedArrayToBST(right0);

	return root;

}

void main()
{

}