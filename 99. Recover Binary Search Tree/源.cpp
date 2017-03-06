#include<iostream>
#include<vector>
#include<queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

vector<int>data;

void dfs(TreeNode*root)
{
	if (root->left != NULL)
		dfs(root->left);

	data.push_back(root->val);

	if (root->right!=NULL)
		dfs(root->right);
}

TreeNode*mis1 = NULL, *mis2 = NULL,*pre=NULL;


void findTwoNode(TreeNode* root)
{
	if (root == NULL)
		return;
	findTwoNode(root->left);
	if (pre != NULL&&pre->val>root->val)
	{
		if (mis1 == NULL)
			mis1 = pre;
		mis2 = root;
	}
	pre = root;
	findTwoNode(root->right);
	
}


void recoverTree(TreeNode* root) 
{
	findTwoNode(root);
	if (mis1 != NULL&&mis2 != NULL)
	{
		int value = mis1->val;
		mis1->val = mis2->val;
		mis2->val = value;
	}


	
}


	

void main()
{

}