#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
	if (preorder.size() == 0 || inorder.size() == 0)return NULL;

	if (preorder.size() == 1)
	{
		TreeNode*result = new TreeNode(preorder[0]);
		return result;
	}

	int first = preorder[0];

	TreeNode*node = new TreeNode(first);


	int index = 0;

	for (; index < inorder.size(); index++)
	{
		if (inorder[index] == first)
			break;
	}

	vector<int>preleft(preorder.begin()+1,preorder.begin()+1+index);
	vector<int>preright(preorder.begin() + 1 + index,preorder.end());

	vector<int>inleft(inorder.begin(),inorder.begin()+index);
	vector<int>inright(inorder.begin()+index+1,inorder.end());

	node->left = buildTree(preleft,inleft);
	node->right = buildTree(preright,inright);

	return node;
}



void main()
{

}