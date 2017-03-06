#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool check = false;

void dfs(TreeNode*cur,int curSum,int sum,vector<int>list)
{
	if (check)return;

	if (curSum > sum)return;

	curSum += cur->val;
	if (curSum == sum&&cur->left == NULL&&cur->right == NULL)
	{
		check = true;
		return;
	}

}

bool hasPathSum(TreeNode* root, int sum) 
{
	if (root == NULL)
	{
		return false;
	}

	if (root->left == NULL&&root->right == NULL&&root->val == sum)return true;

	return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);





}


void main()
{

}