#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int GetLength(TreeNode* root)
{
	if (root == NULL)return 0;

	int leftLength = GetLength(root->left);
	int rightlength = GetLength(root->right);

	return 1 + max(leftLength,rightlength);
}

bool isBalanced(TreeNode* root) 
{
	if (root == NULL)return true;

	int leftLength = GetLength(root->left);
	int rightLength = GetLength(root->right);

	if (abs(leftLength - rightLength) <= 1)
		return isBalanced(root->left) && isBalanced(root->right);
	else
		return false;

}
void main()
{

}