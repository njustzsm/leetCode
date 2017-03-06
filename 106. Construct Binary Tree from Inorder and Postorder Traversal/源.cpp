#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
	if (inorder.size() == 0 || postorder.size() == 0)return NULL;
	if (inorder.size() == 1)
	{
		TreeNode*node = new TreeNode(inorder[0]);
		return node;
	}

	int first = postorder[postorder.size() - 1];
	TreeNode*node = new TreeNode(first);


	int index = 0;

	for (; index < inorder.size();index++)
	{
		if (inorder[index] == first)
			break;
	}

	vector<int>inleft(inorder.begin(),inorder.begin()+index);
	vector<int>inright(inorder.begin()+index+1,inorder.end());

	vector<int>poleft(postorder.begin(),postorder.begin()+index);
	vector<int>poright(postorder.begin()+index,postorder.end()-1);

	node->left = buildTree(inleft,poleft);
	node->right = buildTree(inright,poright);
	return node;


}

void main()
{

}