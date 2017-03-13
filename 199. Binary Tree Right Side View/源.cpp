#include<iostream>
#include<queue>
#include<vector>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



vector<int> rightSideView(TreeNode* root) 
{
	vector<int>result;
	if (root == NULL)return result;

	queue<TreeNode*>que;

	que.push(root);

	while (!que.empty())
	{
		int m = que.size();

		for (int i = 0; i < m; i++)
		{
			TreeNode*cur = que.front();
			que.pop();
			if (i == m - 1)
			{
				result.push_back(cur->val);
			}

			if (cur->left)
			{
				que.push(cur->left);
			}
			if (cur->right)
			{
				que.push(cur->right);
			}
		}
	}

	return result;




}

void main()
{

}