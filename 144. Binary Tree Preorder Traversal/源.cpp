#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

void preOrder2(TreeNode *root)     //非递归前序遍历 
{
	stack<TreeNode*> s;
	TreeNode *p = root;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			cout << p->val << " ";
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}

void inOrder2(TreeNode *root)      //非递归中序遍历
{
	stack<TreeNode*> s;
	TreeNode *p = root;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			cout << p->val << " ";
			s.pop();
			p = p->right;
		}
	}
}

vector<int>result;

void dfs(TreeNode*root)
{
	if (root == NULL)return;

	result.push_back(root->val);
	dfs(root->left);
	dfs(root->right);
}


vector<int> preorderTraversal(TreeNode* root) 
{
	dfs(root);
	return result;
}

void main()
{

}