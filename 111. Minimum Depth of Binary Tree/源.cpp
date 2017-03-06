#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int minDepth(TreeNode* root) 
{
	if (root == NULL)return 0;

	if (root->left == NULL&&root->right == NULL)return 1;

	int result = INT_MAX;
	if (root->left != NULL)
	{
		int leftLength = minDepth(root->left);
		result = min(result,leftLength);
	}
	if (root->right != NULL)
	{
		int rightLength = minDepth(root->right);
		result = min(result,rightLength);
	}
	
	

	return 1 + result;


}

void main()
{

}
