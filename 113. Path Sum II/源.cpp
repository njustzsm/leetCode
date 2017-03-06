#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>>result;

void dfs(TreeNode*cur, int curSum, int sum, vector<int>list)
{
	if (curSum+cur->val == sum)
	{
		if (cur->left == NULL&&cur->right == NULL)
		{
			list.push_back(cur->val);
			result.push_back(list);
			list.pop_back();
			return;
		}
		
	}

	list.push_back(cur->val);
	
	if (cur->left != NULL)
		dfs(cur->left,curSum+cur->val,sum,list);

	if (cur->right != NULL)
		dfs(cur->right, curSum + cur->val, sum, list);

	list.pop_back();

}


vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
	vector<int>list;
	if (root == NULL)
	{
		result.push_back(list);
		return result;
	}

	dfs(root,0,sum,list);
	return result;

}

void main()
{

}