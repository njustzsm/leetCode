#include<iostream>
#include<stack>
#include<vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode* root) 
{
	
	vector<int>result;
	if (!root)return result;
	stack<TreeNode*>Stack;

	TreeNode*p = root,*pre=NULL;

	Stack.push(p);

	while (!Stack.empty())
	{
		TreeNode*cur = Stack.top();
		

		if ((cur->left == NULL&&cur->right == NULL) || (pre != NULL && (cur->left == pre || cur->right == pre)))
		{
			result.push_back(cur->val);
			Stack.pop();
			pre = cur;
		}
		else
		{
			if (cur->right != NULL)
				Stack.push(cur->right);
			if (cur->left != NULL)
				Stack.push(cur->left);
		}

	}

	return result;



}

void main()
{

}