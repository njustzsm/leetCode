#include<iostream>
#include<vector>

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
	if (root->right != NULL)
		dfs(root->right);
}


bool isValidBST(TreeNode* root) 
{
	if (root == NULL)return true;

	dfs(root);
	for (int i = 0; i < data.size() - 1; i++)
	{
		if (data[i] >= data[i + 1])
			return false;
	}
	return true;

}

void main()
{
	TreeNode*node1 = new TreeNode(1);
	TreeNode*node2 = new TreeNode(2);
	TreeNode*node3 = new TreeNode(3);

	node2->left = node1;
	node2->right = node3;
	isValidBST(node2);
}