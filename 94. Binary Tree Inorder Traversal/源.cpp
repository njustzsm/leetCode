#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

vector<int>result;

void Recursion(TreeNode*curNode)
{
	if (curNode->left != NULL)
		Recursion(curNode->left);

	result.push_back(curNode->val);

	if (curNode->right != NULL)
	{
		Recursion(curNode->right);
	}
}

vector<int> inorderTraversal(TreeNode* root) 
{
	if (root == NULL)return result;

	Recursion(root);

	return result;



}

void main()
{

}