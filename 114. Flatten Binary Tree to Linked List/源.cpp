#include<iostream>


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



void flatten(TreeNode* root) 
{
	if (root == NULL)return;

	if (root->left != NULL)flatten(root->left);
	if (root->right != NULL)flatten(root->right);

	if (root->left == NULL)return;

	if (root->right == NULL)
	{
		root->right = root->left;
		root->left = NULL;
		return;
	}

	TreeNode*node = root->left;

	while (node->right!=NULL)
	{
		node = node->right;
	}
	
	node->right = root->right;
	root->right = root->left;
	root->left = NULL;
	

	

}


void main()
{
	TreeNode*node1 = new TreeNode(1);
	TreeNode*node2 = new TreeNode(2);
	TreeNode*node3 = new TreeNode(3);
	node1->left = node2;
	node2->left = node3;
	flatten(node1);
	int t = 0;
}