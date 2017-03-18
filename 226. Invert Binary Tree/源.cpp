#include<iostream>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) 
{
	if (root == NULL || (root->left == NULL&&root->right == NULL))
		return root;

	TreeNode*leftNode = root->left;
	TreeNode*rightNode = root->right;

	root->left = invertTree(rightNode);
	root->right = invertTree(leftNode);

	return root;
}

void main()
{

}