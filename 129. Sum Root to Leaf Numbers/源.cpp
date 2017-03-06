#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




int sumNumbers(TreeNode* root) 
{
	if (root == NULL)return 0;

	long long int result=0;

	queue<TreeNode*>que;
	queue<int>digits;

	digits.push(root->val);
	que.push(root);

	while (!que.empty())
	{
		int num = que.size();

		for (int i = 0; i < num; i++)
		{
			TreeNode*cur = que.front();
			que.pop();
			int curNum = digits.front();
			digits.pop();

			if (cur->left != NULL)
			{
				que.push(cur->left);
				digits.push(curNum*10+cur->left->val);
			}
			 if (cur->right != NULL)
			{
				que.push(cur->right);
				digits.push(curNum*10+cur->right->val);
			}
			 if (cur->left==NULL&&cur->right==NULL)
			{
				result += curNum;
			}
		}
	}

	if (result <= INT_MAX)
		return result;
	return 0;




}
void main()
{
	TreeNode*root = new TreeNode(0);
	TreeNode*root1 = new TreeNode(1);
	TreeNode*root2 = new TreeNode(2);
	root->left = root1;
	root->right = root2;
	sumNumbers(root);
}