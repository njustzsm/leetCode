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

bool isMirror(TreeNode*left0,TreeNode*right0)
{
	if (left0 == NULL&&right0 == NULL)return true;
	if (left0 == NULL || right0 == NULL)return false;

	bool result = true;

	if (left0->val != right0->val)return false;

	return isMirror(left0->left, right0->right) && isMirror(left0->right, right0->left);
}

bool isSymmetric(TreeNode* root) 
{
	if (root == NULL)return true;

	return isMirror(root->left, root->right);

	


}

void main()
{
	TreeNode*node1 = new TreeNode(1);
	TreeNode*node2 = new TreeNode(2);
	TreeNode*node3 = new TreeNode(2);
	TreeNode*node4 = new TreeNode(3);
	TreeNode*node5 = new TreeNode(3);

	node1->left = node2;
	node1->right = node3;
	node2->right = node4;
	node3->right = node5;

	data.clear();
	isSymmetric(node1);

}