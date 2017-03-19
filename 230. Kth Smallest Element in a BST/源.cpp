#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int getCount(TreeNode*root)
{
	if (root == NULL)return 0;
	return 1 + getCount(root->left) + getCount(root->right);
}


int kthSmallest(TreeNode* root, int k) 
{
	int leftCount =getCount(root->left);

	if (leftCount == k - 1)
		return root->val;

	if (leftCount > k - 1)
		return kthSmallest(root->left,k);

	return kthSmallest(root->right,k-leftCount-1);

}
void main()
{

}